/*! \page page_cones Cones
 * 
 * \tableofcontents
 * 
 * \section cones-in-general Cones and inequalities
 * 
 * Pointed and salient <a href="https://en.wikipedia.org/wiki/Convex_cone">
 * convex cones</a> in \f$\mathbb{R}^n\f$ define a partial order therein. 
 * 
 * In particular, a pointed, salient, convex cone \f$\mathcal{K}\f$ induces a 
 * partial order \f$\preceq_{\mathcal{K}}\f$ such that 
 * \f$x \preceq_{\mathcal{K}} y\f$ if \f$y-x\in\mathcal{K}\f$.
 * 
 * What is important is that all common convex sets can be represented in terms
 * of conic inequalities using cones \f$\mathcal{K}\f$ on which projection is
 * numerically feasible.
 * 
 * Hereafter, we list the convex cones which are supported by SuperSCS.
 * 
 * 
 * \subsection cones-zero Zero cone
 * 
 * The zero cone is the set \f$\mathcal{K}^{\mathrm{f}}_{n_{\mathrm{f}}} = 
 * \{0_{n_{\mathrm{f}}}\}\f$.
 * 
 * This is used to encode equality constraints.
 * 
 * 
 * 
 *
 * \subsection cone-linear Linear cone
 * 
 * The linear cone is the positive orthant
 * \f$\mathcal{K}^{\mathrm{l}}_{n_{\mathrm{l}}} = 
 * \{x\in\mathbb{R}^{n_{\mathrm{l}}}: x_i \geq 0, \forall i\}\f$
 * 
 * 
 * 
 * 
 * \subsection cone-soc SO cone
 * 
 * This is the Cartesian product of \f$N_{\mathrm{so}}\f$ cones with 
 * dimensions \f$n_{\mathrm{so},1},\ldots, n_{\mathrm{so},N_{\mathrm{so}}}\f$
 * 
 * The cone is
 * 
 * \f{eqnarray*}{
 * \mathcal{K}^{\mathrm{so}}_{n_{\mathrm{so},1},\ldots, n_{\mathrm{so},N_{\mathrm{so}}}} = 
 *      \mathcal{K}^{\mathrm{so}}_{n_{\mathrm{so},1}} 
 *      \times 
 *      \cdots
 *      \times
 *      \mathcal{K}^{\mathrm{so}}_{n_{\mathrm{so}, N_{so}}},
 * \f}
 * 
 * where \f$\mathcal{K}^{\mathrm{so}}_{n}\f$ is the second-order cone of 
 * dimension \f$n\f$, that is
 * 
 * \f{eqnarray*}{
 * \mathcal{K}^{\mathrm{so}}_{n} = \{x = (y,t): y\in\mathbb{R}^{n-1}, t\in\mathbb{R}:
 * \|y\| \leq t\}
 * \f}
 * 
 * This array contains the dimensions \f$(n_{\mathrm{so},1},\ldots, n_{\mathrm{so},N_{\mathrm{so}}})\f$.
 * 
 * 
 * 
 * \subsection cones-psd PSD cone
 * Let us first give a few necessary definitions. Given a symmetric matrix 
 * \f$X\in\mathbb{R}^{k\times k}\f$ we define the vectorization operator as 
 * 
 * \f{eqnarray*}{
 * \mathrm{vec}(X) = \sqrt{2} \left(
 * \textstyle\frac{X_{11}}{\sqrt{2}}, X_{2,1},\ldots, X_{k,1}, 
 * \textstyle\frac{X_{22}}{\sqrt{2}}, X_{3,2}, \ldots, X_{k,2},
 * \ldots, \textstyle\frac{X_{kk}}{\sqrt{2}} \right).
 * \f}
 * 
 * We further define the inverse operation, \f$\mathrm{mat}\f$ which maps a vector
 * of \f$\mathbb{R}^{k(k+1)/2}\f$ to the matrix
 * 
 * \f{eqnarray*}{
 * \mathrm{mat}(x) = \textstyle\frac{1}{\sqrt{2}}
 * \begin{bmatrix}
 * \sqrt{2}x_1 & x_2 & \cdots & x_k\\
 * x_{2} & \sqrt{2}x_{k+1} & \cdots & x_{2k-1}\\
 * \vdots & \vdots & \ddots & \vdots\\
 * x_{k} & x_{2k-1} & \cdots & \sqrt{2}x_{k(k+1)/2}
 * \end{bmatrix}.
 * \f}
 * 
 * The above definitions preserve the inner product operations. In particular
 * 
 * \f{eqnarray*}{
 * \langle X,Y \rangle  = \mathrm{tr}(X'Y) = \mathrm{vec}(X)'\mathrm{vec}(Y) = 
 * \langle \mathrm{vec}(X),\mathrm{vec}(Y) \rangle,
 * \f}
 * 
 * and
 * 
 * \f{eqnarray*}{
 * \langle x,y \rangle  = \langle \mathrm{mat}(x),\mathrm{mat}(y) \rangle.
 * \f}
 * 
 * We define the positive definite cone as
 * 
 * \f{eqnarray*}{
 * \mathcal{K}^{\mathrm{psd}}_{k} = 
 * \{x\in\mathbb{R}^{k(k+1)/2} : \mathrm{mat}(x) \text{ is positive semidefinite}\}
 * \f}
 * 
 * Furthermore, define
 * 
 * \f{eqnarray*}{
 * \mathcal{K}^{\mathrm{psd}}_{k_1,\ldots, k_{N_{\mathrm{p}}}} = 
 * \prod_{i=1}^{N_{\mathrm{psd}}}\mathcal{K}^{\mathrm{psd}}_{k_i}.
 * \f}
 * 
 * 
 * 
 * \subsection cones-exponential Exponential cone
 * 
 * Consider the following set in \f$\mathbb{R}^3\f$
 * \f{eqnarray*}{
 * \mathcal{K}^{\mathrm{e}} = \{(x,y,z)\in\mathbb{R}^3: y e^{x/y} \leq z, y>0\}.
 * \f}
 * 
 * The exponential cone is the closure of \f$\mathcal{K}^{\mathrm{e}}\f$
 * \f{eqnarray*}{
 * \mathcal{K}^{\mathrm{exp}} = \mathrm{cl}\mathcal{K}^{\mathrm{e}}.
 * \f}
 * 
 * Define the Cartesian product of \f$n_{\mathrm{exp}}\f$ such cones
 * 
 * \f{eqnarray*}{
 * \mathcal{K}^{\mathrm{exp}}_{n_{\mathrm{exp}}} = 
 * \prod_{i=1}^{n_{\mathrm{exp}}}\mathcal{K}^{\mathrm{exp}}.
 * \f}
 * 
 * 
 * 
 * \subsection cones-dual-exponential Dual exponential cone
 * 
 * The dual exponential cone is the set
 * 
 * \f{eqnarray*}{
 * \mathcal{K}^{\mathrm{dexp}} = 
 * \left\{
 * (u,v,w)\in\mathbb{R}^3: u\leq 0, w \geq 0, -u 
 *   \log(-\textstyle\frac{u}{w})+u-v\leq 0
 * \right\},
 * \f}
 * 
 * with \f$0 \log(0/w)=0\f$ for all \f$w\geq 0\f$.
 * 
 * We define
 * 
 * \f{eqnarray*}{
 * \mathcal{K}^{\mathrm{dexp}}_{n_{\mathrm{dexp}}} = 
 * \prod_{i=1}^{n_{\mathrm{dexp}}}\mathcal{K}^{\mathrm{dexp}}.
 * \f}
 * 
 * 
 * 
 * 
 * \subsection cones-power Power cone
 * 
 * 
 * \subsection cones-cartesian-product General cones
 * 
 * In SuperSCS, cones are described by the general form
 * 
 * \f{eqnarray*}{
 * \mathcal{K} = \mathcal{K}^{\mathrm{f}}_{n_{\mathrm{f}}} 
 *                  \times 
 *               \mathcal{K}^{\mathrm{l}}_{n_{\mathrm{l}}}
 *                  \times
 *               \mathcal{K}^{\mathrm{so}}_{n_{\mathrm{so}_1},\ldots, n_{\mathrm{so},N_{\mathrm{so}}}}
 *                  \times
 *               \mathcal{K}^{\mathrm{psd}}_{k_{1},\ldots, k_{N_{\mathrm{p}}}}
 *                  \times
 *              \mathcal{K}^{\mathrm{exp}}_{n_{\mathrm{exp}}}
 *                  \times
 *              \mathcal{K}^{\mathrm{dexp}}_{n_{\mathrm{dexp}}}
 * \f}
 * 
 * 
 * 
 * \section cones-matlab MATLAB
 * 
 * \section cones-c C
 */