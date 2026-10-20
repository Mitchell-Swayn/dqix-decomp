#pragma force_active on
// Preserve this original entry despite fallback objects supplying only weak references.
// Original: arm9/ov005 @ 0x02154da8; symbol: func_ov005_02154da8; size: 0x40.
// Resets the allocator at offset 0x26c and rebuilds the compact attribute table at 0x19ec.
extern "C" void _ZN13SafeAllocator5ResetEv(void*);
extern "C" void ZoneRecord_ResetCompactAttributeTable(void*);
extern "C" void ZoneRecord_BuildCompactAttributeTable(void*,void*,int,int);
extern "C" void EquipmentMenu_RebuildCompactItemAttributes(char* self,int a,int b) { _ZN13SafeAllocator5ResetEv(self+0x26c); ZoneRecord_ResetCompactAttributeTable(self+0x19ec); ZoneRecord_BuildCompactAttributeTable(self+0x19ec,self+0x26c,a,b); }
