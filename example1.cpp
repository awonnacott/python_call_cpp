#include "nr3python.h"

static PyObject *func(PyObject *self, PyObject *pyargs) {
  NRpyArgs args(pyargs); // unpack args
  Doub x = NRpyDoub(args[0]);
  Doub y = (x != 0. ? SQR(sin(x) / x) : 1.);
  return NRpyObject(y); // return a single value
}

static PyObject *gunc(PyObject *self, PyObject *pyargs) {
  NRpyArgs args(pyargs); // unpack args
  Doub x1, x2, z1, z2;
  Int n, m;
  x1 = NRpyDoub(args[0]); // use args
  x2 = NRpyDoub(args[1]);
  n = NRpyInt(args[2]);
  z1 = pow(x1, n);
  z2 = pow(x2, n);
  m = Int(x1 + x2);
  return NRpyTuple( // more than one return must be a tuple
      NRpyObject(z1), NRpyObject(z2), NRpyObject(m),
      NULL // NRpyTuple *always* needs NULL as last arg
  );
}
static PyObject *hunc(PyObject *self, PyObject *pyargs) {
  NRpyArgs args(pyargs); // unpack args
  Doub sum = 0.;
  Int i, n = args.size();
  for (i = 0; i < n; i++) {
    sum += NRpyDoub(args[i]);
  }
  return NRpyObject(sum);
}
// standard boilerplate
static PyMethodDef example1_methods[] = { // note required name
    {"func", func, METH_VARARGS, "func() doc string"},
    {"gunc", gunc, METH_VARARGS, "gunc() doc string"},
    {"hunc", hunc, METH_VARARGS, "hunc() doc string"},
    {NULL, NULL, 0, NULL}};
PyMODINIT_FUNC initexample1(void) { // note required name
  import_array();
  Py_InitModule("example1", example1_methods);
}
