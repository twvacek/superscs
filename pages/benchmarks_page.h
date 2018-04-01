/*! \page page_benchmark_results Benchmarks
 * 
 * \tableofcontents
 * 
 * \section benchmarks-dolan-more Dolan-Moré performance profiles
 * 
 * In order to compare different solvers, we employ the [Dolan-Moré performance 
 * profile plot](https://pdfs.semanticscholar.org/54a2/0dbd409436be4f188dfa9a78949a1cac230d.pdf).
 * 
 * Let us briefly introduce the Dolan-Moré performance profile plot. 
 * 
 * Let \f$P\f$ be a finite set of problems used as benchmarks and \f$S\f$ be a 
 * set of solvers we want to compare to one another.
 * 
 * Let \f$t_{p,s}\f$ be the computing cost (e.g., time of flops) to solve a problem 
 * \f$p\f$ using a solver \f$s\f$.
 * 
 * We define the ration between \f$t_{p,s}\f$ and the lowest observed cost to solve
 * this problem using some solver \f$s\in S\f$:
 * 
 * \f{eqnarray*}{
 * r_{p,s} = \frac{t_{p,s}}{\min_{s \in S} t_{p,s}}.
 * \f}
 * 
 * If a solver \f$s\f$ does not solve a problem \f$p\f$, then we assign to \f$r_{p,s}\f$
 * a very high value \f$r_M > r_{p,s}\f$ for all other \f$p,s\f$.
 * 
 * The cumulative distribution of the performance ratio is the Dolan-Moré performance 
 * profile plot.
 * 
 * In particular, define
 * 
 * \f{eqnarray*}{
 * \rho_s(\tau) = \frac{1}{n_p}\#\{p\in P: r_{p,s}\leq \tau\},
 * \f}
 * 
 * for \f$\tau\geq 1\f$ and where \f$n_p\f$ is the number of problems.
 * 
 * The Dolan-Moré performance profile is the plot of \f$\rho_s\f$ vs \f$\tau\f$,
 * typically on a logarithmic x-axis.
 *
 * \section benchmark-results Benchmark results 
 * 
 * \subsection benchmarks-lasso LASSO problems 
 * 
 * [1152 lasso problems](https://github.com/kul-forbes/scs/blob/master/tests/profiling_matlab/profile_runners/profile_runner_lasso.m)
 * 
 *
 * <div>
 * <table border="0">
 *  <tr>
 *      <td style="padding:1px">
 *          <img src="images/lasso/lasso-broyden-50.png" alt="lasso-broyden-50" width="95%"/>
 *      </td>
 *      <td style="padding:1px">
 *          <img src="images/lasso/lasso-broyden-100.png" alt="lasso-broyden-100" width="95%"/>
 *      </td>
 *      <td style="padding:1px">
 *          <img src="images/lasso/lasso-anderson-10-15.png" alt="lasso-anderson-10-15" width="95%"/>
 *      </td>
 *  </tr>
 * </table>
 * </div>
 * 
 *  
 * \subsection benchmarks-pca1 Regularized PCA
 * 
 * [288 regularized PCA problems](https://github.com/kul-forbes/scs/blob/master/tests/profiling_matlab/profile_runners/profile_runner_pca.m)
 * 
 * <div>
 * <table border="0">
 *  <tr>
 *      <td style="padding:1px">
 *          <img src="images/pca/pca-broyden-100.png" alt="pca-broyden-100" width="93%"/>
 *      </td>
 *      <td style="padding:1px">
 *          <img src="images/pca/pca-anderson-15.png" alt="pca-anderson-15" width="100%"/>
 *      </td>
 *      <td style="padding:1px">
 *          <img src="images/pca/pca-anderson-20.png" alt="pca-anderson-20" width="93%"/>
 *      </td>
 *  </tr>
 * </table>
 * </div>
 * 
 *  
 * \subsection benchmarks-logreg Logistic regression problems
 * 
 * [288 logistic regression problems](https://github.com/kul-forbes/scs/blob/master/tests/profiling_matlab/profile_runners/profile_runner_logreg.m)
 * 
 * <div>
 * <table border="0">
 *  <tr>
 *      <td style="padding:1px">
 *          <img src="images/logreg/logreg-broyden-50-100.png" alt="logreg-broyden-50-100" width="95%"/>
 *      </td>
 *      <td style="padding:1px">
 *          <img src="images/logreg/logreg-anderson-5.png" alt="logreg-anderson-5" width="95%"/>
 *      </td>
 *      <td style="padding:1px">
 *          <img src="images/logreg/logreg-anderson-10.png" alt="logreg-anderson-10" width="95%"/>
 *      </td>
 *  </tr>
 * </table>
 * </div>
 * 
 * \subsection benchmarks-sdp2 SDP Problems
 * 
 * [36 logistic regression problems](https://github.com/kul-forbes/scs/blob/master/tests/profiling_matlab/profile_runners/profile_runner_sdp2.m)
 * 
 * <div>
 * <table border="0">
 *  <tr>
 *      <td style="padding:1px">
 *          <img src="images/sdp2/sdp2-broyden-50.png" alt="sdp-broyden-50" width="95%"/>
 *      </td>
 *      <td style="padding:1px">
 *          <img src="images/sdp2/sdp2-anderson-10.png" alt="sdp2-anderson-10" width="95%"/>
 *      </td>
 *      <td style="padding:1px">
 *          <img src="images/sdp2/sdp2-anderson-15.png" alt="sdp2-anderson-15" width="90%"/>
 *      </td>
 *  </tr>
 * </table>
 * </div>
 */