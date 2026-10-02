# ov010 initialization and cleanup batch

Batch: `fleet_ov010_20261002t1547`. Baseline revision:
`0ade2646fe7e27eb53d084a9e857334d18b3b47f`. Exclusive worker worktree;
no integrator queue or shared headers changed. No prior ov010 source or local
variant records were present when this batch began.

## Accepted family

`src/Factory/ov010/PitSequenceState.cpp` owns `[0x021842a0, 0x02184354)`.

| Function | Range | Behavior | Candidate comparisons |
| --- | --- | --- | --- |
| `func_ov010_021842a0` | `0x021842a0–0x021842d8` | Reset phase, delay and task ID; initialize text table and allocator pointer; clear effect flag | First exact; remained exact in second |
| `func_ov010_021842d8` | `0x021842d8–0x02184354` | Release effect resource 17, destroy/free allocator storage, remove a pending loader task, set the selected object's flag, reset state | 90.32258% then exact |

The second hypothesis makes the task handle volatile, preserving the original
reload after the loader singleton call. This is an access-semantics reconstruction;
the original source qualifier and any asynchronous writer are not established.
The first comparison retained the handle in r4 and replaced that reload with a
register move. All other cleanup instructions and relocations already matched.
Two compiled source variants total; no function reached its ten-variant cap.

## Layout and dependencies

The update routine `func_ov010_02184354` establishes phase/effect bytes at +0/+1,
delay at +2, signed loader task at +4, effect object index at +8, an eight-byte
text table at +0xc, and the existing `SafeAllocator` subobject at +0x14.
`func_020729b4`, `func_02072a28` and `func_02072a68` establish the table's actual
eight-byte identifier/text records and signed capacity/count fields. The local
header records these types, with no opaque replacement buffer.

`data_02114e20` is declared as `AllocatorUnion`: `func_02012d88` calls its
allocation method and `func_02012da4` tail-calls its free method. The effect
manager remains an opaque external interface: `func_02057924` returns its address,
and `func_02057f00` removes objects/resources associated with the requested ID.
`func_020397c0` sets byte +0x253 on the GameObject returned by the existing
GameState interface. Its exact gameplay meaning remains unresolved.

The update function has eight explicit cleanup calls, and cleanup calls reset.
External calls at the common overlay entry address are mapped ambiguously among
overlays 8–14; identical addresses in another overlay are not ov010 caller proof.
The `str_pit` filenames support the local family name; the gameplay expansion of
"pit" is unknown. No other-module source was edited.

## Verification and measured delta

- `match_unit.py --worker fleet_ov010 --hypothesis ...`: 2/2 exact symbols.
- `factory_evidence.py`: baseline, first-candidate and accepted object evidence.
- `factory_diff.py`: first mismatch classified as register/immediate differences.
- `ninja -j2 rom check report sha1`: exit 0, ARM9 main/autoload/35 overlays,
  symbol check, ARM7 check, full ROM and SHA-1 passed.
- ROM SHA-1: `c7c3014c237900c8281289b8bc76a781969b6278`.
- Runtime/gameplay testing was not performed in this worker batch.

`work_batch.py` measured 271.737531 seconds from baseline capture through full
acceptance. ARM9 report delta: +2 functions, +180 matched code-range bytes;
denominators unchanged. This is 176 ARM instruction bytes and a separate four-byte
pointer literal at `0x02184350`. Initialized data, BSS and assembly deltas are
zero; ARM7 deltas are zero. Matched functions: 1651 → 1653; matched code:
218816 → 218996; matched data remains 66724. Token usage was not measured.

Verbose logs, disassembly, evidence and candidate snapshots stay under ignored
`build/factory/fleet_ov010/`, `build/matching/` and
`build/workflow/fleet_ov010_20261002t1547/`. Exact candidate attempt:
`build/matching/20261002T154608-4aff975e57ef425d8bf9be85705b8f2a/`.
The earlier timing snapshot was taken while packaging was still running; it was
moved to `build/factory/fleet_ov010/premature-snapshot.json` and superseded by
the finish snapshot taken after successful acceptance.

## Required follow-up

`[0x02184354, 0x02184a6c)` remains the original update-function fallback.
Its effect creation parameters, record types and overlay-17 dependencies still
need reconstruction. The `.ctor` word, 64-byte initialized string/data section,
and section alignment remain original fallback; no data credit is claimed.
ov010 has zero BSS bytes. External text-table helpers, effect-manager helpers,
allocator backing global and GameObject flag helper also remain dependencies.
This batch does not establish module completion.

