# Introduction to Python

## What is python?
  * General purpose language blending procedural, functional, and object-oriented programming paradigms
  * A very high level language very different from C and C++
  * Interpreted language - compilation at run time
   - no separation in header files, source file, libraries, executables

## Scripting language?
  - Python **is not** a scripting language
  - it can be used easily to achieve goals addressed by scripting languages like Perl, Ruby, shell scripts

## What about object oriented programming?
  - Python is object oriented by construction
  - all entities are objects
    - even functions are objects!

## Pros and cons
  - Good
    - easy to use for first time programmers
    - simpler syntax than lower-level C and C++
      - no use of ; or }
      - logical structure of program only determined by indentation
    - easy to use as scripting language
    - can be used as a __glue__ between operating system (shell) and low-level language C/C++
    - can easily be extended by merging and using C/C++ libraries
    - extremely rich and numerous external packages (libraries) for many purposes

  - Bad
    - logical structure of program only determined by indentation
      - if you are a messy programmer, your code will not work
    - no compiler to assist you finding your mistakes
    - being an interpreted language, is less performant than compiled C++ code
      - not optimal for real-time applications, e.g. data acquisition at high rate
      - for example compare compiled application using ROOT libraries to interactive ROOT macros

## Powerful and popular features
  - dynamic typing
    - no need for type and size declaration
    - objects are tracked at run time by python
    - you will never see a type or size declaration
      - significantly different than C/C++
  - automatic memory management
    - no need for `new` and `delete`
  - Built-in object types
    - lists, dictionaries, strings, files are native objects of the language
  - powerful tools for file management and manipulation
    - achieve shell scripting inside a C++-style program
  - large collection of tools and libraries
    - both included by default or available online
  - easy to install and manage external packages with `pip` or `conda`
    - we will use `pip` in these Lectures
    - ubuntu virtual box also managed with `pip`

## What can it be used for
  - Largely used and considered one of the top 5 or top 10 programming languages world wide
  - widely used in web programming
    - used by Google in web search  systems
    - youtube largely written in python
  - Pixar uses python for animated movies
  - Civilization IV events written in python
  - Netflix uses python for software infrastructure
  - iRobot uses python for commercial and military robotic devices

## Python in science
  - widely used for data analysis and many packages for advanced machine learning techniques
    - we will learn to use `NumPy`, `pandas`, `matplotlib`, `scikit-learn`
  - ROOT now has a python interface to do analysis
    - I/O of TTree and other ROOT objects
  - python used as configuration language for all executables a large LHC experiments
    - processing of data, calibration, alignment, high-level analysis
      - application in C++
      - configuration with python
  - Nasa uses python for scientific programming

## Python versions

  - there are currently two major versions available
    - important differences but not so significant to break code that we will be writing
      - we will wrote python3 code that works also on python2
    - Python2
      - default version on macOS and older Linux distributions
    - Python3
      - fixes some legacy problems and short comings
      - installed on newer operating systems, e.g. ubuntu 18

    - You can check your version
      - macOS
      ```shell
      $ uname -a
      Darwin dot1x130.roma1.infn.it 17.7.0 Darwin Kernel Version 17.7.0: Wed Oct 10 23:06:14 PDT 2018; root:xnu-4570.71.13~1/RELEASE_X86_64 x86_64
      $ python --version
      Python 2.7.10
      $ python3 --version
      Python 3.7.0
      ```
      - ubuntu 18.04
        - no default `python` command
        - only `python3` can be used

## First program with python

Python has an interactive Interface. *Reminder: it is interpreted not compiled*
```python
$ python3
Python 3.7.0 (default, Oct  2 2018, 09:20:07)
[Clang 10.0.0 (clang-1000.11.45.2)] on darwin
Type "help", "copyright", "credits" or "license" for more information.
```python
>>> print ("Finally python")
Finally python
>>> a = 3.2
>>> b = 4.23
>>> c = 3
>>> x = a*(b/c)
>>> x
4.5120000000000005
>>> print (x)
4.5120000000000005
>>> print ("wow! " + "new life")
wow! new life
>>> print (a,b,c,x)
3.2 4.23 3 4.5120000000000005
>>> print ("a =  " + str(a) )
a =  3.2
>>> print('a = {0}, b = {1}, c = {2}'.format( a, b, c) )
a = 3.2, b = 4.23, c = 3
>>>
```
Note that ```>>>``` is the prompt for interactive use.
You can type any python command and see immediately the outcome.

To exit the interactive session you can type `quit()` or press `Ctrl-D`.

## Running a program

You can also write a program and run it without the interactive interface. We save the following lines in a file called [`example1.py`](examples/example1.py)
```python
# this is my first program
a = 2.3
b = 4.5
c = a/b
# plain print
print (a,b,c)

#plain print of more variables
print('c = a/b = ', c)

#print using ""
print("a = {0}, b = {1}, c = {2}".format( a, b, c) )

#print using ''
print('a = {0}, b = {1}, c = {2}'.format( a, b, c) )
```
You see that we can start a line with `#` to add comments

To run your program
```shell
$ python example1.py
(2.3, 4.5, 0.5111111111111111)
('c = a/b = ', 0.5111111111111111)
a = 2.3, b = 4.5, c = 0.511111111111
a = 2.3, b = 4.5, c = 0.511111111111
```
or

```shell
$ python3 example1.py
2.3 4.5 0.5111111111111111
c = a/b =  0.5111111111111111
a = 2.3, b = 4.5, c = 0.5111111111111111
a = 2.3, b = 4.5, c = 0.5111111111111111
```

Note how python2 and python3 produce different outputs for
```python
print('c = a/b = ', c)
```

# Interactive python with jupyter

In addition to writing standalone programs in python, and python modules and libraries, we will be using the [jupyter notebook](https://jupyter.org) for interactive python during lectures and for projects.

A simple introduction to jupyter notebook is available at [https://jupyter-notebook.readthedocs.io/en/stable/notebook.html](https://jupyter-notebook.readthedocs.io/en/stable/notebook.html).

## Installing jupyter
On ubuntu virtual box jupyter has been already installed.

For macOS or linux distributions follow the simple instructions at [https://jupyter.org/install.html](https://jupyter.org/install.html).

__NB:__ On macOS I __recommend__ installing with `pip` instead of `Anaconda`.

## first example with jupyter

In order to start jupyter, from the command line
```
jupyter notebook
```
Let's start with our first notebook [example2.ipynb](examples/example2.ipynb) .
You can view this notebook online with `github` by clicking on the link.

In order to interact with the notebook you must
  1. download the notebook file (ipynb)
  2. run `jupyter notebook example2.ipynb`

To download and run a jupyter notebook locally, follow these [instructions](../misc/DownloadNotebook.md).
