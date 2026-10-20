#include <globaldefs.h>
ARM
struct Position;
extern "C" void Tilemap_SetWholeMapPalette(Position*,int);
extern "C" char* Graphics_GetLoadedScreenDescriptor(char*,unsigned int);
extern "C" void LoadToSubBG1ScreenData(const void*,unsigned int,unsigned int);
extern "C" void _Z25CleanInvalidateCacheRangePKvj(const void*,unsigned int);
// Original: arm9/ov023 @ 0x021E7B34; symbol: func_ov023_021e7b34; size: 0x90.
extern "C" int Graphics_LoadIndexedSubBG1Screen(unsigned char* p,int index) {
if(!*(int*)(p+0x5dc))return 1;
int valid=index>=0 && index<=3;
if(!valid)return 1;
char* entry=Graphics_GetLoadedScreenDescriptor((char*)p+0x154,0);
if(!entry)return 1;
Tilemap_SetWholeMapPalette((Position*)entry,(unsigned short)(index+12));
void* data=*(void**)(entry+12);unsigned int size=*(unsigned int*)(entry+8);
_Z25CleanInvalidateCacheRangePKvj(data,size);
LoadToSubBG1ScreenData(data,0,size);
return 0;
}
