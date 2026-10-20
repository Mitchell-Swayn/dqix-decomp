#include <globaldefs.h>
ARM
struct Node { unsigned pad[3]; unsigned lowC:20; unsigned kind:8; unsigned highC:4; unsigned low10:21; unsigned enabled:1; unsigned selected:1; unsigned category:8; unsigned high10:1; unsigned pad14; short index; short pad1a; Node* next; };
struct List { Node* head; Node* nodes; unsigned short pad,count; };
struct Display { char pad[0x36]; short selected; };
struct Object {
 char pad0[0x14]; Display* display; void* input; char pad1[0x28]; short* selected;
 char pad2[0x316]; short previous; char pad3[14]; short kind; char pad4[0x1d];
 unsigned char state, flag; char pad5[5]; unsigned short flags;
};
extern "C" {
int Input_IsKeyMaskNewlyPressed(unsigned short*,unsigned);
void SoundSfx_StartCurrentSequenceArchiveEntry(char*,int,void*);
Node* LinkedList_SelectAndRebuildNodes(List*,int,int,int,short,short*);
int TextCanvas_CreateAndConfigureDisplayPart(char*,int);
void KeyRepeater_Reset(unsigned char*);
void KrakPot_ConfigureRecipeBrowserHitRegions(void*);
void Util_DecodeSplitByteSelector(int,unsigned char*,signed char*);
int KrakPot_HandleSelectionConfirmInput(Object*);
int KrakPot_HandleSelectionCancelInput(char*);
void KrakPot_RequestExitOnNewInputMask(Object*);
void KrakPot_ResetRecipePagination(unsigned char*);
void ConfigureSelectedPartsWithFlaggedEntryPercentage(char*,int);
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
}
#define H(o) (*(short*)(self+(o)))
#define U(o) (*(unsigned short*)(self+(o)))
// Original: arm9/ov006 @ 0x0215B1A0; symbol: func_ov006_0215b1a0; size: 0x3DC.
// Advances two levels of record-category selection and rebuilds their linked list.
extern "C" void KrakPot_AdvanceRecipeCategorySelection(unsigned char* self) {
 if(self[0x390]==0) {
  self[0x397]=2;
  ConfigureSelectedPartsWithFlaggedEntryPercentage((char*)self,1);
  H(0x36e)=8;
  if(H(0x366)<0) H(0x366)=0x24;
  *(short*)(*(unsigned char**)(self+0x14)+0x36)=H(0x366);
  TextCanvas_CreateAndConfigureDisplayPart(*(char**)(self+0x14),H(0x36e));
  KeyRepeater_Reset(self+0x9c);
  *(void**)(self+0x44)=0; ++self[0x390];
 } else if(self[0x390]==1) {
  *(void**)(self+0x44)=self+0x366;
  if(KrakPot_HandleSelectionConfirmInput((Object*)self)) {
   SoundSfx_StartCurrentSequenceArchiveEntry(Main_UnknownRoleZeroInitializedStorage,1,0);
   KeyRepeater_Reset(self+0x9c);
   *(void**)(self+0x44)=0;
   int selected=0;
   H(0x368)=-1; H(0x36a)=-1; *((signed char*)self+0x384)=-1; *((signed char*)self+0x385)=-1;
   switch(H(0x366)) {
   case 0x24: selected=1; break;
   case 0x25: self[0x384]=0; ++self[0x390]; break;
   case 0x26: ++self[0x390]; break;
   case 0x27: self[0x384]=7; selected=1; break;
   case 0x28: self[0x384]=8; selected=1; break;
   }
   if(selected) {
    self[0x38f]=3; self[0x390]=0;
    KrakPot_ConfigureRecipeBrowserHitRegions(self+0x100);
    U(0x394)|=0x80;
   }
   short count=0;
   LinkedList_SelectAndRebuildNodes((List*)(self+0x14c),(signed char)self[0x384],(signed char)self[0x385],self[0x386],0x10,&count);
   *(unsigned*)(self+0x30)=*(unsigned*)(self+0x2c)=*(unsigned*)(self+0x14c);
   KrakPot_ResetRecipePagination(self);
   TextCanvas_ResetDisplayPartByKey(*(unsigned char**)(self+0x14),8);
  } else if(KrakPot_HandleSelectionCancelInput((char*)self) || Input_IsKeyMaskNewlyPressed(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,0x800)) {
   **(short**)(self+0x44)=-1;
   *(void**)(self+0x44)=0;
   self[0x38f]=0xc; self[0x390]=0;
  }
 } else if(self[0x390]==2) {
  self[0x397]=2;
  ConfigureSelectedPartsWithFlaggedEntryPercentage((char*)self,0);
  if(H(0x366)==0x25) {
   H(0x36e)=0xc;
   if(H(0x368)<0) H(0x368)=0x48;
  } else if(H(0x366)==0x26) {
   H(0x36e)=0xb;
   if(H(0x368)<0) H(0x368)=0x40;
  }
  *(short*)(*(unsigned char**)(self+0x14)+0x36)=H(0x368);
  TextCanvas_CreateAndConfigureDisplayPart(*(char**)(self+0x14),H(0x36e));
  KeyRepeater_Reset(self+0x9c);
  *(void**)(self+0x44)=0; ++self[0x390];
 } else if(self[0x390]==3) {
  *(void**)(self+0x44)=self+0x368;
  if(KrakPot_HandleSelectionConfirmInput((Object*)self)) {
   SoundSfx_StartCurrentSequenceArchiveEntry(Main_UnknownRoleZeroInitializedStorage,1,0);
   self[0x38f]=3; self[0x390]=0; *(void**)(self+0x44)=0;
   H(0x36a)=-1;
   Util_DecodeSplitByteSelector(H(0x368),self+0x384,(signed char*)self+0x385);
   short count=0;
   LinkedList_SelectAndRebuildNodes((List*)(self+0x14c),(signed char)self[0x384],(signed char)self[0x385],self[0x386],0x10,&count);
   *(unsigned*)(self+0x30)=*(unsigned*)(self+0x2c)=*(unsigned*)(self+0x14c);
   KrakPot_ResetRecipePagination(self);
   TextCanvas_ResetDisplayPartByKey(*(unsigned char**)(self+0x14),H(0x36e));
   self[0x38f]=3; self[0x390]=0;
   KrakPot_ConfigureRecipeBrowserHitRegions(self+0x100);
   U(0x394)|=0x80;
  } else {
   if(KrakPot_HandleSelectionCancelInput((char*)self)) {
    H(0x368)=-1;
    TextCanvas_ResetDisplayPartByKey(*(unsigned char**)(self+0x14),H(0x36e));
    self[0x390]=0;
   }
   KrakPot_RequestExitOnNewInputMask((Object*)self);
  }
 }
}
