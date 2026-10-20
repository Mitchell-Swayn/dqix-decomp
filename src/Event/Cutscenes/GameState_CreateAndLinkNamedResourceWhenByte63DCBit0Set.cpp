#include <globaldefs.h>
ARM
extern "C" void *_ZN9GameState11GetInstanceEv(void);
extern "C" int GameState_TestTransitionRequestFlags(void *, unsigned int);
extern "C" void Field_QueueMemoryScenarioScript(void);
// Original: arm9/ov001 @ 0x021624A8; symbol: GameState_CreateAndLinkNamedResourceWhenByte63DCBit0Set; size: 0x24.
// Tests GameState byte flags at offset 0x63DC with mask 1, conditionally creates and links the named resource entry, and returns 1.
extern "C" int GameState_CreateAndLinkNamedResourceWhenByte63DCBit0Set(void) {
    if (GameState_TestTransitionRequestFlags(_ZN9GameState11GetInstanceEv(), 1))
        Field_QueueMemoryScenarioScript();
    return 1;
}
