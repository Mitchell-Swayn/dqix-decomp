#pragma thumb off
// Field layout is established by instructions; object semantics remain uncertain.
// Original: arm9/ov000 @ 0x0215A8D4; symbol: func_ov000_0215a8d4; size: 0x34.
extern "C" void IncrementByteCounterWithSpecialIndex(unsigned char* obj,int index) {
    unsigned char* counters=obj+0x8d5c;
    counters[index]++;
    if(counters[index]>99)counters[index]=99;
    if(index==9)counters[index]=1;
}
