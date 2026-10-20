#include <globaldefs.h>
ARM
struct PackedModes { unsigned low:21; unsigned mode:4; unsigned bit:1; unsigned upper:6; };
extern "C" void Window_BindNextCanvasResourceByFormatAndLayer(char*,unsigned,unsigned);
extern "C" void Menu_ConfigurePairedSelectionGridsForActiveCanvas(unsigned char*);
extern "C" void ProfileEditor_BuildPreviewModePage(unsigned char*);
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
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void ProfileEditor_RefreshPreview(char*,int,int,int);
// Original: arm9/ov012 @ 0x02188AEC; symbol: func_ov012_02188aec; size: 0x1E4.
// Updates paired controls for a packed global mode, committing or restoring selection.
extern "C" void ProfileEditor_UpdatePreviewModeSelection(char* p) {
 PackedModes* modes=(PackedModes*)((char*)_ZN9GameState11GetInstanceEv()+0x569c);
 if(*(unsigned char*)(p+0x1370)==0) { ++*(unsigned char*)(p+0x1370); ++*(unsigned char*)(p+0x1370); }
 else if(*(unsigned char*)(p+0x1370)==1) ++*(unsigned char*)(p+0x1370);
 else if(*(unsigned char*)(p+0x1370)==2) {
 *(unsigned char*)(p+0x13a0)=0;
 *(int*)(p+0x13f4)=(modes->mode-modes->bit)>>1;
 Window_BindNextCanvasResourceByFormatAndLayer(p+0xac,0,3);
 Menu_ConfigurePairedSelectionGridsForActiveCanvas((unsigned char*)p);
 ProfileEditor_BuildPreviewModePage((unsigned char*)p);
 ++*(unsigned char*)(p+0x1370);
 } else if(*(unsigned char*)(p+0x1370)==3) {
 *(unsigned char*)(p+0x13a0)=1;
 int selected=Selection_ReadEnabledIndexFromControl(p+0xac);
 if(*(int*)(p+0x13f4)!=selected) {
 *(int*)(p+0x13f4)=selected;
 int bit=modes->bit;
 int current=*(int*)(p+0x13f4);
 ProfileEditor_RefreshPreview(p,0,(current<<1)+bit,0);
 }
 int done=0;
 if(Menu_IsConfirmOrCanvasActionPressed(p)) {
 SoundSfx_StartCurrentSequenceArchiveEntry(Main_UnknownRoleZeroInitializedStorage,1,0);
 PackedModes* updated=(PackedModes*)((char*)_ZN9GameState11GetInstanceEv()+0x569c);
 int bit=updated->bit;
 int current=*(int*)(p+0x13f4);
 updated->mode=(current<<1)+bit;
 *(unsigned*)updated|=0x8000000;
 done=1;
 } else if(Menu_TestCancelKeyOrCanvasTouchKindTwo(p)) {
 *(int*)(p+0x13f4)=(modes->mode-modes->bit)>>1;
 done=1;
 ProfileEditor_RefreshPreview(p,0,-1,0);
 }
 if(done) ++*(unsigned char*)(p+0x1370);
 } else if(*(unsigned char*)(p+0x1370)==4) ++*(unsigned char*)(p+0x1370);
 else if(*(unsigned char*)(p+0x1370)==5) {
 *(unsigned char*)(p+0x1371)=1;
 *(unsigned char*)(p+0x1370)=1;
 ProfileEditor_ReturnToParentPage(p,1);
 }
}
