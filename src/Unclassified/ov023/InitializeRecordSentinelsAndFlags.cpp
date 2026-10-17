#pragma thumb off
// Field layout is established by instructions; object semantics remain uncertain.
// Original: arm9/ov023 @ 0x021EEFAC; symbol: func_ov023_021eefac; size: 0x24.
extern "C" void InitializeRecordSentinelsAndFlags(char* obj) {
    *(unsigned*)obj=0;
    *(int*)(obj+4)=-1;
    *(int*)(obj+8)=-1;
    *(unsigned*)(obj+0x70)=0;
    obj[0xe3]=0;
    obj[0xe5]=-1;
}
