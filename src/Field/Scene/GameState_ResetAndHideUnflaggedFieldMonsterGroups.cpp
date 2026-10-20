#include <globaldefs.h>
ARM
struct Entry { unsigned short id; unsigned short low:2; unsigned short skip:1; unsigned short high:13; };
extern "C" { void* _ZN9GameState11GetInstanceEv(); char* _ZN9GameState27GetMaybeFieldMonsterByIndexEi(void*,int); void* ZoneState_GetTrackedZoneCache(); Entry* GetBoundedEntryAtStride318(void*,int); void _ZN8Object3D10MakeHiddenEv(void*); void Object3D_InitializeExtendedMovementStateDefaults(char*); }
// Original: arm9/ov017 @ 0x0219E0EC; symbol: func_ov017_0219e0ec; size: 0x94.
extern "C" void GameState_ResetAndHideUnflaggedFieldMonsterGroups() {
 int base;
 void* state=_ZN9GameState11GetInstanceEv();
 void* groups=ZoneState_GetTrackedZoneCache();
 for(int group=0;group<4;++group) {
  Entry* entry=GetBoundedEntryAtStride318(groups,group);
  if(entry && !entry->skip) {
   base=group*12+0x70;
   for(int i=0;i<12;++i) {
    char* monster=_ZN9GameState27GetMaybeFieldMonsterByIndexEi(state,i+base);
    if(monster) {
     Object3D_InitializeExtendedMovementStateDefaults(monster);
     _ZN8Object3D10MakeHiddenEv(monster);
    }
   }
  }
 }
}
