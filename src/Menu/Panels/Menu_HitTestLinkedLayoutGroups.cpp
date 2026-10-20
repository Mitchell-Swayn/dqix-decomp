#include <globaldefs.h>
ARM
// Original data: arm9/main @ 0x2114e54; symbol: data_02114e54.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 112 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char Main_UnknownRoleZeroInitializedStorage_Variant4[];
struct StateRecord { unsigned char unknown00[0x20]; unsigned short first; unsigned short second; unsigned short useWideValues; unsigned char unknown26[0x12]; unsigned int wideFirst; unsigned int wideSecond; };
extern "C" unsigned int ReadSelectedCoordinatePair(const StateRecord*,unsigned int*,unsigned int*);
extern "C" char* MenuLayout_FindGroupByKey(char*,int);
extern "C" void* Menu_ResolveFirstLayoutCellForGroup(void*,int);
extern "C" void Menu_GetLayoutCellScreenCoordinates(char*,int,short*,short*);
// Original: arm9/ov023 @ 0x021E2868; symbol: func_ov023_021e2868; size: 0x150.
// Searches enabled record chains for a rectangle containing the selected coordinates.
extern "C" int Menu_HitTestLinkedLayoutGroups(char* self){
 union Coordinate { unsigned int output; int value; } x,y; short rx,ry;
 if(!*(unsigned char*)(Main_UnknownRoleZeroInitializedStorage_Variant4+0x5f) || !*(unsigned short*)(Main_UnknownRoleZeroInitializedStorage_Variant4+0x24))return 0;
 ReadSelectedCoordinatePair((const StateRecord*)Main_UnknownRoleZeroInitializedStorage_Variant4,&x.output,&y.output);
 char* entry=*(char**)(self+8);
 for(unsigned short i=0;i<*(unsigned short*)(self+0x14);i++,entry=*(char**)(self+8)+i*24){
 if(!*(short*)(entry+14) || !(*(unsigned char*)(entry+22)&2))continue;
 char* node=MenuLayout_FindGroupByKey(self,*(short*)(entry+14));
 while(node){
 char* rectangle=(char*)Menu_ResolveFirstLayoutCellForGroup(self,*(short*)node);
 if(!rectangle){node=MenuLayout_FindGroupByKey(self,*(short*)(node+18));continue;}
 Menu_GetLayoutCellScreenCoordinates(self,*(short*)rectangle,&rx,&ry);
 if(rx>x.value || x.value>rx+*(short*)(rectangle+8)){node=MenuLayout_FindGroupByKey(self,*(short*)(node+18));continue;}
 if(ry>y.value || y.value>ry+*(short*)(rectangle+10)){node=MenuLayout_FindGroupByKey(self,*(short*)(node+18));continue;}
 return *(short*)node;
 }
 }
 return 0;
}
