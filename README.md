# QuadMesher
A high performance implement of Doc Chi-Han Peng's paper Exploring Quadrangulations.

# Resources
Here are some resources for you to fully understand the paper.
(you can also find these resources in the link of header description)

- [The paper itself](http://pengchihan.co/papers/explore/ExploringQuadrangulations%20main_paper.pdf)
- [The appendix](http://pengchihan.co/papers/explore/ExploringQuadrangulations%20additional_materials.pdf)
- [Video for explaination of algorithm](https://www.youtube.com/watch?v=9dvSntCIE60&feature=youtu.be)

# Ultimate target
Implement a stable reliable C++ lib for doing quadmesh of arbitrary 2D polygon with high performace.

# Why is quadmesh important?
This framework can be used in many industries, including architecture, CV.
For instance, say we have a 2D polygon of a block, iterating every possible position to put a building on is very
difficult since iterating in a continuous search space is nearly impossible. However, if we divide such polygon into
high quality quadmesh, iterating is now a trivial problem.

# How to contribute
For now, no special rules are set for its project, If you wanna contribute to this project, you can
1. fork the project.
2. fire pull request to us.

# Compiling
## Compiling Prerequisite
1. cmake(version > 3.14)
    - the executable in software repository of each linux distro might be outdated, install the lastest cmake [via](https://cmake.org/install/) 
2. gcc / clang / msvc
    - install one of them is enough
3. conan
    - download [conan](https://docs.conan.io/en/latest/introduction.html#) via pip: `pip install conan`
    - make a default profile: `conan profile new default --detect --force`

## How to compile
1. `mkdir build && cd build`
2. `conan install ..`
2. `cmake ..`
3. `make`
4. Find the lib file at `YOUR_PROJECT_DIR/build/src/libMeshGenerator.a`

## 3rd party lib
1. mesquite. One of the core components of our implement, mainly for optimizing quadmesh
2. pybind11, for wrapping a python module of the quadmesh library
3. pmp-library: consider as a must

## How to test
After compiling the whole program, you can find a tests executable file in `YOUR_PROJECT_DIR/build/test`.
Execute it for testing.

# Basic concept
## MeshGenerator
The entry class that takes a Polygon as input and output high quality quadmesh

## Division
A class for holding actual boundary coordinates. Have the ability to:
1. divide itself into 2 subdivisions
2. iterate through different versions of subdivisions
3. method that can tell whether itself is dividable

## DivisionClassifier
A class that takes a division and decide its type among:
- UNKNOWN
- IS_SIMPLE_TRIANGLE
- IS_SIMPLE_QUADRILATERAL
- IS_SIMPLE_PENTAGON
- IS_SIMPLE_CONCAVE
- IS_ABS_TVD_LT_1
- IS_POLYGON_WITHOUT_HOLES
- IS_POLYGON_WITH_HOLES

## DivisionEnumerator
The class that enumerate ways of dividing division, filter those could lead to duplicate quadmesh,
and rank the rest with clear criteria

## CaveFiller
The class that can "fill" a concave polygon to a convex polygon

## MeshSolver
The class that takes a simple triangle / quadrilateral / pentagon division and output the position of 
steiner point and the lengths of new created sides

## Mesher / TriMesher / QuadMesher / PentaMesher
The class that takes a specific division and return the quadmesh of it

## MeshOptimizer
The class that takes a mesh object and return the optimized version of it. Methods including:
- Laplace smooth
- Quasi-Newton

## MeshIO
The class that can do the input and output of mesh
