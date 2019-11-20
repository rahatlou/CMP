CC := g++

ROOTCPPFLAGS := `${ROOTSYS}/bin/root-config --cflags`
ROOTLDFLAGS :=  `${ROOTSYS}/bin/root-config --libs`

# files that are compiled AND linked to create an application
APPS := app1.cc app2.cc app11.cc

# binaries are appications to run from the command line, linked from APPS
BINS := $(APPS:%.cc=%)

# source files are fonly compiled, typically one file for each class
SRCS := $(filter-out $(APPS), $(wildcard *.cc))

# name of object files generated automatically from source files
OBJS := $(subst .cc,.o, $(SRCS))

# name of our library
OURLIB := CMP
LIBFILE := lib$(OURLIB).a

# compilation and linking options
CPPFLAGS := $(ROOTCPPFLAGS)
LDFLAGS := -L. -l$(OURLIB) $(ROOTLDFLAGS)

list:
	@echo "source files: ${SRCS}"
	@echo "objects files: ${OBJS}"
	@echo "application files: ${APPS}"
	@echo "executables: ${BINS}"

bin: ${BINS}

%:	%.cc lib
	@echo "Linking $@ from $<"
	@$(CC) -o $@ $(LDFLAGS) $<

lib: $(LIBFILE)
	@echo "Creating library ${LIBFILE}"

$(LIBFILE):	$(SRCS:%.cc=%.o)
	@ar ru $@ $^
	@ranlib $@

%.o:	%.cc
	@echo "Compiling $<"
	@$(CC) -c $(CPPFLAGS) $<

clean:
	@rm -f $(LIBFILE)
	@rm -f $(OBJS)
	@rm -f $(BINS)
