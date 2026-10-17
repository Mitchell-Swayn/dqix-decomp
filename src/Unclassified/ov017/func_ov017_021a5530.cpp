#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* _ZN9GameState20GetUnknownGameObjectEv(void*);
extern "C" void Object_ClearTwoStateFieldsAndOptionallyResetAnimation(void*, int);
extern "C" void func_ov017_021a5568(void*);
extern "C" void LinkedQueue_InsertAfterHeadAndMarkLinked(char*, char*);
// Original: arm9/ov017 @ 0x021A5530; symbol: func_ov017_021a5530; size: 0x38.
extern "C" void func_ov017_021a5530(char* p) {
    void* gameState = _ZN9GameState11GetInstanceEv();
    void* object = _ZN9GameState20GetUnknownGameObjectEv(gameState);
    Object_ClearTwoStateFieldsAndOptionallyResetAnimation(object, 1);
    func_ov017_021a5568(*(void**)(p + 0x371c));
    LinkedQueue_InsertAfterHeadAndMarkLinked(*(char**)(p + 0x36fc), *(char**)(p + 0x371c));
}
