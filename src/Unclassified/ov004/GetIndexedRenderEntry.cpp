struct RenderEntry { unsigned char bytes[0x28]; };
struct RenderEntryOwner { unsigned char pad[0x40]; RenderEntry* entries; unsigned char pad2[10]; unsigned short count; };
// Original: arm9/ov004 @ 0x0215E438; symbol: func_ov004_0215e438; size: 0x28.
extern "C" RenderEntry* GetIndexedRenderEntry(RenderEntryOwner* owner,unsigned index) { RenderEntry* result=0; if(owner->entries && index<owner->count)result=owner->entries+index; return result; }
