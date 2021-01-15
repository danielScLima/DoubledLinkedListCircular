Doubled Linked List Circular
====================
Building with AppVeyor: [![Build status](https://ci.appveyor.com/api/projects/status/w84paok27r65w4bw?svg=true)](https://ci.appveyor.com/project/DanielSLima/doubledlinkedlistcircular)

Building with Travis: [![Build Status](https://www.travis-ci.com/danielScLima/DoubledLinkedListCircular.svg?branch=master)](https://www.travis-ci.com/danielScLima/DoubledLinkedListCircular)

This repository has a project with the implementation of a Doubled Linked List Circular.

It is written in C++.

The code of the List is independent of platform.

Is has two possible main files:

* [Codes](#markdown-header)
	* [A main that triggers unit test;](#markdown-header-emphasis)

	* [A Qt project to manage the Doubled Linked List Circular (With Gui).](#markdown-header-strikethrough)
	
The library used to make the Unit Test is the Catch v2.12.3. The code is already in this repository.

The Qt project generates images of the Doubled Linked List Circular, using the lib Graphviz.
Install this lib in your computer for you to be able to create such images.

The code was written containing the Doxygen documentation.

- - -

You have several options to build the project: 
====================

* [Build tools](#markdown-header)
	* [Makefile (using the file named MakefileGeneral);](#markdown-header-emphasis)
	* [CMake.](#markdown-header-emphasis)
	* [Qt Project (With QMake).](#markdown-header-emphasis)

The project has no leaks (Fully tested with Valgrind).

All the unit tests are ok.

- - -

The main functionalities available are: 
====================

* [Functionalities](#markdown-header)
	* [Insert after start;](#markdown-header-emphasis)
	* [Insert before start;](#markdown-header-emphasis)	
	* [Remove after start;](#markdown-header-emphasis)	
	* [Remove before start;](#markdown-header-emphasis)
	
- - -

Sample image: 
====================

![Alt text](images/sample.png)


Qt gui project: 
====================
The qt gui application gui is shown below:

![Alt text](images/guisample.png)
