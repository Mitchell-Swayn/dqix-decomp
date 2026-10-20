#include "Graphics/NSBXX/RenderCommands_Common.h"

// Mutable command packets: pop, select matrix mode, load identity/translation,
// then scale. Translation and scaling are filled by the rendering callers.
Struct_020f1d78 RenderCommand7_UnknownRoleInitializedBytes = {
    0x1b171012, 1, 2,
    {{{4096, 0, 0}, {0, 4096, 0}, {0, 0, 4096}, {0, 0, 0}}},
    {0, 0, 0}
};
Struct_020f1d78 RenderCommand8_UnknownRoleInitializedBytes = {
    0x1b171012, 1, 2,
    {{{4096, 0, 0}, {0, 4096, 0}, {0, 0, 4096}, {0, 0, 0}}},
    {0, 0, 0}
};
typedef char MatrixCommandPacketSizeCheck[sizeof(Struct_020f1d78) == 72 ? 1 : -1];
