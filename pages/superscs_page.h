/*! \page page_superscs The SuperSCS Algorithm
 * 
 * \section superscs-problem-statement Problem Statement 
 * 
 * SCS and SuperSCS solve the following problem
 * 
 * \f{eqnarray*}{
 * &&\mathrm{Minimize}\ \langle c, x \rangle\\
 * &&Ax + s = b\\
 * &&s\in\mathcal{K},
 * \f}
 * 
 * where \f$x\in\mathbb{R}^n\f$, \f$s\in\mathbb{R}^,\f$ are the primal variables
 * and \f$\mathcal{K}\f$ is a nonempty, closed, convex cone.
 * 
 * The matrix \f$A\in\mathbb{R}^{m\times n}\f$ and the vector \f$b\in\mathbb{R}^m\f$
 * are the problem data.
 * 
 * The algorithm makes use of the homogeneous self-dual embedding which is the 
 * following problem
 * 
 * \f{eqnarray*}{
 * &&\mathrm{Find}\ (u,v)\\
 * &&u\in\mathcal{C}\\
 * &&Qu\in\mathcal{C}^*\\
 * &&\langle u, Qu \rangle = 0,
 * \f}
 * 
 * where \f$u=(x,y,\tau)\in\mathbb{R}^{n+m+1}\f$,
 * 
 * \f{eqnarray*}{
 * Q = \begin{bmatrix}
 * 0 & A^* & c\\
 * -A & 0 & b\\
 * -c^* & -b^* & 0
 * \end{bmatrix}
 * \f}
 * 
 * and \f$\mathcal{C} = \mathbb{R}^n\times \mathcal{K}^* \times \mathbb{R}_+\f$
 * is a cone.
 * 
 * Equivalently, the homogeneous self-dual embedding can be written as a variational
 * inequality:
 * 
 * \f{eqnarray*}{
 * 0 \in Qu + N_{\mathcal{C}}(u),
 * \f}
 * 
 * where \f$N_{\mathcal{C}}\f$ is the normal cone of \f$\mathcal{C}\f$.
 * 
 * 
 * \section superscs-algorithmic-solution Algorithmic Solution
 * 
 * The Douglas-Rachford splitting can be applied to the above variational problem.
 * 
 * This leads to the following iterative scheme:
 * 
 * \f{eqnarray*}{
 * &&\tilde{u}^{k+1} = (I+Q)^{-1}(u^k),\\
 * &&\bar{u}^{k+1} = \Pi_{\mathcal{C}}(2\tilde{u}^{k+1}-u^k),\\
 * &&u^{k+1} = u^k -\tilde{u}^{k+1} +  \bar{u}^{k+1},
 * \f}
 * 
 * which \f$\Pi_{\mathcal{C}}\f$ denotes the projection operator on \f$\mathcal{C}\f$.
 * 
 * This defines the Douglas-Rachford operator
 * 
 * \f{eqnarray*}{
 * T(u) &=& u - (I+Q)^{-1}(u) + \Pi_{\mathcal{C}}(2(I+Q)^{-1}(u)-u)\\
 *      &=& u -\tilde{u} + \bar{u}
 * \f}
 * 
 * This is a firmly nonexpansive operator on which we may apply the SuperMann
 * algorithmic scheme.
 */