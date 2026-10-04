# Native GPC decompression differential validation

On 2026-10-02, the Python decoder in `tools/gpc.py` matched the original USA ARM9
algorithms in **84 comparisons**, covering 42 inputs in both whole-input and
fragmented-input modes. No decoder discrepancy was found.

The harness is `tools/test_gpc_native.py`. It reads the user's extracted ARM9
binary and runs these actual instructions under Unicorn 2.1.4's ARM946 model:

| GPC type | Native function | Runtime range |
| --- | --- | --- |
| 1: LZ | DecompressA | `[0x020caa10, 0x020cab94)` |
| 2: 4-bit Huffman; 3: 8-bit Huffman | DecompressB | `[0x020cab94, 0x020cad00)` |
| 4: RLE | DecompressC | `[0x020ca95c, 0x020caa10)` |

It rejects algorithm bytes whose SHA-256 differs from
`0207844940c601f90e02c46844db494934b3efcbe930e4898e98a3ec7d5b5bf5`
for the combined interval `[0x020ca95c, 0x020cad00)`. No original executable or
asset bytes are embedded in the harness or committed as fixtures.

## Reproduce

After extracting the supplied USA ROM, run from the repository root:

```bat
.venv\Scripts\python.exe -m pip install unicorn==2.1.4
.venv\Scripts\python.exe tools\test_gpc_native.py --samples-per-kind 8
```

The JSON evidence is `build/usa/gpc-native-validation.json`: input identifiers,
compressed/output hashes, function addresses, emulator version, original code
hash, decoder-source hash, sizes, call counts and comparison outcomes. The report
is regenerated only after all comparisons pass; a previous report is removed
before an explicit run. Native execution has per-call time/instruction limits.

Unicorn is an **optional validation dependency**, separate from the matching
build. Standard unittest discovery skips the native integration test. To run a
smaller native sample through unittest on Windows PowerShell:

```powershell
$env:DQIX_NATIVE_GPC_TESTS = '1'
.venv\Scripts\python.exe -m unittest discover -s tools -p test_gpc_native.py
Remove-Item Env:DQIX_NATIVE_GPC_TESTS
```

## Sample coverage

The harness scanned all 1,671 extracted `.gp2` containers. It used deterministic
reservoir sampling (seed 9), selected eight real compressed sections per type,
and added each type's largest eligible output. This produced 36 file-backed
samples. Eligibility excludes empty outputs and outputs above the configured
512 KiB limit; scanning covers compressed file tables, filename tables and
members, without claiming every section was executed natively.

| Type | Eligible compressed sections | Real samples | Largest tested output |
| --- | ---: | ---: | ---: |
| 1 | 44,068 | 9 | 161,696 bytes |
| 2 | 795 | 9 | 14,444 bytes |
| 3 | 2,439 | 9 | 81,643 bytes |
| 4 | 7,763 | 9 | 3,272 bytes |

Six additional synthetic inputs exercise overlapping LZ copies, maximum LZ
token length, maximum LZ distance, nibble/byte Huffman partial output words,
and mixed RLE literal packets with a maximum-length repeated run.

Each input runs once as a single call and once with a repeating chunk schedule
of 1, 2, 3, 7, 31, 257, 1,024, 4,096 and 16,384 bytes. This deliberately splits
flags, tokens, trees and bitstreams across calls. The largest sample needed 36
native calls in fragmented mode. Output bytes and the native remaining-output
counter are checked; canaries detect writes outside the word-rounded output
allocation. Up to three final Huffman padding bytes are allowed because the
native routine writes words; comparisons use the exact declared logical size.

## Context and limits

The harness initializes the 0x228-byte `Decompressor` state exactly as described
by `Decompressor::InitAndDecompress` in `src/Filesystem/ExtendedNitroVM.cpp`:
output pointer and remaining size, LZ state byte `+0x11 = 3`, Huffman tree pointer
`+0x08 = context + 0x1c`, tree-length state `+0x14 = -1`, and symbol width
`+0x18 = 1 << type`. It calls the native algorithms directly. Inputs have readable
padding for the native Huffman word loads.

The reconstructed `Decompressor` now names these overlapping fields through
algorithm-specific views of bytes `+0x08..+0x1b`. Huffman uses a tree cursor,
input/output bit accumulators and counts; its 512-byte tree buffer begins at
`+0x1c`. LZ uses packet flags, token-read state and an extended-length mode byte;
RLE uses a packet control byte and remaining-run count. The wrapper leaves the
extended LZ mode at zero, so the decoder and differential samples cover that
normal mode. Native extended-mode behavior is outside the current validation.
These inferred types preserve the complete 0x228-byte object layout and compile
to identical original wrapper bytes; they add no new native source coverage.

This validates compression output and streaming state against native code. It
does not validate filesystem/cache/mutex wrappers, in-place scratch-buffer
overlap behavior, malformed-data handling equivalence, or gameplay. Type 0 is
raw copying and is outside these three algorithm tests. Native register-state
execution in Unicorn is separate from a complete Nintendo DS emulator test.
