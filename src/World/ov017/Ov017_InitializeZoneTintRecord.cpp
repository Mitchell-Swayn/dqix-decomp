#include <globaldefs.h>
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* GameState_ReadUnkF8(void*);
extern "C" void* ReadGlobalValueAt020FB3F0();
extern "C" void* _ZN9GameState14GetProtagonistEv(void*);
extern "C" void InitializeRecordWithEnabledAndInvalidIndices(char*);
extern "C" void _ZN8Vector3iaSERKS_(void*, const void*);
// Original: arm9/ov017 @ 0x0219BCAC; symbol: func_ov017_0219bcac; size: 0x70.
extern "C" ARM void Ov017_InitializeZoneTintRecord(unsigned char enabled) {
    void* state = _ZN9GameState11GetInstanceEv();
    void* record = GameState_ReadUnkF8(state);
    unsigned short* global = (unsigned short*)ReadGlobalValueAt020FB3F0();
    void* protagonist = _ZN9GameState14GetProtagonistEv(state);
    InitializeRecordWithEnabledAndInvalidIndices((char*)record);
    *(unsigned short*)record = *global;
    _ZN8Vector3iaSERKS_((char*)record + 0x10, (char*)protagonist + 0x44);
    *(unsigned short*)((char*)record + 0x1c) = *(unsigned int*)((char*)protagonist + 0x54);
    *(unsigned char*)((char*)record + 7) = 1;
    *(unsigned char*)((char*)record + 2) = 1;
    *(unsigned char*)((char*)record + 9) = 0;
    *(unsigned char*)((char*)record + 0xa) = 1;
    *(unsigned char*)((char*)record + 0x65) = enabled;
}
