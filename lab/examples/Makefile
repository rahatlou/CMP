CXX := g++

# files that are compiled AND linked to create an application
APPS := analyser.cc

# binaries are appications to run from the command line, linked from APPS
BINS := $(APPS:%.cc=%)

# source files are only compiled, typically one file for each class
SRCS := $(filter-out $(APPS), $(wildcard *.cc *.C))

# name of object files generated automatically from source files
OBJS := $(subst .cc,.o, $(SRCS))

# name of our library
OURLIB := CMP
LIBFILE := lib$(OURLIB).a

# our linking options are added to LDFLAGS. If it has no previous value
# it only has what we add
LDFLAGS += -L. -l$(OURLIB) `$(ROOTSYS)/bin/root-config --libs`


# compilation flags
CPPFLAGS +=  `$(ROOTSYS)/bin/root-config --cflags`


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
