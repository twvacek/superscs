/*! \mainpage SuperSCS Documentation
 *
 * \section intro_sec Installation
 * 
 * \subsection installation_in_c For use in C
 *
 * 
 * First, you need to [download SuperSCS](https://github.com/kul-forbes/scs/archive/master.zip)
 * from the [github repo](https://github.com/kul-forbes/scs) of SuperSCS, or use the 
 * command:
 * 
 *     git clone https://github.com/kul-forbes/scs.git
 * 
 * Installation runs as simple as 
 * 
 *     make
 *  
 * If you want to run the tests, do 
 *
 *     make run-test
 *
 * 
 * If, additionally, you want to run the tests and perform a memory check
 * using [valgrind](http://valgrind.org), do 
 * 
 *     make run-test-mem
 * 
 * 
 * For more advanced options, type in your terminal 
 * 
 *     make help
 * 
 * 
 * \subsection installation_in_matlab For use in MATLAB
 * 
 * In order to use SuperSCS from MATLAB, you need to compile a MEX interface.
 * 
 *     cd matlab
 *     make_scs; 
 *  
 * \section sec-documentation Documentation
 * 
 * 1. Installation:
 *   - \ref page_installation "Detailed installation instructions"
 * 2. Documentation:
 *   - \ref page_doc "Using SuperSCS"
 *      - \ref secc "in C"
 *      - \ref secmatlab "in MATLAB"
 *      - \ref seccvx "via CVX"
 *   - \ref page_tuning "SuperSCS tuning"
 *   - \ref page_warm_starting "Warm starting"
 *   - \ref page_logging "Logging"
 * 3. Examples:
 *   - \ref page_socp "Examples in C"
 *   - \ref page_benchmarks "Examples via CVX"
 * 4. Under the hood:
 *   - About the algorithm
 *   - \ref page_directions "Directions"
 * 
 * 
 * \subsection sec-github-page Source code
 * 
 * The source code of [SuperSCS](https://github.com/kul-forbes/scs) is available on [github](https://github.com/kul-forbes/scs).
 * 
 * This project was originally forked from [cvxgrp/scs](https://github.com/cvxgrp/scs).
 * 
 * \subsection sec-verification Verification
 * 
 * Quality assurance:
 * - [unit tests](https://github.com/kul-forbes/scs/tree/master/tests)
 * - [memory management tests](http://valgrind.org) using valgrind
 * - [continuous integration](https://travis-ci.org/kul-forbes/scs) on Travis CI
 * - [coverage reports](https://codecov.io/gh/kul-forbes/scs) on Codecov
 * - [code quality reports](https://www.codacy.com/app/alphaville/scs/dashboard) on codacy
 * - lcov report using <code>make cov</code>
 */

