genetic-algorithm
=================

Guessing string of bits basing on genetic algo definition and core steps

## Usage

To build:
`docker build -t vladfau/ga .`

To compile and run:
`docker run -it -v $(pwd)/src:/source -e IP=64 -e CP=32 -e UR=0.56 -e MR=0.0025 vladfau/ga`

Environment variables:

* `IP` - initial population: how many individuals to start with
* `CP` - crossing (crossingover) point: where to swap genes
* `UR` - uniform rate: chance for reproduction
* `MR` - mutation rate: chance for random mutation

