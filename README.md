# Rehydrated

Rehydrated is a ReXGlue based recompilation project for the vanilla version of Diablo 3 (C1.0.0.17339). This targets the vanilla version specifically, and not later Ultimate Evil Edition releases that include the Reaper of Souls expansion. You can find out more about the differences between versions [here](./docs/VersionDifferences.md).

**This is not a server emulator, and this project is intended for local use only. You need a legally acquired copy of the game to run it.**

Currently in early experimental state: the game runs and is playable as a basic recomp. Right now the main development focus is a proxy mode to allow PC clients to connect to the Xbox 360 server. The proxy mode works with game version 1.0.8.16603 and requires [Rehydrated.Bnet](https://github.com/Crypto137/Rehydrated.Bnet) to route the PC client to a local server.

Feel free to join the [Discord server](https://discord.gg/BtdsgtfuKN) if you want to discuss this project.

## Building

This is still at the proof-of-concept stage, so expect some tinkering to get it to run.

- Clone the repository. Make sure it's a recursive clone so that the dependencies are cloned as well.

- Put `Default.xex` and the `CPKs` folder in `Rehydrated/assets`. These need to be extracted from a vanilla US disc image of Diablo 3 for Xbox 360 (MD5 `3360CCDA2970F81AD75DE8EC02D2AE1E`).

- Build `rehydrated.exe`.
  
  - If you run into a libmspack error, open `Rehydrated\thirdparty\rexglue-sdk\thirdparty\CMakeLists.txt` and replace `set(MSPACK_DIR "${CMAKE_CURRENT_SOURCE_DIR}/libmspack/cabextract/mspack")` with `set(MSPACK_DIR "${CMAKE_CURRENT_SOURCE_DIR}/libmspack/libmspack/mspack")`.
  
  - Building for the first time and when changes are made to .toml files can be slow, especially in debug mode. You should prefer the release mode by default.

- If you get a black screen with UI on top of it, press `F4` to open settings and enable `execute_unclipped_draw_vs_on_cpu` under `GPU`.

## FAQ

**What makes this different from other similar projects?**

Unlike existing server emulator projects, this uses the original game server that is embedded in console versions of the game for offline play. This means that all gameplay aspects, such as pathfinding and scripting, are fully functional and completely faithful to the original game out of the box.

Rehydrated also focuses on the vanilla pre-expansion version of the game, which is no longer playable on PC.

**How is AI used in this project?**

This project is not "vibe coded". AI agents are not used in the development, and the vast majority of code is handwritten or generated with deterministic tools (e.g. protobuf). AI chatbots are used in some cases to replace writing one-off scripts (e.g. generating attribute enum from dumped attribute definitions). All AI output is checked and tested by a human developer before being commited.

**Why is this project named Rehydrated?**

The codename for Diablo 3 during its development was Hydra.
