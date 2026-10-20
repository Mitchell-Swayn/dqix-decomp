#include <globaldefs.h>
ARM
extern "C" {char* TextContext_GetSharedInstance();void Resource_BuildActiveRecordPagePointers(void*);void World_PartitionAndSortKindNineAndTenEntries(void*);void Graphics_CacheFourMainBackgroundControlsOnce(void*);void* GameResources_GetInstance();unsigned GameResources_GetSecondaryFlags(void*);void G3X_SetClearColor(unsigned,unsigned,unsigned short,unsigned,int);}
// Original: arm9/ov003 @ 0x0216E200; symbol: InitializeCaptureBackgroundState; size: 0xa4.
// Caches main background controls, selects layers7 and initializes capture control pair.
extern "C" void GuestList_InitializeCapturedBackground(char* self){if(self[2])return;*(int*)(self+24)=*(int*)(TextContext_GetSharedInstance()+0x5c);Resource_BuildActiveRecordPagePointers(self);World_PartitionAndSortKindNineAndTenEntries(self);Graphics_CacheFourMainBackgroundControlsOnce(self+0x48);volatile unsigned* display=(volatile unsigned*)0x04000000;*(unsigned*)(self+0x5c)=(*display&0x1f00)>>8;*display=(*display&~0x1f00)|0x700;*(unsigned*)(self+0x174)=GameResources_GetSecondaryFlags(GameResources_GetInstance());G3X_SetClearColor(0,0,0x7fff,0,0);self[1]=1;self[2]=0;*(int*)(self+0x16c)=0;}
