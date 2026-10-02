# CRT formatting reconstruction (Sol 6.1, 2026-10-02)

Based on `7a3cdb3`. The inherited console start/finish snapshots and all prior
deferred evidence were preserved. The original ROM input SHA-1 was rechecked;
the baseline passed `ninja rom check report sha1` before the batch snapshot.

`func_02002b90` is the formatter's ASCII decimal rounding routine. It differs
from the numeric-digit arithmetic helpers: it subtracts ASCII zero before
comparing digits, uses the retained digit's parity for exact half ties, removes
trailing zero digits, propagates a carry, and normalizes zero/overflow results.
For a half tie at requested length zero, the original parity read is the
record's length byte at offset 4. The source uses a character view of the
complete record and starts its digit cursor at offset 5, so that preceding-byte
access stays within the object representation rather than outside a subarray.
The two C candidates differed only in the signedness of the original length
comparison; the signed local reproduces all 292 instruction bytes. Callers in
the floating formatter use the same decimal-record field offsets.

`data_020eef34` contains eight binary64 powers of ten, 10 through 100000000.
The decimal-to-binary converter at `0200a3a8` groups up to eight digits, loads
the table element at `(groupLength - 1) * 8`, multiplies the running value,
and adds the next digit group. Its initialized `double[8]` source matched all
64 bytes on the first candidate, including four-byte target alignment.

Both retained units passed exact objdiff and full module, symbol, ARM7 baseline,
ROM and USA SHA-1 checks. No denominator, fallback-input, or relocation edits
were made. Logs are under ignored `build/sol61-library-*-acceptance.log` and
`build/matching/`. No gameplay tests were performed.

The 32-bit integer formatter `func_0200216c` remains required fallback. Six
source variants recovered its conversion/sign/prefix/precision logic and the
16-byte format descriptor. The best candidate reached 92.52%, with the same
register allocation after moving the base declaration before the cursor, but
initial width/alternate loads and their stack slots differ; it is four bytes
short because MWCC reuses the initial alternate-value register. Splitting the
initial zero check and using byte-sized locals did not resolve that difference.
No volatile barrier or assembly was introduced. Draft and inferred descriptor:
`build/RuntimeIntegerFormat-pending.cpp`, `build/RuntimePrintFormat-pending.h`.
Further experiments should investigate source/compiler evidence for those
initialization and lifetime differences rather than repeat the same forms.

The adjacent 64-byte formatter text region was also investigated. Individual
character arrays matched as symbols, but MWCC reordered them in the object,
so full checks correctly rejected their layout. Named data sections and explicit
character initializers did not fix emission order. All rejected text source
and boundaries were removed. A coherent record can preserve the fields, provided
the original interior symbols remain available through reviewed linker aliases.
