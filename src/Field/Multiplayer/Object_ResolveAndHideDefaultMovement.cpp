#include <globaldefs.h>
ARM
extern "C" int Field_ResolveSynchronizedMonster(void *, void *, int);
extern "C" void Object3D_InitializeExtendedMovementStateDefaults(char *);
extern "C" void _ZN8Object3D10MakeHiddenEv(void *);
// Original: arm9/ov017 @ 0x021C95B4; symbol: Object_ResolveAndHideDefaultMovement; size: 0x38.
// Resolves the nested object, initializes default movement state, and hides it when found.
extern "C" void Object_ResolveAndHideDefaultMovement(void *a, void *b) {
 void *slots[3];
 if (Field_ResolveSynchronizedMonster((char *)b + 4, slots, -1)) {
  Object3D_InitializeExtendedMovementStateDefaults((char *)slots[2]);
  _ZN8Object3D10MakeHiddenEv(slots[2]);
 }
}
