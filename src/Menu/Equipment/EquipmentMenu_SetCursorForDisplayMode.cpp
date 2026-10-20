#include <globaldefs.h>
ARM
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define S(p,o) (*(signed char*)((char*)(p)+(o)))
#define H(p,o) (*(short*)((char*)(p)+(o)))
#define U(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define W(p,o) (*(unsigned*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
struct Coordinates;extern "C" void EquipmentMenu_SetCursorTargetOrigin(Coordinates*,int,int);extern "C" void EquipmentMenu_SetCursorTargetOppositeCorner(Coordinates*,int,int);extern "C" void EquipmentMenu_GetItemDisplayCoordinates(void*,int,int*,int*);
// Original: arm9/ov005 @ 0x021579EC; symbol: Graphics_SetModeDependentCursorCoordinates; size: 0xFC.
extern "C" void EquipmentMenu_SetCursorForDisplayMode(char* self,unsigned mode,int index){int x=0,y=0;switch(mode){case 2:x=(index<<4)+129;if(index==7)x--;EquipmentMenu_SetCursorTargetOrigin((Coordinates*)(self+0x1a34),x<<12,4096);EquipmentMenu_SetCursorTargetOppositeCorner((Coordinates*)(self+0x1a34),0xf000,0x11000);break;case 3:EquipmentMenu_SetCursorTargetOrigin((Coordinates*)(self+0x1a34),0x85000,0x17000);EquipmentMenu_SetCursorTargetOppositeCorner((Coordinates*)(self+0x1a34),0x76000,0x16000);break;case 4:case 6:EquipmentMenu_GetItemDisplayCoordinates(self,index,&x,&y);EquipmentMenu_SetCursorTargetOrigin((Coordinates*)(self+0x1a34),x<<12,y<<12);EquipmentMenu_SetCursorTargetOppositeCorner((Coordinates*)(self+0x1a34),0x18000,0x18000);break;}}
