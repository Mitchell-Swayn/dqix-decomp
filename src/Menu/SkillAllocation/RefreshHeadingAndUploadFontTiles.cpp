#include <globaldefs.h>
ARM
extern "C" void Window_BindNextCanvasResourceByFormatAndLayer(char*,unsigned,unsigned);
extern "C" void* memset(void*,int,unsigned);
extern "C" void* memcpy(void*,const void*,unsigned);
extern "C" void AppendCenteredHeadingAndSevenValues(char*,char*);
extern "C" void Window_PushTextCanvas(void*,void*,int,int,int,int,int,int);
extern "C" unsigned ComputeIndexedEntryAddressAtStride40(void*,unsigned);
extern "C" char* TextLayout_GetThirtyTwoByteFontEntry(int);
extern "C" void _Z25CleanInvalidateCacheRangePKvj(const void*,unsigned);
extern "C" void _Z15CleanCacheRangePKvj(const void*,unsigned);
extern "C" void LoadToSubObjVRAM(const void*,unsigned,unsigned);
extern "C" void LoadToMainObjVRAM(const void*,unsigned,unsigned);
// Original data: arm9/ov013 @ 0x2187d9c; symbol: data_ov013_02187d9c.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 2000000007000000.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov013.md.
// Original data: arm9/ov013 @ 0x2187da4; symbol: data_ov013_02187da4.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 2a00000005000000.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov013.md.
extern "C" unsigned RefreshHeadingAndUploadFontTiles_UnknownRoleInitializedBytes_Variant2[],RefreshHeadingAndUploadFontTiles_UnknownRoleInitializedBytes[];
// Original: arm9/ov013 @ 0x02185CC0; symbol: func_ov013_02185cc0; size: 0x180.
// Refreshes formatted heading and copies its selected font tiles to object VRAM.
extern "C" void RefreshHeadingAndUploadFontTiles(char* p){
 Window_BindNextCanvasResourceByFormatAndLayer(p+0x38,0,2);
 *(short*)(p+0xd8)=15;*(short*)(p+0xda)=11;*(short*)(p+0xdc)=1;*(short*)(p+0xde)=13;
 *(short*)(p+0xe0)=6;*(short*)(p+0xe2)=5;*(short*)(p+0xe4)=10;*(short*)(p+0xe6)=13;
 p[0xe9]=4;p[0xed]=!*(unsigned char*)(p+0x640);
 memset(*(void**)(p+0x658),0,0x960);AppendCenteredHeadingAndSevenValues(p,*(char**)(p+0x658));
 Window_PushTextCanvas(p+0x38,*(void**)(p+0x658),0,0,0,1,0,0);
 unsigned sub; char* tiles; void* object=*(void**)(p+0x18);tiles=*(char**)(p+0x654);unsigned font=*(unsigned char*)(p+0x6a8);sub=*(unsigned char*)(p+0x640);
 if(object && tiles){
 unsigned* config=RefreshHeadingAndUploadFontTiles_UnknownRoleInitializedBytes_Variant2;if(sub)config=RefreshHeadingAndUploadFontTiles_UnknownRoleInitializedBytes;
 char* entry=(char*)ComputeIndexedEntryAddressAtStride40(object,(unsigned short)config[0]);
 if(entry){char* image=*(char**)(entry+8);if(image){
 memcpy(tiles,TextLayout_GetThirtyTwoByteFontEntry((unsigned char)(font*4+40)),128);
 unsigned offset=(unsigned short)(*(unsigned short*)(image+4)&0x3ff)<<config[1];
 _Z25CleanInvalidateCacheRangePKvj(tiles,128);
 if(sub)LoadToSubObjVRAM(tiles,offset,128);else LoadToMainObjVRAM(tiles,offset,128);
 _Z15CleanCacheRangePKvj(tiles,128);
 }}
 }
}
