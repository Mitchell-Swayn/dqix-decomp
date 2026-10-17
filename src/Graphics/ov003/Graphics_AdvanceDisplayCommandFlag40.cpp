#include <globaldefs.h>
ARM
extern "C" unsigned Object_ReadGlobalDisplayContextWord();
extern "C" void DisplayContext_IgnoreCommand(void*,int,int,int,int);
extern "C" int ReturnOne_Main02094B4C();
// Original: arm9/ov003 @ 0x021749F0; symbol: func_ov003_021749f0; size: 0x90.
extern "C" void Graphics_AdvanceDisplayCommandFlag40(unsigned char* p){
 if(*(unsigned short*)(p+0x1046)&0x40){
 if(p[0x1041]==0){
 DisplayContext_IgnoreCommand((void*)Object_ReadGlobalDisplayContextWord(),0x1fb,0x66,0,0);
 p[0x1041]++;
 }else if(p[0x1041]==1){
 Object_ReadGlobalDisplayContextWord();
 if(ReturnOne_Main02094B4C()){
 *(unsigned short*)(p+0x1046)&=~0x40;
 p[0x1041]=0;
 }
 }
 }
}
