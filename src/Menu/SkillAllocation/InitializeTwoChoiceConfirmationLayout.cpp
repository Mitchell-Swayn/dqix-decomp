#include <globaldefs.h>
ARM
struct State;struct GridSelection;
extern "C" void Window_BindNextCanvasResourceByFormatAndLayer(char*,unsigned,unsigned);
extern "C" void* memset(void*,int,unsigned);
extern "C" void AppendTwoChoiceLabels(char*,char*);
extern "C" void Window_PushTextCanvas(void*,void*,int,int,int,int,int,int);
extern "C" void Grid_SetOrientationAndCoordinatePointers(unsigned char*,int,int,int);
extern "C" void Grid_SetEntryCountAndClampSelection(int*,int);
extern "C" void Grid_SelectIndexAndInvalidateTouchHistory(State*,int);
extern "C" void Grid_SelectIndexAndComputePageCoordinates(GridSelection*,int);
// Original data: arm9/ov013 @ 0x2187d98; symbol: data_ov013_02187d98.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 00020002.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov013.md.
extern "C" char InitializeTwoChoiceConfirmationLayout_UnknownRoleInitializedBytes[];
// Original: arm9/ov013 @ 0x02185AAC; symbol: func_ov013_02185aac; size: 0x134.
// Configures and populates a two-choice confirmation text layout.
extern "C" void InitializeTwoChoiceConfirmationLayout(unsigned char* p){
 Window_BindNextCanvasResourceByFormatAndLayer((char*)p+0x38,0,2);
 *(short*)(p+0xd8)=7;*(short*)(p+0xda)=5;*(short*)(p+0xdc)=25;*(short*)(p+0xde)=19;*(short*)(p+0xe0)=12;*(short*)(p+0xe2)=7;*(short*)(p+0xe4)=10;*(short*)(p+0xe6)=16;p[0xe9]=3;if(p[0x640])p[0xed]=0;else p[0xed]=1;
 memset(*(void**)(p+0x658),0,0x960);AppendTwoChoiceLabels((char*)p,*(char**)(p+0x658));
 Window_PushTextCanvas(p+0x38,*(void**)(p+0x658),0,0,0,1,(int)InitializeTwoChoiceConfirmationLayout_UnknownRoleInitializedBytes,1);
 p[0xe9]=3;*(int*)(p+0x40)=1;*(int*)(p+0x90)=1;
 Grid_SetOrientationAndCoordinatePointers(p+0x3c,1,2,0);Grid_SetOrientationAndCoordinatePointers(p+0x8c,1,2,0);
 Grid_SetEntryCountAndClampSelection((int*)(p+0x3c),2);Grid_SetEntryCountAndClampSelection((int*)(p+0x8c),2);
 int index=*(int*)(p+0x660);Grid_SelectIndexAndInvalidateTouchHistory((State*)(p+0x3c),index);Grid_SelectIndexAndComputePageCoordinates((GridSelection*)(p+0x8c),index);
}
