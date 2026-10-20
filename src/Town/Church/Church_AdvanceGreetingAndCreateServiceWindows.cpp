#include <globaldefs.h>
ARM
extern "C" int Text_AppendFormatString(...);
extern "C" int TextContext_GetSharedInstance(...);
extern "C" int ResourceStringTable_GetTextByKey(...);
extern "C" int Church_CreatePartyStatusWindow(...);
extern "C" int Window_SetCanvasDisplayAttribute(...);
extern "C" int _ZN9GameState11GetInstanceEv(...);
extern "C" int _ZNK9GameState21IsMorningDayOrEveningEv(...);
extern "C" int Church_StartConfiguredMessage(...);
extern "C" int Church_CreateGoldWindow(...);
extern "C" int Church_CreateServiceOptionWindow(...);
extern "C" int Church_CreatePartyStatusWindow(...);
extern "C" void* memcpy(void*,const void*,unsigned);extern "C" void* memset(void*,int,unsigned);

#define P(p,o) (*(char**)((char*)(p)+(o)))
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define C(x) ((char*)(x))
// Original: arm9/ov003 @ 0x02159B20; symbol: AppendDayNightTextAndAdvanceReadyLayoutState.
extern "C" void Church_AdvanceGreetingAndCreateServiceWindows(char* self){
char* layout=C(TextContext_GetSharedInstance());unsigned phase=B(self,0x580);if(phase==0){if(B(self,0x59d))return;int day=_ZNK9GameState21IsMorningDayOrEveningEv(_ZN9GameState11GetInstanceEv());int key=1000;if(day==0)key++;Text_AppendFormatString(P(self,124),ResourceStringTable_GetTextByKey(self+100,key));W(layout,0x998)=1;Church_StartConfiguredMessage(self,P(self,124));B(self,0x580)++;}if(phase==1&&!B(self,0x59d)&&W(layout,0x9a0)==3){Church_CreateGoldWindow(self);Church_CreatePartyStatusWindow(self);Church_CreateServiceOptionWindow(self);Window_SetCanvasDisplayAttribute(self+244,0,0);Window_SetCanvasDisplayAttribute(self+244,1,0);Window_SetCanvasDisplayAttribute(self+244,2,0);B(self,0x588)=2;B(self,0x580)=0;}
}
