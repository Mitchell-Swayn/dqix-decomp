#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv(void);
extern "C" void** GameState_GetFieldAddress5CA4(void*);
extern "C" void Script_WriteIntegerReferenceOutput(void*, int);
// Original: arm9/ov001 @ 0x02163C28; symbol: GameState_SetNestedObjectPresenceFlag; size: 0x38.
// One C variant matches size and call sequence; difference is conditional flag materialization (original initializes r1 before two guarded loads, candidate uses moveq after the checks). [2026-10-17 11:39 l13e] Sets self's nested type-3 second word according to whether GameState's object and nested pointer at +0x424 are nonnull, then returns 1; exact instruction match.
extern "C" int GameState_SetNestedObjectPresenceFlag(void* self) {
    void* game = _ZN9GameState11GetInstanceEv();
    void** field = GameState_GetFieldAddress5CA4(game);
    void* object = *field;
    int valid = 0;
    if (object == 0) goto done;
    if (*(void**)((char*)object + 0x424) == 0) goto done;
    valid = 1;
done:
    Script_WriteIntegerReferenceOutput(self, valid);
    return 1;
}
