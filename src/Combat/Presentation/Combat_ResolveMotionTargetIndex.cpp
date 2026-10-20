#include <globaldefs.h>
ARM
extern "C" unsigned int CombatantMotion_GetPrimaryTargetIndex(unsigned char **p);
extern "C" unsigned int CombatantMotion_GetFallbackTargetIndex(char *p);
// Original: arm9/ov025 @ 0x021E1F08; symbol: func_ov025_021e1f08; size: 0x38.
extern "C" int Combat_ResolveMotionTargetIndex(char *obj, void *record) {
    unsigned int result = CombatantMotion_GetPrimaryTargetIndex((unsigned char **)obj);
    if (result != 0xff) return result;
    result = CombatantMotion_GetFallbackTargetIndex(obj);
    if (result != 0xff) return result;
    void *field = *(void **)((char *)record + 0x14);
    if (field != 0) result = *(short *)((char *)field + 0xe);
    return result;
}
