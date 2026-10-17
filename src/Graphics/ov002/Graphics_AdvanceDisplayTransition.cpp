#include <globaldefs.h>
ARM
extern "C" unsigned Object_ReadGlobalDisplayContextWord();
extern "C" void BackgroundLoader_CancelEightTasksAndResetState(int);
extern "C" void DisplayContext_IgnoreTransitionParameter(unsigned,int);
extern "C" void DisplayContext_IgnoreCommand(unsigned,int,int,int,int);
extern "C" int ReturnOne_Main02094B4C(unsigned);
// Original: arm9/ov002 @ 0x021561B0; symbol: func_ov002_021561b0; size: 0x9C.
extern "C" void Graphics_AdvanceDisplayTransition(char* self) {
if(!(*(unsigned*)(self+0x247c)&2)) return;
unsigned char step=*(unsigned char*)(self+0x247a);
if(step==0) {
unsigned context=Object_ReadGlobalDisplayContextWord();
BackgroundLoader_CancelEightTasksAndResetState(context);
DisplayContext_IgnoreTransitionParameter(context,12);
DisplayContext_IgnoreCommand(context,100,0x208,0,0);
++*(unsigned char*)(self+0x247a);
}
else if(step==1) {
if(ReturnOne_Main02094B4C(Object_ReadGlobalDisplayContextWord())) {
*(unsigned*)(self+0x247c)&=~2;
self[0x247a]=0;
}
}
}
