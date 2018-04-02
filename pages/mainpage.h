/*! \mainpage SuperSCS: Fast & Accurate conic programming
 *
 * \section sec-about About SuperSCS
 * 
 * SuperSCS is a fast solver for conic problems of the form
 * 
 * \f{eqnarray*}{
 * &&\mathrm{Minimize}\ \langle c, x \rangle\\
 * &&Ax + s = b\\
 * &&s\in\mathcal{K},
 * \f}
 *
 * where \f$A\in\mathbb{R}^{m\times n}\f$ is a (sparse) matrix, and 
 * \f$\mathcal{K}\f$ is a closed, convex, proper cone.
 * 
 * \f$\mathcal{K}\f$ can be the Cartesian product of the zero cone, the positive
 * orthant, the second-order cone, the positive semidefinite cone and many other.
 * 
 * SuperSCS is based on the algorithmic scheme SuperMann applied to a Douglas-Rachford
 * splitting on the self-dual homogeneous embedding of the original problem.
 * 
 * SuperSCS achieves higher accuracy and faster convergence compared to SCS as 
 * you can see for example in the \ref page_cvx_examples "CVX examples page".
 * 
 * 
 * \section sec-documentation Documentation
 * 
 * 1. Installation:
 *   - \ref page_installation "Detailed installation instructions"
 * 2. Documentation:
 *   - \ref page_doc "Using SuperSCS"
 *      - \ref secc "in C"
 *      - \ref secmatlab "in MATLAB"
 *      - \ref secpython "in Python"
 *      - \ref seccvxmatlab "via CVX (MATLAB)"
 *      - \ref seccvxpython "via CVX (Python)"
 *   - \ref page_benchmark_results "Benchmarks"
 *   - \ref page_warm_starting "Warm starting"
 *   - \ref page_logging "Logging"
 * 3. Examples:
 *   - \ref page_socp "Examples in C"
 *   - \ref page_cvx_examples "Examples via CVX"
 * 4. Under the hood:
 *   - \ref page_superscs "About the algorithm"
 *   - \ref page_directions "Directions"
 *   - \ref #setDefaultSettings "Default Settings"
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
 * - [unit tests](https://github.com/kul-forbes/scs/tree/master/tests) (<code>make run-test</code>)
 * - [memory management tests](http://valgrind.org) using valgrind
 * - [continuous integration](https://travis-ci.org/kul-forbes/scs) on Travis CI
 * - [coverage reports](https://codecov.io/gh/kul-forbes/scs) on Codecov
 * - [code quality reports](https://www.codacy.com/app/alphaville/scs/dashboard) on codacy
 * - lcov report using <code>make cov</code>
 * 
 * 
 * \subsection cite-superscs Cite SuperSCS
 * 
 * SuperSCS is based on the algorithmic scheme presented in:
 * 
 * A. Themelis and P. Patrinos, <em>SuperMann: a superlinearly convergent algorithm for 
 * finding fixed points of nonexpansive operators</em>, arXiv:1609.06955, 2017.
 */

