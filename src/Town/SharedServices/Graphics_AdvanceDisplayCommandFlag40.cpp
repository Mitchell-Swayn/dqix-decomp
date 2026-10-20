#include <globaldefs.h>
ARM
extern "C" unsigned DisplayContext_GetGlobalInstance();
extern "C" void DisplayContext_IgnoreCommand(void*,int,int,int,int);
extern "C" int DisplayContext_ReportRequestComplete();
// Original: arm9/ov003 @ 0x021749F0; symbol: func_ov003_021749f0; size: 0x90.
extern "C" void Graphics_AdvanceDisplayCommandFlag40(unsigned char* p){
 if(*(unsigned short*)(p+0x1046)&0x40){
 if(p[0x1041]==0){
 DisplayContext_IgnoreCommand((void*)DisplayContext_GetGlobalInstance(),0x1fb,0x66,0,0);
 p[0x1041]++;
 }else if(p[0x1041]==1){
 DisplayContext_GetGlobalInstance();
 if(DisplayContext_ReportRequestComplete()){
 *(unsigned short*)(p+0x1046)&=~0x40;
 p[0x1041]=0;
 }
 }
 }
}
