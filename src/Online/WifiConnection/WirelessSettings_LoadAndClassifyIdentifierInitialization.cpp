#include <globaldefs.h>
ARM
extern "C" void OSi_ReferSymbol(const void*);
extern "C" int WfcUtility_LoadAndRepairSettingsPages(char*);
extern "C" int WfcUtility_ArePersistentIdentifiersEmpty(void);
extern "C" int WfcUtility_GenerateAndStorePersistentIdentifier(unsigned);
// Original: arm9/ov031 @ 0x02212CBC; symbol: func_ov031_02212cbc; size: 0x64.
// Loads settings, generates a missing identifier, and classifies load and generation outcomes.
extern "C" unsigned WirelessSettings_LoadAndClassifyIdentifierInitialization(unsigned char* settings) {
    int loadResult;
    int generated = 0;
    OSi_ReferSymbol((const void*)0x02000c5c);
    loadResult = WfcUtility_LoadAndRepairSettingsPages((char*)settings);
    if (WfcUtility_ArePersistentIdentifiersEmpty()) {
        WfcUtility_GenerateAndStorePersistentIdentifier((unsigned)settings);
        generated = 1;
    }
    if (loadResult < 0) return generated ? 2 : 3;
    return generated ? 1 : 0;
}
