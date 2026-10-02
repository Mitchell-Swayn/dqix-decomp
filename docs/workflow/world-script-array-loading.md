# World script array loading and access

This USA batch reconstructs nine ARM9 functions:

- `0208d51c..0208d540`: reset a 24-byte entry, leaving the unknown halfword at
  offset two untouched as the original does.
- `0208d550..0208d594`: parse the allocation count, selecting the list's signed
  capacity override when present.
- `0208d594..0208d82c`: read a key and twelve text parameters, apply the optional
  key filter, copy enabled nonempty strings, then append the entry.
- `0208d860..0208d8ec`: configure the loading context and run the script.
- `0208d9e8..0208daf4`: four string-field getters and one selector over eight
  stored string pointers.

Disassembly and the record reader establish actual pointer types: four entry
fields point to allocated C strings; the middle field points to a 32-byte
object containing eight string pointers. The list owns a `const short*` key
filter, signed override count, and 12-bit-use string mask. Compile-time checks
retain the observed entry/list/payload/context sizes: 24, 16, 32, and 8 bytes.
The two-pointer loading context is source-owned BSS at `02108fc0..02108fc8`.
The five-entry opcode table is source-owned initialized data at
`020f121c..020f1244`; the `%s` format slot at `020f1244..020f1248` preserves its
one padding byte after the terminator. These units are mapped only by USA
configuration; no Japanese coverage is claimed.

Every new function and data object compares at 100%. The four previously
accepted array-list helpers also remain 100% after the type correction.
`ninja rom check report sha1` passes all module and symbol checks and the expected
USA SHA-1 `c7c3014c237900c8281289b8bc76a781969b6278`. Final evidence is
`build/sol61-world-array-access/final-acceptance.log`; candidate details are under
`build/matching/`. No gameplay test was run.

Coverage gains are +9 functions, +1,176 reported code bytes, and +52 reported
data bytes. Function ranges contain 1,156 instruction bytes and 20 compiler
literal bytes. Data consists of 44 initialized bytes and 8 BSS bytes. All ARM9
and ARM7 denominators remain unchanged; no ARM7 source coverage changed.

The large reader matched after six successfully compiled semantic variants.
One intervening redeclaration caused a compile error; a final formatting and
`sizeof` rebuild also matched. Its first attempt was 76.65%, rising to 97.59%
after recovering the correct independent string-length helper at `020d2ff0`,
keeping a destination pointer across the byte terminator store, and recovering
register lifetimes. Moving the filter pointer increment into the `for` loop's
increment expression produced the original separate load and ADD. Moving the
mask's update before the eight-string index update reproduced its original
register allocation and instruction order. The outer filter scope retains the
matching declaration order. No assembly, volatile barrier, or binary substitute
was used.

The measurement records 17 distinct unit-source SHA-256 versions passed to
candidate builds, including the compile error and mechanical rebuild. This is a
reproducible source-version count, excluding repeated comparisons of an unchanged
source; it is not a count of every transitive-header change or compiler invocation.
The batch clock started after full acceptance on baseline `1c18ab0`; elapsed time
excludes setup and integrator work. Token usage is unknown. Queue state remains
integrator-owned. The inherited population draft is preserved and uncredited.
