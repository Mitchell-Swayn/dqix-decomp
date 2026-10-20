#include "Graphics/NSBXX/RenderCommands_Common.h"

// Render-command copy of the nine pivot forms also used by joint animation.
const PivotMatrixPositions RenderCommand6_UnknownRoleInitializedBytes[9] = {
    {4, 5, 7, 8},
    {3, 5, 6, 8},
    {3, 4, 6, 7},
    {1, 2, 7, 8},
    {0, 2, 6, 8},
    {0, 1, 6, 7},
    {1, 2, 4, 5},
    {0, 2, 3, 5},
    {0, 1, 3, 4},
};
typedef char RenderPivotPositionsSizeCheck[sizeof(RenderCommand6_UnknownRoleInitializedBytes) == 36 ? 1 : -1];
