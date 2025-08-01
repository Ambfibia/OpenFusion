# AGENTS

## Project Overview
OpenFusion is a C++17 server implementation of the FusionFall MMO. The codebase reverses the original game's protocol and provides login and shard servers for gameplay.

## Repository Structure
- `src/`: server source modules (chat, combat, NPCs, etc.).
- `sql/`: database schema and initialization scripts.
- `res/`: static resources such as images.
- `tdata/`: table data loaded by the server at runtime.
- `vendor/`: vendored third‑party libraries.

## Building and Testing
- Requires SQLite 3.33.0 or later and Clang.
- Build with `make` (default) or `cmake -B build`.
- The project has no automated test suite yet; run `make test` if one is added. Otherwise ensure `make` completes without errors.

## Coding Guidelines
- Match the surrounding code's whitespace, brace style, and naming.
- Prefer short‑circuiting/early returns to reduce branching complexity.
- Follow include conventions:
  - Header files must explicitly include any types they use (except those covered by `Core.hpp`).
  - Source files should include their partner header first; redundant includes are acceptable.
- Keep commits focused and clean; avoid unnecessary merge commits.

For further details consult `README.md` and `CONTRIBUTING.md`.
