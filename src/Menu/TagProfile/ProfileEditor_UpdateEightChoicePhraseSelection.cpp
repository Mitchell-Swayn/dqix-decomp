#include <globaldefs.h>
ARM
struct PackedRecordCount { unsigned short flags:5; unsigned short count:11; };
extern "C" void Window_BindNextCanvasResourceByFormatAndLayer(char*,unsigned,unsigned);
extern "C" void Menu_ConfigurePairedSelectionGridsForActiveCanvas(unsigned char*);
extern "C" void Graphics_BuildEightIndexedRecordPage(unsigned char*);
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
struct E { short key; short pad; unsigned value; }; struct T { E* data; short count; };
extern "C" unsigned MessageTextTable_FindTextById(T*,int);
extern "C" void ProfileEditor_RefreshPreview(char*,int,int,int);
struct SignedRecordMode { unsigned low:9; signed mode:10; unsigned upper:13; };
struct GlobalRecord { unsigned first; SignedRecordMode second; };
inline GlobalRecord* GetGlobalRecord(char* state) {return (GlobalRecord*)(state+0x569c);}
extern "C" int ReadModeRangeOffset(int);
// Original: arm9/ov012 @ 0x02186FD8; symbol: func_ov012_02186fd8; size: 0x180.
// Selects the mode-200 record text, then copies it and updates the packed mode.
extern "C" void ProfileEditor_UpdateEightChoicePhraseSelection(char* p) {
 if(*(unsigned char*)(p+0x1370)==0) {
 *(unsigned char*)(p+0x13a0)=0;
 *(int*)(p+0x13e0)=ReadModeRangeOffset(1);
 if(*(int*)(p+0x13e0)<0) *(int*)(p+0x13e0)=0;
 Window_BindNextCanvasResourceByFormatAndLayer(p+0xac,0,3);
 Menu_ConfigurePairedSelectionGridsForActiveCanvas((unsigned char*)p);
 Graphics_BuildEightIndexedRecordPage((unsigned char*)p);
 ++*(unsigned char*)(p+0x1370);
 } else if(*(unsigned char*)(p+0x1370)==1) {
 *(unsigned char*)(p+0x13a0)=1;
 *(int*)(p+0x13e0)=Selection_ReadEnabledIndexFromControl(p+0xac);
 if(Menu_IsConfirmOrCanvasActionPressed(p)) {
 SoundSfx_StartCurrentSequenceArchiveEntry(Main_UnknownRoleZeroInitializedStorage,1,0);
 char* state=(char*)_ZN9GameState11GetInstanceEv();
 const char* text=(const char*)MessageTextTable_FindTextById((T*)(p+0x133c),(short)(*(int*)(p+0x13e0)+0x27d8));
 GlobalRecord* record=GetGlobalRecord(state);
 memset(p+0x1440,0,64);
 memcpy(p+0x1440,text,strlen(text));
 record->second.mode=*(int*)(p+0x13e0)+200;
 ProfileEditor_RefreshPreview(p,0,-1,0);
 ProfileEditor_ReturnToParentPage(p,0);
 } else if(Menu_TestCancelKeyOrCanvasTouchKindTwo(p)) ProfileEditor_ReturnToParentPage(p,1);
 }
}
