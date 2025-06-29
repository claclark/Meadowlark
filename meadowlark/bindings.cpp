#include "src/cottontail.h"
#include <pybind11/pybind11.h>

PYBIND11_MODULE(_meadowlark, m) {
  m.doc() = "Meadowlark test module"; // Optional module docstring
  m.def("stamp", &cottontail::stamp, pybind11::arg("label") = "",
        "Print a timestamp to stderr with an optional label");
}
