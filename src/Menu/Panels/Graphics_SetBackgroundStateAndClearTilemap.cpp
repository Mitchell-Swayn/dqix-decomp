#include <globaldefs.h>
ARM
extern "C" void Menu_RemoveStoredBackgroundTask(int*);
extern "C" unsigned GetSubBG0ScreenBase();
extern "C" unsigned GetMainBG2ScreenBase();
extern "C" void* memset(void*,int,unsigned);
// Original: arm9/ov023 @ 0x021DCBA4; symbol: func_ov023_021dcba4; size: 0xB4.
extern "C" void Graphics_SetBackgroundStateAndClearTilemap(char* self,int value) {
if(!*(unsigned char*)(self+0x776)) {*(short*)(self+0x772)=value;return;}
if(!(*(unsigned short*)(self+0x774)&4)) return;
Menu_RemoveStoredBackgroundTask((int*)(self+0x734));
for(int i=0;i<7;++i) Menu_RemoveStoredBackgroundTask((int*)(self+0x738)+i);
*(short*)(self+0x770)=value;
*(short*)(self+0x772)=*(short*)(self+0x770);
*(unsigned*)(self+0x754)=0;
*(unsigned short*)(self+0x774)|=9;
if(*(signed char*)(self+0x77c)==1) memset((void*)GetSubBG0ScreenBase(),0,0x800);
else memset((void*)GetMainBG2ScreenBase(),0,0x800);
}
