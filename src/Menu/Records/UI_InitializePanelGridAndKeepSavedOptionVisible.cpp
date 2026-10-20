#include <globaldefs.h>
ARM
#pragma opt_propagation off
struct GridSelection;
extern "C" {void Grid_InitializeDirectionalSelection(char*);void Grid_SetOrientationAndCoordinatePointers(unsigned char*,int,int,int);void Grid_SetEntryCountAndClampSelection(int*,int);void Grid_SelectIndexAndComputePageCoordinates(GridSelection*,int);}
#define B(o) (*(unsigned char*)(self+(o)))
// Original: arm9/ov008 @ 0x02186964; symbol: func_ov008_02186964; size: 0xCC.
// Initializes the grid, finds the saved option and keeps it within the six visible rows.
extern "C" void UI_InitializePanelGridAndKeepSavedOptionVisible(char* self) {
 int limit,one,selected,count;
 int mode=*(signed char*)(self+0xb10);one=1;count=one;limit=one;selected=0;
 if(mode==3){count=B(0x74c);limit=count;for(int i=0;i<count;i++){if(B(0xb28)==*(unsigned char*)((self+i)+0x744)){selected=i;break;}}
 if(count>6){*(unsigned*)(self+0xb18)|=16;if(selected>B(0xb29)+5)B(0xb29)=selected-5;else if(selected<B(0xb29))B(0xb29)=selected;}}
 Grid_InitializeDirectionalSelection(self+0x750);Grid_SetOrientationAndCoordinatePointers((unsigned char*)self+0x750,one,count,0);Grid_SetEntryCountAndClampSelection((int*)(self+0x750),limit);*(int*)(self+0x754)=one;Grid_SelectIndexAndComputePageCoordinates((GridSelection*)(self+0x750),selected);
}
