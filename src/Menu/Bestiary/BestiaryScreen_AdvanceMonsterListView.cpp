#include <globaldefs.h>
ARM
struct Owner; struct Entry; struct Node;
extern "C" {
void Graphics_PopulateRecordGroupSummaryDisplay(Owner*); void BestiaryScreen_UpdateCategoryHeading(Owner*); void Graphics_SetRecordOptionIndexDisplay(Owner*); void Graphics_PopulateRecordListPage(Owner*);
int FindGroupRecordWithNonzeroFieldsAndFlagTwoClear(unsigned char*,int);
void KeyRepeater_Reset(unsigned char*);
Node* BestiaryScreen_ResolveSelectedMonster(Owner*); unsigned* BestiaryScreen_GetMonsterProgressRecord(Owner*,Entry*);
void BestiaryDetail_BeginMonsterLoad(Owner*,Entry*,unsigned*,unsigned char);
int Graphics_ToggleSelectionFromTouchOrButton(char*);
void BestiaryDetail_UpdateMonsterSelection(Owner*,void*,unsigned*);
void BestiaryScreen_ChangePageWithWrap(Owner*,int);
int BestiaryScreen_ProcessSelectionActivation(Owner*); int DetectInputOutsideScaledTextureRegion(Owner*);
void BestiaryDetail_PlayNextMonsterAnimation(Owner*); void BestiaryDetail_ToggleTriviaPage(Owner*); void BestiaryDetail_CancelLoadsAndRequestDefaultBackground(Owner*);
int Input_IsKeyMaskNewlyPressed(unsigned short*,unsigned int);
void TextCanvas_ResetDisplayPartByKey(unsigned char*,int);
// Original data: arm9/main @ 0x2114e30; symbol: data_02114e30.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern unsigned short KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage[];
}
#define FIELD(t,o) (*(t*)(p+(o)))
// Original: arm9/ov014 @ 0x02188010; symbol: func_ov014_02188010; size: 0x2C4.
// Initializes and advances a selection state, refreshing its mapped display and resetting resource groups on exit.
extern "C" void BestiaryScreen_AdvanceMonsterListView(Owner* self) {
 unsigned char* p=(unsigned char*)self;
 if(p[0x17b]==0) {
  if(p[0x17e]&0x10) return;
  FIELD(unsigned,0xbc)=FIELD(unsigned,0xb8);
  Graphics_PopulateRecordGroupSummaryDisplay(self); BestiaryScreen_UpdateCategoryHeading(self); Graphics_SetRecordOptionIndexDisplay(self);
  FIELD(short,0x170)=5;
  FIELD(short,0x176)=FindGroupRecordWithNonzeroFieldsAndFlagTwoClear(FIELD(unsigned char*,0xc0),FIELD(short,0x170));
  Graphics_PopulateRecordListPage(self);
  KeyRepeater_Reset(p+0x14c);
  FIELD(void*,0xd0)=0;
  ++p[0x17b]; FIELD(void*,0x48)=0; FIELD(void*,0x4c)=0;
  Entry* e=(Entry*)BestiaryScreen_ResolveSelectedMonster(self);
  unsigned* d=BestiaryScreen_GetMonsterProgressRecord(self,e);
  BestiaryDetail_BeginMonsterLoad(self,e,d,1);
  p[0x82]|=8;
 } else if(p[0x17b]==1) {
  FIELD(short*,0xd0)=(short*)(p+0x176);
  if(Graphics_ToggleSelectionFromTouchOrButton((char*)self)) {
   if(FIELD(short,0x178)<0) {
    Entry* e=(Entry*)BestiaryScreen_ResolveSelectedMonster(self);
    if(((unsigned)((unsigned char*)e)[0x13]<<30)>>31) {
     unsigned* d=BestiaryScreen_GetMonsterProgressRecord(self,e); BestiaryDetail_UpdateMonsterSelection(self,e,d);
    }
    FIELD(short,0x178)=*FIELD(short*,0xd0);
   }
   return;
  }
  unsigned flags=FIELD(unsigned,0x160);
  if(flags || FIELD(short,0x178)!=*FIELD(short*,0xd0)) {
   if(flags&0x10) BestiaryScreen_ChangePageWithWrap(self,1);
   else if(flags&0x20) BestiaryScreen_ChangePageWithWrap(self,-1);
   Graphics_PopulateRecordListPage(self);
   Entry* e=(Entry*)BestiaryScreen_ResolveSelectedMonster(self);
   unsigned* d=BestiaryScreen_GetMonsterProgressRecord(self,e); BestiaryDetail_UpdateMonsterSelection(self,e,d);
  }
  if(BestiaryScreen_ProcessSelectionActivation(self)) {
   if(p[0x17e]&0x40) {
    Entry* e=(Entry*)BestiaryScreen_ResolveSelectedMonster(self);
    unsigned* d=BestiaryScreen_GetMonsterProgressRecord(self,e); BestiaryDetail_UpdateMonsterSelection(self,e,d);
   } else BestiaryDetail_PlayNextMonsterAnimation(self);
   return;
  }
  if(Input_IsKeyMaskNewlyPressed(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,0x800)) {BestiaryDetail_ToggleTriviaPage(self);return;}
  if(!DetectInputOutsideScaledTextureRegion(self))return;
  p[0x81]&=~4;
  if(FIELD(signed char,0x17d)>=0)p[0x17a]=3;
  if(FIELD(signed char,0x17d)<0)p[0x17a]=2;
  FIELD(void*,0x48)=0; FIELD(void*,0x4c)=0;
  p[0x17e]|=0x10;
  TextCanvas_ResetDisplayPartByKey(FIELD(unsigned char*,0xc0),FIELD(short,0x170));
  p[0x17b]=0; FIELD(void*,0xd0)=0;
  TextCanvas_ResetDisplayPartByKey(FIELD(unsigned char*,0xc0),4);
  TextCanvas_ResetDisplayPartByKey(FIELD(unsigned char*,0xc0),3);
  BestiaryDetail_CancelLoadsAndRequestDefaultBackground(self);
 }
}
