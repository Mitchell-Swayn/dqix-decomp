#include <globaldefs.h>
#include <std_library_functions.h>
ARM
struct Object;
extern "C" {
unsigned int TextContext_GetSharedInstance();
ARM void Window_PopTextCanvases(Object* p, unsigned count);
}
namespace {
extern "C" void Bank_AppendBalanceOrEmptyAccountMessage(void* self, const char* buffer);
extern "C" void TextWindow_StartFormattedMessage(void* context, unsigned text, unsigned a, unsigned b);
}

// Original: arm9/ov003 @ 0x02169430; symbol: func_ov003_02169430; size: 0x88.
// Pops the bank window, fills the farewell account message, and waits for
// the formatted text window to finish before returning to the parent state.
extern "C" void Bank_AdvanceFarewellMessage(unsigned char* self)
{
    unsigned shared = TextContext_GetSharedInstance();
    unsigned char phase = self[0x4e8];
    if (phase == 0) {
        Window_PopTextCanvases((Object*)(self + 0xe4), 1);
        memset(*(void**)(self + 0x7c), 0, 0x960);
        Bank_AppendBalanceOrEmptyAccountMessage(self, *(const char**)(self + 0x7c));
        TextWindow_StartFormattedMessage(
            (void*)shared, *(unsigned*)(self + 0x7c), 0, 0xe3);
        self[0x4e8] = (unsigned char)(self[0x4e8] + 1);
        return;
    }
    if (phase == 1) {
        if (*(int*)(shared + 0x998) == 0) {
            self[0x4ec] = 6;
            self[0x4e8] = 0;
        }
    }
}
