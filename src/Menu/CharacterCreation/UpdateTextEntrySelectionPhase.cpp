#include <globaldefs.h>
ARM
struct GameState { char prefix[0x7f71]; unsigned char cycle; };
struct Entry { unsigned unknown; const signed char* name; unsigned tail[3]; };
struct Table { Entry* entries; short pad,count; };
struct State { Entry* current; Table* table; unsigned pad[4]; unsigned field18; unsigned short field1c; unsigned char field1e,pad1f,field20; };
struct PhaseState { char unknown0[0xc58]; signed char phase; unsigned char phaseStep; char unknown1[0x142]; unsigned flags; signed char maximumPhase[3]; unsigned char selection; };
struct GridSelection { int count; int unknown04; int width; int height; int unknown10; int page; int unknown18[3]; int *rowWidth; int *row; int *column; };
extern "C" {
void* _ZN9GameState11GetInstanceEv();unsigned _ZNK9GameState12GetTickCountEv(GameState*);
void TextEntry_SelectControlByNameAndResetInput(State*,const signed char*,int);
char* TextLookup_FindMatchingByteKeyEntry(const void*,int);
unsigned char TextEntry_UpdateControlInput(void*,unsigned);
int CharacterCreation_ProcessChoiceAndPhaseNavigation(void*);void CharacterNameFilter_ValidateEnteredName(void*);void CharacterCreation_EnterPhaseAndMarkScreenDirty(PhaseState*,int);void FormatRandomCategoryEntry(unsigned char*);
void SoundSfx_StartCurrentSequenceArchiveEntry(char*,int,void*);
int Input_IsKeyMaskNewlyPressed(unsigned short*,unsigned);
void Text_RebuildSelectedEightGlyphCanvas(unsigned char*);
unsigned char* TextEntry_FindControlByAction(const unsigned char*,int);
unsigned char* TextEntry_SelectControlByActionIfPresent(const unsigned char*,int);
void Grid_InitializeDirectionalSelection(char*);
void Grid_SetOrientationAndCoordinatePointers(unsigned char*,int,int,int);
void Grid_SetEntryCountAndClampSelection(int*,int);
void Grid_SelectIndexAndComputePageCoordinates(GridSelection*,int);
int sprintf(char*,const char*,...);
void Math_GetSignedTablePairByIndex(unsigned,short*,short*);
// Original data: arm9/ov009 @ 0x218ad26; symbol: data_ov009_0218ad26.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 3100.
// Observed span: 2 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov009.md.
extern signed char UpdateTextEntrySelectionPhase_UnknownRoleInitializedBytes[];
// Original data: arm9/ov009 @ 0x218ad2a; symbol: data_ov009_0218ad2a.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 5700.
// Observed span: 2 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov009.md.
// Original data: arm9/main @ 0x20ef078; symbol: data_020ef078.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 25730000.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x2108760; symbol: data_02108760.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 208 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x2114e54; symbol: data_02114e54.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 112 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern char UpdateTextEntrySelectionPhase_UnknownRoleInitializedBytes_Variant2[],Main_UnknownRoleZeroInitializedStorage[],Main_UnknownRoleZeroInitializedStorage_Variant4[],UpdateTextEntrySelectionPhase_UnknownRoleInitializedBytes_Variant3[];
// Original data: arm9/main @ 0x2114e30; symbol: data_02114e30.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern unsigned short KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage[];
}
#define FIELD(T,p,o) (*(T*)((p)+(o)))
// Original: arm9/ov009 @ 0x02186E00; symbol: func_ov009_02186e00; size: 0x62C.
// Updates byte-key text entry, input actions, selection rectangle and confirmation phases.
extern "C" void UpdateTextEntrySelectionPhase(unsigned char* p) {
 if(p[0xc59]==0) {
  char* context=FIELD(char*,p,0xc0);
  FIELD(char*,context,8)=FIELD(char**,p,0xdb0)[p[0xda3]];
  FIELD(unsigned,context,0x10)=0x48;
  FIELD(unsigned,FIELD(char*,p,0xc0),0x14)=8;
  FIELD(unsigned char,FIELD(char*,p,0xc0),0x1f)=0;
  FIELD(unsigned char,FIELD(char*,p,0xc0),0x21)=0;
  FIELD(unsigned char,FIELD(char*,p,0xc0),0x24)=1;
  // The legacy third parameter is overwritten before use; this call has a two-argument ABI.
  ((void(*)(State*,const signed char*))TextEntry_SelectControlByNameAndResetInput)((State*)FIELD(char*,p,0xc0),UpdateTextEntrySelectionPhase_UnknownRoleInitializedBytes);
  char* current=FIELD(char*,FIELD(char*,p,0xc0),0);
  FIELD(char*,p,0xbc)=current;
  if(current)FIELD(char*,FIELD(char*,p,0xc0),0)=current;
  FIELD(char*,p,0xbc)=0;
  char* entry=TextLookup_FindMatchingByteKeyEntry(UpdateTextEntrySelectionPhase_UnknownRoleInitializedBytes_Variant2,0);
  if(entry)FIELD(int,FIELD(char*,p,0xc0),0xc)=(*(signed char*)(entry+4)<<3)+7;
  ++p[0xc59];
 }else if(p[0xc59]==1) {
  FIELD(unsigned,FIELD(char*,p,0xc0),0x18)=0;
  FIELD(unsigned short,FIELD(char*,p,0xc0),0x1c)=0;
  FIELD(unsigned,p,0xd9c)|=1;
  FIELD(unsigned,p,0xd9c)&=~0x800;
  FIELD(unsigned,p,0xd9c)|=0x8100;
  ++p[0xc59];
 }else if(p[0xc59]==2) {
  if(FIELD(unsigned,p,0xd9c)&0x80)return;
  unsigned ticks=_ZNK9GameState12GetTickCountEv((GameState*)_ZN9GameState11GetInstanceEv());
  p[0xdb5]=TextEntry_UpdateControlInput(FIELD(void*,p,0xc0),ticks);
  int selected=CharacterCreation_ProcessChoiceAndPhaseNavigation(p);
  if(p[0xdb5])selected=-1;
  bool handled=false;
  if(selected==-2) {handled=true;CharacterNameFilter_ValidateEnteredName(p);}
  else if(selected==-3) {CharacterCreation_EnterPhaseAndMarkScreenDirty((PhaseState*)p,7);return;}
  else if(selected>=0x65 && selected<=0x6c) {
   selected-=0x64;
   if(selected<=*(signed char*)(p+0xda0+p[0xda3]) && selected!=*(signed char*)(p+0xc58)) {CharacterCreation_EnterPhaseAndMarkScreenDirty((PhaseState*)p,(unsigned char)selected);return;}
  }
  FIELD(unsigned,p,0xd9c)|=0x2000;
  switch(p[0xdb5]) {
  case 1:SoundSfx_StartCurrentSequenceArchiveEntry(Main_UnknownRoleZeroInitializedStorage,2,0);break;
  case 9:
   if(!Input_IsKeyMaskNewlyPressed(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,1) && !*(unsigned char*)(Main_UnknownRoleZeroInitializedStorage_Variant4+0x55))CharacterCreation_EnterPhaseAndMarkScreenDirty((PhaseState*)p,7);
   else SoundSfx_StartCurrentSequenceArchiveEntry(Main_UnknownRoleZeroInitializedStorage,1,0);
   FIELD(unsigned,p,0xd9c)|=0x8100;break;
  case 2:case 4:case 5:case 6:case 7:case 8:case 11:
   if(!Input_IsKeyMaskNewlyPressed(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,2))SoundSfx_StartCurrentSequenceArchiveEntry(Main_UnknownRoleZeroInitializedStorage,1,0);
   FIELD(unsigned,p,0xd9c)|=0x8100;break;
  case 3:
   SoundSfx_StartCurrentSequenceArchiveEntry(Main_UnknownRoleZeroInitializedStorage,1,0);
   FIELD(unsigned,p,0xd9c)|=0x8100;
   Text_RebuildSelectedEightGlyphCanvas(p);
   if(Input_IsKeyMaskNewlyPressed(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,1)) {
    unsigned char* found=TextEntry_FindControlByAction(FIELD(unsigned char*,p,0xc0),6);
    if(found)FIELD(unsigned char*,FIELD(char*,p,0xc0),0)=found;
   }break;
  case 10:
   if(!*(signed char*)FIELD(char**,p,0xdb0)[p[0xda3]])SoundSfx_StartCurrentSequenceArchiveEntry(Main_UnknownRoleZeroInitializedStorage,1,0);
   if(!handled) {
    handled=true;SoundSfx_StartCurrentSequenceArchiveEntry(Main_UnknownRoleZeroInitializedStorage,1,0);CharacterNameFilter_ValidateEnteredName(p);
   }break;
  case 13:SoundSfx_StartCurrentSequenceArchiveEntry(Main_UnknownRoleZeroInitializedStorage,1,0);break;
  case 12:
   SoundSfx_StartCurrentSequenceArchiveEntry(Main_UnknownRoleZeroInitializedStorage,1,0);FormatRandomCategoryEntry(p);
   FIELD(unsigned,p,0xd9c)|=0x8100;return;
  default:
   FIELD(unsigned,p,0xd9c)&=~0x2000;
   if(Input_IsKeyMaskNewlyPressed(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,4) && selected!=-2) {
    if(FIELD(void*,FIELD(char*,p,0xc0),0)) {FormatRandomCategoryEntry(p);FIELD(unsigned,p,0xd9c)|=0x8100;return;}
   }else if(Input_IsKeyMaskNewlyPressed(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,0xc0))FIELD(unsigned,p,0xd9c)|=0x2000;
   break;
  }
  if(p[0xdb5]!=0 && p[0xdb5]!=8) {
   unsigned char* selectionBase=p+0x3ec;
   Grid_InitializeDirectionalSelection((char*)selectionBase+0x800);
   Grid_SetOrientationAndCoordinatePointers(selectionBase+0x800,11,6,1);
   Grid_SetEntryCountAndClampSelection((int*)(selectionBase+0x800),0x42);
   FIELD(int,selectionBase,0x804)=1;
   Grid_SelectIndexAndComputePageCoordinates((GridSelection*)(selectionBase+0x800),0);
  }
  if(Input_IsKeyMaskNewlyPressed(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,8) && !(FIELD(unsigned,p,0xd9c)&0x8100) && FIELD(void*,FIELD(char*,p,0xc0),0) && !handled)CharacterNameFilter_ValidateEnteredName(p);
  if(FIELD(unsigned,p,0xd9c)&0x400000) {FIELD(unsigned,p,0xd9c)|=0x2000;FIELD(unsigned,p,0xd9c)|=0x1000000;++p[0xc59];}
  if(FIELD(unsigned,p,0xd9c)&0x800) {
   unsigned char* selectionBase=p+0x3ec;
   Grid_InitializeDirectionalSelection((char*)selectionBase+0x800);
   Grid_SetOrientationAndCoordinatePointers(selectionBase+0x800,11,6,1);
   Grid_SetEntryCountAndClampSelection((int*)(selectionBase+0x800),0x42);
   FIELD(int,selectionBase,0x804)=1;
   Grid_SelectIndexAndComputePageCoordinates((GridSelection*)(selectionBase+0x800),0);
   TextEntry_SelectControlByActionIfPresent(FIELD(unsigned char*,p,0xc0),6);
   FIELD(unsigned,p,0xd9c)|=0x1000000;
   sprintf(FIELD(char*,p,0xd88)+0x3c,UpdateTextEntrySelectionPhase_UnknownRoleInitializedBytes_Variant3,FIELD(char**,p,0xdb0)[p[0xda3]]);
   CharacterCreation_EnterPhaseAndMarkScreenDirty((PhaseState*)p,9);
  }
 }else if(p[0xc59]==3) {
  if(Input_IsKeyMaskNewlyPressed(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,0x401) || *(unsigned char*)(Main_UnknownRoleZeroInitializedStorage_Variant4+0x55)) {
   SoundSfx_StartCurrentSequenceArchiveEntry(Main_UnknownRoleZeroInitializedStorage,1,0);
   FIELD(unsigned,p,0xd9c)=(FIELD(unsigned,p,0xd9c)&~0x1400000)|0x2000;p[0xc59]=2;
  }else if(Input_IsKeyMaskNewlyPressed(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,2)) {
   FIELD(unsigned,p,0xd9c)=(FIELD(unsigned,p,0xd9c)&~0x1400000)|0x2000;p[0xc59]=2;
  }
 }
 unsigned char* current=FIELD(unsigned char*,FIELD(char*,p,0xc0),0);
 if(current) {
  short width,height;
  Math_GetSignedTablePairByIndex(current[0xe],&width,&height);
  FIELD(short,p,0xc4c)=FIELD(short,current,0);FIELD(short,p,0xc4e)=FIELD(short,current,2);
  FIELD(short,p,0xc50)=width;FIELD(short,p,0xc52)=height;
 }
}
