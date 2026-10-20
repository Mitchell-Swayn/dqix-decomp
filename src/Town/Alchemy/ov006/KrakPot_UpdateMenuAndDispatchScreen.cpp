#include <globaldefs.h>
ARM
struct KeyRepeater;struct Obj;struct A;
struct Screen {void Handler();};
typedef void (Screen::*Handler)();
extern "C" {
void DisplayLayout_AdvanceActiveCanvases(unsigned char*,unsigned);
void TextCanvas_ResetDisplayPartByKey(unsigned char*,int);
unsigned TextCanvas_UpdateSelectionFromTouchOrDirection(unsigned char*,short*,int,unsigned short,unsigned char,int);
void TextCanvas_ClearGroupEntrySelection(unsigned char*,int);
int TextCanvas_CreateAndConfigureDisplayPart(char*,int);
unsigned char KeyRepeater_Update(KeyRepeater*,int);
bool Bgm_IsTemporarySequencePendingOrPlaying(char*);
void Window_UpdateOptionSelectionAndEntry(Obj*,int);
unsigned Window_IsVisible(A**);
void KrakPot_UpdateSceneAndDispatchPhase(char*,unsigned);
void KrakPot_RequestMenuExitOnce(unsigned char*);
int GameState_TestFlagOrNewHalfwordMask();
void Text_AdvanceFormattedMessageAndRefreshDisplay(unsigned char*);
int Field_IsHostDisconnectPending();
extern char Main_UnknownRoleZeroInitializedStorage_Variant2[];
extern unsigned KrakPotUpdateMenuAndDispatchScreen_UnknownRoleZeroInitializedStorage;
extern Handler ShopUpdateInterface_UnknownRoleInitializedBytes;
extern Handler KrakPotUpdateMenuAndDispatchScreen_UnknownRoleProcedureReferenceRecords[];
}
#define H(o) (*(short*)(self+(o)))
#define U(o) (*(unsigned short*)(self+(o)))
#define P(o) (*(unsigned char**)(self+(o)))
// Original: arm9/ov006 @ 0x02157D7C; symbol: KrakPot_UpdateMenuAndDispatchScreen; size: 0x2BC.
// Updates screen input and display state, then dispatches the active stage member handler.
extern "C" int KrakPot_UpdateMenuAndDispatchScreen(unsigned char* self,int ticks) {
 *(int*)(self+0x34c)=ticks;
 if(Field_IsHostDisconnectPending()) KrakPot_RequestMenuExitOnce(self);
 if(!(U(0x394)&0x200) && self[0x433]) {
  if(P(0x44)) **(short**)(self+0x44)=-1;
  P(0x44)=0;self[0x38f]=12;self[0x390]=0;self[0x433]=0;
 }
 if((self[0x38f]<=4)<=self[0x38f]) {*((signed char*)self+0x42c)+=ticks;self[0x42c]=((signed char)self[0x42c])&0x3f;}
 if(!Bgm_IsTemporarySequencePendingOrPlaying(Main_UnknownRoleZeroInitializedStorage_Variant2)) self[0x42f]=0;
 KrakPot_UpdateSceneAndDispatchPhase((char*)P(0x10),ticks);
 unsigned char* display=P(0x14);
 if(display) DisplayLayout_AdvanceActiveCanvases(display,ticks);
 if(H(0x37e)>=0) {self[0x42c]=0;Text_AdvanceFormattedMessageAndRefreshDisplay(self);return 0;}
 if(U(0x394)&0x100) {
  if(((int(*)(unsigned char*))GameState_TestFlagOrNewHalfwordMask)(self)) {TextCanvas_ResetDisplayPartByKey(display,0);TextCanvas_ResetDisplayPartByKey(display,1);U(0x394)&=~0x100;}
  return 0;
 }
 if(*(unsigned short*)(P(0x10)+0xae2)&0x380) {self[0x42c]=0;return 0;}
 if(P(0x44)) {
  KeyRepeater_Update((KeyRepeater*)(self+0x9c),ticks);
  H(0x35e)=**(short**)(self+0x44);
  *(unsigned*)(self+0x350)=TextCanvas_UpdateSelectionFromTouchOrDirection(display,*(short**)(self+0x44),H(0x35e),U(0xa8),self[0xaa],(U(0x394)&4)!=0);
  *(short*)(display+0x36)=**(short**)(self+0x44);
  if(*(unsigned*)(self+0x350)) TextCanvas_ClearGroupEntrySelection(display,H(0x36e));
  if(H(0x35e)!=**(short**)(self+0x44)) TextCanvas_CreateAndConfigureDisplayPart((char*)display,H(0x36e));
 }
 if(P(0x18) && Window_IsVisible((A**)P(0x18))) Window_UpdateOptionSelectionAndEntry((Obj*)P(0x18),*(int*)(self+0x34c));
 if(!(KrakPotUpdateMenuAndDispatchScreen_UnknownRoleZeroInitializedStorage&1)) {KrakPotUpdateMenuAndDispatchScreen_UnknownRoleProcedureReferenceRecords[13]=ShopUpdateInterface_UnknownRoleInitializedBytes;KrakPotUpdateMenuAndDispatchScreen_UnknownRoleZeroInitializedStorage|=1;}
 if(!KrakPotUpdateMenuAndDispatchScreen_UnknownRoleProcedureReferenceRecords[self[0x38f]]) return 1;
 (((Screen*)self)->*KrakPotUpdateMenuAndDispatchScreen_UnknownRoleProcedureReferenceRecords[self[0x38f]])();
 return 0;
}
