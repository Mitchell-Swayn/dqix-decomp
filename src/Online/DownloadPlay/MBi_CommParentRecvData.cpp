#include <globaldefs.h>
ARM
extern "C" char *WirelessCommand_FindEnabledIdentifierInVariableStrideTable(char*,unsigned);
extern "C" void MBi_ProcessChildDownloadPacket(unsigned char*,unsigned);
// Original data: arm9/ov027 @ 0x21e33ec; symbol: data_ov027_021e33ec.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov027.md.
extern "C" unsigned char *MBRegisterFile_UnknownRoleZeroInitializedStorage_Variant2;
// Original data: arm9/ov027 @ 0x21dd920; symbol: data_ov027_021dd920.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov027.md.
extern "C" unsigned AdvanceSendBlock_UnknownRoleZeroInitializedStorage;
struct ReceiveSlot { unsigned char pad[0x1d4a]; unsigned short acknowledged; unsigned char gap[6]; unsigned char active; };
// Original: arm9/ov027 @ 0x021D9618; symbol: func_ov027_021d9618; size: 0xAC.
// Resets active-slot acknowledgements then dispatches valid nonempty child packets.
extern "C" void MBi_CommParentRecvData(char *table)
{
    for(unsigned short slot=0;slot<16;slot++) {
        ReceiveSlot *s=(ReceiveSlot*)(MBRegisterFile_UnknownRoleZeroInitializedStorage_Variant2+slot*0x5d4);
        if(s->active)s->acknowledged=0;
    }
    AdvanceSendBlock_UnknownRoleZeroInitializedStorage=0;
    for(unsigned short child=1;child<=15;child++) {
        unsigned char *packet=(unsigned char*)WirelessCommand_FindEnabledIdentifierInVariableStrideTable(table,child);
        if(packet && *(unsigned short*)packet!=65535 && *(unsigned short*)packet!=0)MBi_ProcessChildDownloadPacket(packet,child);
    }
}
