# Using ROOT libraries

## ROOT installation
follow the [instructions on the ROOT website](https://root.cern.ch/content/release-61404) to install the latest version of ROOT.
As of 7 Nov 2019 the latest PRO version is 6.18/04.

Typically you download a `tar gz` file (usually saved in Downloads) and uncompress it in some directory. This works perfectly fine on MacOS and Linux. For example:
```shell
cd $HOME
tar xvzf root_v6.18.04.Linux-ubuntu18-x86_64-gcc7.4.tar.gz
```
this will create a `root` directory in your home directory (aka `$HOME`).

It is good practice to rename the directory to reflect the version of ROOT
```
mv root root-61804
ls root-61804
LICENSE    aclocal/   cmake/     emacs/     fonts/     icons/     lib/       man/       tmva/
README/    bin/       config/    etc/       geom/      include/   macros/    test/    tutorials/
```

## Setup environment variables
every time you open a terminal you need to setup the following environment variables to run root or use its libraries:
  * `ROOTSYS`
  * `LD_LIBRARY_PATH`
  * `PATH`

Setting these variables is different for different shells

#### bash
If you are using **sh** or **bash**
```
export ROOTSYS=${HOME}/root-61804
export LD_LIBRARY_PATH=${ROOTSYS}/lib
export PATH=${PATH}:${ROOTSYS}/bin
```

you can add these lines at the end of `$HOME/.bash_profile` file so it is done automatic ally for all new sessions or terminal windows

#### cshrc or tcsh
If you are using **csh** or **tcsh**
```
setenv ROOTSYS ${HOME}/root-61804
setenv LD_LIBRARY_PATH ${ROOTSYS}/lib
setenv PATH ${PATH}:${ROOTSYS}/bin
```

you can add these lines at the end of `$HOME/.cshrc` file so it is done automatic ally for all new sessions or terminal windows

If you have done eveything right you should be able to do the following:
```
root-config
Usage: root-config [--prefix[=DIR]] [--exec-prefix[=DIR]] [--version] [--cflags] [--auxcflags] [--ldflags] [--new] [--nonew] [--libs] [--glibs] [--evelibs] [--bindir] [--libdir] [--incdir] [--etcdir] [--srcdir] [--noauxcflags] [--noauxlibs] [--noldflags] [--has-<feature>] [--arch] [--platform] [--config] [--features] [--ncpu] [--git-revision] [--python-version] [--cc] [--cxx] [--f77] [--ld ] [--help]
```
or run root interactively
```
$ root
   ------------------------------------------------------------
  | Welcome to ROOT 6.18/00                http://root.cern.ch |
  |                               (c) 1995-2018, The ROOT Team |
  | Built for macosx64                                         |
  | From tag v6-14-00, 13 June 2018                            |
  | Try '.help', '.demo', '.license', '.credits', '.quit'/'.q' |
   ------------------------------------------------------------

root [0] .q
$
```

## Compiling and Linking with ROOT libraries

In order to compile a class `Datum` with files `Datum.h` and `Datum.cc` and link an application `app.cc` using also ROOT classes you need to do
```
g++ -o /tmp/app app.cc Datum.cc `$ROOTSYS/bin/root-config --libs --cflags`
```

**Nota bene**: this exact order of file names and options are needed by recent versions of g++, for example on recent versions of ubuntu (14 or later)

```
g++ -o /tmp/app `$ROOTSYS/bin/root-config --libs --cflags`  app.cc Datum.cc
```

works on MacOS but will fail on Ubuntu.
