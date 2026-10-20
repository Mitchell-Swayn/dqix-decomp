#include <globaldefs.h>
ARM
// Original data: arm9/ov027 @ 0x21dd920; symbol: data_ov027_021dd920.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov027.md.
extern "C" unsigned AdvanceSendBlock_UnknownRoleZeroInitializedStorage;
// Original data: arm9/ov027 @ 0x21e33ec; symbol: data_ov027_021e33ec.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov027.md.
extern "C" unsigned char *MBRegisterFile_UnknownRoleZeroInitializedStorage_Variant2;
struct SendBlockSlot { unsigned char pad[0x1d48]; unsigned short block,acknowledged,children; unsigned char rest[4]; unsigned char active; };
// Original: arm9/ov027 @ 0x021D9D5C; symbol: func_ov027_021d9d5c; size: 0x7C.
// Advances the selected send block toward the acknowledged block with a two-block window.
extern "C" void AdvanceSendBlock(unsigned slot)
{
    unsigned short current,acknowledged;
    if(!(AdvanceSendBlock_UnknownRoleZeroInitializedStorage&(1<<slot)))return;
    SendBlockSlot *s=(SendBlockSlot*)(MBRegisterFile_UnknownRoleZeroInitializedStorage_Variant2+slot*0x5d4);
    if(s->active && s->children) {
        current=s->block; acknowledged=s->acknowledged;
        
        if(acknowledged<=current && current<=acknowledged+2) s->block=current+1;
        else s->block=acknowledged;
    }
}
