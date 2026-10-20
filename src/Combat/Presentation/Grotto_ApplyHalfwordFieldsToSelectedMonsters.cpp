#include <globaldefs.h>
ARM
extern "C" void *_ZN9GameState11GetInstanceEv(void);
extern "C" int _ZN9GameState31GetMaybeWanderingMonsterByIndexEi(void *, int);
extern "C" void GameObject_SetCameraDisplacementPulse(void *, short, unsigned short);
extern "C" int Combat_DispatchSelectionProcedure(void *, void *, unsigned short, int *);
// Original: arm9/ov025 @ 0x021E7AFC; symbol: Grotto_ApplyHalfwordFieldsToSelectedMonsters; size: 0x78.
// Dispatches selection into an index array, then writes object halfwords +0xA/+0xC to each found wandering monster.
extern "C" int Grotto_ApplyHalfwordFieldsToSelectedMonsters(void *object, void *selection, void *unused, void *context) {
 void *state = _ZN9GameState11GetInstanceEv();
 int indices[12];
 int count = Combat_DispatchSelectionProcedure(context, selection, *(unsigned short *)((char *)object + 8), indices);
 for (int i = 0; i < count; ++i) {
  void *monster = (void *)_ZN9GameState31GetMaybeWanderingMonsterByIndexEi(state, indices[i]);
  if (monster) GameObject_SetCameraDisplacementPulse(monster, *(short *)((char *)object + 0xa), *(unsigned short *)((char *)object + 0xc));
 }
 return 1;
}
