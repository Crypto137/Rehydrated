# Rehydrated

Rehydrated is a ReXGlue based recompilation project for the vanilla version of Diablo 3 (C1.0.0.17339). This targets the vanilla version specifically, and not later Ultimate Evil Edition releases that include the Reaper of Souls expansion.

This project is intended for local use only. You also need a legally acquired copy of the game to run it.

Currently in early experimental state: the game runs, but nothing exciting beyond that. Working on the PC proxy mode to allow PC clients to connect to the Xbox 360 server.

## Building

This is still at the proof-of-concept stage, so expect some tinkering to get it to run. Requires ReXGlue 0.10.0 and all of its dependencies.

- Put ReXGlue in `Rehydrated/thirdparty/rexglue-sdk`.

- Put `Default.xex` and the `CPKs` folder in `Rehydrated/assets`. These need to be extracted from a vanilla US disc image of Diablo 3 for Xbox 360 (MD5 `3360CCDA2970F81AD75DE8EC02D2AE1E`).

- Open the folder in VS 2022 and build (or use your other preferred method).

- If you get a black screen with UI on top of it, press `F4` to open settings and enable `execute_unclipped_draw_vs_on_cpu` under `GPU`.

## FAQ

**What makes this different from other similar projects?**

Unlike existing server emulator projects, this uses the original game server that is embedded in console versions of the game for offline play. This means that all gameplay aspects, such as pathfinding and scripting, are fully functional and completely faithful to the original game out of the box.

Rehydrated also focuses on the vanilla pre-expansion version of the game, which is no longer playable on PC.

**How is AI used in this project?**

This project is not "vibe coded". AI agents are not used in the development, and the vast majority of code is handwritten or generated with deterministic tools (e.g. protobuf). AI chatbots are used in some cases to replace writing one-off scripts (e.g. generating attribute enum from dumped attribute definitions). All AI output is checked and tested by a human developer before being commited.
