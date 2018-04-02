# Features

- Several benchmarks made available
- Parser for SIF/MPS/QPS files
- Anderson Acceleration implemented
- Implementation of SuperSCS using the same function template as SCS
- Implementation of restarted limited-memory Broyden directions
- Unit tests (90.9% coverage of scs.c, overall 80% coverage)
- [Online API documentation](https://kul-forbes.github.io/scs/index.html) using Doxygen with examples and benchmarks
- Support of printing to streams using stdio
- Modification of MEX interface that allows us to call SuperSCS from MATLAB
- Integration with CVX in MATLAB
- A lot more info can be exported to MATLAB regarding the progress of the algorithm
- Integration tools: codacy, Travis CI, codecov
- Memory management verification using valgrind
- Makefile with new functionality: run doxygen, generate coverage reports, run unit tests, test using valgrind
- Improvement of linear algebra routines using manual loop unrolling
- Gitter chat
