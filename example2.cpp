#include "nr3python.h"

static PyObject *func(PyObject *self, PyObject *pyargs) {
  NRpyArgs args(pyargs);                     // unpack args
  const char *mystring = NRpyCharP(args[0]); // first argument is a string
  VecDoub myvec(args[1]);                    // second argument is a Doub vector
  MatDoub mymat(args[2]);                    // third argument is a Doub matrix
  MatInt myimat(args[3]);                    // fourth argument is an Int matrix
  NRpyList mylist(args[4]);                  // fifth argument is a Python list
  NRpyDict mydict(args[5]);                  // sixth argument is a Python dict

  // string examples
  Int len = strlen(mystring);
  // mystring[2] = 'Z'; // Error: mystring is const (and must be!)
  char *newstring = new char[len + 1];
  strcpy(newstring, mystring); // ... whatever ...
  delete[] newstring;

  // vector and matrix examples
  Int v = myvec.size(); // get sizes in usual C++ way
  Int m = mymat.nrows(), n = mymat.ncols();
  myimat[0][1] = 7;            // changes a value both here and back in Python
  MatDoub copyofmymat = mymat; // copy values
  copyofmymat[1][0] = 3.;      // does not change a value back in Python

  // list examples
  Int lsize = mylist.size();     // size of top level of list
  Int llsize = mylist[0].size(); // size of next level at top level index 0
  PyObject_Print(mylist[0][2][2].p, stdout, 0);
  Int listval = NRpyInt(mylist[0][2][2]); // component must exist
  mylist[0][2].set(2, 55.); // modifies list[0][2][2] back in Python
  NRpyList mynewlist(5);    // length 5, available to Python only if returned
  mynewlist.set(0, 16.6);   // set component 0
  mynewlist.set(1, "dog");  // Doub, Int, and char* ok for list values

  // dict examples
  Doub dictval = NRpyDoub(mydict.get("somekey")); // value known to exist
  PyObject *testit = mydict.get("anotherkey");    // value may not exist
  Doub anotherval = (testit != Py_None ? NRpyDoub(testit) : 0.);
  mydict.set("thirdkey", 523.48);   // modifies dict back in Python
  mydict.set(54321, "stringvalue"); // Doub, Int, and char* ok on both args
  NRpyDict mynewdict; // new dict, available to Python only if returned
  mynewdict.set("A", "one");
  mynewdict.set("B", 2);
  mynewdict.set("C", 3.1416);
  Doub newdictval = NRpyInt(mynewdict.get("B")); // has value 2
  // create some additional local objects as return examples
  VecDoub vret(6, 16.);
  MatDoub mret(3, 2, 17.);
  // return lots of things, for example
  return NRpyTuple(NRpyObject(v), NRpyObject(m), NRpyObject(vret),
                   NRpyObject(mret), NRpyObject(mynewlist),
                   NRpyObject(mynewdict), NULL);
}
// standard boilerplate
static PyMethodDef example2_methods[] = {
    {"func", func, METH_VARARGS, "func() doc string"}, {NULL, NULL, 0, NULL}};
PyMODINIT_FUNC initexample2(void) {
  import_array();
  Py_InitModule("example2", example2_methods);
}
