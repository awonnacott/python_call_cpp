#!/usr/bin/env python2
import unittest
import example1
import example2
from numpy import array


class TestNR3Python(unittest.TestCase):
    def test_example1(self):
        self.assertAlmostEqual(example1.func(1.5), 0.4422205548)
        a, b, c = example1.gunc(1.2, 3.4, 5)
        self.assertAlmostEqual(a, 2.48832)
        self.assertAlmostEqual(b, 454.3542399999999)
        self.assertAlmostEqual(c, 4)
        self.assertAlmostEqual(example1.hunc(1., 2., 3., 4., 5., 6.), 21.0)

    def test_example2(self):
        arg1 = "inputstring"
        arg2 = array([1., 2., 3.])
        arg3 = array([[4., 5., 6.], [7., 8., 9.]])
        arg4 = array([[10, 11, 12, 13], [20, 21, 22, 23]])
        arg5 = [[[14], ["cat"], [[15], [16], [17]]], [["toy"], ["ball"]], [0.]]
        arg6 = {"somekey": 18.}
        u, v, w, x, y, z = example2.func(arg1, arg2, arg3, arg4, arg5, arg6)
        self.assertEqual(u, 3)
        self.assertEqual(v, 2)
        self.assertEqual(str(w), "[ 16. 16. 16. 16. 16. 16.]")
        self.assertEqual(str(x), "[[ 17. 17.]\n [ 17. 17.]\n [ 17. 17.]]")
        self.assertEqual(str(y), "[16.6, 'dog', None, None, None]")
        self.assertEqual(str(z), "{'A': 'one', 'C': 3.1416, 'B': 2}")

if __name__ == "__main__":
    unittest.main()
