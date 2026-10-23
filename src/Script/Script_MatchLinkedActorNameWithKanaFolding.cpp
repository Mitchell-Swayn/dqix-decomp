#include <globaldefs.h>
#include <std_library_functions.h>
#include <GameState/GameState.h>
// Matches the legacy scalar alias in the linked-state owner definition.
typedef unsigned int undefined4;
ARM
extern "C" GameObject* GameState_GetObjectWithFlag100(GameState*, int);
// The existing owner represents the object and linked pointer as machine words.
extern "C" unsigned GameObject_GetLinkedIndexedState(int);

// Original: arm9/main @ 0x0206483C; symbol: func_0206483c; size: 0xC8.
// Compares the linked actor name prefix, allowing the observed alternate second-byte mapping.
// The first incoming word is unused. The comparison runs for the actor-name length.
extern "C" int Script_MatchLinkedActorNameWithKanaFolding(unsigned, const char* input)
{
    GameObject* object = GameState_GetObjectWithFlag100(GameState::GetInstance(), 0);
    const char* name = (const char*)GameObject_GetLinkedIndexedState((int)object) + 0x3c;
    int length = (int)strlen(name);
    int highByteAdjustment = 0x5e;
    int lowByteAdjustment = 0x5f;
    bool firstByteMatches;
    for (int i = 0; i < length; ++input, ++name, ++i) {
        if (i % 2 == 0) {
            if (*input == *name) firstByteMatches = true;
            else firstByteMatches = false;
        } else if (firstByteMatches) {
            if (*input != *name) return 0;
        } else {
            unsigned char folded = (unsigned char)*input;
            unsigned char expected = (unsigned char)*name;
            int adjustment = lowByteAdjustment;
            if (folded > 0x7f) adjustment = highByteAdjustment;
            folded += adjustment;
            if (folded != expected) return 0;
        }
    }
    return 1;
}
