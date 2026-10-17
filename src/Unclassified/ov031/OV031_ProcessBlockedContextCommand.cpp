#include <globaldefs.h>
extern "C" unsigned GetOverlaySharedWord();
extern "C" int func_ov031_0220f2e0(void *);
extern "C" int ValidateStatusElevenAndDispatchBoundedBufferCommand(int, const void *, void *, unsigned);
extern "C" void Ov031_DecrementBlockedContextCount(char *);
extern "C" unsigned char data_ov031_0224e54c[];
extern "C" void func_ov031_0220f2cc();
// Original: arm9/ov031 @ 0x0220EFD0; symbol: func_ov031_0220efd0; size: 0x70.
extern "C" void OV031_ProcessBlockedContextCommand(void) {
    unsigned char *shared = (unsigned char *)GetOverlaySharedWord();
    if (!shared) return;
    if (*(unsigned *)(shared + 0x2260) != 9) return;
    if (shared[0x226b] == 1) return;
    if (!func_ov031_0220f2e0(data_ov031_0224e54c)) return;
    int status = ValidateStatusElevenAndDispatchBoundedBufferCommand((int)func_ov031_0220f2cc, shared + 0x2144, shared + 0xf00, 0);
    if (status != 2) Ov031_DecrementBlockedContextCount((char *)data_ov031_0224e54c);
}
