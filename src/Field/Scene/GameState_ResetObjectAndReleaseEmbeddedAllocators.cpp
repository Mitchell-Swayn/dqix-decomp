#include <globaldefs.h>
ARM
extern "C" void GameState_ResetUnknownObjectAndResourceFlag(void *);
extern "C" void Memory_ReleaseTwoEmbeddedAllocatorsAndClearResourceFlag(void *);
// Original: arm9/ov017 @ 0x021BF5DC; symbol: GameState_ResetObjectAndReleaseEmbeddedAllocators; size: 0x18.
// Calls GameState_ResetUnknownObjectAndResourceFlag and Memory_ReleaseTwoEmbeddedAllocatorsAndClearResourceFlag on the same object.
extern "C" void GameState_ResetObjectAndReleaseEmbeddedAllocators(void *object) {
    GameState_ResetUnknownObjectAndResourceFlag(object);
    Memory_ReleaseTwoEmbeddedAllocatorsAndClearResourceFlag(object);
}
