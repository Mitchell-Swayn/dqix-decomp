extern "C" { void ClearEachIndexedEntryResource(void*); void ProcessAllTwoHundredTwentyFourByteRecordsWhenBothPointersSet(void*); void Graphics_ResetCountedThirtyTwoByteTransfers(void*); void func_ov008_02188730(void*); void func_ov008_02188934(void*); void func_ov008_021889f8(void*); void func_ov008_02188870(void*); void func_ov023_021eb4b8(void*); }
// Original: arm9/ov008 @ 0x02184878; symbol: func_ov008_02184878; size: 0xA0.
extern "C" void func_ov008_02184878(signed char* object) {
    int state=object[0xb10];
    if(state==0 || state==1 || state==14) return;
    if(!*(void**)(object+0xb08)) {ClearEachIndexedEntryResource(object+0x130);ProcessAllTwoHundredTwentyFourByteRecordsWhenBothPointersSet(object+0x130);Graphics_ResetCountedThirtyTwoByteTransfers(object+0x130);}
    if(*(int*)(object+0xb24)==1) return;
    if(object[0xb10]==3 && ((unsigned char*)object)[0xb11]<1) return;
    func_ov008_02188730(object);func_ov008_02188934(object);func_ov008_021889f8(object);func_ov008_02188870(object);
    void* dependency=*(void**)(object+0xb08); if(dependency)func_ov023_021eb4b8(dependency);
}
