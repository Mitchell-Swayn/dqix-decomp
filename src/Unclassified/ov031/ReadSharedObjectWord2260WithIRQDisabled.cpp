int DisableIRQInterrupts();
void SetIRQInterruptState(int);
extern "C" char* data_ov031_0224e53c;
// Original: arm9/ov031 @ 0x0220D540; symbol: func_ov031_0220d540; size: 0x30.
extern "C" unsigned ReadSharedObjectWord2260WithIRQDisabled() {
    int state=DisableIRQInterrupts();
    unsigned value=0;
    char* p=data_ov031_0224e53c;
    if(p)value=*(unsigned*)(p+0x2260);
    SetIRQInterruptState(state);
    return value;
}
