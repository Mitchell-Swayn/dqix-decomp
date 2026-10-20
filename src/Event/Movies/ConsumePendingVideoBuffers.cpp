#include <globaldefs.h>
ARM
struct E {int a,b,start,end,pad;}; struct T {E* data; int pad,count;};
extern "C" E* VideoCaptions_FindEntryAtFrame(T*,int);
extern "C" unsigned Graphics_GetVramAddressForModeFlag();
extern "C" unsigned Resource_IsNonNullAndHelperReturnsOne(void*);
extern "C" unsigned ModsDecoder_SkipVideoFrame(void*);
extern "C" void _Z19SleepCurrentContextj(unsigned);
extern "C" void MovieCaptions_DrawProgressiveText(unsigned,void*,int,int,int,int,int,int);
// Original data: arm9/ov016 @ 0x219d144; symbol: data_ov016_0219d144.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov016.md.
extern "C" unsigned MoviePlayDualScreenFiles_UnknownRoleZeroInitializedStorage_Variant2[];
extern "C" unsigned GetSubBG2ScreenBase();
// Original: arm9/ov016 @ 0x0218D0D4; symbol: func_ov016_0218d0d4; size: 0x1C0.
// Consumes pending work into two video destinations and advances counters.
extern "C" void ConsumePendingVideoBuffers(void* first,void* second,T* table) {
 while(*(volatile unsigned*)(MoviePlayDualScreenFiles_UnknownRoleZeroInitializedStorage_Variant2+12)==0){}
 int consumed,produced;
 while((produced=(int)MoviePlayDualScreenFiles_UnknownRoleZeroInitializedStorage_Variant2[6]) <= (consumed=(int)MoviePlayDualScreenFiles_UnknownRoleZeroInitializedStorage_Variant2[7]))_Z19SleepCurrentContextj(1);
 MoviePlayDualScreenFiles_UnknownRoleZeroInitializedStorage_Variant2[0]=0;
 if(MoviePlayDualScreenFiles_UnknownRoleZeroInitializedStorage_Variant2[8]<2 || produced-consumed<=1) {
 E* record=VideoCaptions_FindEntryAtFrame(table,consumed);
 unsigned dest=MoviePlayDualScreenFiles_UnknownRoleZeroInitializedStorage_Variant2[1]==0?0x6820000:0x6800000;
 ((unsigned(*)(void*,unsigned,unsigned,unsigned))Resource_IsNonNullAndHelperReturnsOne)(first,dest,256,0);
 if(record && record->b==0){MovieCaptions_DrawProgressiveText(dest,(void*)record->pad,32767,0,168,1,1,record->a);record->a+=4;}
 dest=MoviePlayDualScreenFiles_UnknownRoleZeroInitializedStorage_Variant2[1]==0?0x6600000:GetSubBG2ScreenBase();
 ((unsigned(*)(void*,unsigned,unsigned,unsigned))Resource_IsNonNullAndHelperReturnsOne)(second,dest,256,0);
 if(record && record->b==1){MovieCaptions_DrawProgressiveText(dest,(void*)record->pad,65535,0,168,1,1,record->a);record->a+=4;}
 MoviePlayDualScreenFiles_UnknownRoleZeroInitializedStorage_Variant2[12]=0;
 }else {ModsDecoder_SkipVideoFrame(first);ModsDecoder_SkipVideoFrame(second);MoviePlayDualScreenFiles_UnknownRoleZeroInitializedStorage_Variant2[8]=0;}
 ++MoviePlayDualScreenFiles_UnknownRoleZeroInitializedStorage_Variant2[7];++MoviePlayDualScreenFiles_UnknownRoleZeroInitializedStorage_Variant2[8];
}
