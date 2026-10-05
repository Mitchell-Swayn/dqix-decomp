#include "World/Zone3D.h"
#include "World/LootableContainer.h"

extern const Vector3i data_020e6e08 = { 0, 0, -0x1000 };
extern const Vector3i data_020e6e14 = { 0, 0x1000, 0 };
extern "C"
{
    void func_020c52e8();
    void func_020c5414();
    void func_020c57d4(const Vector3i*, const Vector3i*, const Vector3i*, int, void*);
    void func_020c5770(int, int, int, int, int, int, int, int, void*);
    void func_02015ef4(Zone3D*, int);
}

void Zone3D::DrawChestModels()
{
    if (!LootableContainerManager::GetMainInstance() || !pUnknownStruct_8_) return;
    Vector3i target = data_020e6e08;
    Vector3i eye = { 0, 0, 0 };
    Vector3i up = data_020e6e14;
    func_020c52e8();
    func_020c5414();
    *(volatile unsigned int*)0x04000440 = 0;
    func_020c57d4(&eye, &up, &target, 1, NULL);
    func_020c5770(0, 0xc0000, 0, 0x100000, -0x400000, 0x400000, 0x400000, 1, NULL);
    *(volatile unsigned int*)0x04000440 = 2;
    for (int i = 0; i < numChests_; ++i)
        func_02015ef4(this, i);
}
