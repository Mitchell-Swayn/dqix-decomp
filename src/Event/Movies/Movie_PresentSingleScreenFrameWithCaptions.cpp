#include <globaldefs.h>
ARM
struct E {int a,b,start,end,pad;}; struct T {E* data; int pad,count;};
extern "C" E* VideoCaptions_FindEntryAtFrame(T*,int);
extern "C" unsigned Graphics_GetVramAddressForModeFlag();
extern "C" unsigned Resource_IsNonNullAndHelperReturnsOne(void*);
extern "C" unsigned ModsDecoder_SkipVideoFrame(void*);
extern "C" void _Z19SleepCurrentContextj(unsigned);
extern "C" void* __clear(void*,unsigned);
extern "C" unsigned TextContext_GetSharedInstance();
extern "C" void TextMarkup_ExpandAndWrapText(void*,int,void*,void*,int,int,unsigned);
extern "C" void MovieCaptions_DrawProgressiveText(unsigned,void*,int,int,int,int,int,int);
// Original data: arm9/ov016 @ 0x219d0c0; symbol: data_ov016_0219d0c0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov016.md.
extern "C" unsigned MemoryAllocateSafe_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov016 @ 0x0218BEC4; symbol: func_ov016_0218bec4; size: 0x160.
// Waits for pending producer work, processes a record, and advances consumption counters.
extern "C" void Movie_PresentSingleScreenFrameWithCaptions(void* object,T* table) {
 while (*(volatile unsigned*)(MemoryAllocateSafe_UnknownRoleZeroInitializedStorage+5)==0) {}
 int consumed,produced;
 while ((produced=(int)MemoryAllocateSafe_UnknownRoleZeroInitializedStorage[15]) <= (consumed=(int)MemoryAllocateSafe_UnknownRoleZeroInitializedStorage[7])) _Z19SleepCurrentContextj(1);
 MemoryAllocateSafe_UnknownRoleZeroInitializedStorage[1]=0;
 if(MemoryAllocateSafe_UnknownRoleZeroInitializedStorage[8]<2 || produced-consumed<=1) {
 E* record=VideoCaptions_FindEntryAtFrame(table,consumed);
 ((unsigned(*)(void*,unsigned,unsigned,unsigned))Resource_IsNonNullAndHelperReturnsOne)(object,Graphics_GetVramAddressForModeFlag(),256,0);
 if(record && !record->b) {
 unsigned scratch[128]; __clear(scratch,512);
 TextMarkup_ExpandAndWrapText((void*)TextContext_GetSharedInstance(),12,(void*)record->pad,scratch,227,0,1);
 MovieCaptions_DrawProgressiveText(Graphics_GetVramAddressForModeFlag(),scratch,32767,0,168,1,1,record->a);
 record->a+=4;
 }
 MemoryAllocateSafe_UnknownRoleZeroInitializedStorage[5]=0;
 } else { ModsDecoder_SkipVideoFrame(object);MemoryAllocateSafe_UnknownRoleZeroInitializedStorage[8]=0; }
 ++MemoryAllocateSafe_UnknownRoleZeroInitializedStorage[7];++MemoryAllocateSafe_UnknownRoleZeroInitializedStorage[8];
}
