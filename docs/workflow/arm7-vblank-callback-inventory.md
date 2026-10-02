# ARM7 startup-installed VBlank callback boundary

The verified WRAM startup loads `r1` from literal `0x037f8498` at
`0x037f83e8`, sets `r0 = 1`, and calls the handler-registration routine at
`0x037fb7f0` from `0x037f83f0`. The literal is the even ARM function pointer
`0x037f84f0`. This small function immediately follows the existing `BootFlags`
source unit ending at that address.

The reference is a callback registration rather than a direct branch. For mask
1, registration's first loop iteration selects index zero: `blt` at
`0x037fb828` reaches `0x037fb83c`, the next `blt` reaches `0x037fb854`, and
`moveq sl,r5` selects the VBlank response address loaded from `0x037fb884`.
`stmne sl,{r1,ip,lr}` at `0x037fb864` stores the incoming callback at
`0x03808e9c`. Remaining iterations shift away the only set mask bit.
The matched VBlank dispatcher loads base `0x03808e3c` from `0x037fb7c4` and
then its callback at offset `0x60`, the same address. Its non-null path sets LR
at `0x037fb7a0` and executes `bx r3` at `0x037fb7a4`.

| Runtime range | Payload range | Bytes | Classification | Boundary evidence |
| --- | --- | ---: | --- | --- |
| `[0x037f84f0, 0x037f8510)` | `[0x70c, 0x72c)` | 32 | ARM instructions | Startup installs the pointer as the VBlank callback. The eight instructions push, load a pointer and its value, compare against zero, optionally call `0x038063ac`, pop, and return through `bx lr`. The conditional branch at `0x037f8500` reaches the pop at `0x037f8508`; both paths return before the pool. |
| `[0x037f8510, 0x037f8514)` | `[0x72c, 0x730)` | 4 | Literal pool | The PC-relative load at `0x037f84f4` resolves to this word, `0x0380b76c`. |

The pointed-to storage and the external callee's behavior remain outside this
inventory. No SDK ownership, original name, source language, or assembly
exception is inferred. The following function at `0x037f8514` remains
unclassified by this scope. No standalone initialized data or BSS is added.
These 32 instruction bytes and four literal bytes are inventory evidence only,
with zero source-coverage credit. The whole ARM7 denominator remains unknown.

`tools/audit_arm7_vblank_callback.py` verifies the original ROM and ARM7 payload
hashes, checks the registration/dispatch reference chain, and decodes the two
callback paths and literal boundary. `tools/test_audit_arm7_vblank_callback.py`
checks the recorded sidecar against the ROM and rejects broken incoming
pointers, mask, storage, return, and pool boundary. Run with the project Python:

```text
python tools/audit_arm7_vblank_callback.py
python -m unittest discover -s tools -p test_audit_arm7_vblank_callback.py
python -m unittest discover -s tools -p test_arm7_inventory_ranges.py
```

Input ROM SHA-1: `c7c3014c237900c8281289b8bc76a781969b6278`.
ARM7 payload SHA-1: `a662d5c6a78e990244299926cf6862ce910a475d`.

The subsequent C reconstruction is `config/usa/arm7/src/PowerVBlankCallback.c`.
Existing `PowerState.h`, `PowerStateInit.c`, and `PowerLedUpdate.c` establish
the two required contracts: the word loaded from `0x0380b76c` is
`ARM7_PowerState.initialized`, and `0x038063ac` is
`ARM7_UpdatePowerLed(void)`. The first candidate matched the whole 36-byte unit.
The source manifest credits one function, 32 C instruction bytes, and four
literal bytes, replacing 36 fallback bytes. Inventory totals remain separate
and unchanged; the callback introduces no owned data/BSS or assembly exception.
