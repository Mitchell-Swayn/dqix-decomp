#include <globaldefs.h>

extern "C" void SoundCommand_SubmitOpcodeSevenWithPackedMode(unsigned, unsigned, unsigned, unsigned, unsigned);

// Original: arm9/main @ 0x020D1EA0; symbol: func_020d1ea0; size: 0x1C.
extern "C" ARM void SoundCommand_SubmitOpcodeSevenWithSubcommandTwelve(unsigned a, unsigned b, unsigned c) {
    SoundCommand_SubmitOpcodeSevenWithPackedMode(a, b, 12, c, 2);
}
