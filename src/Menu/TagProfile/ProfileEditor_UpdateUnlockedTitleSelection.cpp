#include <globaldefs.h>
ARM
struct PackedRecordCount { unsigned short flags:5; unsigned short count:11; };
extern "C" int ProfileEditor_FindCurrentTitleIndex(const unsigned short*, int);
extern "C" void Window_BindNextCanvasResourceByFormatAndLayer(char*,unsigned,unsigned);
extern "C" void Menu_ConfigurePairedSelectionGridsForActiveCanvas(unsigned char*);
extern "C" void Graphics_BuildProfileRecordListPage(unsigned char*);
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
#include <std_library_functions.h>
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* ResourceStringTable_GetTextByKey(void*,void*);
extern "C" void ProfileEditor_RefreshPreview(char*,int,int,int);
extern "C" int Menu_HandleCanvasPageArrowTouch(char*);
struct RecordBits { unsigned first; unsigned low:19; unsigned identifier:11; unsigned high:2; };
inline RecordBits* GetRecordBits(char* state) {return (RecordBits*)(state+0x569c);}
// Original: arm9/ov012 @ 0x02188924; symbol: func_ov012_02188924; size: 0x1C8.
// Copies selected indexed record text and commits its eleven-bit identifier.
extern "C" void ProfileEditor_UpdateUnlockedTitleSelection(char* p) {
 if(*(unsigned char*)(p+0x1370)==0) {
 *(unsigned char*)(p+0x13a0)=0;
 *(int*)(p+0x13f0)=ProfileEditor_FindCurrentTitleIndex(*(const unsigned short**)(p+0x13c8),((PackedRecordCount*)(p+0x13c4))->count);
 if(*(int*)(p+0x13f0)<0) *(int*)(p+0x13f0)=0;
 Window_BindNextCanvasResourceByFormatAndLayer(p+0xac,0,3);
 Menu_ConfigurePairedSelectionGridsForActiveCanvas((unsigned char*)p);
 Graphics_BuildProfileRecordListPage((unsigned char*)p);
 ++*(unsigned char*)(p+0x1370);
 } else if(*(unsigned char*)(p+0x1370)==1) {
 *(unsigned char*)(p+0x13a0)=1;
 *(int*)(p+0x13f0)=Selection_ReadEnabledIndexFromControl(p+0xac);
 if(Menu_HandleCanvasPageArrowTouch(p)) *(int*)(p+0x13f0)=Selection_ReadEnabledIndexFromControl(p+0xac);
 if(Menu_IsConfirmOrCanvasActionPressed(p)) {
 const char* text=(const char*)ResourceStringTable_GetTextByKey(p+0x1344,(void*)(*(short**)(p+0x13c8))[*(int*)(p+0x13f0)]);
 if(!text) return;
 SoundSfx_StartCurrentSequenceArchiveEntry(Main_UnknownRoleZeroInitializedStorage,1,0);
 memset(p+0x1400,0,64);
 memcpy(p+0x1400,text,strlen(text));
 char* state=(char*)_ZN9GameState11GetInstanceEv();
 GetRecordBits(state)->identifier=(*(unsigned short**)(p+0x13c8))[*(int*)(p+0x13f0)];
 *(unsigned*)(state+0x569c)=(*(unsigned*)(state+0x569c)&~0x40000000)|0x20000000;
 ProfileEditor_RefreshPreview(p,0,-1,0);
 ProfileEditor_ReturnToParentPage(p,0);
 } else if(Menu_TestCancelKeyOrCanvasTouchKindTwo(p)) ProfileEditor_ReturnToParentPage(p,1);
 }
}
