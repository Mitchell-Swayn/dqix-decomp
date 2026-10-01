#include "World/Zone3D.h"

extern "C"
{
    void func_020177d4(Zone3D*, Zone3D_BMDJStruct*, SafeAllocator*);
}

bool Zone3D::BuildBMDJObjects(Zone3D_BMDJStruct* group)
{
    int count = group->scriptData_.counter_4;
    SafeAllocator* allocator = pAllocator_68_;
    group->ptr_40 = (Zone3D_BMDJStruct::ObjectEntry*)allocator->Allocate(count * sizeof(Zone3D_BMDJStruct::ObjectEntry));
    if (!group->ptr_40) return false;
    for (int i = 0; i < count; ++i)
    {
        Zone3D_BMDJStruct::StructSizeC* definition = group->scriptData_.GetStructC(i);
        Zone3D_BMDJStruct::ObjectEntry* entry = &group->ptr_40[i];
        ResetBMDJObjectEntry(entry);
        if (!definition) continue;
        if (definition->name[3] == 'A')
            LoadBMDJCollision(entry, definition);
        else if (definition->unk_2 & 0x10)
            LoadBMDJAnimatedObject(entry, definition);
        else
            LoadBMDJModel(group, entry, definition);
    }
    func_020177d4(this, group, allocator);
    return true;
}
