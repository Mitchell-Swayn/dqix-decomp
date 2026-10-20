#include <globaldefs.h>
ARM
extern "C" void *Combat_FindIndexedMonsterObject(void *, int, int, int);

// Original: arm9/ov024 @ 0x021F6230; symbol: Combat_TryMarkEligibleIndexedState; size: 0x68.
// Finds the indexed flag-0x400 state object; if its sentinel and packed-field checks pass, sets the flag output and copies the input halfword to output.
extern "C" int Combat_TryMarkEligibleIndexedState(void **object, unsigned short value, int key, int *flag, short *output) {
    void *entry = Combat_FindIndexedMonsterObject(*object, value, key, (int)flag);
    if (entry == 0) return 0;
    unsigned char *state = *(unsigned char **)((unsigned char *)entry + 0x138);
    if (*(unsigned short *)(state + 8) >= 0xffff) goto fail;
    int field = *(int *)(state + 0x58);
    if ((field << 29 >> 29) < 2) goto success;
fail:
    return 0;
success:
    *flag = 1;
    *output = (short)value;
    return 1;
}
