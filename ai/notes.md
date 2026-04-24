# Meadowlark Notes

- Repo role: Python wrapper for the sibling `../Cottontail` repository.
- More precisely:
  this repo is the Python-facing repo for the Meadowlark system, while
  Meadowlark-specific native code also lives in `../Cottontail/meadowlark/`.
- Architectural layering:
  `Cottontail` is the shared engine;
  `Cottontail/meadowlark/` holds Meadowlark-native support and regression
  coverage;
  this repo holds Python bindings, packaging, and Python workflow.
- Current package layout is minimal:
  `meadowlark/bindings.cpp` contains the pybind11 module and
  `meadowlark/__init__.py` re-exports it.
- Current exposed surface is centered on:
  `Hopper`, `Meadow.open`, `start`, `end`, `hopper`, and `translate`.
- Build system:
  `pyproject.toml` uses `scikit-build-core`;
  `CMakeLists.txt` links against the sibling `../Cottontail` checkout and its
  Bazel build output.
- Local helper scripts:
  `test.py` is a small smoke test and `browse.py` is an interactive query
  shell.
- Relevant Cottontail layer for next wrapper work:
  `../Cottontail/meadowlark/` and `../Cottontail/apps/meadowlark.cc`.
- Cross-repo work is expected over time because Meadowlark is a specific
  Cottontail-based system, not just a generic binding exercise.
- Near-term wrapper target:
  collection creation/opening, TSV/JSONL ingestion, forage support, and
  ranking support from Python.
- Longer-term packaging target:
  make `import meadowlark as lark` easy for remote users, likely by shipping a
  Linux wheel that carries the native Cottontail functionality Meadowlark
  needs.
- Working delivery loop:
  improve local build/test, wrap new functionality, package/publish, repeat.
- Packaging for PyPI is intentionally deferred until the local workflow is in
  better shape.
