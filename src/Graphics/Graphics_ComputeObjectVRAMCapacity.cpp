#include <globaldefs.h>
ARM
#pragma optimize_for_size off
#include <System/VRAM.h>
// Original: arm9/main @ 0x020937F0; symbol: func_020937f0; size: 0xDC.
extern "C" int Graphics_ComputeObjectVRAMCapacity(int sub){
    int capacity=0;
    if(!sub){
        switch(GetMainObjVRAMBanks()){
        case 0:capacity=0;break;
        case 0x20:case 0x40:capacity=0x10;break;
        case 0x10:capacity=0x40;break;
        case 0x30:case 0x50:capacity=0x50;break;
        case 1:case 2:capacity=0x80;break;
        case 3:capacity=0x100;break;
        case 0x60:capacity=0x20;break;
        case 0x70:capacity=0x60;break;
        }
    }else{
        switch(GetSubObjVRAMBanks()){
        case 0:break;
        case 8:capacity=0x80;break;
        case 0x100:capacity=0x10;break;
        }
    }
    return capacity<<10;
}
