#include <globaldefs.h>
ARM
struct Display { char pad[0x36]; short selected; };
struct Object {
 char pad0[0x14]; Display* display; void* input; char pad1[0x28]; short* selected;
 char pad2[0x316]; short previous; char pad3[14]; short kind; char pad4[0x1d];
 unsigned char state, flag; char pad5[5]; unsigned short flags;
};
extern "C" {
int Input_IsKeyMaskNewlyPressed(unsigned short*,unsigned);
void SoundSfx_StartCurrentSequenceArchiveEntry(char*,int,void*);
void Graphics_UpdateCounted224ByteDisplayRecords(char*);
int FindGroupRecordWithNonzeroFieldsAndFlagTwoClear(unsigned char*,int);
int TextCanvas_CreateAndConfigureDisplayPart(char*,int);
void TextCanvas_SetDisplayPartRefreshFlag(void*,int,int);
void KeyRepeater_Reset(unsigned char*);
int SetFlag800AndUpdateEmbeddedScreen(char*,int);
char* KrakPot_FindLayoutHitRegion(void*,int);
int KrakPot_HandleSelectionConfirmInput(Object*);
int KrakPot_HandleSelectionCancelInput(char*);
void KrakPot_RebuildAvailableIngredientInventory(unsigned char*);
void Graphics_ConfigureThreeModeSelectedDisplayEntries(char*);
// Original data: arm9/main @ 0x2108760; symbol: data_02108760.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 208 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern char Main_UnknownRoleZeroInitializedStorage[];
// Original data: arm9/main @ 0x2114e30; symbol: data_02114e30.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern unsigned short KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage[];
void TextCanvas_ResetDisplayPartByKey(unsigned char*,int);
void TextCanvas_HideDisplayPart(unsigned char*,int);
void TextCanvas_ShowDisplayPart(unsigned char*,int);
}
#define H(o) (*(short*)(self+(o)))
#define U(o) (*(unsigned short*)(self+(o)))
// Original: arm9/ov006 @ 0x0215B7E8; symbol: func_ov006_0215b7e8; size: 0x394.
// Advances grouped selection, handling group activation, empty groups, and cancellation.
extern "C" void KrakPot_AdvanceAlchemyModeSelection(unsigned char* self) {
 unsigned char* display=*(unsigned char**)(self+0x14);
 if(self[0x390]==0) {
  SetFlag800AndUpdateEmbeddedScreen(*(char**)(self+0x10),1);
  self[0x397]=0; H(0x36e)=2;
  if(H(0x360)<0) H(0x360)=FindGroupRecordWithNonzeroFieldsAndFlagTwoClear(display,H(0x36e));
  *(short*)(display+0x36)=H(0x360);
  TextCanvas_CreateAndConfigureDisplayPart((char*)display,H(0x36e));
  Graphics_ConfigureThreeModeSelectedDisplayEntries((char*)self);
  TextCanvas_SetDisplayPartRefreshFlag(display,H(0x36e),0);
  KeyRepeater_Reset(self+0x9c);
  *(void**)(self+0x44)=0;
  ++self[0x390];
  if(H(0x360)==4) TextCanvas_HideDisplayPart(display,3);
  else TextCanvas_ShowDisplayPart(display,3);
  return;
 }
 if(self[0x390]!=1) return;
 *(void**)(self+0x44)=self+0x360;
 if(H(0x35e)!=**(short**)(self+0x44)) {
  if(H(0x360)==4) TextCanvas_HideDisplayPart(display,3);
  else TextCanvas_ShowDisplayPart(display,3);
  Graphics_ConfigureThreeModeSelectedDisplayEntries((char*)self);
 }
 self[0x42c]=0;
 if(KrakPot_HandleSelectionConfirmInput((Object*)self)) {
  SoundSfx_StartCurrentSequenceArchiveEntry(Main_UnknownRoleZeroInitializedStorage,1,0);
  KeyRepeater_Reset(self+0x9c);
  *(void**)(self+0x44)=0;
  switch(H(0x360)) {
  case 2: {
   H(0x366)=-1;
   Graphics_UpdateCounted224ByteDisplayRecords((char*)display);
   self[0x38f]=9; self[0x390]=0;
   char* entry=KrakPot_FindLayoutHitRegion(self+0x100,0x50);
   if(entry) ((unsigned char*)entry)[0x16]&=~1;
   entry=KrakPot_FindLayoutHitRegion(self+0x100,0x4f);
   if(entry) ((unsigned char*)entry)[0x16]|=1;
   entry=KrakPot_FindLayoutHitRegion(self+0x100,0xe);
   if(entry) ((unsigned char*)entry)[0x16]&=~1;
   entry=KrakPot_FindLayoutHitRegion(self+0x100,0xf);
   if(entry) ((unsigned char*)entry)[0x16]|=1;
   entry=KrakPot_FindLayoutHitRegion(self+0x100,0x15);
   if(entry) ((unsigned char*)entry)[0x16]&=~1;
   break;
  }
  case 3: {
   KrakPot_RebuildAvailableIngredientInventory(self);
   unsigned short* used=*(unsigned short**)(self+0x50);
   unsigned char i;
   int any=0;
   if(used) {
    for(i=0;i<9;++i) if(used[i]) {any=true;break;}
    if(used[8]) any=true;
   }
   if(any) {
    H(0x362)=-1; H(0x364)=-1;
    Graphics_UpdateCounted224ByteDisplayRecords((char*)display);
    self[0x38f]=5; self[0x390]=0;
    SetFlag800AndUpdateEmbeddedScreen(*(char**)(self+0x10),1);
    H(0x37e)=0x24; self[0x392]=0; U(0x394)|=0x120;
   } else {
    U(0x394)|=0x20; H(0x37e)=0x35; self[0x392]=0;
    TextCanvas_SetDisplayPartRefreshFlag(display,H(0x36e),1);
    self[0x390]=0;
    KeyRepeater_Reset(self+0x9c);
    *(void**)(self+0x44)=0;
    return;
   }
   break;
  }
  case 4: self[0x38f]=0xc; self[0x390]=0; break;
  }
  TextCanvas_ResetDisplayPartByKey(display,3);
  TextCanvas_ResetDisplayPartByKey(display,H(0x36e));
 } else {
  if(KrakPot_HandleSelectionCancelInput((char*)self) || Input_IsKeyMaskNewlyPressed(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,0x800)) {
   Graphics_UpdateCounted224ByteDisplayRecords((char*)display);
   self[0x38f]=0xc; self[0x390]=0;
  }
 }
}
