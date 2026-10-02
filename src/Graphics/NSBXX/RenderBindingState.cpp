#include "Graphics/NSBXX/RenderCommands_Common.h"

void MaterialBindProc(RenderCommandHandler*, int, NSBXXMaterial*, unsigned int);
void MeshDrawProc(RenderCommandHandler*, int, NSBXXMesh*, unsigned int);

// Mutable texture command arguments, material/mesh dispatch, and command-13 matrix.
Struct_020f1d08 data_020f1d08 = {
    0x2a, 0, 0x2a, 0,
    {MaterialBindProc, 0, 0, 0},
    {MeshDrawProc, 0, 0, 0},
    {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x10000, 0, 0, 0, 0, 0x10000}}
};
typedef char RenderBindingStateSizeCheck[sizeof(Struct_020f1d08) == 112 ? 1 : -1];
