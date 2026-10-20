#include <globaldefs.h>
ARM
extern "C" int Window_ClearResourceBuffers(...);
extern "C" int Graphics_ResetCountedThirtyTwoByteTransfers(...);
extern "C" int Graphics_UpdateSelectedEntryPositionAndVisibility(...);
extern "C" int Ov003_ConfigureIndexedRecord(...);
extern "C" int Ov003_ConfigureVisibleRecord(...);
extern "C" int ProcessAllTwoHundredTwentyFourByteRecordsWhenBothPointersSet(...);
extern "C" int Zone3D_GetMainInstance(...);
extern "C" int Window_FillCanvasRectanglesOnAlternateLayer(...);
extern "C" int Ov003_ConfigureIndexedRecord(...);
extern "C" int Ov003_ConfigureVisibleRecord(...);
extern "C" int Graphics_UpdateSelectedEntryPositionAndVisibility(...);
extern "C" int GuestList_UpdateActionSelectionMarkers(...);
extern "C" void* memcpy(void*,const void*,unsigned);extern "C" void* memset(void*,int,unsigned);

#define P(p,o) (*(char**)((char*)(p)+(o)))
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define C(x) ((char*)(x))
// Original: arm9/ov003 @ 0x0217019C; symbol: RefreshActiveListResourcesAndConfigureEightRows.
extern "C" void GuestList_RefreshWindowAndRowIcons(char* self){
if(!P(self,60))return;int state=*(signed char*)(self+1);if(state==0||state==1||state==7)return;Window_ClearResourceBuffers(P(self,60));ProcessAllTwoHundredTwentyFourByteRecordsWhenBothPointersSet(P(self,60));Window_FillCanvasRectanglesOnAlternateLayer(P(self,60),2,1,1);Graphics_ResetCountedThirtyTwoByteTransfers(P(self,60));Graphics_UpdateSelectedEntryPositionAndVisibility(self);GuestList_UpdateActionSelectionMarkers(self);Ov003_ConfigureVisibleRecord(self);state=*(signed char*)(self+1);switch(state){case 0:case 1:return;};Zone3D_GetMainInstance();int y=46,id=64;for(int i=0;i<8;){int key=W(self+i*4,0x3b0);if(key<0)return;Ov003_ConfigureIndexedRecord(self+104,key+9,81,y,id,2,3);id++;y+=16;i++;}
}
