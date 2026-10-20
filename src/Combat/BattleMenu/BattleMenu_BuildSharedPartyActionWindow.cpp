struct WindowCanvasOwner;
struct WindowCanvasRecord;
#include <globaldefs.h>
ARM
#define W(p,o) (*(int*)((p)+(o)))
#define P(p,o) (*(unsigned char**)((p)+(o)))
#define H(p,o) (*(short*)((p)+(o)))
#define U(p,o) (*(unsigned short*)((p)+(o)))
extern "C" {void BattleMenu_UpdateSharedPartyActionDescriptionWindow(void*);void BattleMenu_ConfigureGlobalCommandSelection(void*,int,int);unsigned TextContext_GetSharedInstance();void* memset(void*,int,unsigned);void Graphics_AppendSelectableRecordNameList(char*,void*,char*);void Window_PushTextCanvas(void*,void*,int,int,int,int,int,int);WindowCanvasRecord* Window_FindActiveCanvasById(WindowCanvasOwner*,unsigned);}
// Original: arm9/ov000 @0x02179f94; symbol:Graphics_BuildSelectableNamePageAndAlignFollowingRecord; size:0x110.
// Builds selectable-name page and aligns following ready record below preceding record.
extern "C" void BattleMenu_BuildSharedPartyActionWindow(unsigned char* self,void* records,int value,int option){BattleMenu_UpdateSharedPartyActionDescriptionWindow(self);BattleMenu_ConfigureGlobalCommandSelection(self,value,option);unsigned char* owner=self+0x188;H(owner,0xa0)=22;H(owner,0xa2)=6;H(owner,0xa4)=5;H(owner,0xa6)=5;H(owner,0xa8)=12;H(owner,0xaa)=8;H(owner,0xac)=10;H(owner,0xae)=14;owner[0xb1]=23;unsigned char* text=P((unsigned char*)TextContext_GetSharedInstance(),0x5c);memset(text,0,2400);Graphics_AppendSelectableRecordNameList((char*)self,records,(char*)text);Window_PushTextCanvas(owner,text,0,1,0,1,0,0);unsigned char* next=(unsigned char*)Window_FindActiveCanvasById((WindowCanvasOwner*)(owner),24);if(next){H(next,0xc2)=0;unsigned char* previous=(unsigned char*)Window_FindActiveCanvasById((WindowCanvasOwner*)(owner),23);if(previous){volatile short* xField=(volatile short*)(previous+0xac);volatile short* yField=(volatile short*)(previous+0xae);volatile short* hField=(volatile short*)(previous+0xaa);int x=*xField,y=*yField,height=*hField;H(next,0xac)=x;H(next,0xae)=y+height;}}}
