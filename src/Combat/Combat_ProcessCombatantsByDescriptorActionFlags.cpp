#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* _ZN9GameState19GetCombatantByIndexEi(void*, int);
extern "C" void ObjectPool_BindSlotToResourceKey(void*, int, int);
// Original: arm9/main @ 0x020D738C; symbol: Combat_ProcessCombatantsByDescriptorActionFlags; size: 0x118.
extern "C" void Combat_ProcessCombatantsByDescriptorActionFlags(void* self) {
    void* state = _ZN9GameState11GetInstanceEv();
    for (int slot = 0; slot < 12; ++slot) {
        int combatantId = slot;
        if (slot > 3) combatantId += 0xbc;
        void* combatant = _ZN9GameState19GetCombatantByIndexEi(state, combatantId);
        if (!combatant) continue;
        unsigned char* descriptor = *(unsigned char**)((char*)combatant + 0x138);
        unsigned int flags = *(unsigned int*)(descriptor + 0x14) & 0xffffu;
        unsigned int subtype = ((unsigned int)*(unsigned short*)(descriptor + 0x22) << 26) >> 28;
        unsigned short header = *(unsigned short*)descriptor;
        if (flags & 1) continue;
        if (!header) continue;
        if (flags & 2) ObjectPool_BindSlotToResourceKey(self, combatantId, 0);
        else if (flags & 0x10) ObjectPool_BindSlotToResourceKey(self, combatantId, 1);
        else if (flags & 8) ObjectPool_BindSlotToResourceKey(self, combatantId, 3);
        else if (flags & 0x20) ObjectPool_BindSlotToResourceKey(self, combatantId, 4);
        else if ((flags & 0x80000) && subtype == 6) ObjectPool_BindSlotToResourceKey(self, combatantId, 2);
    }
}
