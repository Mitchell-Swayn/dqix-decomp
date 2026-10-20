#include <globaldefs.h>
ARM
struct StateRecord {
    unsigned char unknown00[0x20];
    unsigned short first;
    unsigned short second;
    unsigned short useWideValues;
    unsigned char unknown26[0x12];
    unsigned int wideFirst;
    unsigned int wideSecond;
};
struct Grid;
struct GridSelection { int count, unknown04, width, height, unknown10, page; int unknown18[3]; int *rowWidth, *row, *column; };
// Original data: arm9/main @ 0x2114e54; symbol: data_02114e54.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 112 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" {unsigned int ReadSelectedCoordinatePair(const StateRecord*,unsigned int*,unsigned int*);int Grid_UpdateDirectionalSelection(Grid*,int);int UI_HitTestScrollableRowsAndActionButtons(unsigned char*,int,int);void Grid_SelectIndexAndComputePageCoordinates(GridSelection*,int);extern StateRecord Main_UnknownRoleZeroInitializedStorage_Variant4;}
// Original: arm9/ov008 @ 0x02186A30; symbol: func_ov008_02186a30; size: 0xE8.
// Updates touch or directional grid selection; preserves the -2 action-button result.
extern "C" int UI_UpdatePanelGridFromTouchOrDirections(char* self,int ticks) {
 unsigned int x,y;int active=0;int hit=active-1;
 ReadSelectedCoordinatePair(&Main_UnknownRoleZeroInitializedStorage_Variant4,&x,&y);
 if(((unsigned char*)&Main_UnknownRoleZeroInitializedStorage_Variant4)[0x55]){active=1;hit=UI_HitTestScrollableRowsAndActionButtons((unsigned char*)self,x,y);if(hit!=-1)Grid_SelectIndexAndComputePageCoordinates((GridSelection*)(self+0x750),hit);}
 else if(((unsigned char*)&Main_UnknownRoleZeroInitializedStorage_Variant4)[0x5f]&&*(unsigned short*)((unsigned char*)&Main_UnknownRoleZeroInitializedStorage_Variant4+0x24))active=1;
 else if(((unsigned char*)&Main_UnknownRoleZeroInitializedStorage_Variant4)[0x54])active=1;
 if(!active)Grid_UpdateDirectionalSelection((Grid*)(self+0x750),ticks);
 if(active){if(hit==-1)return 0;if(hit==-2)return -2;if(hit>=0)return 1;}
 return 0;
}
