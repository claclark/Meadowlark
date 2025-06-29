#include "src/warren.h"
#include <pybind11/pybind11.h>

namespace py = pybind11;

PYBIND11_MODULE(_meadowlark, m) {
  py::class_<cottontail::Warren, std::shared_ptr<cottontail::Warren>>(m,
                                                                      "Meadow")
      .def_static("open",
                  [](const std::string &burrow) {
                    std::string error;
                    auto warren = cottontail::Warren::make(burrow, &error);
                    if (!warren)
                      throw std::runtime_error(error);
                    return warren;
                  })
      .def("start", &cottontail::Warren::start)
      .def("end", &cottontail::Warren::end)
      .def("name", &cottontail::Warren::name)
      .def("recipe", &cottontail::Warren::recipe)
      .def("__enter__",
           [](std::shared_ptr<cottontail::Warren> self) {
             self->start();
             return self;
           })
      .def("__exit__", [](std::shared_ptr<cottontail::Warren> self, py::handle,
                          py::handle, py::handle) { self->end(); });
}
