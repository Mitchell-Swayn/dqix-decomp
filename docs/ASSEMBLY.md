# Assembly coverage and exception review

An objdiff match does not establish that a function was reconstructed entirely
as C/C++. Existing sources contain both CPU-specific operations and assembly
introduced to force matching compiler output. These must be distinguished before
the final acceptance criteria can be satisfied.

Run `python tools/audit_assembly.py` after `ninja rom check report`. The output
`build/usa/assembly-audit.json` partitions every reported unit and reconciles the
code, data and function counters. Source units containing assembly, including
local headers transitively, are reported separately from source units without
detected assembly and from original binary units. The report lists source lines
requiring review. It intentionally flags unused header macros and inactive
branches; its byte counts describe affected whole units, **not exact assembly
instruction coverage**. It does not approve exceptions or count assembly as C++.

## Review register

ARM7 has a separate reviewed manifest at
[`config/usa/arm7/assembly_exceptions.json`](../config/usa/arm7/assembly_exceptions.json).
It records six CPSR access routines (120 initialized bytes), whose register access
requires MRS/MSR instructions. Their original authorship remains unknown. The
ARM7 source builder checks these exact ranges and reports them separately from
C functions, literal pools and BSS. This approval does not extend to other
routines or compiler-matching aids.

The separate [ARM9 review manifest](../config/usa/arm9/assembly_exceptions.json)
approves only the seven existing `CPSRInterruptState.cpp` routines at
`[0x020c96e8, 0x020c976c)`: 132 mixed C/assembly routine bytes, of which 48 bytes
are the twelve required MRS/MSR instructions. Masks and returns are ordinary C.
Original assembly authorship remains unknown. This review adds no matched code
or function coverage and does not reclassify these routines as pure C++.

The audit validates each recorded review against the normalized source hash,
exact original routine-byte hash, complete range coverage and every objdiff
function match. Changed source, bytes or nonmatching functions invalidate the
review until rechecked. Reviews are reported as a subset of assembly-affected
units; the scanner itself grants no approval. Run it after the full build checks.

| Source | Observation | Acceptance status |
|---|---|---|
| `src/System/Cache.cpp` | CP15 cache maintenance instructions (`mcr`) plus assembly loop/register setup | CPU-specific instructions are candidates for necessary assembly; ordinary loop/setup code still needs individual review |
| `src/System/CPSRInterruptState.cpp` | Seven CPSR read/write routines; only MRS/MSR expressed in assembly | Reviewed bounded exception, 132 routine bytes / 48 inline-assembly bytes; see manifest |
| `src/System/Timing.cpp`, `Timer1OverflowInterruptRoutine` | Whole assembly wrapper saves/restores registers around `HandleTimer1Overflow` | Original handwritten origin or necessity not established; exception not approved |
| `src/System/GamecardBusOwnership.cpp`, `ReleaseGBABus` | Whole assembly indirect branch wrapper | Exception not approved; source reconstruction work remains |
| `src/System/ProcessorContext.cpp`, `InitializeContextRegisters` | Assembly branches implement alignment and ARM/Thumb status selection | Not established as necessary assembly; replace with matching understandable source if possible |
| `include/asmhacks.h` | Branch/label macros and compiler ordering barriers | Matching aids, not established original assembly; all call sites need review |
| `src/Filesystem/{FileIO,NitroVM,OverlayFSManagement}.cpp` | Register moves/arithmetic inserted to force code generation | Matching aids, not approved low-level exceptions |
| `src/Grotto/Main/DetailedTreasureMapData.cpp` | Assembly stride/load-level arithmetic | Matching aid, not approved low-level exception |

This is an initial source audit, not an exhaustive instruction-level exception
registry. The generated list is the discovery queue. For each accepted exception,
record its module, address range, purpose, evidence of necessity/original assembly,
source implementation and module verification. Unknown original provenance must
remain unknown. Generated fallback objects are a separate, much larger gap and
are never assembly exceptions merely because a disassembler can print them.
