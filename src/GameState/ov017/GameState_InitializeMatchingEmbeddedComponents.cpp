#include <globaldefs.h>
ARM
extern "C" void* OV017_GetEmbeddedField1C(void*);
extern "C" void Object_InitializePackedCountersWeightsAndTimers(unsigned short*);
// Original: arm9/ov017 @ 0x021CA358; symbol: func_ov017_021ca358; size: 0x6C.
extern "C" void GameState_InitializeMatchingEmbeddedComponents(void* unused0, unsigned char* parameter, void* unused2, unsigned char* owner) {
    void* entry = OV017_GetEmbeddedField1C(*(void**)(owner + 0x3718));
    if (!entry) return;
    if (*(unsigned short*)((char*)entry + 8) != *(unsigned short*)(parameter + 4)) return;
    if (parameter[6] && !*(unsigned*)((char*)entry + 0x30)) return;
    for (int i = 0; i < 8; ++i)
        Object_InitializePackedCountersWeightsAndTimers((unsigned short*)((char*)entry + 0x158 + i * 0xa4));
}
