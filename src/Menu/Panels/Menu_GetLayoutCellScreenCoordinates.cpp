#include <globaldefs.h>
ARM
extern "C" char* Menu_FindLayoutCellByKey(char*,int);
extern "C" short* FindGroupContainingSignedHalfword(char*,int);
extern "C" void AccumulateLinkedRecordOffsets(char*,int,short*,short*);
// Original: arm9/ov023 @ 0x021E2B5C; symbol: ReadMappedCoordinatesAndAccumulateOffsets; size: 0x80.
extern "C" void Menu_GetLayoutCellScreenCoordinates(char* self,int key,short* x,short* y){
if(!*(int*)(self+8)||!*(unsigned short*)(self+20)||!*(int*)(self+12)||!*(unsigned short*)(self+22))return;char* entry=Menu_FindLayoutCellByKey(self,key);if(!entry)return;*x=*(short*)(entry+4);*y=*(short*)(entry+6);short* link=FindGroupContainingSignedHalfword(self,key);if(!link)return;AccumulateLinkedRecordOffsets(self,*link,x,y);
}
