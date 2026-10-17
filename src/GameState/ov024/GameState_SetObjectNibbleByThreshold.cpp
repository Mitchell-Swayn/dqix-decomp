#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* GameState_GetObjectWithFlag100(void*, int);
extern "C" unsigned ReadNestedFieldAtOffset150And150And950And16C(void*);
struct State { char pad[0x3b]; unsigned char low : 4; unsigned char category : 4; };
// Original: arm9/ov024 @ 0x021EB3E0; symbol: func_ov024_021eb3e0; size: 0x9C.
extern "C" void GameState_SetObjectNibbleByThreshold(void *unused, int index) {
    char *object = (char*)GameState_GetObjectWithFlag100(_ZN9GameState11GetInstanceEv(), index);
    if (!object) return;
    if (ReadNestedFieldAtOffset150And150And950And16C(object) >= 75) {
        (*(State**)(object + 0x138))->category = 10;
    } else if (ReadNestedFieldAtOffset150And150And950And16C(object) >= 50) {
        (*(State**)(object + 0x138))->category = 9;
    } else if (ReadNestedFieldAtOffset150And150And950And16C(object) >= 25) {
        (*(State**)(object + 0x138))->category = 8;
    } else {
        (*(State**)(object + 0x138))->category = 7;
    }
}
