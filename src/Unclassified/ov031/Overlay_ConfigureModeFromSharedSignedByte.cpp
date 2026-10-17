#include <globaldefs.h>
ARM
extern "C" void func_ov031_0222a900(void);
extern "C" void func_ov031_0222a904(void);
extern "C" int ReadSharedObjectSignedByte1B(void);
extern "C" unsigned char data_ov031_02290c78;
extern "C" void System_ResolveGlobalGroupEntry(unsigned);
extern "C" void Ov031_SetGlobalObjectField1E298(unsigned);
extern "C" void CreateSharedDisplayResource(void);
extern "C" void SetMainLoopCallback(void*);
extern "C" void ConfigureThirdContextFromSharedState(void);
// Original: arm9/ov031 @ 0x0222A890; symbol: func_ov031_0222a890; size: 0x70.
extern "C" void Overlay_ConfigureModeFromSharedSignedByte(void) {
    func_ov031_0222a900();
    func_ov031_0222a904();
    int state = ReadSharedObjectSignedByte1B();
    switch (state) {
    case 0:
        *((unsigned char*)&data_ov031_02290c78 + 1) = 0;
        System_ResolveGlobalGroupEntry(7);
        break;
    case 1:
        *((unsigned char*)&data_ov031_02290c78 + 1) = 1;
        System_ResolveGlobalGroupEntry(0xe);
        break;
    default:
        return;
    }
    Ov031_SetGlobalObjectField1E298(0);
    CreateSharedDisplayResource();
    SetMainLoopCallback((void*)ConfigureThirdContextFromSharedState);
}
