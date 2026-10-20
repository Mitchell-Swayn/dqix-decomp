#include <globaldefs.h>
ARM
extern "C" void TextCanvas_ClearDisplayLayerBuffers(void*);
extern "C" void TextCanvas_CopyAllDisplayPartsToLayers(void*);
extern "C" void TextCanvas_FillDisplayPartRegionsOnLayer(void*,int,int,int);
extern "C" void Graphics_CleanConfiguredDestinationCacheForEachThirtyTwoByteEntry(void*);
extern "C" void Shop_DrawItemSelectionCursor(void*);
extern "C" void Window_UpdateEntryIfBitSet(void*);
extern "C" void Graphics_UpdateTwoIndexedPartPositions(void*);
extern "C" void Graphics_DrawPageRecordKindIcons(void*);
extern "C" void Shop_DrawQuantityAdjustmentSprites(void*);
// Original: arm9/ov003 @ 0x0217480C; symbol: Graphics_RefreshActivePageTransfersAndParts; size: 0x84.
// Refreshes active page transfer records and indexed display parts, clearing pending flags.
extern "C" void Graphics_RefreshActivePageTransfersAndParts(char* self) {
 if(!*(unsigned char*)(self+0x103e))return;
 void* records=*(void**)(self+0x89c);
 TextCanvas_ClearDisplayLayerBuffers(records);TextCanvas_CopyAllDisplayPartsToLayers(records);
 TextCanvas_FillDisplayPartRegionsOnLayer(records,1,2,1);Graphics_CleanConfiguredDestinationCacheForEachThirtyTwoByteEntry(records);
 Shop_DrawItemSelectionCursor(self);Window_UpdateEntryIfBitSet(self);Graphics_UpdateTwoIndexedPartPositions(self);Graphics_DrawPageRecordKindIcons(self);Shop_DrawQuantityAdjustmentSprites(self);
 self[0x104c]=0;self[0x104b]=0;
}
