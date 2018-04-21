import unittest
import superscs
import numpy as np
from numpy import linalg as npla
from scipy import sparse


class BroydenTestCase(unittest.TestCase):

    def test_nothing(self):
	return

    def test_superscs_solved(self):    
	x_correct = np.array([0., 0., 1., 1.])   
	ij = np.array([[0, 1, 2, 3] ,[0, 1, 2, 3]])
	A = sparse.csc_matrix(([-1., -1., 1., 1.], ij), (4, 4))
	b = np.array([0., 0.,  1,  1])
	c = np.array([1., 1., -1, -1])
	cone = {'l': 4}
	data = {'A': A, 'b': b, 'c': c}
	tolerance = 1e-8
	sol = superscs.solve(\
		data, cone, do_super_scs = True, \
		direction = 100, \
		use_indirect = False, memory = 10, \
		verbose = 0, eps = tolerance)
	self.assertEquals('Solved',sol['info']['status'])
	self.assertEquals(1, sol['info']['statusVal'])
	self.assertTrue(sol['info']['resPri'] < tolerance)
	self.assertTrue(sol['info']['resDual'] < tolerance)
	self.assertTrue(npla.norm(x_correct - sol['x']) < 1e-12)



class AATestCase(unittest.TestCase):


    def test_superscs_aa(self):    
	x_correct = np.array([0., 0., 1., 1.])   
	ij = np.array([[0, 1, 2, 3] ,[0, 1, 2, 3]])
	A = sparse.csc_matrix(([-1., -1., 1., 1.], ij), (4, 4))
	b = np.array([0., 0.,  1,  1])
	c = np.array([1., 1., -1, -1])
	cone = {'l': 4}
	data = {'A': A, 'b': b, 'c': c}
	tolerance = 1e-8
	sol = superscs.solve(\
		data, cone, do_super_scs = True, \
		direction = 150, \
		use_indirect = False, memory = 3, \
		verbose = 0, eps = tolerance)
	self.assertEquals('Solved',sol['info']['status'])
	self.assertEquals(1, sol['info']['statusVal'])
	self.assertTrue(sol['info']['resPri'] < tolerance)
	self.assertTrue(sol['info']['resDual'] < tolerance)
	self.assertTrue(npla.norm(x_correct - sol['x']) < 1e-12)

if __name__ == '__main__':
    unittest.main()

