#include <globaldefs.h>
ARM
// Original data: arm9/ov003 @ 0x217fad4; symbol: data_ov003_0217fad4.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 0108402828020840282804043a3030030840182005043a3030ff000000000000.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov003.md.
extern signed char GameStateCopyLanguageMappedBytes_UnknownRoleInitializedBytes[];
extern "C" void *_ZN9GameState11GetInstanceEv(void);
extern "C" int GameState_ReadSupportedFirmwareLanguage(void *);
// Original: arm9/ov003 @ 0x02173F08; symbol: func_ov003_02173f08; size: 0x68.
extern "C" void GameState_CopyLanguageMappedBytes(char *out0, char *out1, char *out2, char *out3) {
    signed char language = (signed char)GameState_ReadSupportedFirmwareLanguage(_ZN9GameState11GetInstanceEv());
    signed char *entry = GameStateCopyLanguageMappedBytes_UnknownRoleInitializedBytes;
    for (;;) {
        signed char value = *entry;
        if (value < 0) {
            entry = GameStateCopyLanguageMappedBytes_UnknownRoleInitializedBytes;
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
