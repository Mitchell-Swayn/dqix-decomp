extern "C" { void Window_ClearResourceBuffers(void*); void ProcessAllTwoHundredTwentyFourByteRecordsWhenBothPointersSet(void*); void Graphics_ResetCountedThirtyTwoByteTransfers(void*); void Graphics_SubmitVisibleStatisticRows(void*); void Graphics_SubmitEnabledPanelMarkerPair(void*); void Graphics_SetRenderBindingWordsAndRefreshWhenFlag80000Set(void*); void UpdateSelectionMarkerPositionAndTick(void*); void Graphics_CleanupActiveObjectResourceBlock(void*); }
// Original: arm9/ov008 @ 0x02184878; symbol: func_ov008_02184878; size: 0xA0.
extern "C" void Graphics_UpdateOverlay8PanelAndReleaseResources(signed char* object) {
    int state=object[0xb10];
    if(state==0 || state==1 || state==14) return;
    if(!*(void**)(object+0xb08)) {Window_ClearResourceBuffers(object+0x130);ProcessAllTwoHundredTwentyFourByteRecordsWhenBothPointersSet(object+0x130);Graphics_ResetCountedThirtyTwoByteTransfers(object+0x130);}
    if(*(int*)(object+0xb24)==1) return;
    if(object[0xb10]==3 && ((unsigned char*)object)[0xb11]<1) return;
    Graphics_SubmitVisibleStatisticRows(object);Graphics_SubmitEnabledPanelMarkerPair(object);Graphics_SetRenderBindingWordsAndRefreshWhenFlag80000Set(object);UpdateSelectionMarkerPositionAndTick(object);
    void* dependency=*(void**)(object+0xb08); if(dependency)Graphics_CleanupActiveObjectResourceBlock(dependency);
}
