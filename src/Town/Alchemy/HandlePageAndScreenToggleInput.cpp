#include <globaldefs.h>
ARM
extern "C" {
int Input_IsKeyMaskNewlyPressed(unsigned short*,unsigned);
void SoundSfx_StartCurrentSequenceArchiveEntry(char*,int,void*);
void TextCanvas_SetDisplayPartRefreshFlag(void*,int,int);
int SetFlag800AndUpdateEmbeddedScreen(char*,int);
void KrakPot_RefreshIngredientPage(unsigned char*);
int Menu_HitTestEnabledLayoutGroups(char*);
// Original data: arm9/main @ 0x2114e30; symbol: data_02114e30.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern unsigned short KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage[];
// Original data: arm9/main @ 0x2108760; symbol: data_02108760.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 208 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern char Main_UnknownRoleZeroInitializedStorage[];
}
// Original: arm9/ov006 @ 0x021595B4; symbol: func_ov006_021595b4; size: 0x13C.
// Handles page transition requests and toggles the embedded screen flag.
extern "C" int HandlePageAndScreenToggleInput(unsigned char* self) {
 int key=Menu_HitTestEnabledLayoutGroups((char*)self+0x100);
 int page=key==0x78;
 int toggle=key==0x25;
 if(self[0x38c]>1 || self[0x38d]>=1) {
  page=page | Input_IsKeyMaskNewlyPressed(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,0x400) ? 1:0;
  if(page) {
   *(void**)(self+0x44)=0;
   self[0x38f]=7; self[0x390]=6;
   KrakPot_RefreshIngredientPage(self);
   TextCanvas_SetDisplayPartRefreshFlag(*(void**)(self+0x14),0x10,1);
   *(unsigned short*)(self+0x394)&=~0x10;
   *(unsigned short*)(self+0x394)|=0x20;
   *(short*)(self+0x37e)=0xa; self[0x392]=0;
   return 1;
  }
 }
 if(page) return 1;
 if((*(unsigned short*)(self+0x394)&0x10) && (Input_IsKeyMaskNewlyPressed(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,0x300) || toggle)) {
  char* screen=*(char**)(self+0x10);
  SetFlag800AndUpdateEmbeddedScreen(screen,(*(unsigned short*)(screen+0x1258)&0x800)==0);
  SoundSfx_StartCurrentSequenceArchiveEntry(Main_UnknownRoleZeroInitializedStorage,1,0);
  return 1;
 }
 return 0;
}
