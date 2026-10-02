# World placement script opcode callbacks

Branch `work/luna-world-placement-opcodes`, based on `1fd54b4eec8bc0c47973c168e89980953f4f1748`.

The batch reconstructs the two eight-byte callbacks at `0x0208d540` and `0x0208d548`, both confirmed by the adjacent World script opcode table as opcodes 100 and 101. Their `Script::OpcodeProc` signature is `int (Script::Parameter*, int)` and each target consists of `mov r0, #1; bx lr`. Each object matched 1/1 symbols at 100%. The two compiled callbacks account for 16 instruction bytes, two functions, no literals or data, and remove 16 bytes of fallback.

An initial third candidate at `0x0208e894` was compiled once. It matched only 11.76% of its 340-byte target. The assembly accesses the GameState table at `+0x5cdc` and combines several script parameters with placement variants, but the candidate's behavior and relationship to the existing WorldPlacementSource callback/table declarations are not established well enough to claim source credit. Its candidate and delink range were removed; the target remains fallback for later reconstruction. No coverage denominator was changed.

Validation: both accepted objects were separately checked with `tools/match_unit.py` at 100%. `ninja rom check report sha1` completed all 358 tasks. Module and symbol checks passed; the ARM7 source build passed with existing coverage; the USA ROM guard and SHA-1 passed. Worker ROM SHA-1: `c7c3014c237900c8281289b8bc76a781969b6278`, equal to the verified copied input. Input and generated ROM are separate ordinary files.

The batch clock started at 2026-10-02 12:09:21.700 UTC after the baseline build and finished at 12:18:22.463 UTC; elapsed time recorded by `tools/work_batch.py` was 540.76 seconds. This includes setup/build activity and is not CPU time. Attempts recorded: one compilation per accepted function and one for the deferred candidate. Token usage was not measured. Detailed build and comparison logs remain under ignored `build/workflow/luna-world-placement-opcodes/` and `build/matching/`.