## Continuation: update sequence, 2026-10-02

Batch `fleet_ov010_20261002t1549` starts from the prior worker commit
`623a89be039355a2a6ae32d335db842eb7c6f941`. The initial worktree was clean;
the prior two initialization/cleanup variants remain recorded. No previous
update-function variants were present. Queue ownership and original inputs were
preserved, and no subagents, integrations or shared-tool changes were made.

`src/Factory/ov010/PitSequenceUpdate.cpp` reconstructs
`func_ov010_02184354`, `[0x02184354, 0x02184a6c)`, exactly. Its connected phases
load the localized `str_pit` script, choose/display text, optionally clear the
saved zone, load `data/effect/ana.chr`, wait fifteen updates, create effect 17 at
the party member's position, save/send the compact position, and wait for text
and effect completion before cleanup. The gameplay meaning of this sequence and
several external flag/parameter names remain uncertain.

Eight `match_unit.py` invocations: one conflicting external declaration failed
to compile; seven candidates compiled. Three compiled nonexact variants reached
85.12035%, 91.40969%, and 96.47577%; the fourth compiled variant was exact. The three
subsequent compilations retained exactness while establishing shared layouts,
checking offsets, and naming text argument fields. No ten-variant cap was reached.
The final declaration-order change places persistent member/zone variables
before the selection pointer, preserving initialization order and matching the
original r7/r8/r9 allocation. Earlier hypotheses and all snapshots remain in
`build/matching/`; final exact attempt:
`20261002T160007-c1b1997a5b1c4dfca991f6bf861b2d24`.

Shared header changes travel with the source because the original calls establish
actual embedded objects, rather than independent pointer buffers:

- `GameStateSavedPosition savedPositions_[4]` occupies +0x74de..+0x74fe;
  `func_020120a0` indexes eight-byte records containing a zone and three shorts.
- `GameResources::graphicsRegion_2cc_` embeds a texture checkpoint at +0xf0c;
  `func_0207de48` and `func_0207df50/90/ac` establish two ten-word image-bound
  arrays, allocation key/size fields and two palette-bound records. Unrecovered
  surrounding fields retain their original reserved layout.
- `Zone3D_StructPtr_8` byte +0xe is split into observed 2/4/1/1-bit fields;
  its previous high-bit consumer remains unchanged. No other source used the
  replaced seven-bit aggregate.

The local effect record is 80 bytes, with a real 16-byte animation-name array,
flag bits, short parameters and four vector subobjects. The original initializes
only the observed fields; it does not zero the remaining animation-name bytes or
alignment padding. The text argument record contains two combat-stat pointers
and packed flags, as observed in `func_020e4bf4`/`func_020e4b34`. Partial external
display, selection and metadata views are declarations, not new program storage.
Compile-time checks verify the effect/saved-record sizes and shared offsets.

Final candidate is 1/1 exact. `factory_evidence.py` and `factory_diff.py` evidence
is under `build/factory/fleet_ov010/update-*`. Both full acceptance builds passed
`ninja -j2 rom check report sha1`, including all configured ARM9 modules/symbols,
ARM7 preservation and ROM SHA-1 `c7c3014c237900c8281289b8bc76a781969b6278`.
Final verbose log: `build/factory/fleet_ov010/acceptance-update-final.log`.

`work_batch.py finish` measured **673.729377 seconds**, through final acceptance.
Delta: **+1 function, +1816 matched code-range bytes**, comprising **1792 ARM
instruction bytes and 24 literal bytes** at `[0x02184a54, 0x02184a6c)`.
Initialized data, BSS, assembly and ARM7 deltas are **zero**. Denominators are
unchanged; ARM9 matched functions 1653 -> 1654 and matched bytes 218996 -> 220812.
The batch snapshots are under `build/workflow/fleet_ov010_20261002t1549/`.
Token usage was not measured; gameplay was not tested.

All three inventoried ov010 functions now match, but module completion is not
claimed. The four-byte `.ctor` word, 64-byte initialized string section and
section alignment remain original fallback. Required external dependencies
include the text script/table and display helpers, effect manager/catalog,
overlay-17 position/resource interfaces and allocator backing storage. Future
work must retain these dependencies and the original coverage denominators.
