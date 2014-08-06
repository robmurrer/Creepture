Creepture
=========

Virtual Caterpillar-like Robot that Achieves Locomotion Automatically through Evolutionary Computation

![animation](docs/images/8segment-fullga-500gen.gif?raw=true)

A conference style paper describing this system can be found in  [PDF](https://github.com/robmurrer/Creepture/blob/master/docs/conf/report.pdf?raw=true) format.

## Excerpts from Paper
### Abstract

This paper presents an Evolutionary Computation approach to
automatically realize locomotion with a modular virtual caterpillar-like
robot called Creepture. Without any prior intelligence besides the
number of modules available, a Genetic Algorithm (GA) optimizes a
network of Central Pattern Generators that are connected to each joint
in the Creepture. This was accomplished through a simulation layer in
the fitness function of the GA. Successful locomotion in a desired
direction was realized for Creeptures with up to 4 modules.

### Introduction

Locomotion is an essential behavior of most organisms. How the
locomotive patterns are acquired for efficient movement can be thought
of intuitively as a trial-and-error feedback loop. A child learning to
crawl will attempt many times and fail before they are able to move in a
desired manner. Because this process can be thought of as an
optimization, Evolutionary Computation (EC) and specifically Genetic
Algorithms (GAs) have been used to create automatic locomotion
<span>[</span>1<span>]</span> <span>[</span>2<span>]</span>.

Through a network of Central Pattern Generators (CPGs), a locomotive
pattern is created. These CPGs create non-linear oscillations that
excite or inhibit muscle movement. The network of CPGs work in concert
to create complex movement such as locomotion. The parameters of a CPG
network increase exponentially as the network increases. Because the
number of parameters can be so large, creating desired movements is
increasing difficult as the number of modules increase.

The EC approach using a GA to optimize the CPG network was used to
achieve semi-realistic caterpillar-like movement. A simulation layer was
created using the *Box2D* physics engine and was used in the fitness
function within the GA. The segments of the Creepture are similar to the
*M-TRAN* modules created by Kimura et al <span>[</span>1<span>]</span>.
These segments are fused together and locomotion was realized on
Creeptures up to 4 segments.

## Installing and Running

*This is very rough and I am sure there are some dependencies and steps I have missed.  If you do try and fail, feel free to message me on twitter [@robmurrer](https://twitter.com/robmurrer) or raise an issue here and I will do my best to step you through the process.*

### Requirements

* Linux or Mac OS X
* [cmake](http://www.cmake.org/)
* [XQuartz (Mac OS X only)](http://xquartz.macosforge.org/landing/)
* [Gnuplot](http://www.gnuplot.info/)

### Steps

1. Download and unpack sources
2. From a terminal program `cd` into the project directoy's `src`.
4. If desired, edit main.cpp to modify the parameters of the system.
3. Run the `make` command.
4. The GA will then run. With default settings it will take about 30 minutes.
5. When GA is complete a graph and testbed will be launched (on OS X)

note: For Linux users you must change the `open` command with `xdg-open` in order for the graph to display

