#include <globaldefs.h>
ARM
extern "C" int Input_TestKeyMask(unsigned short *, unsigned short);
extern "C" int Input_IsKeyMaskReleased(unsigned short *, unsigned int);
extern "C" int CharacterViewer_UpdateCameraTargetFollowingFromInput(void *);
// Original data: arm9/main @ 0x2114e30; symbol: data_02114e30.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned short KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov015 @ 0x02190C98; symbol: IsObjectActiveForPressedOrReleasedInput; size: 0x70.
// Returns active when object flag +0x350 is set or, outside the state predicate, input mask 0xC0 is pressed or released.
extern "C" int IsObjectActiveForPressedOrReleasedInput(void *obj) {
 if (*(unsigned char *)((char *)obj + 0x350)) return 1;
 if (!CharacterViewer_UpdateCameraTargetFollowingFromInput(obj) && Input_TestKeyMask(&KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage, 0xc0)) return 1;
 if (!CharacterViewer_UpdateCameraTargetFollowingFromInput(obj) && Input_IsKeyMaskReleased(&KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage, 0xc0)) return 1;
 return 0;
}
