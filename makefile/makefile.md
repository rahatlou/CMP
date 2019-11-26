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
Using a `Makefile` we can obtain the same results by running a simple command from the command line
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

## First simple example from lec13

Let's look at the examples in [lec13/examples1](../lec13/examples1):
```shell
$ ls
CustomIntegrator.h     Function.cc            Gauss.h                MCIntegrator.h         app11.cc
CustomMCIntegrator.cc  Function.h             Integrator.h           Makefile               app2.cc
CustomMCIntegrator.h   Gauss.cc               MCIntegrator.cc        app1.cc
```

we have 3 applications `app1.cc`, `app11.cc`, and `app2.cc` which depend on different files and require different compilation commands




### Makefile for application `app1`
In order to build the app
```shell
g++ MCIntegrator.cc app1.cc -o app1
```
this can be achieved with a simple [Makefile](../lec13/examples1/Makefile.1)
```Makefile
app1: app1.cc MCIntegrator.cc
```
```shell
$ make
c++     app1.cc MCIntegrator.cc   -o app1
$ ls app1
app1
```
however it uses the XCode C++ compiler instead of `g++`. This can be changed via setting a variable in the Makefile
```make
CXX:=g++

app1: app1.cc MCIntegrator.cc
```
now
```shell
$ make
g++     app1.cc MCIntegrator.cc   -o app1
```
we can now add all our applications to the Makefile and also create a new *target* to quickly delete the executable files
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
$ make
g++     app1.cc MCIntegrator.cc   -o app1
```
you can specify another target
```shell
$ make app11
g++     app11.cc CustomMCIntegrator.cc Function.cc Gauss.cc   -o app11
```
we have also added a new target `clean` to remove the executables if needed
```shell
$ ls app*
app1     app1.cc   app11    app11.cc  app2.cc
$ make  clean
rm -f app1 app2 app11
$ ls app*
app1.cc   app11.cc  app2.cc
```
### special target *all*

If we want to always build all executables by default we can introduce a first target `all` that has all
other targets as prerequisites.
```make
CXX:=g++

all: app1 app2 app11

app1: app1.cc MCIntegrator.cc

app2: app2.cc MCIntegrator.cc

app11: app11.cc  CustomMCIntegrator.cc  Function.cc  Gauss.cc

clean:
	rm -f app1 app2 app11
```
now by default all executables are built
```make
$ make
g++     app1.cc MCIntegrator.cc   -o app1
g++     app2.cc MCIntegrator.cc   -o app2
g++     app11.cc CustomMCIntegrator.cc Function.cc Gauss.cc   -o app11

$ ls app*
app1     app1.cc   app11    app11.cc  app2     app2.cc
```
