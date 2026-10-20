#include <globaldefs.h>
ARM
extern "C" unsigned int DisplayContext_GetGlobalInstance();
extern "C" void DisplayContext_IgnoreCommand(void*,int,int,int,int);
extern "C" int DisplayContext_ReportRequestComplete(unsigned int);
// Original: arm9/ov003 @ 0x0216D84C; symbol: func_ov003_0216d84c; size: 0x88.
extern "C" void AdvanceFlaggedDisplayCommandState(unsigned char* p){
if(p[0x13ec]&1){
if(*(short*)(p+8)==0){DisplayContext_IgnoreCommand((void*)DisplayContext_GetGlobalInstance(),0x1f5,0x66,0,0);*(short*)(p+8)=1;}
else if(*(short*)(p+8)==1){if(DisplayContext_ReportRequestComplete(DisplayContext_GetGlobalInstance())){p[0x13ec]&=~1;*(short*)(p+8)=-1;}}
}
}
