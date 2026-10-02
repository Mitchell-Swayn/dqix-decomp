# Luna VRAM callback pilot

The measured batch window started at `2026-10-02T09:41:25.825120Z`; worktree
setup and initial inspection happened before that snapshot and are excluded from
the recorded elapsed time. The final full USA acceptance build completed by
`2026-10-02T09:48:54Z`; the batch window closed at
`2026-10-02T09:49:25.303453Z` per `tools/work_batch.py`. The
isolated worktree was created from
`3e8b0a61a0353295d031712af0ddc4b9258cefa4` on `work/luna-vram`.

The source now owns the four initialized callback pointers at
`0x020f1ee8..0x020f1ef8` in `VRAMDefaults.cpp`, with the corresponding data
range delinked. `VRAMAllocations.h` defines one shared callback type: allocation
flags are `unsigned int` so `Model3D` can pass the original `0x8000` palette
flag unchanged; free callbacks return signed `int` status. Model3D includes the
shared declarations after the USA/JPN symbol aliases, and allocator declarations
use the same wide flag type. Default hooks still return allocation key zero and
free status `-1`.

Seven `match_unit.py` invocations were recorded: six comparisons passed and one
early candidate compile failed because the new TU did not include the callback
typedef header. The later full build exposed the palette allocator's remaining
`bool` signature mismatch; its declaration and definition were changed to the
wide flag type. Root review specifically requested this consistency and the
shared declarations in Model3D; both points were addressed and recorded here.
The final object comparisons passed with no mismatched symbols: VRAMDefaults
8/8, Model3D 30/30, VRAMImageInit 2/2, and VRAMPaletteAllocation 7/7. All 47
compared symbols matched. The callback object accounts for 48 exact matched
bytes (32 bytes of existing hook code and 16 bytes of newly source-owned pointer
data); the integrated ARM9 report gained 16 matched data bytes, with no function
or code increase and unchanged denominators.

The isolated build used the root `.venv` through a junction, root MWCC and DSD
paths passed to configure, local ignored objdiff/DSD executables, and a hard link
from the supplied USA ROM to `extract/baserom_dqix_usa.nds`. Initial setup
attempts were logged under ignored `build/`.

Commands:

```powershell
python tools/configure.py --compiler ..\DQIX-Decomp\tools\mwccarm --dsd ..\DQIX-Decomp\dsd.exe usa
ninja delink objdiff
python tools/match_unit.py src/Graphics/VRAMDefaults
python tools/match_unit.py src/Graphics/Model3D
python tools/match_unit.py src/Graphics/VRAMImageInit
python tools/match_unit.py src/Graphics/VRAMPaletteAllocation
ninja rom check report sha1
```

Full acceptance completed all 181 Ninja steps. Module and symbol checks passed;
the final USA ROM SHA-1 was
`c7c3014c237900c8281289b8bc76a781969b6278`. The ARM7 baseline check also passed.

Open reviewer questions: none.
