genetic-algorithm
=================

Guessing string of bits basing on genetic algo definition and core steps

## Usage

To build:
`docker build -t vladfau/ga .`

To compile and run:
`docker run -it -v $(pwd)/src:/source -e TG=00011010001100111111 -e IP=64 -e UR=0.56 -e MR=0.0025 vladfau/ga`

Environment variables:

* `TG` - target genome to resolve (max length is in `MAX_GENOME` in `util.h`)
* `IP` - initial population: how many individuals to start with
* `UR` - uniform rate: chance to take father's or mother's gene
* `MR` - mutation rate: chance for random mutation

