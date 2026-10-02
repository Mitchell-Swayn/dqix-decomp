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

The subsequent record candidate uses `RuntimeFormatText` and the independently
reviewed alias generator from `501d2c9`. It retains every original interior
symbol and all configured load relocations. The final empty fields are a
two-element 16-bit wide string at `020eef28` (passed to `func_020019c8`) and a
four-byte narrow string at `020eef2c`. This type distinction follows the actual
output-engine call sites. The complete target/candidate `.data` payload is
64 bytes with identical SHA-256
`5cd80a33cddfab53836fb2d16b73e29ca96bcc6359ee5d642837f4d38b093bcb`.
The record matches at 100% and aggregate data matching is unchanged; objdiff
lists the ten storage-free target interior aliases as unpaired. Full linked
symbol and module checks, followed by exact USA ROM SHA-1, all pass. The report
adds exactly 64 source-owned bytes, with no denominator change or alias credit.
The formatter-data source commit requires the alias generator from `501d2c9`;
the worker used its exact file for verification and retained it in standalone
support commit `06c4c13`, without including tooling in the source commit.
The integrator should skip `06c4c13` once `501d2c9` is integrated.

The measured snapshot window was 1046.3 seconds and excludes baseline setup.
The batch recorded 17 distinct candidates: three rounding forms including the
reviewed whole-record pointer correction, one power-table form, seven text
layout/type forms including the rejected section declaration, and six integer
formatter forms. Repeated unchanged comparisons and final builds are excluded.
Coverage changed from 212188 to 212480 matched code bytes, 48320 to 48448
matched data bytes, and 1558 to 1559 matched functions. All denominators and
ARM7 counters stayed unchanged. Token usage was not measured.
