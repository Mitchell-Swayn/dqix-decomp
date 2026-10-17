#include "World/Zone3D.h"
#include "World/LootableContainer.h"

extern const Vector3i data_020e6e08 = { 0, 0, -0x1000 };
extern const Vector3i data_020e6e14 = { 0, 0x1000, 0 };
extern "C"
{
    void Graphics_InitializeGeometryAndDisplayState();
    void Graphics_ResetGeometryMatrixStackState();
    void BuildViewMatrixAndOptionallyApply(const Vector3i*, const Vector3i*, const Vector3i*, int, void*);
    void Geometry_BuildAndOptionallyApplyProjectionMatrix(int, int, int, int, int, int, int, int, void*);
    void func_02015ef4(Zone3D*, int);
}

// Original: arm9/main @ 0x020158CC; symbol: _ZN6Zone3D15DrawChestModelsEv; size: 0xF4.
void Zone3D::DrawChestModels()
{
    if (!LootableContainerManager::GetMainInstance() || !pUnknownStruct_8_) return;
    Vector3i target = data_020e6e08;
    Vector3i eye = { 0, 0, 0 };
    Vector3i up = data_020e6e14;
    Graphics_InitializeGeometryAndDisplayState();
    Graphics_ResetGeometryMatrixStackState();
    *(volatile unsigned int*)0x04000440 = 0;
    BuildViewMatrixAndOptionallyApply(&eye, &up, &target, 1, NULL);
    Geometry_BuildAndOptionallyApplyProjectionMatrix(0, 0xc0000, 0, 0x100000, -0x400000, 0x400000, 0x400000, 1, NULL);
    *(volatile unsigned int*)0x04000440 = 2;
    for (int i = 0; i < numChests_; ++i)
        func_02015ef4(this, i);
}
