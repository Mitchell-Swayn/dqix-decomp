#include <globaldefs.h>
ARM
#include <std_library_functions.h>
extern "C" void Window_BindNextCanvasResourceByFormatAndLayer(void*,unsigned,unsigned);extern "C" void Graphics_InitializeFormattedStateValue(char*,void*);extern "C" void Window_PushTextCanvas(void*,void*,int,int,int,int,int,int);
// Original: arm9/ov003 @ 0x0215DDC0; symbol: InitializeFormattedMenuStateAndBindText; size: 0xAC.
// Initializes menu layout halfwords and state flags, formats the cleared text buffer and binds it.
extern "C" void InitializeFormattedMenuStateAndBindText(char* self){Window_BindNextCanvasResourceByFormatAndLayer(self+0x98,0,2);*(unsigned short*)(self+0x138)=11;*(unsigned short*)(self+0x13a)=2;*(unsigned short*)(self+0x13c)=20;*(unsigned short*)(self+0x13e)=0;*(unsigned short*)(self+0x140)=16;*(unsigned short*)(self+0x142)=2;*(unsigned short*)(self+0x144)=8;*(unsigned short*)(self+0x146)=8;self[0x14f]=8;self[0x149]=0;self[0x14d]=1;memset(*(void**)(self+0x7c),0,0x960);Graphics_InitializeFormattedStateValue(self,*(void**)(self+0x7c));Window_PushTextCanvas(self+0x98,*(void**)(self+0x7c),0,0,0,1,0,0);}
