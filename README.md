# QuadMesher
A high performance implement of Doc Chi-Han Peng's paper Exploring Quadrangulations.

# Resources
Here are some resources for you to fully understand the paper.
(you can also find these resources in the link of header description)

- [The paper itself](http://pengchihan.co/papers/explore/ExploringQuadrangulations%20main_paper.pdf)
- [The appendix](http://pengchihan.co/papers/explore/ExploringQuadrangulations%20additional_materials.pdf)
- [Video for explaination of algorithm](https://www.youtube.com/watch?v=9dvSntCIE60&feature=youtu.be)

# Ultimate target
Implement a stable reliable C++ lib for generating quad-mesh of arbitrary 2D polygon with high performance.

# Why is quadmesh important?
This framework can be used in many industries, including architecture, CV.
Say we have a 2D polygon of a block, iterating every possible position to put a building on is very
difficult since iterating in a continuous search space is nearly impossible. However, if we divide such polygon into
high quality quadmesh, iterating is now a trivial problem.

# Compiling
## Prerequisite
1. latest cmake(version > 3.14)
    - the executable in software repository of each linux distro might be outdated, install the lastest cmake [via](https://cmake.org/install/) 
2. gcc / clang / msvc(untested)
3. conan(>=1.24)
    - download [conan](https://docs.conan.io/en/latest/introduction.html#) via pip: `pip install conan`
    - make a default profile: `conan profile new default --detect --force`

## How to compile
1. `mkdir build && cd build`
2. `conan install ..` to install several dependencies via conan
2. `cmake ..` or `ccmake ..` if you prefer interactive process
3. `make` or `make [target]`, add `-j` for multi-thread compiling

## 3rd party lib
1. [pmp-library](https://github.com/pmp-library/pmp-library): an excellent lib for polygon meshing, install via cmake
2. [boost-geometry](https://github.com/boostorg/geometry): geometry related lib, component of boost, install via conan
3. [catch2](https://github.com/catchorg/Catch2): a head-only modern test framework, install via conan

## How to test
After compiling the project, find tests executable in build/bin and run

# Design
## Model
- Coordinate: hold the 2D or 3D coordinate
- Division: hold the coordinates of exterior and interiors
- DivisionIterable: for iterating different sub-divisions splitted from a Division
- DividingEvaluator: for scoring the dividing in order for DivisionIterable to return good dividing first
- Tree: template class for making a tree data structure
- DivisionTypeChecker: to get the type of division
- Mesher: TriMesher / QuadMesher / PentaMesher for generating SurfaceMesh obj from Division


# Contribution Notices
1. use google style, for clion user check [this](https://blog.jetbrains.com/clion/2015/07/new-clion-1-1-eap-select-and-use-your-favourite-code-style/) out
