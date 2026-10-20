#include <globaldefs.h>
ARM
extern "C" void DisableInterruptsAndHaltForever(void);
struct SegmentOutput { unsigned receive,load,length; unsigned arm7:1; unsigned other:31; };
struct BootHeader { unsigned char pad[0x28]; unsigned arm9Address,arm9Size; unsigned char gap[8]; unsigned arm7Address,arm7Size; };
// Original: arm9/ov027 @ 0x021DA690; symbol: func_ov027_021da690; size: 0x178.
// Builds ARM9, ARM7 or header segment metadata and validates permissible transfer destinations.
extern "C" void MBi_SetSegmentInfo(BootHeader *header,unsigned *type,SegmentOutput *out,unsigned *receiveCursor)
{
    unsigned invalid,end,address;
    switch(*type) {
    case 0:
        if(header->arm9Address>=0x02000000 && header->arm9Address<0x022c0000 && header->arm9Address+header->arm9Size<=0x022c0000) {
            out->length=header->arm9Size;
            out->receive=out->load=header->arm9Address;
            out->arm7=0;
        } else DisableInterruptsAndHaltForever();
        break;
    case 1: {
        address=header->arm7Address;
        unsigned length=header->arm7Size;
        invalid=0;
        unsigned relocate=0;
        end=address+length;
        if(address>=0x02000000 && address<0x023fe800) {
            if(end<=0x02300000) {}
            else if(end<0x023fe800 && length<=0x40000)relocate=1;
            else invalid=1;
        } else if(address>=0x037f8000 && address<0x0380f000) {
            if(end<=0x0380f000)relocate=1;
            else invalid=1;
        } else invalid=1;
        if(invalid==1)DisableInterruptsAndHaltForever();
        out->length=header->arm7Size;
        out->load=header->arm7Address;
        if(!relocate)out->receive=out->load;
        else {
            out->receive=*receiveCursor;
            *receiveCursor+=out->length;
        }
        out->arm7=1;
        break;
    }
    case 2:
        out->length=0x160;
        out->receive=out->load=0x027ffe00;
        out->arm7=0;
        break;
    }
}
