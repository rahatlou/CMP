# Makefile

The [GNU Makefile](https://www.gnu.org/software/make/manual/make.html) is a utility
to help compiling large projects and determine which files and pieces of code must
be compiled to link an executable.

A typical use case from the previous lectures
- write a few classes `Shape`, `Square`, `Circle`
- compile each class separately
```shell
g++ -c Square.cc
g++ -c Circle.cc
```
- write an application  `app.cc`
- link the executable
```shell
g++ -o app.exe Square.o Circle.o app.cc
```

Another example using also the ROOT libraries for the numerical integrators was
- compile `MCIntegrator` and `RectangleIntegrator` using the ROOT header files and flags
```shell
g++ -c `${ROOTSYS}/bin/root-config --cflags` MCIntegrator.cc
g++ -c `${ROOTSYS}/bin/root-config --cflags` RectangleIntegrator.cc
```
- write an application `example.cc` and compile and link it using also the ROOT libraries
```shell
g++ -o  MCIntegrator.o RectangleIntegrator.o `${ROOTSYS}/bin/root-config --cflags --libs` example.app
```
Using a `Makefile` called `someMakeFile` we can obtain the same results by running a simple command from the command line
```shell
make -f someMakeFile
```
and more often, when we have just one make file called `Makefile` we do
```shell
make
```
The instructions for compiling which files and how to compile them is stored in a `Makefile` file that is used by the `make` command.

The `Makefile` has a simple structure
```make
target: prerequisites ...
  recipe...
  ...
  ...

```
### __Do Not Forget__
- you must use a [TAB] keystroke before the *recipe*. Using simple space keystrokes
will cause errors with make.
- the file must be called `Makefile` or `makefile`. Anything else will not work. So `MakeFile` (with capital `F`) will not be understood
- If your makefile has a different name (for unusual reasons) or you have several of them you can use the `-f` option
```shell
make -f Makefile.3 all
make -f Makefile.4 clean
```

## Example: Strategy Pattern

Let's look at these [examples](../examples/makefile/) for strategy pattern:
```shell
$ ls
CustomIntegrator.h     Function.cc            Gauss.h                MCIntegrator.h         app11.cc
CustomMCIntegrator.cc  Function.h             Integrator.h           Makefile               app2.cc
CustomMCIntegrator.h   Gauss.cc               MCIntegrator.cc        app1.cc
```

we have 3 applications `app1.cc`, `app11.cc`, and `app2.cc` which depend on different files and require different compilation commands




### A first example of Makefile
In order to build the app
```shell
g++ MCIntegrator.cc app1.cc -o app1
```
this can be achieved with a simple makefile [`Makefile.1`](../examples/makefile/Makefile.1)
```Makefile
app1: app1.cc MCIntegrator.cc
```
running the command,
```shell
$ make
c++     app1.cc MCIntegrator.cc   -o app1
$ ls app1
app1
```
it builds the executable, however it uses the XCode C++ compiler instead of `g++`. This can be changed via setting a *variable* in [`Makefile.2`](../examples/makefile/Makefile.2)
```make
CXX:=g++

app1: app1.cc MCIntegrator.cc
```
now
```shell
$ make -f Makefile.2
g++     app1.cc MCIntegrator.cc   -o app1
```
we can now add all our applications in  [`Makefile.3`](../examples/makefile/Makefile.3) and also create a new *target* to quickly delete the executable files
```make
CXX:=g++

app1: app1.cc MCIntegrator.cc

app2: app2.cc MCIntegrator.cc

app11: app11.cc  CustomMCIntegrator.cc  Function.cc  Gauss.cc

clean:
        rm -f app1 app2 app11
```
by default `make` executes the first target in the file.

```shell
$ make -f Makefile.3
g++     app1.cc MCIntegrator.cc   -o app1
```
you can specify another target
```shell
$ make -f Makefile.3 app11
g++     app11.cc CustomMCIntegrator.cc Function.cc Gauss.cc   -o app11
```
we have also added a new target `clean` to remove the executables if needed
```shell
$ ls app*
app1     app1.cc   app11    app11.cc  app2.cc
$ make  -f Makefile.3 clean
rm -f app1 app2 app11
$ ls app*
app1.cc   app11.cc  app2.cc
```
### special target *all*

If we want to always build all executables by default we can introduce a first target `all` that has all
other targets as prerequisites. This is  done in [`Makefile.4`](../examples/makefile/MakeFile.4)
```make
CXX:=g++

all: app1 app2 app11

app1: app1.cc MCIntegrator.cc

app2: app2.cc MCIntegrator.cc

app11: app11.cc  CustomMCIntegrator.cc  Function.cc  Gauss.cc

clean:
	rm -f app1 app2 app11 *.o
```
now by default all executables are built
```make
$ make -f Makefile.4
g++     app1.cc MCIntegrator.cc   -o app1
g++     app2.cc MCIntegrator.cc   -o app2
g++     app11.cc CustomMCIntegrator.cc Function.cc Gauss.cc   -o app11

$ ls app*
app1     app1.cc   app11    app11.cc  app2     app2.cc
```

## Makefile with variables

In the previous examples we had to type in explicitly the name of all source files, or application  files and their dependencies. We then relied on the implicit Makefile rules to compile and link.

Instead we would like to
- specify the list of application files - those that are linked to build the binaries
- determine automatically the other files (source files) to be compiled
- compile the source files and possibly specify compilation options such as ROOT header files
- make a library with compiled object files  
- use the library and the link the binaries

This is done in [`Makefile.5`](../examples/makefile/Makefile.5)

First we define the C++ compiler to be used and define a new variable `APPS` to specify which files are used to build binaries
```make
CXX := g++

# files that are compiled AND linked to create an application
APPS := app1.cc app2.cc app11.cc

# binaries are appications to run from the command line, linked from APPS
BINS := $(APPS:%.cc=%)
```
The name of the binaries is determined automatically from `APPS` by removing the `.cc` extension and the list is stored in a new variable `BINS`.

Now we can determine the list of source files to be compiled and their corresponding object files. The source files are all `.cc` files excluding the application files.
```make
# source files are only compiled, typically one file for each class
SRCS := $(filter-out $(APPS), $(wildcard *.cc))

# name of object files generated automatically from source files
OBJS := $(subst .cc,.o, $(SRCS))
```
Next we define the name of our library to made. For now we put the library file in the current directory. We also modify the `LDFLAG` variable (used at link time) to use our library.
```make
# name of our library
OURLIB := CMP
LIBFILE := lib$(OURLIB).a

# compilation and linking options
LDFLAGS += -L. -l$(OURLIB)
```
we now define a target `list` to test our variables in the Makefile
```make
list:
	echo "source files:\t" $(SRCS)
	echo "objects files:\t" $(OBJS)
	echo "applications:\t" $(APPS)
	echo "executables:\t" $(BINS)
```
and try our makefile. Note that since the file is called `Makefile.5` and not simply
`Makefile` we need to specify it at the command line.
```shell
$ make -f Makefile.5
echo "source files:\t" CustomMCIntegrator.cc Function.cc Gauss.cc MCIntegrator.cc
source files:	 CustomMCIntegrator.cc Function.cc Gauss.cc MCIntegrator.cc
echo "objects files:\t"  CustomMCIntegrator.o Function.o Gauss.o MCIntegrator.o
objects files:	 CustomMCIntegrator.o Function.o Gauss.o MCIntegrator.o
echo "applications:\t" app1.cc app2.cc app11.cc
applications:	 app1.cc app2.cc app11.cc
echo "executables:\t" app1 app2 app11
executables:	 app1 app2 app11
```
both the recipe being executed and its output are displayed. It is possible to hide the recipe and only show its output
using the `@` at the beginning of the recipe in [Makefile.6](../examples/makefile/Makefile.6)
```make
list:
	@echo "source files:\t" $(SRCS)
	@echo "objects files:\t" $(OBJS)
	@echo "applications:\t" $(APPS)
	@echo "executables:\t" $(BINS)
```
now
```shell
$ make -f Makefile.6
source files:	 CustomMCIntegrator.cc Function.cc Gauss.cc MCIntegrator.cc
objects files:	 CustomMCIntegrator.o Function.o Gauss.o MCIntegrator.o
applications:	 app1.cc app2.cc app11.cc
executables:	 app1 app2 app11
```

Now we add the targets for binaries and libraries in [Makefile.7](../examples/makefile/Makefile.7)
```make
# target to build all binaries
bin: ${BINS}

## rule to make a BIN from an APPS file and the library
%:	%.cc lib
	$(CXX) -o $@  $(LDFLAGS) $<
```
The `bin` target has the binaries as the prerequisite. and for each prerequisite we define a rule with a recipe.
This time we do not reply on the implicit rule but provide a recipe that uses `LDFLAGS` which we modified to include our library.
Note the use of two special `Makefile` variables
- `$@` is  the target  name
- `$<` is the name of the first prerequisite

the binary target has `lib` as one of its prerequisites which we need to define
```make
# lib target requires there be a library called $(LIBFILE)
lib: $(LIBFILE)

# the library file needs the object files
$(LIBFILE):	$(OBJS)
	libtool -static -o $@  $^
# remove the object files that are no longer needed
	rm -f $(OBJS)
```
the `lib` target has the library file `$(LIBFILE)` as the prerequisite so we define also a targe to create such a file from the object files.

Try `man libtool` in the shell to learn more about the `libtool` command that we have used to build a static library. Again we use the special variable `$@` and a new variable `$^` whose value is the full list of prerequisites. __NB:__ `$<` was only the first prerequisite.

Then we add the rules to compile the object files needed to make the library
```make
# Rule to compile cc files
%.o:	%.cc
	$(CXX) -c  $<

# Rule to compile C files
%.o:	%.C
	@$(CXX) -c $<
```
and  a `clean` target to remove both binaries and the library file
```make
clean:
	rm -f $(LIBFILE)
	rm -f $(BINS)
```
and using [`Makefile.7`](../examples/makefile/Makefile.7)
```shell
$ make -f Makefile.7 bin
g++ -c  CustomMCIntegrator.cc
g++ -c  Function.cc
g++ -c  Gauss.cc
g++ -c  MCIntegrator.cc
libtool -static -o libCMP.a  CustomMCIntegrator.o Function.o Gauss.o MCIntegrator.o
rm -f  CustomMCIntegrator.o Function.o Gauss.o MCIntegrator.o
echo libCMP.a "built"
libCMP.a built
g++ -o app1  -L. -lCMP app1.cc
g++ -o app2  -L. -lCMP app2.cc
g++ -o app11  -L. -lCMP app11.cc
```
By invoking the bin target all source files are compiled, a library is made and then the binaries are correctly linked. In this version of the file all details of the recipe appear on the screen.

### cleaning the make output [`Makefile.8`](../examples/makefile/Makefile.8)
It is common to hide the recipe commands with `@` and provide a simpler and more concise output  with `@echo "some message"`. This is done in [`Makefile.8`](../examples/makefile/Makefile.8)
```make
CXX := g++

# files that are compiled AND linked to create an application
APPS := app1.cc app2.cc app11.cc

# binaries are applications to run from the command line, linked from APPS
BINS := $(APPS:%.cc=%)

# source files are only compiled, typically one file for each class
SRCS := $(filter-out $(APPS), $(wildcard *.cc))

# name of object files generated automatically from source files
OBJS := $(subst .cc,.o, $(SRCS))

# name of our library
OURLIB := CMP
LIBFILE := lib$(OURLIB).a

# our linking options are added to LDFLAGS. If it has no previous value
# it only has what we add
LDFLAGS += -L. -l$(OURLIB)

# Use @ at the beginning of a recipe to prevent the comment from being shown in output
# only the output of the display will be displayed

list:
	@echo "source files:\t" $(SRCS)
	@echo "objects files:\t" $(OBJS)
	@echo "applications:\t" $(APPS)
	@echo "executables:\t" $(BINS)

# target to buil all binaries
bin: ${BINS}

## rule to make a BIN from an APPS file and the library
%:	%.cc lib
	@echo "Linking $@ from $<"
	@$(CXX) -o $@  $(LDFLAGS) $<

# lib target requires there be a library called $(LIBFILE)
lib: $(LIBFILE)

# the library file needs the object files
$(LIBFILE):	$(OBJS)
	@libtool -static -o $@  $^
# remove the object files that are no longer needed
	@rm -f $(OBJS)
	@echo $(LIBFILE) "built"

# Rule to compile cc files
%.o:	%.cc
	@echo "Compiling $<"
	@$(CXX) -c $(CPPFLAGS) $<

# Rule to compile C files
%.o:	%.C
	@echo "Compiling $<"
	@$(CXX) -c $(CPPFLAGS) $<

clean:
	@echo "Removing" $(LIBFILE) " and " $(BINS)
	@rm -f $(LIBFILE) $(BINS)
```
which produces the following output
```shell
$ make -f Makefile.8 bin
Compiling CustomMCIntegrator.cc
Compiling Function.cc
Compiling Gauss.cc
Compiling MCIntegrator.cc
libCMP.a built
Linking app1 from app1.cc
Linking app2 from app2.cc
Linking app11 from app11.cc

$ make -f Makefile.8 clean
Removing libCMP.a  and  app1 app2 app11
```
