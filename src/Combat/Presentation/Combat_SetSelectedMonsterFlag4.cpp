#include <globaldefs.h>
ARM
extern "C" {
void* _ZN9GameState11GetInstanceEv();
unsigned char* _ZN9GameState31GetMaybeWanderingMonsterByIndexEi(void*,int);
int Combat_DispatchSelectionProcedure(void*,void*,int,int*);
void GameObject_EnableMotionUpdates(unsigned char*);
void GameObject_DisableMotionUpdates(unsigned char*);
}
// Original: arm9/ov025 @ 0x021E7E34; symbol: func_ov025_021e7e34; size: 0x84.
extern "C" int Combat_SetSelectedMonsterFlag4(unsigned char* action,void* selection,int unused,void* context) {
 void* state=_ZN9GameState11GetInstanceEv();
 int ids[12];
 int count=Combat_DispatchSelectionProcedure(context,selection,*(unsigned short*)(action+8),ids);
 for(int i=0;i<count;++i) {
  unsigned char* monster=_ZN9GameState31GetMaybeWanderingMonsterByIndexEi(state,ids[i]);
  if(monster) {
   if(*(int*)(action+12)) GameObject_EnableMotionUpdates(monster);
   else GameObject_DisableMotionUpdates(monster);
  }
 }
 return 1;
}
