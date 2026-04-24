# Meadowlark Architecture And Direction

## Purpose

Meadowlark is a specific Cottontail-based system, not merely a generic Python
binding layer.

This repository is the Python-facing side of Meadowlark. Its job is to make
the Meadowlark workflow usable from Python:

- build collections
- enrich them with additional annotations and derived indexes
- query them
- run rankers over them

Meadowlark carries some opinionated conventions about annotation and storage.
In particular, it is intended to support self-describing indexes, with
annotation information stored in the index itself, ultimately oriented toward
LLM-backed use.

The Python layer should stay close to Cottontail semantics, but it does not
need to mirror every C++ type one-to-one. A good Meadowlark API should make
common tasks straightforward while preserving access to the underlying model.

## Relationship To Cottontail

Cottontail is the authoritative implementation of the indexing machinery and
the underlying retrieval model. Meadowlark depends on it and should treat its
core behavior as the source of truth for general engine behavior.

The longer-term structure is:

- `Cottontail` holds general-purpose engine primitives.
- `Cottontail/meadowlark/` holds Meadowlark-specific native code and
  regression coverage close to the engine implementation.
- this `Meadowlark` repo holds Python bindings, packaging, examples, and the
  Python-facing workflow.
- other Cottontail-based systems may eventually follow the same pattern:
  a dedicated subdirectory in `Cottontail` plus a separate wrapper or product
  repo.

Meadowlark currently builds a pybind11 extension that links against a sibling
checkout of `../Cottontail`. That local-development assumption is acceptable
for now. Packaging for PyPI is a later problem and should not drive early API
decisions.

Changes in Meadowlark should avoid silently redefining Cottontail behavior.
If the wrapper reveals friction caused by Cottontail interfaces, document the
friction here or in `ai/notes.md` and discuss cross-repo changes with the user
before editing Cottontail.

## Current State

At present, this repo is a thin Python wrapper around a small subset of
Cottontail:

- open a `Warren`
- start and end sessions
- create hoppers from GCL
- iterate hopper results
- translate intervals back to text

This is enough for basic querying demos, but not enough for the intended
Meadowlark collection-building and ranking workflow.

## Near-Term Direction

The short-term goal is a locally usable build/test workflow, not a polished
distributable package.

Near-term Meadowlark should support a complete demo workflow from Python:

1. Create or open a meadow-like collection.
2. Ingest source data from TSV, JSONL, or a mix of both when appropriate.
3. Run forage passes, including tf-idf and SPLADE-oriented indexing paths.
4. Run rankers from Python over the resulting collection.

The intended implementation path is to wrap the higher-level
`../Cottontail/meadowlark/` facilities and related ranking functionality,
not just the low-level `Warren` primitives.

The development loop is expected to be iterative:

1. Stabilize local build/test support for the current wrapper surface.
2. Wrap the next useful functionality, including Cottontail additions when
   they are needed.
3. Package and publish the resulting state when it is worth shipping.
4. Repeat.

## API Design Bias

When choosing what to expose:

- Prefer thin, comprehensible wrappers over large speculative Python
  frameworks.
- Expose obvious workflow operations first:
  create, open, append_tsv, append_jsonl, forage, rank.
- Preserve escape hatches to lower-level primitives when they are already
  stable and useful.
- Favor boring, explicit data flow over magic.
- Keep Meadowlark-specific conventions in Meadowlark-facing layers, while
  keeping general engine functionality in Cottontail when possible.

The project is exploratory. It is fine for the API to evolve as the workflow
becomes clearer, but changes should be made deliberately and documented.

## What Counts As Progress

Useful progress in Meadowlark includes:

- expanding the bound C++ surface in service of the Python workflow
- adding small Python helpers that make demos easier to write
- documenting build assumptions and known rough edges
- adding smoke tests or simple examples for ingestion, forage, and ranking

Useful progress does not require full packaging polish or a final public API.
It does require keeping the repo boundary and the longer-term layering clear.
