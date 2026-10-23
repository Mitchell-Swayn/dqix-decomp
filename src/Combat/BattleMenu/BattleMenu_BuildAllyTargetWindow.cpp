#include <globaldefs.h>
ARM
#pragma force_active on
#define WORD(p,o) (*(int*)((p)+(o)))
#define HALF(p,o) (*(short*)((p)+(o)))
#define UHALF(p,o) (*(unsigned short*)((p)+(o)))
#define BYTE(p,o) (*(unsigned char*)((p)+(o)))
#define SBYTE(p,o) (*(signed char*)((p)+(o)))
#define PTR(p,o) (*(char**)((p)+(o)))
extern "C" {
void BattleMenu_ConfigureActorCommandSelection(void*,int,int);
unsigned TextContext_GetSharedInstance();
void* memset(void*,int,unsigned);
void BattleMenu_AppendAllyTargetNames(unsigned char*,signed char*,int,char*);
void Window_PushTextCanvas(void*,void*,int,int,int,int,int,int);
}
// Original: arm9/ov000 @ 0x0217992C; symbol: func_ov000_0217992c; size: 0xE8.
// Positions the ally target canvas using actor coordinates and submits the formatted shared text buffer.
extern "C" void BattleMenu_BuildAllyTargetWindow(char* self,char* actor,int mode,int option) {
    if(!actor) return;
    int x=WORD(actor,0x44),y=WORD(actor,0x48);
    BattleMenu_ConfigureActorCommandSelection(actor,mode,option);
    char* window=self+0x188;
    if(SBYTE(self,0x78)==3) {HALF(window,0xa0)=12;HALF(window,0xa2)=6;}
    else {HALF(window,0xa0)=12;HALF(window,0xa2)=1;}
    HALF(window,0xa4)=(x>>3)+20;
    HALF(window,0xa6)=y>>3;
    HALF(window,0xa8)=12;HALF(window,0xaa)=8;
    HALF(window,0xac)=10;HALF(window,0xae)=11;
    BYTE(window,0xb1)=18;
    char* text=PTR((char*)TextContext_GetSharedInstance(),0x5c);
    memset(text,0,0x960);
    BattleMenu_AppendAllyTargetNames((unsigned char*)self,(signed char*)actor,mode,text);
    Window_PushTextCanvas(window,text,0,1,0,1,0,0);
}
