#include <globaldefs.h>
ARM
struct Eight {short values[8];};struct Triple {int x,y,z;};
extern "C" int BattleMenu_ConfigureGlobalCommandSelection(...);
extern "C" char* TextContext_GetSharedInstance(...);
extern "C" void* memset(...);
extern "C" int Window_PushTextCanvas(...);
extern "C" int Text_AppendIndexedObjectNames(...);
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define U(p,o) (*(unsigned*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
// Original: arm9/ov000 @ 0x02177BF0; symbol: Graphics_FormatObjectPositionedNameWindow; size: 0xc8.
// Graphics FormatObjectPositionedNameWindow from listed field operations and calls.
extern "C" void Graphics_FormatObjectPositionedNameWindow(char* self,char* object,int a,int b){if(!object)return;int x=W(object,0x44),y=W(object,0x48);BattleMenu_ConfigureGlobalCommandSelection(self,a,b);char* window=self+0x188;H(window,0xa0)=21;H(window,0xa2)=7;H(window,0xa4)=(x>>3)+9;H(window,0xa6)=(y>>3)+1;H(window,0xa8)=12;H(window,0xaa)=5;H(window,0xac)=10;H(window,0xae)=12;B(window,0xb1)=5;void* text=P(TextContext_GetSharedInstance(),0x5c);memset(text,0,2400);Text_AppendIndexedObjectNames(self,text);Window_PushTextCanvas(self+0x188,text,0,0,0,1,0,0);}
