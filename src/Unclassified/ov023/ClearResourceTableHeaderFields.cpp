#pragma thumb off
// Field layout is established by instructions; object semantics remain uncertain.
// Original: arm9/ov023 @ 0x021E20C0; symbol: func_ov023_021e20c0; size: 0x30.
extern "C" void ClearResourceTableHeaderFields(char* obj) {
    *(unsigned*)(obj)=0;
    *(unsigned*)(obj+4)=0;
    *(unsigned*)(obj+8)=0;
    *(unsigned*)(obj+12)=0;
    *(short*)(obj+16)=0;
    *(short*)(obj+18)=0;
    *(short*)(obj+20)=0;
    *(short*)(obj+22)=0;
    *(short*)(obj+72)=0;
    *(short*)(obj+74)=0;
}
