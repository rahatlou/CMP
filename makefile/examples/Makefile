CXX := g++

# files that are compiled AND linked to create an application
APPS := app1.cc app2.cc app11.cc

# binaries are appications to run from the command line, linked from APPS
BINS := $(APPS:%.cc=%)

# source files are only compiled, typically one file for each class
SRCS := $(filter-out $(APPS), $(wildcard *.cc))

# name of object files generated automatically from source files
OBJS := $(subst .cc,.o, $(SRCS))

# name of our library
OURLIB := CMP
LIBFILE := lib$(OURLIB).a

# compilation and linking options
LDFLAGS += -L. -l$(OURLIB)

list:
	echo "source files:\t" $(SRCS)
	echo "objects files:\t" $(OBJS)
	echo "applications:\t" $(APPS)
	echo "executables:\t" $(BINS)

bin: ${BINS}

## rule to make a BIN from an APPS file and the library
%:	%.cc lib
	$(CXX) -o $@ $(CPPFLAGS) $(LDFLAGS) $<

# lib target requires there be a library called $(LIBFILE)
lib: $(LIBFILE)

# the library file needs the object files
$(LIBFILE):	$(OBJS)
	libtool -static -o $@  $^
# remove the object files that are no longer needed
	rm -f $(OBJS)
	echo $(LIBFILE) "built"


# Rule to compile cc files
%.o:	%.cc
	$(CXX) -c $(CPPFLAGS) $<

# Rule to compile C files
%.o:	%.C
	$(CXX) -c $(CPPFLAGS) $<

clean:
	@rm -f $(LIBFILE)
	@rm -f $(BINS)
