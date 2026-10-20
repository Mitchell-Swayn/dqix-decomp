struct WindowCanvasOwner;
struct WindowCanvasRecord;
#include <globaldefs.h>
ARM
extern "C" int TextCanvas_HasActiveTilemap(...);
extern "C" int GameResources_GetInstance(...);
extern "C" void* Field_GetSharedSubscreenInstance(void*);
extern "C" WindowCanvasRecord* Window_GetSelectedTextCanvas(WindowCanvasOwner*);
extern "C" int SpriteAnimation_SubmitAllTrackFrames(...);
extern "C" int Window_IsVisible(...);
extern "C" void Resource_ResetAndPositionFirstEntry(void*,short,short);
extern "C" int Selection_ReadEnabledIndexFromControl(void*);
extern "C" void* memcpy(void*,const void*,unsigned);extern "C" void* memset(void*,int,unsigned);extern "C" char* strcpy(char*,const char*);extern "C" int sprintf(char*,const char*,...);

#define P(p,o) (*(char**)((char*)(p)+(o)))
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define C(x) ((char*)(x))
// Original: arm9/ov005 @ 0x0215A7EC; symbol: PositionSharedResourceAtSelectionOrFallbackRow.
extern "C" void EquipmentMenu_PositionActionCursor(char*self){
char*record=C((int)Window_GetSelectedTextCanvas((WindowCanvasOwner*)(self+3812)));if(record){int mode=B(record,196);if(P(self,3684)&&Window_IsVisible(P(self,3684)))SpriteAnimation_SubmitAllTrackFrames(P(self,3688));else if(mode==1&&TextCanvas_HasActiveTilemap(record)){short x=S(record,188)+(short)(S(record,172)<<3);short y=S(record,190)+(short)(S(record,174)<<3);if(mode==2){x=212;int index=Selection_ReadEnabledIndexFromControl(self+3812);if(index==0)y=87;else if(index==1)y=101;}Resource_ResetAndPositionFirstEntry(Field_GetSharedSubscreenInstance(P(C(GameResources_GetInstance())+12288,1800)),(short)(x-8),(short)(y-2));}}if(!B(self+12288,3512)){short y=24*(short)*(volatile unsigned char*)(self+12288+3516)+4;Resource_ResetAndPositionFirstEntry(Field_GetSharedSubscreenInstance(P(C(GameResources_GetInstance())+12288,1800)),116,y);}
}
