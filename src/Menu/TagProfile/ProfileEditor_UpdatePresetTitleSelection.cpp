#include <globaldefs.h>
#include <GameState/GameState.h>
ARM
extern "C" void Window_BindNextCanvasResourceByFormatAndLayer(char*,unsigned,unsigned);
extern "C" void Menu_ConfigurePairedSelectionGridsForActiveCanvas(unsigned char*);
extern "C" void Graphics_BuildIndexedProfileRecordValuesPage(unsigned char*);
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
extern "C" void ProfileEditor_RefreshPreview(char*,int,int,int);
extern "C" int Menu_HandleCanvasPageArrowTouch(char*);
struct RecordBits { unsigned firstLow:29; unsigned committed:1; unsigned derived:1; unsigned firstHigh:1; unsigned low:19; signed identifier:11; unsigned high:2; };
inline RecordBits* GetRecordBits(GameState* state) {return (RecordBits*)((char*)state+0x569c);}
struct ProtagonistFlag { unsigned char kind:1; unsigned char rest:7; };
struct E {short key;short pad;unsigned value;}; struct T {E* data;short count;};
extern "C" unsigned MessageTextTable_FindTextById(T*,int);
extern "C" void* _ZN9GameState14GetProtagonistEv(void*);
extern "C" void* Network_GetConnectionManager();
extern "C" unsigned int GameState_GetProgressChapter(GameState* state);
// Original: arm9/ov012 @ 0x02188640; symbol: func_ov012_02188640; size: 0x2E4.
// Resolves protagonist-dependent profile text selection and commits its packed identifier.
extern "C" void ProfileEditor_UpdatePresetTitleSelection(char* p) {
 if(*(unsigned char*)(p+0x1370)==0) {
 *(unsigned char*)(p+0x13a0)=0;
 GameState* state=GameState::GetInstance();
 RecordBits* record=GetRecordBits(state);
 int selected;
 if(record->derived) goto noSelection;
 {
 int id=record->identifier;
 if(id>=800 && id<900) {selected=id-799; goto selectionReady;}
 if(id>=900 && id<1000) {selected=id-899; goto selectionReady;}
 }
 noSelection: selected=0;
 selectionReady:
 *(int*)(p+0x13ec)=selected;
 Window_BindNextCanvasResourceByFormatAndLayer(p+0xac,0,3);
 Menu_ConfigurePairedSelectionGridsForActiveCanvas((unsigned char*)p);
 Graphics_BuildIndexedProfileRecordValuesPage((unsigned char*)p);
 ++*(unsigned char*)(p+0x1370);
 } else if(*(unsigned char*)(p+0x1370)==1) {
 *(unsigned char*)(p+0x13a0)=1;
 *(int*)(p+0x13ec)=Selection_ReadEnabledIndexFromControl(p+0xac);
 if(Menu_HandleCanvasPageArrowTouch(p)) *(int*)(p+0x13ec)=Selection_ReadEnabledIndexFromControl(p+0xac);
 if(Menu_IsConfirmOrCanvasActionPressed(p)) {
 SoundSfx_StartCurrentSequenceArchiveEntry(Main_UnknownRoleZeroInitializedStorage,1,0);
 GameState* state=GameState::GetInstance();
 RecordBits* record=GetRecordBits(state);
 state=GameState::GetInstance();
 Network_GetConnectionManager();
 char* protagonist=(char*)_ZN9GameState14GetProtagonistEv(state);
 if(*(int*)(p+0x13ec)==0) {
 char* details=*(char**)(protagonist+0x150);
 int flag=((ProtagonistFlag*)(details+0x49c))->kind;
 int index=*(int*)(details+0x950);
 int key=20700;
 if(flag==1) {key+=50; record->derived=1;} else record->derived=1;
 record->identifier=key+index-20000;
 if(GameState_GetProgressChapter(state)==1) record->identifier=key-19987;
 } else {
 char* details=*(char**)(protagonist+0x150);
 int key=20800;
 if(((ProtagonistFlag*)(details+0x49c))->kind==1) key+=100;
 record->identifier=key+*(int*)(p+0x13ec)-20001;
 record->derived=0;
 }
 const char* text=(const char*)MessageTextTable_FindTextById((T*)(p+0x133c),(short)(record->identifier+20000));
 memset(p+0x1400,0,64);
 memcpy(p+0x1400,text,strlen(text));
 record->committed=1;
 ProfileEditor_RefreshPreview(p,0,-1,0);
 ProfileEditor_ReturnToParentPage(p,0);
 } else if(Menu_TestCancelKeyOrCanvasTouchKindTwo(p)) ProfileEditor_ReturnToParentPage(p,1);
 }
}
