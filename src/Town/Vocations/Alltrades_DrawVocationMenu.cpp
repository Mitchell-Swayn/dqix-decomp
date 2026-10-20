#include <globaldefs.h>
ARM
extern "C" void Graphics_CleanupActiveObjectResourceBlock(void*);
extern "C" void TextCanvas_ClearDisplayLayerBuffers(void*);
extern "C" void TextCanvas_CopyAllDisplayPartsToLayers(void*);
extern "C" void TextCanvas_FillDisplayPartRegionsOnLayer(void*,int,int,int);
extern "C" void Graphics_CleanConfiguredDestinationCacheForEachThirtyTwoByteEntry(void*);
extern "C" unsigned Window_IsVisible(void*);
extern "C" void Window_UpdateEnabledEntryAndRoot(void*,void*);
extern "C" void UpdateReadyLookupCoordinatesAndResourceEntries(char*);
// Original: arm9/ov003 @ 0x02154EEC; symbol: UpdateActiveTransferRecordsAndWindow; size: 0x94.
// Updates active transfer owner or counted records, then chooses enabled window update or resource-coordinate refresh.
extern "C" void Alltrades_DrawVocationMenu(char* p){
 if(!*(unsigned char*)(p+0x1f8))return;
 if(*(void**)(p+0x204))Graphics_CleanupActiveObjectResourceBlock(*(void**)(p+0x204));
 else{void* r=*(void**)(p+0x18);if(r){TextCanvas_ClearDisplayLayerBuffers(r);TextCanvas_CopyAllDisplayPartsToLayers(r);TextCanvas_FillDisplayPartRegionsOnLayer(r,2,1,1);Graphics_CleanConfiguredDestinationCacheForEachThirtyTwoByteEntry(r);}}
 if(*(void**)(p+0x1c)&&Window_IsVisible(*(void**)(p+0x1c)))Window_UpdateEnabledEntryAndRoot(*(void**)(p+0x1c),p+0x2c);
 else UpdateReadyLookupCoordinatesAndResourceEntries(p);
}
