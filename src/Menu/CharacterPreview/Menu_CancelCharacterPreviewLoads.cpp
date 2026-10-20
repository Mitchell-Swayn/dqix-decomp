#include <globaldefs.h>
#include <Filesystem/BackgroundLoader.h>
ARM
#pragma force_active on
struct PreviewLoadTickets { unsigned char preceding[0xbf4]; short tickets[12]; };
// Original: arm9/ov023 @ 0x021E61A0; symbol: func_ov023_021e61a0; size: 0x54.
// Cancels the twelve preview resource tickets and restores their -1 sentinel.
extern "C" void Menu_CancelCharacterPreviewLoads(void* preview) {
    PreviewLoadTickets* state = (PreviewLoadTickets*)preview;
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    for (int i = 0; i < 12; ++i) {
        if (state->tickets[i] > -1) loader->RemoveTask(state->tickets[i]);
        state->tickets[i] = -1;
    }
}
