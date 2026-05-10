# Meadowlark

**Meadowlark** is a Python wrapper for [Cottontail](https://github.com/claclark/Cottontail), a flexible and efficient indexing library written in C++. Meadowlark exposes a minimal interface to Cottontail using `pybind11`, with additional conventions for handling annotations in Python.

Or that's the idea. Not much to see yet.

## Local Development

This repo currently assumes a sibling checkout of Cottontail at
`../Cottontail`.

Known-good local setup:

```bash
conda activate meadow
```

Install the Python build tools if needed:

```bash
make deps
```

Build Cottontail first:

```bash
make cottontail
```

Then rebuild the extension in place from this repo:

```bash
make
```

The extension links against:

```text
../Cottontail/bazel-bin/src/libcottontail.so
```

Quick checks:

```bash
make checking
```

If the editable install fails while writing package metadata, the extension may
still have rebuilt successfully in `meadowlark/`.
