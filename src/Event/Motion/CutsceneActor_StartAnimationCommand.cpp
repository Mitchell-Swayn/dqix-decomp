#include <globaldefs.h>
extern "C" int _fflt(int);
// Original data: arm9/ov001 @ 0x2165884; symbol: data_ov001_02165884.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 52 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov001.md.
extern "C" unsigned AdvanceSessionCommandLists_UnknownRoleZeroInitializedStorage;
extern "C" void Graphics_SetIndexedObjectRegularAnimation(unsigned, unsigned, void *, unsigned, int);
// Original: arm9/ov001 @ 0x02159A00; symbol: func_ov001_02159a00; size: 0x74.
extern "C" int CutsceneActor_StartAnimationCommand(void *entry, void *context) {
    if (*(unsigned *)((char *)entry + 0x18) != 0) goto rejected;
    int fixed = _fflt(*(int *)((char *)entry + 0x14));
    Graphics_SetIndexedObjectRegularAnimation(AdvanceSessionCommandLists_UnknownRoleZeroInitializedStorage, *(unsigned *)((char *)context + 0x70), (char *)entry + 0x1c, *(unsigned *)((char *)entry + 0x10), fixed);
    unsigned *related = *(unsigned **)((char *)entry + 0x3c);
    if (related && (*related == 0xd || *related == 0xf)) return 0;
    *(unsigned *)((char *)entry + 0x18) = 1;
    return 1;
rejected:
    return 0;
}
