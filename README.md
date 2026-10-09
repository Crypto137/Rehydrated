# Rehydrated

Rehydrated is a ReXGlue based recompilation project for the vanilla version of Diablo 3 (C1.0.0.17339, disc image MD5 `3360CCDA2970F81AD75DE8EC02D2AE1E`). This targets the vanilla version specifically, and not later Ultimate Evil Edition releases that include the Reaper of Souls expansion.

Currently in early experimental state: the game runs, but nothing exciting beyond that.

## Building

Expect some tinkering to get it to run. Requires ReXGlue 0.10.0 and all of its dependencies.

- Put ReXGlue in `Rehydrated/thirdparty/rexglue-sdk`.

- Put `Default.xex` and the `CPKs` folder in `Rehydrated/assets`. These need to be extracted from a vanilla US disc image of Diablo 3 for Xbox 360.

- Open the folder in VS 2022 and build (or use your other preferred method).

- Add `execute_unclipped_draw_vs_on_cpu = true` to `rehydrated.toml` to fix 3D graphics rendering as black.
