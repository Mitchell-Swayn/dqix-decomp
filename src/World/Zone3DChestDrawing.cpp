#include "World/Zone3D.h"
#include "World/LootableContainer.h"

// Original data: arm9/main @ 0x20e6e08; symbol: data_020e6e08.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 000000000000000000f0ffff.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern const Vector3i Zone3DDrawChestModels_UnknownRoleInitializedBytes = { 0, 0, -0x1000 };
// Original data: arm9/main @ 0x20e6e14; symbol: data_020e6e14.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 000000000010000000000000.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern const Vector3i Zone3DDrawChestModels_UnknownRoleInitializedBytes_Variant2 = { 0, 0x1000, 0 };
extern "C"
{
    void Graphics_InitializeGeometryAndDisplayState();
    void Graphics_ResetGeometryMatrixStackState();
    void G3_LookAt(const Vector3i*, const Vector3i*, const Vector3i*, int, void*);
    void Geometry_BuildAndOptionallyApplyProjectionMatrix(int, int, int, int, int, int, int, int, void*);
    void Zone3D_UpdateChestOpeningAndLootDisplay(Zone3D*, int);
}

// Original: arm9/main @ 0x020158CC; symbol: _ZN6Zone3D15DrawChestModelsEv; size: 0xF4.
void Zone3D::DrawChestModels()
{
    if (!LootableContainerManager::GetMainInstance() || !pUnknownStruct_8_) return;
    Vector3i target = Zone3DDrawChestModels_UnknownRoleInitializedBytes;
    Vector3i eye = { 0, 0, 0 };
    Vector3i up = Zone3DDrawChestModels_UnknownRoleInitializedBytes_Variant2;
    Graphics_InitializeGeometryAndDisplayState();
    Graphics_ResetGeometryMatrixStackState();
    *(volatile unsigned int*)0x04000440 = 0;
    G3_LookAt(&eye, &up, &target, 1, NULL);
    Geometry_BuildAndOptionallyApplyProjectionMatrix(0, 0xc0000, 0, 0x100000, -0x400000, 0x400000, 0x400000, 1, NULL);
    *(volatile unsigned int*)0x04000440 = 2;
    for (int i = 0; i < numChests_; ++i)
        Zone3D_UpdateChestOpeningAndLootDisplay(this, i);
}
