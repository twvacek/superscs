'''
The MIT License (MIT)

Copyright (c) 2017 Pantelis Sopasakis (https://alphaville.github.io),
                   Krina Menounou (https://www.linkedin.com/in/krinamenounou), 
                   Panagiotis Patrinos (http://homes.esat.kuleuven.be/~ppatrino)

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
'''
#!/usr/bin/env python
from warnings import warn
from scipy import sparse
import _superscs_indirect

__version__ = _superscs_indirect.version()
__sizeof_int__ = _scs_direct.sizeof_int()
__sizeof_float__ = _scs_direct.sizeof_float()

_USE_INDIRECT_DEFAULT = False

def solve(probdata, cone, **kwargs):
    """
    solves convex cone problems
     
    @return dictionary with solution with keys:
         'x' - primal solution
         's' - primal slack solution
         'y' - dual solution
         'info' - information dictionary
    """
    if not probdata or not cone:
        raise TypeError("Missing data or cone information")

    if not 'b' in probdata or not 'c' in probdata:
        raise TypeError("Missing one or more of b, c from data dictionary")
    b = probdata['b']
    c = probdata['c']

    m = len(b)
    n = len(c)

    warm = {}
    if 'x' in probdata:
        warm['x'] = probdata['x']
    if 'y' in probdata:
        warm['y'] = probdata['y']
    if 's' in probdata:
        warm['s'] = probdata['s']

    if b is None or c is None:
        raise TypeError("Incomplete data specification")
    linsys_cbs = kwargs.get('linsys_cbs', None)
    if linsys_cbs:
        # Create an empty placeholder A matrix that is never used.
        A = sparse.csc_matrix((m,n))
    else:
    if 'A' not in probdata:
        raise TypeError('Missing A from data dictionary')
    A = probdata['A']

    if not sparse.issparse(A):
        raise TypeError("A is required to be a sparse matrix")
    if not sparse.isspmatrix_csc(A):
        warn("Converting A to a CSC (compressed sparse column) matrix; may take a while.")
        A = A.tocsc()

    if sparse.issparse(b):
        b = b.todense()

    if sparse.issparse(c):
        c = c.todense()

    Adata, Aindices, Acolptr = A.data, A.indices, A.indptr
    if kwargs.pop('gpu', False): # False by default
        if not kwargs.pop('use_indirect', _USE_INDIRECT_DEFAULT):
            raise NotImplementedError('GPU direct solver not yet available, pass `use_indirect=True`.')
        import _superscs_gpu
        return _superscs_gpu.csolve((m, n), Adata, Aindices, Acolptr, b, c, cone, warm, **kwargs)

    if not kwargs.pop('use_indirect', _USE_INDIRECT_DEFAULT): # True by default
        import _superscs_direct
        return _superscs_direct.csolve((m, n), Adata, Aindices, Acolptr, b, c, cone, warm, **kwargs)
    if linsys_cbs:
        import _scs_python
        return _scs_python.csolve(
            (m, n), Adata, Aindices, Acolptr, b, c, cone,
            warm, **kwargs)

    return _superscs_direct.csolve((m, n), Adata, Aindices, Acolptr, b, c, cone, warm, **kwargs)
