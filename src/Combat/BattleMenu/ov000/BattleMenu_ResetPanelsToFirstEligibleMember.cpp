#include <globaldefs.h>
ARM
struct State;
extern "C" void Window_PopCanvasesAndResetSelection(State*,int);
extern "C" void* memset(void*,int,unsigned);
extern "C" void TextCanvas_ResetLayoutAndDisplayFlags(char*);
extern "C" int BattleMenu_HasCommandBlockingStatus(char*);
// Original: arm9/ov000 @ 0x02174C14; symbol: BattleMenu_ResetPanelsToFirstEligibleMember; size: 0xF4.
// Clears menu mode slots and positions its canvas at the first eligible record.
extern "C" void BattleMenu_ResetPanelsToFirstEligibleMember(char* self){
 Window_PopCanvasesAndResetSelection((State*)(self+0x188),1);
 memset(self+0x1d60,0,8);self[0x1d68]=0;
 *(self+*(signed char*)(self+0x1d68)+0x1d60)=1;
 char* record;
 for(int i=0;i<4;++i){
 record=self+0x958+*(signed char*)(self+0x6c+i)*0x448;
 if(*(int*)(record+0x4c)<0)continue;
 if(!*(short*)(record+0xc))continue;
 if(BattleMenu_HasCommandBlockingStatus(record))continue;
 if(!*(unsigned char*)(record+0x87))continue;
 char* canvas=self+0x284;int x=*(int*)(record+0x44);int y=*(int*)(record+0x48);
 TextCanvas_ResetLayoutAndDisplayFlags(canvas);
 *(short*)(canvas+0xac)=(x>>3)+9;*(short*)(canvas+0xae)=y>>3;*(short*)(canvas+0xc2)=0;
 *(unsigned short*)(self+0x1d72)|=2;return;
 }
}
