#include <globaldefs.h>
ARM
struct GameState; struct KeyRepeater;
extern "C" {
void* _ZN9GameState11GetInstanceEv();
unsigned _ZNK9GameState12GetTickCountEv(GameState*);
unsigned char KeyRepeater_Update(KeyRepeater*,int);
void KrakPot_IncreaseIngredientQuantity(unsigned char*);
void KrakPot_DecreaseIngredientQuantity(unsigned char*);
int KrakPot_ReadRepeatedInputKey(void*);
int Menu_HitTestLinkedLayoutGroups(char*);
int Menu_HitTestEnabledLayoutGroups(char*);
}
// Original: arm9/ov006 @ 0x02159834; symbol: func_ov006_02159834; size: 0x178.
// Combines touch and repeated keys to change bounded selection; reports action type.
extern "C" int UpdateBoundedSelectionFromInput(unsigned char* self) {
 int accept=0,cancel=0,direction=0;
 if(self[0x393]<5) ++self[0x393];
 else {
  int key=Menu_HitTestLinkedLayoutGroups((char*)self+0x100);
  if(key==0x76) direction=1;
  if(key==0x77) direction=-1;
  if(direction) self[0x393]=0;
 }
 int jump=0;
 int key=Menu_HitTestEnabledLayoutGroups((char*)self+0x100);
 if(key>=0) {
  if(key==0x76) direction=1;
  if(key==0x77) direction=-1;
  accept=key==0x11;
  cancel=key==0x12;
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
  if(jump==9) KrakPot_IncreaseIngredientQuantity(self);
  else KrakPot_DecreaseIngredientQuantity(self);
  self[0x430]=old<self[0x38b];
  self[0x431]=self[0x38b]<old;
  return 1;
 }
 if(direction) {
  if(direction>0) KrakPot_IncreaseIngredientQuantity(self);
  else KrakPot_DecreaseIngredientQuantity(self);
  return 1;
 }
 if(accept) return 2;
 return cancel?3:0;
}
