#include <globaldefs.h>
ARM
extern "C" {
void* _ZN9GameState11GetInstanceEv();
unsigned char* _ZN9GameState31GetMaybeWanderingMonsterByIndexEi(void*,int);
int DispatchCombatSelectionProcedure(void*,void*,int,int*);
void ClearMaskedFlagsAtOffsetE0(unsigned char*);
void SetByteAtOffsetE0BitsMask4(unsigned char*);
}
// Original: arm9/ov025 @ 0x021E7E34; symbol: func_ov025_021e7e34; size: 0x84.
extern "C" int Combat_SetSelectedMonsterFlag4(unsigned char* action,void* selection,int unused,void* context) {
 void* state=_ZN9GameState11GetInstanceEv();
 int ids[12];
 int count=DispatchCombatSelectionProcedure(context,selection,*(unsigned short*)(action+8),ids);
 for(int i=0;i<count;++i) {
  unsigned char* monster=_ZN9GameState31GetMaybeWanderingMonsterByIndexEi(state,ids[i]);
  if(monster) {
   if(*(int*)(action+12)) ClearMaskedFlagsAtOffsetE0(monster);
   else SetByteAtOffsetE0BitsMask4(monster);
  }
 }
 return 1;
}
