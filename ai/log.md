2026-04-24T19:25:54Z Initialized Meadowlark ai/ docs and updated AGENTS.md with wrapper direction, repo boundary rules, and near-term workflow goals.
2026-04-24T19:57:26Z Refined Meadowlark docs to reflect the longer-term architecture: Meadowlark as a specific Cottontail-based system with native support in ../Cottontail/meadowlark/ and this repo as the Python-facing side.
2026-05-10T20:05:00Z Installed Python build dependencies in the meadow conda environment and rebuilt the local pybind11 extension against ../Cottontail/bazel-bin/src/libcottontail.so; import and ldd smoke checks passed.
2026-05-10T20:12:00Z Documented the known-good local Meadowlark build and smoke-test workflow in README.md and ai/notes.md.
2026-05-10T20:17:00Z Added a simple local Makefile for dependency install, sibling Cottontail build, Meadowlark extension rebuild, and smoke checks; updated README.md and ai/notes.md to point at the make targets.
2026-05-10T20:21:00Z Made the Makefile's default target rebuild the Meadowlark pybind11 extension and updated README.md and ai/notes.md accordingly.
2026-05-10T20:25:00Z Prepared shutdown notes: confirmed README.md, Makefile, and ai/notes.md document the local build/rebuild workflow and the future-agent shutdown convention.
