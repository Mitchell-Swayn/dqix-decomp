#include <globaldefs.h>
ARM
extern signed char data_ov003_0217fad4[];
extern "C" void *_ZN9GameState11GetInstanceEv(void);
extern "C" int GameState_ReadSupportedFirmwareLanguage(void *);
// Original: arm9/ov003 @ 0x02173F08; symbol: func_ov003_02173f08; size: 0x68.
extern "C" void GameState_CopyLanguageMappedBytes(char *out0, char *out1, char *out2, char *out3) {
    signed char language = (signed char)GameState_ReadSupportedFirmwareLanguage(_ZN9GameState11GetInstanceEv());
    signed char *entry = data_ov003_0217fad4;
    for (;;) {
        signed char value = *entry;
        if (value < 0) {
            entry = data_ov003_0217fad4;
            break;
        }
        if (value == language) break;
        ++entry;
    }
    *out0 = entry[1];
    *out1 = entry[2];
    *out2 = entry[3];
    *out3 = entry[4];
}
