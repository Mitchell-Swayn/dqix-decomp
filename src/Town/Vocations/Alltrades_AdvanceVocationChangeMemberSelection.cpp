#include <globaldefs.h>
ARM
class GameState;
extern "C" {
void* _ZN9GameState11GetInstanceEv();
int GameState_ReadProtagonistObjectIndex(GameState*);
void* GameState_GetIndexList(GameState*);
void SoundSfx_StartCurrentSequenceArchiveEntry(char*,int,void*);
void Graphics_UpdateCounted224ByteDisplayRecords(char*);
int FindGroupRecordWithNonzeroFieldsAndFlagTwoClear(unsigned char*,int);
void KeyRepeater_Reset(unsigned char*);
int Alltrades_PollSelectionConfirmation(char*);
int Input_TestNewKeyOrOutsideTextureRectangle(char*);
void Graphics_InitializeSelectedDisplayPartAndLinkedOwner(unsigned char*,int);
int Alltrades_PollConfirmationPrompt(unsigned char*);
unsigned Alltrades_IsMemberCursedOrMissing(int,int);
int Alltrades_IsMemberDead(void*,int);
void UpdateObjectRatioDisplayParts(char*);
// Original data: arm9/main @ 0x2108760; symbol: data_02108760.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 208 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern char Main_UnknownRoleZeroInitializedStorage[];
}
// Original: arm9/ov003 @ 0x02156D40; symbol: func_ov003_02156d40; size: 0x30C.
// Advances compact selection, then chooses a listed party member and routes flag-based rejection or ratio display.
extern "C" void Alltrades_AdvanceVocationChangeMemberSelection(char* p) {
 GameState* game=(GameState*)_ZN9GameState11GetInstanceEv();
 unsigned char* list=(unsigned char*)GameState_GetIndexList(game);
 char* display=*(char**)(p+0x18);unsigned phase=((unsigned char*)p)[0x1f9];
 if(phase==0) {
 Graphics_InitializeSelectedDisplayPartAndLinkedOwner((unsigned char*)p,0);++((unsigned char*)p)[0x1f9];
 }else if(phase==1) {
 int result=Alltrades_PollConfirmationPrompt((unsigned char*)p);
 if(result!=-1) {
 if(result==1) {
 if(((unsigned char*)p)[0x1fb]==0) {
 p[0x1f7]=GameState_ReadProtagonistObjectIndex(game);p[0x1f9]=0;
 if(Alltrades_IsMemberCursedOrMissing((int)p,(signed char)p[0x1f7])) {
 *(short*)(p+0x1ec)=8;p[0x1f8]=7;Graphics_UpdateCounted224ByteDisplayRecords(display);return;
 }
 *(unsigned*)(p+0x1fc)|=2;*(short*)(p+0x1ec)=9;p[0x1f8]=3;p[0x1f9]=0;
 }else {p[0x1f7]=((unsigned char*)p)[0x1f2];*(short*)(p+0x1ec)=6;p[0x1f8]=2;++((unsigned char*)p)[0x1f9];}
 }
 }else {*(short*)(p+0x1ec)=3;p[0x1f8]=7;}
 }else if(phase==2) {
 *(short*)(p+0x1e6)=3;
 switch(list[0xf7c]) {case 3:*(short*)(p+0x1e6)=4;break;case 4:*(short*)(p+0x1e6)=5;break;}
 if(*(short*)(p+0x1e2)<0) {
 *(short*)(p+0x1e2)=FindGroupRecordWithNonzeroFieldsAndFlagTwoClear((unsigned char*)display,*(short*)(p+0x1e6));
 *(short*)(p+0x1e8)=*(short*)(p+0x1e2);
 }
 *(short*)(display+0x36)=*(short*)(p+0x1e2);
 UpdateObjectRatioDisplayParts(p);KeyRepeater_Reset((unsigned char*)p+0x80);
 *(void**)(p+8)=0;++((unsigned char*)p)[0x1f9];
 }else if(phase==3) {
 *(void**)(p+8)=p+0x1e2;
 if(Alltrades_PollSelectionConfirmation(p)) {
 SoundSfx_StartCurrentSequenceArchiveEntry(Main_UnknownRoleZeroInitializedStorage,1,0);
 KeyRepeater_Reset((unsigned char*)p+0x80);*(void**)(p+8)=0;
 int first=FindGroupRecordWithNonzeroFieldsAndFlagTwoClear((unsigned char*)display,*(short*)(p+0x1e6));
 p[0x1f7]=((unsigned char*)p+(short)(*(short*)(p+0x1e2)-first))[0x1f2];
 if(Alltrades_IsMemberDead(p,(signed char)p[0x1f7])) {*(short*)(p+0x1ec)=0x31;p[0x1f8]=7;Graphics_UpdateCounted224ByteDisplayRecords(display);return;}
 if(Alltrades_IsMemberCursedOrMissing((int)p,(signed char)p[0x1f7])) {*(short*)(p+0x1ec)=8;p[0x1f8]=7;Graphics_UpdateCounted224ByteDisplayRecords(display);return;}
 *(unsigned*)(p+0x1fc)|=2;*(short*)(p+0x1ec)=9;p[0x1f8]=3;p[0x1f9]=0;Graphics_UpdateCounted224ByteDisplayRecords(display);
 }else if(Input_TestNewKeyOrOutsideTextureRectangle(p)) {
 *(void**)(p+8)=0;*(short*)(p+0x1ec)=7;p[0x1f8]=7;Graphics_UpdateCounted224ByteDisplayRecords(display);
 }
 }
}
