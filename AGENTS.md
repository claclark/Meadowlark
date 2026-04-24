Be a little chill. This is a resaerch project exploring novel indexing
structures.  We want the code to be solid and usable, but we aren't
shipping to prod at a tech company. We are going boldly where no one has
gone before.

All agent documentation for Meadowlark lives in the ai/ directory.

Before doing substantial work in Meadowlark, read:
    ai/architecture.md
    ai/notes.md

At this level, we are supporting two repos: Cottontail, which is the core
annotative indexing engine, and Meadowlark, which is a separate Python repo
for one specific Cottontail-based system.

If you were activated with this file in the working directory, you are
primarily focused on Meadowlark. However, you should look up one level
and see what's going on there. You may be asked to work at that level.

The directory ../Cottontail should exist. It's existance is mostly
FYI. Read its AGENTS.md file. However, you should not make changes in
that repo unless specifically requested by the user. Instead you should
discuss any proposed idea with the user. In particular, there may be
another instance of codex active in that directory, so use caution. Even
though the AGENTS.md file says to log activities, that's information for
codex running in that repo, not for you.

Meadowlark direction:

- Meadowlark is more than a thin wrapper. It is a specific Cottontail-based
  approach to annotation, enrichment, storage, and retrieval.
- Meadowlark is intended to support self-describing indexes, with annotation
  information stored in the index itself, ultimately oriented toward an LLM
  backend.
- Some Meadowlark-specific native code lives in `../Cottontail/meadowlark/`
  for integration and regression testing.
- This repository is the Python-facing side of Meadowlark: bindings,
  packaging, Python workflow, and demo usability.
- Other Cottontail-based systems may exist in the future with the same basic
  shape:
  a subdirectory inside `../Cottontail` plus a separate language-facing repo.
- In the short term, prioritize a solid local build/test environment and a
  useful Python workflow over packaging polish.
- The near-term target is local usability:
  build a collection from TSV and/or JSONL, run forage passes for tf-idf and
  SPLADE-style indexing, and run rankers from Python.
- Work in an iterative loop:
  stabilize current build/test support, wrap the next useful functionality,
  then package and publish when that state is worth shipping.
- The current codebase is still early and thin. Prefer small, concrete
  improvements that preserve Cottontail semantics rather than inventing a
  large Python abstraction layer too early.

Files in ai/:

ai/architecture.md
    Authoritative Meadowlark mental model, layering, goals, and near-term
    direction.
    Do not modify unless explicitly asked or unless the user is clearly
    revising the project plan.

ai/notes.md
    Concise factual notes about repository structure, build assumptions, and
    the currently exposed wrapper surface.

ai/log.md
    Timestamped record of significant actions taken in this repository.

Modification rules:

- Keep ai/notes.md concise and factual.
- Append concise timestamped entries to ai/log.md for significant Meadowlark
  work.
- Do not make changes in ../Cottontail unless explicitly requested by the
  user.
- If a Meadowlark change seems to require Cottontail changes, discuss that
  boundary with the user before proceeding.
- Treat cross-repo design work as normal when Meadowlark needs new general
  primitives or Meadowlark-specific native support in `../Cottontail`, but do
  not implement those changes without explicit user direction.

Inform the user if ../Cottontail doesn't exist. Afterwards summarized
these rules to the user so that it's clear that they have been seen.
