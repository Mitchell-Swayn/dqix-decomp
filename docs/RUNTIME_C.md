# Matched C runtime primitives

The first runtime milestone reconstructed twelve USA ARM9 functions in seven
units (table below). Subsequent memory, text, stream, termination and conversion
batches are recorded in [runtime attempts](workflow/runtime-attempts.md).

The exit state and 64-slot callback allocation, nine owner/count bookkeeping
slots, seven signal callbacks, and destructor-list head now have typed BSS
definitions in `RuntimeExitState.cpp`, `RuntimeLockBookkeeping.cpp`,
`RuntimeSignalState.cpp`, and `RuntimeDestructorState.cpp`. They cover 376 bytes
at `[0x020f2e60, 0x020f2fb8)` and `[0x020f3394, 0x020f33b4)` and match their
complete linked symbol ranges. The shared declarations in `RuntimeState.h`
preserve caller code exactly. Callback allocation size does not by itself
establish registration policy; mutex objects and other globals remain fallback.

| Source | Range | Functions | Report code bytes |
| --- | --- | --- | ---: |
| `RuntimeRandom.cpp` | `0x02003d14..0x02003d58` | `rand`, `srand` | 68 |
| `RuntimeSignal.cpp` | `0x02003ddc..0x02003f0c` | signal dispatch (`func_02003ddc`) | 304 |
| `StringLength.cpp` | `0x02003f0c..0x02003f28` | `strlen` | 28 |
| `StringCopyAligned.cpp` | `0x02003f28..0x02003ff0` | `strcpy` | 200 |
| `StringCopy.cpp` | `0x02003ff0..0x02004070` | `strncpy`, `strcat` | 128 |
| `StringCompareAligned.cpp` | `0x02004070..0x02004184` | `strcmp` | 276 |
| `StringSearch.cpp` | `0x02004184..0x020042a8` | `strncmp`, `strchr`, `strrchr`, `strstr` | 292 |

The random generator preserves the 32-bit wrapping recurrence
`state = state * 0x41c64e6d + 12345` and returns bits 16..30. Its four-byte
source-owned state at `0x020eef30` starts at 1. Sixteen of its reported code bytes
are compiler-generated literals. Existing grotto code calls `rand`; filesystem
and model code use these string interfaces.

The string implementations preserve the original signed-char searches,
unsigned-byte comparison, count-zero behavior, zero padding, and null-character
search results. The original `strstr` treats a null needle like an empty needle;
that nonstandard behavior is intentionally retained. Assignment expressions in
the bounded-copy and concatenation loops preserve the original post-store
reloads. Other runtime bodies remain fallback and receive no new source credit.

`strcpy` and `strcmp` use word operations only after their pointers have matching
four-byte alignment and the leading bytes have been handled. Copy uses the
standard zero-byte mask `(word + 0xfefefeff) & ~word & 0x80808080`. Comparison
retains the original conservative high-bit shortcut inside its word loop, then
falls back to unsigned-byte comparison. The explicit intermediate terms in copy
preserve compiler register allocation. Both routines include their original
eight-byte compiler literal pools; neither adds standalone data.

The signal dispatcher validates signals 1..7, reads and resets handlers under
the original recursive-lock bookkeeping, and preserves the special handler
value 1 and signal-1 default behavior. Its generic symbol name is retained;
the runtime ABI has not been fully named. In particular, the observed branch
after `TryLockMutex` is preserved verbatim despite its counterintuitive return
handling. The five referenced BSS globals remain binary fallback. Twenty of
the 304 reported code bytes are compiler-generated address literals.

Validation used the pinned compiler, direct instruction comparison, `ninja rom
check`, and `ninja report`. All seven units report 100% matching: twelve functions,
1,296 code bytes and four data bytes. Total denominators remain 2,959,478 code
bytes, 1,602,476 data bytes and 14,790 functions. This is byte-equivalence evidence,
not a replacement for runtime gameplay validation.

## Link-only metadata correction

Creating the new fallback boundaries exposed an existing MWLD compatibility
problem. The generated fallback object's text section contains `_fdiv` and
`_ddiv`, each with an embedded 256-byte table. Dsd also emits those table symbols
as `STT_OBJECT` with `STB_GLOBAL` binding despite their local-label-style names.
MWLD sums the function and table sizes and rejects the object when that sum
exceeds the section length. This is valid overlapping ELF symbol metadata; the
underlying instructions and table bytes are unaffected.

`tools/prepare_link_objects.py` prepares separate copies immediately before
linking. It changes only `st_size` to zero for these two explicitly allowlisted
symbols, and only if the section's size sum otherwise exceeds its length:

| Table | Address | Enclosing function | Function address/size |
| --- | --- | --- | --- |
| `.L_0200c274` | `0x0200c274` | `_fdiv` | `0x0200c1c0 / 0x3b8` |
| `.L_0200d484` | `0x0200d484` | `_ddiv` | `0x0200d34c / 0x544` |

The helper verifies configured symbol names, types, absolute addresses and sizes,
plus ELF binding, type, relative range and unique containment. It preserves
symbol values, bindings and types, every relocation and every other section
payload. Unexpected overlap fails closed. This does not authorize modification
of other globals or local symbols. Seven synthetic-fixture tests cover the
allowlist, changed ranges/configuration, malformed input, unchanged objects and
original-file preservation.

The originals in `build/usa/delinks` remain unchanged and continue to feed
objdiff. Only the linker consumes `build/usa/link_objects` via its separate
response file. `build/usa/link_objects_report.json` records original/copy SHA256
hashes and each changed metadata offset. In the validated build, exactly the two
listed fields changed; hashes confirmed all original fallback files remained
intact. There is no source coverage credit for this compatibility adjustment.
