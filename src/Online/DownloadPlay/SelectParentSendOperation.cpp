#include <globaldefs.h>
ARM
extern "C" void MIi_CpuClear16(int,void*,unsigned);
extern "C" int MBi_CommParentSendMsg(unsigned,unsigned);
extern "C" int MBi_CommParentSendDLFileInfo(unsigned);
extern "C" int MBi_CommParentSendBlock(void);
// Original data: arm9/ov027 @ 0x21e33ec; symbol: data_ov027_021e33ec.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov027.md.
extern "C" unsigned char *MBRegisterFile_UnknownRoleZeroInitializedStorage_Variant2;
struct ParentSendContext { unsigned char pad[0x14e8]; unsigned states[15]; };
// Original: arm9/ov027 @ 0x021D9BDC; symbol: func_ov027_021d9bdc; size: 0x180.
// Prioritizes outbound operations using child-state membership masks.
extern "C" void SelectParentSendOperation(void)
{
    unsigned short masks[5];
    MIi_CpuClear16(0,masks,10);
    for(unsigned short child=1;child<=15;child++) {
        switch(((ParentSendContext*)MBRegisterFile_UnknownRoleZeroInitializedStorage_Variant2)->states[child-1]) {
        case 0: case 1: case 3: case 6: case 7: case 9: case 10: break;
        case 2: masks[0]|=1<<child;break;
        case 5: masks[1]|=1<<child;break;
        case 4: masks[2]|=1<<child;break;
        case 8: masks[3]|=1<<child;break;
        case 11: masks[4]|=1<<child;break;
        }
    }
    int result;
    if(masks[3]) result=MBi_CommParentSendMsg(5,masks[3]);
    else if(masks[0]) result=MBi_CommParentSendMsg(1,masks[0]);
    else if(masks[4]) result=MBi_CommParentSendMsg(6,masks[4]);
    else if(masks[2]) result=MBi_CommParentSendMsg(2,masks[2]);
    else if(masks[1]) result=MBi_CommParentSendDLFileInfo(masks[1]);
    else result=MBi_CommParentSendBlock();
    if(result==21) MBi_CommParentSendMsg(0,65535);
}
