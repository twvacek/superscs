/*
 * The MIT License (MIT)
 *
 * Copyright (c) 2017 Pantelis Sopasakis (https://alphaville.github.io),
 *                    Krina Menounou (https://www.linkedin.com/in/krinamenounou), 
 *                    Panagiotis Patrinos (http://homes.esat.kuleuven.be/~ppatrino)
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 * 
 */
/*! \page page_superscs The SuperSCS Algorithm
 * 
 * \section superscs-problem-statement Conic Optimization and HSDE
 * 
 * SCS and SuperSCS solve the following problem
 * 
 * \f{eqnarray*}{
 * &&\mathrm{Minimize}\ \langle c, x \rangle\\
 * &&Ax + s = b\\
 * &&s\in\mathcal{K},
 * \f}
 * 
 * where \f$x\in\mathbb{R}^n\f$, \f$s\in\mathbb{R}^m\f$ are the primal variables
 * and \f$\mathcal{K}\subseteq\mathbb{R}^m\f$ is a nonempty, closed, convex cone.
 * 
 * The matrix \f$A\in\mathbb{R}^{m\times n}\f$ and the vector \f$b\in\mathbb{R}^m\f$
 * are the problem data.
 * 
 * The algorithm makes use of the [homogeneous self-dual embedding]
 * (https://mathematix.wordpress.com/2017/06/05/cone-programs-and-self-dual-embeddings/) 
 * (HSDE) which is the problem of finding a \f$u=(x,y,\tau)\in\mathbb{R}^{n+m+1}\f$ so that
 * 
 * \f{eqnarray*}{
 * &&u\in\mathcal{C}\\
 * &&Qu\in\mathcal{C}^*\\
 * &&\langle u, Qu \rangle = 0,
 * \f}
 * 
 * where 
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
 * Equivalently, the HSDE can be written as a variational inequality:
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
 * \subsection superscs-sec-peaceman-rachford Peaceman-Rachford for HSDE
 * 
 * The Douglas-Rachford splitting can be applied to the above variational problem.
 * 
 * The Douglas-Rachford method is the Krasnosel'skii method applied to the 
 * Peaceman-Rachford operator.
 * 
 * The Peaceman-Rachford method is described by
 * 
 * \f{eqnarray*}{
 * &&\tilde{u}^{k+1} = (I+Q)^{-1}(u^k),\\
 * &&\bar{u}^{k+1} = \Pi_{\mathcal{C}}(2\tilde{u}^{k+1}-u^k),\\
 * &&u^{k+1} = u^k -\tilde{u}^{k+1} +  \bar{u}^{k+1},
 * \f}
 * 
 * which \f$\Pi_{\mathcal{C}}\f$ denotes the <a href="https://en.wikipedia.org/wiki/Projection_(linear_algebra)">
 * projection operator</a> on \f$\mathcal{C}\f$.
 * 
 * This defines the Peaceman-Rachford operator
 * 
 * \f{eqnarray*}{
 * T(u) &=& u - (I+Q)^{-1}(u) + \Pi_{\mathcal{C}}(2(I+Q)^{-1}(u)-u)\\
 *      &=& u -\tilde{u} + \bar{u}
 * \f}
 *
 * In lack of additional assumptions, the Peaceman-Rachford operator is merely 
 * nonexpansive, therefore, convergence is not guaranteed.
 * 
 * This is remedied by applying the Krasnosel'skii-Mann method on \f$T\f$ leading
 * to the Douglas-Rachford splitting which updates \f$u\f$ as follows:
 * 
 * \f{eqnarray*}{
 *  u^{\nu+1} = T_\lambda(u^\nu) = \lambda T(u^\nu) + (1-\lambda) u^\nu.
 * \f}
 * 
 * Operator \f$T_\lambda\f$ is firmly nonexpansive and the Douglas-Rachford method
 * is such that \f$\{u^\nu\}_\nu\f$ is a Fejérian sequence, it is bounded and converges
 * to a fixed point of \f$T\f$.
 * 
 * 
 * Neverheless, the Douglas-Rachford splitting exhibit often slow convergence, 
 * achieves low to medium accuracy only and is sensitive to problem scaling.
 *  
 * Operator \f$T\f$ is a nonexpansive operator on which we may apply the <b>SuperMann</b>
 * algorithmic scheme.
 * 
 * \subsection superscs-sec-supermann-scheme SuperMann
 * 
 * This section is under construction...
 * 
 * <img src="images/strip.gif" width="70%" alt="Generalized KM steps (SuperMann)"/>
 * 
 * The SuperMann scheme aims at finding a zero of the fixed-point residual operator
 * defined as \f$R = I - T\f$, where \f$I\f$ is the identity operator.
 * 
 * For details on SuperMann, the reader is referred to 
 * [our arXiv paper](https://arxiv.org/abs/1609.06955).
 */