#include "src/warren.h"
#include <pybind11/pybind11.h>

namespace {
struct HopperIter {
  cottontail::Hopper *hopper;
  cottontail::addr k = cottontail::minfinity + 1;

  HopperIter(cottontail::Hopper *h) : hopper(h) {}

  pybind11::object next() {
    cottontail::addr p, q;
    cottontail::fval v;
    hopper->tau(k, &p, &q, &v);
    if (p >= cottontail::maxfinity)
      throw pybind11::stop_iteration();
    k = p + 1;
    return pybind11::make_tuple(p, q, v);
  }
};
} // namespace

PYBIND11_MODULE(_meadowlark, m) {
  m.doc() = "Meadowlark: Python wrapper for Cottontail annotative indexing";
  m.attr("maxfinity") = pybind11::int_(cottontail::maxfinity);
  m.attr("minfinity") = pybind11::int_(cottontail::minfinity);
  pybind11::class_<HopperIter>(m, "HopperIter")
      .def("__iter__", [](HopperIter &self) -> HopperIter & { return self; })
      .def("__next__", &HopperIter::next);
  pybind11::class_<cottontail::Hopper, std::unique_ptr<cottontail::Hopper>>(
      m, "Hopper")
      .def("tau",
           [](cottontail::Hopper &self, cottontail::addr k) {
             cottontail::addr p, q;
             cottontail::fval v;
             self.tau(k, &p, &q, &v);
             return pybind11::make_tuple(p, q, v);
           })
      .def("rho",
           [](cottontail::Hopper &self, cottontail::addr k) {
             cottontail::addr p, q;
             cottontail::fval v;
             self.rho(k, &p, &q, &v);
             return pybind11::make_tuple(p, q, v);
           })
      .def("uat",
           [](cottontail::Hopper &self, cottontail::addr k) {
             cottontail::addr p, q;
             cottontail::fval v;
             self.uat(k, &p, &q, &v);
             return pybind11::make_tuple(p, q, v);
           })
      .def("ohr",
           [](cottontail::Hopper &self, cottontail::addr k) {
             cottontail::addr p, q;
             cottontail::fval v;
             self.ohr(k, &p, &q, &v);
             return pybind11::make_tuple(p, q, v);
           })
      .def(
          "__iter__",
          [](cottontail::Hopper &self) { return HopperIter(&self); },
          pybind11::keep_alive<0, 1>());
  pybind11::class_<cottontail::Warren, std::shared_ptr<cottontail::Warren>>(
      m, "Meadow")
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
      .def("__enter__",
           [](std::shared_ptr<cottontail::Warren> self) {
             self->start();
             return self;
           })
      .def("__exit__",
           [](std::shared_ptr<cottontail::Warren> self, pybind11::handle,
              pybind11::handle, pybind11::handle) { self->end(); })
      .def("hopper", [](std::shared_ptr<cottontail::Warren> self,
                        const std::string &gcl) {
        std::string error;
        std::unique_ptr<cottontail::Hopper> hopper =
            self->hopper_from_gcl(gcl, &error);
        if (!hopper)
          throw std::runtime_error(error);
        return hopper;
      });
}
