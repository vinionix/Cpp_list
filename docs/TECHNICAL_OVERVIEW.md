# Technical Overview — C++ Modules

## Purpose

This repository collects the C++ modules from the 42 curriculum, from `cpp00` through `cpp09`. The sequence is useful as a progression map: it starts with basic classes and streams and finishes with templates, STL containers, data processing and algorithmic trade-offs.

## Progression

```text
Syntax / classes
      ↓
Memory / references / ownership
      ↓
Canonical form / operators
      ↓
Inheritance
      ↓
Polymorphism / abstract classes
      ↓
Exceptions / factories
      ↓
Casts / serialization
      ↓
Templates
      ↓
STL containers / iterators
      ↓
Data processing / algorithms
```

## Design themes

### Resource ownership

Several modules force explicit decisions about copying, assignment, destruction and deep versus shallow ownership. These exercises provide a foundation for reasoning about RAII and resource safety even when later code uses more modern C++ abstractions.

### Polymorphism

Inheritance exercises are valuable not because inheritance should be used everywhere, but because they expose virtual dispatch, base-class contracts, abstract interfaces and object lifetime concerns.

### Generic programming

Template modules move the design from concrete types toward reusable behavior. This is a different style of abstraction from inheritance and is important for understanding the STL.

### Containers and algorithms

The later modules require selecting containers based on access patterns and algorithmic needs rather than treating every data structure as interchangeable.

## Build model

Each exercise is intentionally isolated with its own `Makefile` and executable. There is no single root build because the modules are independent learning units.

## Validation approach

Useful review practices include:

- compile every exercise with the required flags;
- run the provided/manual test driver;
- inspect copy/assignment/destructor behavior;
- test invalid inputs and exception paths;
- use sanitizers or Valgrind where appropriate;
- compare behavior across different containers in algorithm-focused modules.

## Known repository note

The root README records a local compilation issue in `cpp06/ex02` related to catching `std::exception` by value under the project warning policy. This is useful documentation because it distinguishes repository presence from confirmed clean compilation.

## Portfolio value

Together, the modules show progression rather than one isolated C++ demo: object modelling, resource management, polymorphism, exceptions, generic programming and algorithm/data-structure choices.
