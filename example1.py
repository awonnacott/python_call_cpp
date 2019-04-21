#!/usr/bin/env python2

import example1

if __name__ == "__main__":
    print(example1.func(1.5))
    a, b, c = example1.gunc(1.2, 3.4, 5)
    print([a, b, c])
    print(example1.hunc(1., 2., 3., 4., 5., 6.))
