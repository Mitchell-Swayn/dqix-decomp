#include <globaldefs.h>
ARM
extern "C" unsigned DisplayContext_GetGlobalInstance();
extern "C" void DisplayContext_IgnoreRequest(int,int,int);
extern "C" void DisplayContext_IgnoreTransitionParameter(unsigned,int);
extern "C" int DisplayContext_ReportRequestComplete();
// Original: arm9/ov003 @ 0x0215DC20; symbol: func_ov003_0215dc20; size: 0x98.
extern "C" void Graphics_AdvanceDisplayTransitionRequest(unsigned char* p){
 if(!p[0x3ec])return;
 if(!p[0x3ed]){
 unsigned context=DisplayContext_GetGlobalInstance();
 DisplayContext_IgnoreTransitionParameter(context,10);
 if(p[0x3f0])DisplayContext_IgnoreRequest(context,0x1f5,0);
 else DisplayContext_IgnoreRequest(context,0x200,1);
 p[0x3ed]++;
 }else if(p[0x3ed]==1){
 DisplayContext_GetGlobalInstance();
 if(DisplayContext_ReportRequestComplete()){p[0x3ec]=0;p[0x3ed]=0;}
 }
}
