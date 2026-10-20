# Ghidra analysis workspace

The USA Ghidra project is installed on Linux at:

`/home/swayn/Projects/Ghidra-MCP/projects/DQIX-USA.gpr`

It was imported from `/home/swayn/Projects/dqix-factory-v01`, the Linux checkout,
using the original USA ROM with SHA-1
`c7c3014c237900c8281289b8bc76a781969b6278`.
It contains ARM9 main with ITCM/DTCM, all 35 separate overlay programs,
and ARM7 with its runtime autoload mappings. Repository symbols and explicit
ARM9 ARM/Thumb modes were imported. Ghidra analysis is an aid to reconstruction,
not matching-source credit; object/module/ROM verification remains required.

Codex server names:

- Linux: `ghidra`, using the local Python bridge and plugin port 8082.
- This Windows device: `ghidra-dqix-linux`, using SSH to
  `desktop-2gjf44p-linux` and that same bridge.

Restart Codex to load newly registered servers. The plugin must have a program
open in CodeBrowser; setup leaves `ARM9_Main` open on Linux's virtual display
`:99`, so MCP works while the physical desktop is locked.

Setup details, import scripts, block hashes, limitations, and verification are in
`C:/Users/swayn/Projects/Ghidra-MCP/DQIX-SETUP.md`, with a copy in the Linux
Ghidra-MCP folder. Source changes after import do not update Ghidra automatically.
