#include <globaldefs.h>
ARM
extern "C" unsigned short* ReadGlobalValueAt020FB3F0();
extern "C" void Zone3D_SetBMDJInstanceVisibilityFlag(int,int,unsigned char);
extern "C" unsigned char data_020e9148[],data_020e9149[],data_020e914a[];
// Original: arm9/main @ 0x020AEA40; symbol: func_020aea40; size: 0xF4.
extern "C" void Zone3D_UpdateThreeIndexedInstancesInMatchingZone(unsigned index,int mode) {
 if(index<=3){if(*ReadGlobalValueAt020FB3F0()!=0x164a)return;}
 else {if(index<4)return;if(index>7)return;if(*ReadGlobalValueAt020FB3F0()!=0x21ff)return;}
 if(mode==0){int offset=index*3;Zone3D_SetBMDJInstanceVisibilityFlag(1,0,data_020e9148[offset]);Zone3D_SetBMDJInstanceVisibilityFlag(1,0,data_020e9149[offset]);Zone3D_SetBMDJInstanceVisibilityFlag(1,0,data_020e914a[offset]);}
 else {int offset=index*3;Zone3D_SetBMDJInstanceVisibilityFlag(0,0,data_020e9148[offset]);Zone3D_SetBMDJInstanceVisibilityFlag(0,0,data_020e9149[offset]);Zone3D_SetBMDJInstanceVisibilityFlag(0,0,data_020e914a[offset]);}
}
