# Decompilation worker

You turn single ARM9 functions from Dragon Quest IX (Nintendo DS, Metrowerks C/C++)
into source that compiles to the original bytes. Run every command from the
repository root; keep your files in `build/swarm/work/<your-name>/`.

```sh
S="python3 swarm/swarm.py"
$S next --worker NAME [--max-size N]      # lease a function and print its context
$S check TASK FILE [--profile P]          # compile + exact comparison, about 20 ms (--verbose: full diff)
$S submit TASK FILE [--subsystem DIR] [--note "evidence for names/types"]
$S release TASK --note "what you tried"   # give it back when stuck
$S context TASK --callers | --symbol NAME | --grep REGEX
```

`--subsystem` is one of Filesystem, Graphics, Resource, System, Memory, GameState,
World, Combat, Grotto, Math, Network, Util or Unclassified (the default); never a
module name such as `main` or `ov017`.

Loop: `next`, write a file, `check`, edit until it prints `MATCH`, `submit`, `next`.
Until integration you may `submit` the same task again (same `--worker`) to improve
its name or note.
Integration and the full ROM check happen elsewhere; you never build the project.

## Source rules

- Begin with `#include <globaldefs.h>` then `ARM` or `THUMB` (the mode in the header line).
- Define exactly one `extern "C"` function. Name it from evidence in PascalCase,
  `Subsystem_VerbObject` when the subsystem is clear; keep `func_XXXXXXXX` if you
  cannot tell what it does. Do not invent gameplay meaning.
- Use other functions and globals by the names in the listing, declared `extern "C"`.
  Copy declarations shown under `Calls`. Data is `data_XXXXXXXX` (or its listed name).
- Do not define global data, string literals or static tables: declare the original
  data symbol extern instead. No inline assembly, no raw-byte tricks.
- Access widths matter: `ldr`/`ldrh`/`ldrsh`/`ldrb`/`ldrsb` mean 32-bit, unsigned or
  signed 16-bit, unsigned or signed 8-bit. `char` is signed; pointers are 32-bit.
- Headers come from `include/` with `<...>`; `--grep 'struct Name'` finds types.

## Reading `check`

`-` lines are the original, `+` lines yours. Register-only differences usually come
from statement order, variable lifetime, signedness or a missing/extra parameter.
Things that often fix them:

- Write repeated field accesses as `*(T *)(p + off)` each time instead of caching a
  pointer in a local; the original often recomputes the address.
- Many game files use `#pragma optimization_level 4` after `ARM`; try it when
  instruction scheduling differs.
- Match the callee's declared parameter types; look at sibling callers with
  `context --grep NAME`.

`problem:` lines name wrong call targets, data addresses, mode or size. NitroSDK
code (OS_, MI_, FX_, G2/G3, RTC, CARD, ...) often needs `--profile O4p` or another
listed profile; pass the same `--profile` to `submit`.

`hint:` lines give SDK reference sources and flag probable hand-written assembly.
Release, with a short note, after about ten real variants without progress, or when
the listing is hand-written assembly (`mrc`/`mcr`/`svc`, bare `ldm`/`stm` copies)
or a shared epilogue tail (starts with `pop {..., pc}` or `add sp, ...` with no
matching `push`). A lone `bx lr` is not a tail: it is an empty function,
`extern "C" void Name(void) {}`, and `ldr ip, =target` + `bx ip` is a C tail call
(`void Name(args) { target(args); }`), not a veneer. Notes are shown to the next worker.
