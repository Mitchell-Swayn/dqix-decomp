#include <globaldefs.h>
ARM
struct GameState; struct KeyRepeater;
extern "C" {
void* _ZN9GameState11GetInstanceEv();
unsigned _ZNK9GameState12GetTickCountEv(GameState*);
unsigned char KeyRepeater_Update(KeyRepeater*,int);
int KrakPot_HasIngredientsForBatch(char*,int);
void KrakPot_RefreshRecipeBatchQuantity(void*);
void Graphics_ConfigureSelectedDisplayPartTen(unsigned char*);
int KrakPot_ReadRepeatedInputKey(void*);
int Menu_HitTestLinkedLayoutGroups(char*);
int Menu_HitTestEnabledLayoutGroups(char*);
}
// Original: arm9/ov006 @ 0x021599C0; symbol: func_ov006_021599c0; size: 0x1F0.
// Combines touch and repeated keys to change bounded selection; reports action type.
extern "C" int UpdateIngredientLimitedSelectionFromInput(unsigned char* self) {
 int accept=0,cancel=0,direction=0;
 if(self[0x393]<5) ++self[0x393];
 else {
  int key=Menu_HitTestLinkedLayoutGroups((char*)self+0x100);
  if(key==0x49) direction=1;
  if(key==0x4a) direction=-1;
  if(direction) self[0x393]=0;
 }
 int jump=0;
 int key=Menu_HitTestEnabledLayoutGroups((char*)self+0x100);
 if(key>=0) {
  if(key==0x49) direction=1;
  if(key==0x4a) direction=-1;
  accept=key==0x4e;
  cancel=key==0x14;
 }
 unsigned short event=KeyRepeater_Update((KeyRepeater*)(self+0x9c),_ZNK9GameState12GetTickCountEv((GameState*)_ZN9GameState11GetInstanceEv()));
 if(event==1 || event==2) {
  int key=KrakPot_ReadRepeatedInputKey(self+0x9c);
  if(key==0x40) direction=1;
  if(key==0x80) direction=-1;
  if(key==0x20) jump=9;
  if(key==0x10) jump=1;
 }
 if(jump) {
  int old=self[0x38b]; self[0x38b]=jump;
  while(!KrakPot_HasIngredientsForBatch((char*)self+0x74,self[0x38b])) --self[0x38b];
  if(old<self[0x38b]) self[0x430]=1;
  if(self[0x38b]<old) self[0x431]=1;
  Graphics_ConfigureSelectedDisplayPartTen(self);
  KrakPot_RefreshRecipeBatchQuantity(self);
  return 1;
 }
 if(direction) {
  int old=self[0x38b];
  self[0x38b]+=direction;
  if(!KrakPot_HasIngredientsForBatch((char*)self+0x74,self[0x38b])) --self[0x38b];
  if(self[0x38b]==0) self[0x38b]=1;
  if(self[0x38b]>9) self[0x38b]=9;
  if(old<self[0x38b]) self[0x430]=1;
  if(self[0x38b]<old) self[0x431]=1;
  Graphics_ConfigureSelectedDisplayPartTen(self);
  KrakPot_RefreshRecipeBatchQuantity(self);
  return 1;
 }
 if(accept) return 2;
 return cancel?3:0;
}
