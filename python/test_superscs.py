import unittest
import superscs
import numpy as np
from scipy import sparse


class TestStringMethods(unittest.TestCase):


    def test_nothing(self):
	a = 1

    def test_superscs(self):
        self.assertEqual('foo'.upper(), 'FOO')
	ij = np.array([[0,1,2,3],[0,1,2,3]])
	A = sparse.csc_matrix(([-1.,-1.,1.,1.], ij), (4,4))
	b = np.array([0.,0.,1,1])
	c = np.array([1.,1.,-1,-1])
	cone = {'l': 4}
	data = {'A': A, 'b':b, 'c':c}
	sol = superscs.solve(data, cone, use_indirect = False, memory = 50, verbose = 0)


if __name__ == '__main__':
    unittest.main()
