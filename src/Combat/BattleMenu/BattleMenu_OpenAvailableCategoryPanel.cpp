#include <globaldefs.h>
ARM
#pragma optimization_level 4
#pragma force_active on
extern "C" void BattleMenu_ConfigureGlobalCommandSelection(void*,int,int);
extern "C" unsigned TextContext_GetSharedInstance();
extern "C" void* memset(void*,int,unsigned);
extern "C" void BattleMenu_AppendAvailableCategoryPage(char*,char*);
extern "C" void Window_PushTextCanvas(void*,void*,int,int,int,int,int,int);
// Original: arm9/ov000 @ 0x02177E50; symbol: func_ov000_02177e50; size: 0xD8.
extern "C" void BattleMenu_OpenAvailableCategoryPanel(char* self,char* anchor,int value,int option) {
 if(!anchor) return;
 int x=*(int*)(anchor+0x44),y=*(int*)(anchor+0x48);
 BattleMenu_ConfigureGlobalCommandSelection(self,value,option);
 char* panel=self+0x188;
 *(short*)(panel+0xa0)=11;
 *(short*)(panel+0xa2)=9;
 *(short*)(panel+0xa4)=(x>>3)+9;
 *(short*)(panel+0xa6)=y>>3;
 *(short*)(panel+0xa8)=12;
 *(short*)(panel+0xaa)=8;
 *(short*)(panel+0xac)=10;
 *(short*)(panel+0xae)=13;
 panel[0xb1]=6;
 char* text;
 int count=*(int*)(panel+0x58);
 text=*(char**)((char*)TextContext_GetSharedInstance()+0x5c);
 memset(text,0,0x960);
 BattleMenu_AppendAvailableCategoryPage(self,text);
 Window_PushTextCanvas(panel,text,0,0,count>1,1,0,0);
}
