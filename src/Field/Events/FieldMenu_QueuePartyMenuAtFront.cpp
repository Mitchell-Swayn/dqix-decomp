#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* _ZN9GameState20GetUnknownGameObjectEv(void*);
extern "C" void GameObject_DisableMovementInput(void*, int);
extern "C" void FieldMenu_InitializePartyMenuCommand(void*);
extern "C" void LinkedQueue_InsertAfterHeadAndMarkLinked(char*, char*);
// Original: arm9/ov017 @ 0x021A5530; symbol: func_ov017_021a5530; size: 0x38.
extern "C" void FieldMenu_QueuePartyMenuAtFront(char* p) {
    void* gameState = _ZN9GameState11GetInstanceEv();
    void* object = _ZN9GameState20GetUnknownGameObjectEv(gameState);
    GameObject_DisableMovementInput(object, 1);
    FieldMenu_InitializePartyMenuCommand(*(void**)(p + 0x371c));
    LinkedQueue_InsertAfterHeadAndMarkLinked(*(char**)(p + 0x36fc), *(char**)(p + 0x371c));
}
