# Luna GameState helper batch

The whole-task clock began at `2026-10-02T10:31:44Z`, before switching the clean
worker worktree to `work/luna-game-state-next` and configuring the current
`work/full-decomp` base `438bd7cde57b5b7b71661dec5589d5b029c88f9e`. Validated
completion and the coverage snapshot were recorded at
`2026-10-02T10:36:09.846497Z`, 265.85 seconds after start including setup.
Commit and task close completed at `2026-10-02T10:37:14Z`, 330 seconds after
start. The separate `tools/work_batch.py` snapshot interval was 109.807 seconds.
A fresh guarded baseline build passed before candidate work.

The six original ranges were re-read in a fresh `dsd dis` output and checked
against `config/usa/arm9/symbols.txt`. Three source units cover exactly those
ranges; `func_0200fd14` and the 0x100-byte copy routine `func_0200fbb4` remain
fallback. The chunk at GameState offset `0x3f8` stays an opaque pointer target.

| Function | Bytes | Observed behavior | Candidate result |
| --- | ---: | --- | --- |
| `func_0200fba4` | 16 | Tail-call `func_0200fbb4` with the GameState `+0x3f8` address | 100%, first candidate |
| `func_0200fcfc` | 16 | Same tail-call wrapper with its own original literal relocation | 100%, first candidate |
| `func_0200fd0c` | 8 | Return the GameState `+0x3f8` address | 100%, first candidate |
| `func_0200fd38` | 16 | Store a GameObject in `objects_[index]` and write the index to `unknown_4_` | 100%, first candidate |
| `func_0200fd48` | 16 | Clear `objects_[index]` | 100%, first candidate |
| `func_0200fd58` | 24 | Clear the full `objects_` array with `memset` | 100%, first candidate |

Each function had one candidate compilation: six variants total, no failed
variants. The object ranges contain 84 instruction bytes plus 12 compiler
literal-pool bytes for the two `func_0200fbb4` branches and the `memset` branch.
The report delta is +96 matched code bytes and +6 functions, with no additional
initialized data, literal section, BSS, or denominator changes. The literals
remain in `.text` per the original layout.

Full `ninja rom check report sha1` passed ARM9 main, ITCM, DTCM, all 35 overlays,
symbol checks, ARM7 source build and preservation baseline, guarded USA ROM
finalization, and exact ROM SHA-1
`c7c3014c237900c8281289b8bc76a781969b6278`. No gameplay validation was run.
Build and per-object logs remain under ignored `build/`.
