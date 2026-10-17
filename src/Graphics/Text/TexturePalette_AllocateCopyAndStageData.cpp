#include <globaldefs.h>
ARM
extern "C" int AllocateTexturePaletteVRAM(unsigned,int,int);
struct SafeAllocator { void *Allocate(unsigned); };
extern "C" void *memcpy(void *,const void *,unsigned);
enum VRAMSubregion { Palette=0 };
void StageMemoryToVRAM(VRAMSubregion,const void *,unsigned,unsigned,bool,bool);
struct Flags { unsigned char pad:2; unsigned char copy:1; };
// Original: arm9/main @ 0x02047F70; symbol: func_02047f70; size: 0x94.
extern "C" void TexturePalette_AllocateCopyAndStageData(char *self,void *data,unsigned length,SafeAllocator *allocation) { unsigned address=(unsigned short)AllocateTexturePaletteVRAM(length,0,0)*8; bool direct=true; if(((Flags *)(self+0x84))->copy&&allocation) { void *copy=allocation->Allocate(length); if(copy) { memcpy(copy,data,length); data=copy; direct=false; } } StageMemoryToVRAM(Palette,data,address,length,0,direct); *(unsigned *)(self+16)=address; }
