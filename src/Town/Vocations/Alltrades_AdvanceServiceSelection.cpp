#include <globaldefs.h>
ARM
#pragma always_inline on
class GameState;class Object3D;
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" Object3D* _ZN9GameState21GetPartyMemberByIndexEi(GameState*,int);
extern "C" int GameState_ReadProtagonistObjectIndex(GameState*);
extern "C" void* GameState_GetIndexList(GameState*);
extern "C" unsigned GameObject_GetCurrentVocationLevel(void*);
extern "C" void SoundSfx_StartCurrentSequenceArchiveEntry(char*,int,void*);
// Original data: arm9/main @ 0x2108760; symbol: data_02108760.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 208 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char Main_UnknownRoleZeroInitializedStorage[];
extern "C" void Graphics_UpdateCounted224ByteDisplayRecords(char*);
extern "C" int FindGroupRecordWithNonzeroFieldsAndFlagTwoClear(unsigned char*,int);
extern "C" int TextCanvas_CreateAndConfigureDisplayPart(char*,int);
extern "C" void KeyRepeater_Reset(unsigned char*);
extern "C" int Alltrades_PollSelectionConfirmation(char*);
extern "C" int Input_TestNewKeyOrOutsideTextureRectangle(char*);
extern "C" unsigned Alltrades_IsMemberCursedOrMissing(int,int);
inline int HasPartyMemberField99() {
 GameState* scan=(GameState*)_ZN9GameState11GetInstanceEv();
 unsigned char* list=(unsigned char*)GameState_GetIndexList(scan);
 int count=list[0xf7c];
 for(int i=0;i<count;++i) {Object3D* member=_ZN9GameState21GetPartyMemberByIndexEi(scan,(list+i)[0xf78]);if(member&&GameObject_GetCurrentVocationLevel(member)==99)return 1;}
 return 0;
}
// Original: arm9/ov003 @ 0x02156AD4; symbol: func_ov003_02156ad4; size: 0x26C.
// Initializes group-two selection and routes confirmed choices eight/nine using party-member flags and field99.
extern "C" void Alltrades_AdvanceServiceSelection(char* p) {
 char* display=*(char**)(p+0x18);short* output=(short*)(p+0x1ec);
 if(((unsigned char*)p)[0x1f9]==0) {
 *(short*)(p+0x1e6)=2;
 if(*(short*)(p+0x1e0)<0) *(short*)(p+0x1e0)=FindGroupRecordWithNonzeroFieldsAndFlagTwoClear((unsigned char*)display,*(short*)(p+0x1e6));
 *(short*)(display+0x36)=*(short*)(p+0x1e0);
 TextCanvas_CreateAndConfigureDisplayPart(display,*(short*)(p+0x1e6));
 KeyRepeater_Reset((unsigned char*)p+0x80);
 *(void**)(p+8)=0;++((unsigned char*)p)[0x1f9];return;
 }
 if(((unsigned char*)p)[0x1f9]!=1)return;
 *(void**)(p+8)=p+0x1e0;
 if(Alltrades_PollSelectionConfirmation(p)) {
 SoundSfx_StartCurrentSequenceArchiveEntry(Main_UnknownRoleZeroInitializedStorage,1,0);
 KeyRepeater_Reset((unsigned char*)p+0x80);
 *(void**)(p+8)=0;
 GameState* game=(GameState*)_ZN9GameState11GetInstanceEv();
 switch(*(short*)(p+0x1e0)) {
 case 8:
 if(((unsigned char*)p)[0x1fb]==0) {
 p[0x1f7]=GameState_ReadProtagonistObjectIndex(game);p[0x1f9]=0;
 if(Alltrades_IsMemberCursedOrMissing((int)p,(signed char)p[0x1f7])) {
 output[0]=8;p[0x1f8]=7;Graphics_UpdateCounted224ByteDisplayRecords(display);return;
 }
 *(unsigned*)(p+0x1fc)|=2;output[0]=9;p[0x1f8]=3;p[0x1f9]=0;
 } else {p[0x1f7]=((unsigned char*)p)[0x1f2];output[0]=6;p[0x1f8]=2;p[0x1f9]=2;}
 break;
 case 9:
 if(((unsigned char*)p)[0x1fb]==0) {p[0x1f7]=GameState_ReadProtagonistObjectIndex(game);output[0]=14;p[0x1f8]=4;p[0x1f9]=2;}
 else {output[0]=14;output[1]=15;p[0x1f8]=4;p[0x1f9]=0;}
 {
 int found=HasPartyMemberField99();
 if(!found){output[1]=0x42;p[0x1f8]=7;}
 } break;
 }
 Graphics_UpdateCounted224ByteDisplayRecords(display);
 } else if(Input_TestNewKeyOrOutsideTextureRectangle(p)) {
 *(void**)(p+8)=0;Graphics_UpdateCounted224ByteDisplayRecords(display);output[0]=5;p[0x1f8]=7;
 }
}
