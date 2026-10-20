#include <globaldefs.h>
ARM
#pragma always_inline on
struct Record { short key; unsigned short flags; };
struct Table { char pad[0x20]; Record* volatile records; unsigned short count; };
struct Display { char pad[0x36]; short selected; };
struct Object {
 char pad0[0x14]; Display* display; void* input; char pad1[0x28]; short* selected;
 char pad2[0x316]; short previous; char pad3[14]; short kind; char pad4[0x1d];
 unsigned char state, flag; char pad5[5]; unsigned short flags;
};
extern "C" {
void SoundSfx_StartCurrentSequenceArchiveEntry(char*,int,void*);
void KeyRepeater_Reset(unsigned char*);
void KrakPot_GetRecipeIngredientStockCounts(char*,int,unsigned char*);
Record* FindNonnegativeHalfwordKeyInPackedTable(Table*,int);
void KrakPot_RequestRecipePreviewIfChanged(unsigned char*,short*,char*,int);
int SetFlag800AndUpdateEmbeddedScreen(char*,int);
void Graphics_ClearFlagAndRefreshBackgrounds(unsigned char*);
int KrakPot_HandleSelectionConfirmInput(Object*);
int KrakPot_HandleSelectionCancelInput(char*);
void KrakPot_RequestExitOnNewInputMask(Object*);
void* KrakPot_GetRecipeAtPageRowClamped(void*,int);
int KrakPot_ClassifyRecipeBrowserAction(char*);
void ToggleListModeAndPreserveSelectedNode(unsigned char*);
void KrakPot_RefreshRecipePage(unsigned char*);
void ConfigureSelectedPartsWithFlaggedEntryPercentage(char*,int);
void KrakPot_RefreshRecipeCategoryHeading(char*);
void Object_ConfigureSelectedDisplayPart(void*);
// Original data: arm9/main @ 0x2108760; symbol: data_02108760.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 208 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern char Main_UnknownRoleZeroInitializedStorage[];
void TextCanvas_ResetDisplayPartByKey(unsigned char*,int);
}
struct Category {char pad[0x66];short value;inline bool First(){return value==37;}inline bool Second(){return value==38;}};
#define H(o) (*(short*)(self+(o)))
#define U(o) (*(unsigned short*)(self+(o)))
#define P(o) (*(unsigned char**)(self+(o)))
// Original: arm9/ov006 @ 0x0215B57C; symbol: func_ov006_0215b57c; size: 0x26C.
// Advances a paged record browser, its mode toggle, and cancellation to category selection.
extern "C" void KrakPot_AdvanceRecipeBookBrowser(unsigned char* self) {
 unsigned char* owner=P(0x10);
 if(self[0x390]==0) {
  self[0x397]=1;
  ConfigureSelectedPartsWithFlaggedEntryPercentage((char*)self,0);
  KrakPot_RefreshRecipeCategoryHeading((char*)self);Object_ConfigureSelectedDisplayPart(self);
  H(0x36e)=9;if(H(0x36a)<0) H(0x36a)=0x29;
  *(short*)(P(0x14)+0x36)=H(0x36a);
  KrakPot_RefreshRecipePage(self);
  KeyRepeater_Reset(self+0x9c);P(0x44)=0;++self[0x390];return;
 }
 if(self[0x390]!=1) return;
 P(0x44)=self+0x36a;
 bool changed=false;
 unsigned flags=*(unsigned*)(self+0x350);
 if(flags&0x10) {++self[0x388];changed=true;}
 else if(flags&0x20) {--self[0x388];changed=true;}
 if(self[0x388]==255) self[0x388]=self[0x389]-1;
 if(self[0x389]<=self[0x388]) self[0x388]=0;
 short* entry=(short*)KrakPot_GetRecipeAtPageRowClamped(self,(short)(H(0x36a)-0x29));
 char* record=0;
 if(entry) {record=(char*)FindNonnegativeHalfwordKeyInPackedTable((Table*)(self+0x74),*entry);KrakPot_GetRecipeIngredientStockCounts((char*)self+0x74,*entry,self+0x398);}
 else Graphics_ClearFlagAndRefreshBackgrounds(owner);
 KrakPot_RequestRecipePreviewIfChanged(owner,entry,record,(int)(self+0x398));
 if(changed) {KrakPot_RefreshRecipePage(self);return;}
 int action=KrakPot_ClassifyRecipeBrowserAction((char*)self);
 if(action==1) {ToggleListModeAndPreserveSelectedNode(self);return;}
 if(action==4) {
  if(entry && record) {
   SetFlag800AndUpdateEmbeddedScreen((char*)owner,(*(unsigned short*)(owner+0x1258)&0x800)==0);
   SoundSfx_StartCurrentSequenceArchiveEntry(Main_UnknownRoleZeroInitializedStorage,1,0);
  }
  return;
 }
 if(!KrakPot_HandleSelectionConfirmInput((Object*)self) && KrakPot_HandleSelectionCancelInput((char*)self)) {
  U(0x394)&=~0x80;
  TextCanvas_ResetDisplayPartByKey(P(0x14),H(0x36e));TextCanvas_ResetDisplayPartByKey(P(0x14),14);TextCanvas_ResetDisplayPartByKey(P(0x14),15);
  self[0x38f]=2;self[0x390]=0;self[0x397]=2;
  Graphics_ClearFlagAndRefreshBackgrounds(owner);
  if(((Category*)(self+0x300))->First() || ((Category*)(self+0x300))->Second()) self[0x390]=2;
 }
 KrakPot_RequestExitOnNewInputMask((Object*)self);
}
