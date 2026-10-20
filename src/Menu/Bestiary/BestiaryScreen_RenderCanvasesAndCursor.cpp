extern "C" {
struct Table { unsigned short first, count, n, m; unsigned pad; unsigned* base; unsigned char* relocBase; };
struct Node { Node* next; };
struct Owner { unsigned char pad[0xb8]; Node* head; Node* selected; void* service; unsigned char gap[0xc]; short* linked; unsigned char gap2[0xa6]; unsigned char state, phase, other[3], closed; };
struct Stream { unsigned char data[0x14]; short index; unsigned short active; int handle; void* source; };
void TextCanvas_ClearDisplayLayerBuffers(void*); void TextCanvas_CopyAllDisplayPartsToLayers(void*); void TextCanvas_FillDisplayPartRegionsOnLayer(void*,int,int,int); void Graphics_CleanConfiguredDestinationCacheForEachThirtyTwoByteEntry(void*); void BestiaryScreen_DrawSelectionCursor(void*);
// Original: arm9/ov014 @ 0x02186D7C; symbol: func_ov014_02186d7c; size: 0x4C.
 void BestiaryScreen_RenderCanvasesAndCursor(Owner* p) { if(!p->state)return;TextCanvas_ClearDisplayLayerBuffers(p->service);TextCanvas_CopyAllDisplayPartsToLayers(p->service);TextCanvas_FillDisplayPartRegionsOnLayer(p->service,1,0,1);Graphics_CleanConfiguredDestinationCacheForEachThirtyTwoByteEntry(p->service);BestiaryScreen_DrawSelectionCursor(p); }
}
