#include <globaldefs.h>
ARM
extern "C" int MBi_SetMPData(int,void*,unsigned,unsigned,unsigned short);
// Original data: arm9/ov027 @ 0x21e33e0; symbol: data_ov027_021e33e0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov027.md.
extern "C" unsigned char MBEnd_UnknownRoleZeroInitializedStorage[];
extern "C" void MBi_HandleChildWirelessEvent(void);
// Original: arm9/ov027 @ 0x021DCF44; symbol: func_ov027_021dcf44; size: 0xE0.
// Sends parent communication data through the fixed MP port according to the active mode.
extern "C" int MBi_SendMP(void *data,unsigned length,unsigned destinations)
{
    unsigned short packetLength=length;
    unsigned short childMask=destinations;
    unsigned char *context=*(unsigned char**)(MBEnd_UnknownRoleZeroInitializedStorage+8);
    if(*(unsigned short*)(context+0x528)==0 || *(unsigned short*)(context+0x526)==1)return 1;
    switch(*(unsigned short*)(context+0x524)) {
    case 1: {
        unsigned short status=*(unsigned short*)(context+0x52c)==0?0x3e8:0;
        int result=MBi_SetMPData(*(int*)(context+0x508),data,packetLength,status,childMask);
        if(result==2) {
            (*(volatile unsigned char**)(MBEnd_UnknownRoleZeroInitializedStorage+8))[0x50c]=1;
        }
        if(result==2)result=0;
        return result;
    }
    case 2: {
        int result=MBi_SetMPData((int)MBi_HandleChildWirelessEvent,data,packetLength,0,childMask);
        if(result==2) {
            (*(volatile unsigned char**)(MBEnd_UnknownRoleZeroInitializedStorage+8))[0x50c]=1;
        }
        if(result==2)result=0;
        return result;
    }
    default:return 1;
    }
}
