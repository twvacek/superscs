/*! \mainpage SuperSCS: Fast & Accurate conic programming
 *
 * \section sec-about About SuperSCS
 * 
 * SuperSCS is a fast solver for conic problems of the form
 * 
 * \f{eqnarray*}{
 * &&\mathrm{Minimize}\ c' x \\
 * &&Ax + s = b\\
 * &&s\in\mathcal{K},
 * \f}
 *
 * where \f$A\in\mathbb{R}^{m\times n}\f$ is a \ref page_sparse_matrices 
 * "(sparse) matrix", and \f$\mathcal{K}\f$ is a closed, convex, proper 
 * \ref page_cones "cone".
 * 
 * \f$\mathcal{K}\f$ can be the Cartesian product of the 
 * \ref cones-zero "zero cone", 
 * the \ref cone-linear "positive orthant", 
 * the \ref cone-soc "second-order cone", 
 * the \ref cones-psd "positive semidefinite cone" and 
 * \ref page_cones "many other".
 * 
 * SuperSCS is based on the algorithmic scheme SuperMann applied to a 
 * \ref page_superscs "Douglas-Rachford splitting" on the self-dual homogeneous 
 * embedding of the original problem.
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
 *   - \ref page_cones "Cones"
 *   - \ref page_doc "Using SuperSCS"
 *      - \ref secc "in C"
 *      - \ref secmatlab "in MATLAB"
 *      - \ref secpython "in Python"
 *      - \ref seccvxmatlab "via CVX (MATLAB)"
 *      - \ref seccvxpython "via CVX (Python)"
 *   - \ref page_save_load "Saving/Loading Problems (YAML)"
 *   - \ref page_warm_starting "Warm starting"
 *   - \ref page_logging "Logging"
 * 3. Performance:
 *   - \ref page_benchmark_results "Benchmarks"
 *   - \ref page_profiling "Profiling"
 * 4. Examples:
 *   - \ref page_socp "Examples in C"
 *   - \ref page_cvx_examples "Examples via CVX"
 * 5. Under the hood:
 *   - \ref page_superscs "About the algorithm"
 *   - \ref page_directions "Directions"
 *   - \ref #scs_set_default_settings "Default Settings"
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
 * - lcov report using <code>make cov COV=1</code>
 * 
 * 
 * \subsection sec-contributing-to-superscs Contributing
 * 
 * SuperSCS is an open-source project to which you may contribute.
 * 
 * Before contributing or filing an \ref sec_git_issues "issue", please read 
 * \ref page_contributing "this guide".
 * 
 * \subsection sec-license License
 * 
 * SuperSCS is licensed with an 
 * <a href="https://github.com/kul-forbes/scs/blob/master/LICENSE.txt">MIT license</a>.
 * 
 * The MIT license is a short and simple permissive license with conditions 
 * only requiring preservation of copyright and license notices. 
 * 
 * Licensed works, modifications, and larger works may be distributed under different 
 * terms and without source code.
 * 
 * You only need to keep 
 * <a href="https://github.com/kul-forbes/scs/blob/master/LICENSE.txt">LICENSE.txt</a>
 * and, if you redistribute the source code, the copyright notices therein.
 * 
 * \subsection cite-superscs Cite SuperSCS
 * 
 * SuperSCS is based on the algorithmic scheme presented in:
 * 
 * A. Themelis and P. Patrinos, <em>SuperMann: a superlinearly convergent algorithm for 
 * finding fixed points of nonexpansive operators</em>, 
 * <a href="https://arxiv.org/abs/1609.06955">arXiv:1609.06955</a>, 2017.
 * 
 */

