#include <globaldefs.h>
ARM
struct PackedRecordCount { unsigned short flags:5; unsigned short count:11; };
extern "C" int ProfileEditor_FindCurrentTitleIndex(const unsigned short*, int);
extern "C" void Window_BindNextCanvasResourceByFormatAndLayer(char*,unsigned,unsigned);
extern "C" void Menu_ConfigurePairedSelectionGridsForActiveCanvas(unsigned char*);
extern "C" void Graphics_BuildProfileCountAndValuePage(unsigned char*);
extern "C" int Selection_ReadEnabledIndexFromControl(void*);
extern "C" bool Menu_IsConfirmOrCanvasActionPressed(char*);
extern "C" int Menu_TestCancelKeyOrCanvasTouchKindTwo(void*);
extern "C" void ProfileEditor_ReturnToParentPage(char*,int);
extern "C" void SoundSfx_StartCurrentSequenceArchiveEntry(char*,int,void*);
// Original data: arm9/main @ 0x2108760; symbol: data_02108760.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 208 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char Main_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov012 @ 0x021884F4; symbol: func_ov012_021884f4; size: 0x14C.
// Initializes paired controls and handles the selected record action state.
extern "C" void ProfileEditor_UpdateTitleSourceSelection(char* p) {
 if (*(unsigned char*)(p+0x1370)==0) {
 *(unsigned char*)(p+0x13a0)=0;
 *(int*)(p+0x13e8)=1;
 if(ProfileEditor_FindCurrentTitleIndex(*(const unsigned short**)(p+0x13c8), ((PackedRecordCount*)(p+0x13c4))->count)<0) *(int*)(p+0x13e8)=0;
 Window_BindNextCanvasResourceByFormatAndLayer(p+0xac,0,3);
 Menu_ConfigurePairedSelectionGridsForActiveCanvas((unsigned char*)p);
 Graphics_BuildProfileCountAndValuePage((unsigned char*)p);
 ++*(unsigned char*)(p+0x1370);
} else if (*(unsigned char*)(p+0x1370)==1) {
 *(unsigned char*)(p+0x13a0)=1;
 *(int*)(p+0x13e8)=Selection_ReadEnabledIndexFromControl(p+0xac);
 if(Menu_IsConfirmOrCanvasActionPressed(p)) {
 int accepted=1;
 switch(*(int*)(p+0x13e8)) {
 case 0: *(unsigned char*)(p+0x1371)=11; *(unsigned char*)(p+0x1370)=0; break;
 case 1: if(((PackedRecordCount*)(p+0x13c4))->count) {*(unsigned char*)(p+0x1371)=12; *(unsigned char*)(p+0x1370)=0;} else accepted=0; break;
 }
 if(accepted) SoundSfx_StartCurrentSequenceArchiveEntry(Main_UnknownRoleZeroInitializedStorage,1,0);
 } else if(Menu_TestCancelKeyOrCanvasTouchKindTwo(p)) ProfileEditor_ReturnToParentPage(p,1);
 }
}
