SuperSCS
====

[![Codacy Badge](https://api.codacy.com/project/badge/Grade/ef4a850c3a3b445f8130452b0edce2c6)](https://www.codacy.com/app/alphaville/scs?utm_source=github.com&utm_medium=referral&utm_content=kul-forbes/scs&utm_campaign=badger)
[![Build Status](https://travis-ci.org/kul-forbes/scs.svg?branch=master)](https://travis-ci.org/kul-forbes/scs)
[![codecov](https://codecov.io/gh/kul-forbes/scs/branch/master/graph/badge.svg)](https://codecov.io/gh/kul-forbes/scs)
[![Gitter](https://badges.gitter.im/kul-forbes/scs.svg)](https://gitter.im/kul-forbes/scs?utm_source=badge&utm_medium=badge&utm_campaign=pr-badge)

<a href="https://kul-forbes.github.io/scs"><img src="https://maxcdn.icons8.com/Share/icon/dotty/User_Interface//user_manual1600.png" style="vertical-align:bottom;max-width:100%" width="25" alt="RTFM" title="Documentation"></a>

SuperSCS is is a fast and accurate solver for conic optimization problems, that is, problems of the form
```
minimize        c'x
subject to      Ax + s = b
                s in K
```
where `K` is a nonempty, closed, convex cone.

It can be accessed from **MATLAB** and **Python**, directly, or via **CVX/CVXPy**.

### Documentation

Detailed documentation can be found [**here**](https://kul-forbes.github.io/scs).

### Download

Download the [**current stable version**](https://github.com/kul-forbes/scs/archive/master.zip)

Check out the [**installation instructions**](https://kul-forbes.github.io/scs/page_installation.html)

### Cite SuperSCS
SuperSCS is based on the SuperMann algorithmic scheme; plese, cite as follows:

A. Themelis and P. Patrinos, "SuperMann: a superlinearly convergent algorithm for finding fixed points of nonexpansive operators," [arXiv:1609.06955](https://arxiv.org/abs/1609.06955), 2017.
