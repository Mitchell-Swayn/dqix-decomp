#include <globaldefs.h>
#include <Graphics/VRAMStaging.h>
#include <std_library_functions.h>
// Original data: arm9/main @ 0x020E7B60; symbol: data_020e7b60.
// Read-only VRAM subregion selection: original words 2 (main BG palette), 11 (sub BG palette).
// Observed span: 8 bytes; full references: docs/data-symbols/main.md.
extern "C" const VRAMSubregion GraphicsStageSerializedPaletteToVRAM_UnknownRoleInitializedBytes[];
// Original: arm9/main @ 0x0204AC60; symbol: func_0204ac60; size: 0x50.
extern "C" ARM void Graphics_StageSerializedPaletteToVRAM(void* unused,int index,const void* data){const unsigned char* file=(const unsigned char*)data;unsigned length;memcpy(&length,file+8,4);StageMemoryToVRAM(GraphicsStageSerializedPaletteToVRAM_UnknownRoleInitializedBytes[index],file+12,0,length,true,false);}
