#!/usr/bin/env python2
import unittest


class TestNR3Python(unittest.TestCase):
    def test_example1(self):
        import example1
        self.assertAlmostEqual(example1.func(1.5), 0.4422205548)
        a, b, c = example1.gunc(1.2, 3.4, 5)
        self.assertAlmostEqual(a, 2.48832)
        self.assertAlmostEqual(b, 454.3542399999999)
        self.assertAlmostEqual(c, 4)
        self.assertAlmostEqual(example1.hunc(1., 2., 3., 4., 5., 6.), 21.0)


if __name__ == "__main__":
    unittest.main()
