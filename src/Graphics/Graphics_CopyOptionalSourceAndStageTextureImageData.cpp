#include <globaldefs.h>
ARM
#include <Memory/SafeAllocator.h>
#include <Graphics/VRAMStaging.h>
extern "C" int NNS_GfdAllocFrmTexVram(unsigned,int,int);
extern "C" void* memcpy(void*,const void*,unsigned);
struct Object {char pad[0x84];unsigned char low:2;unsigned char copy:1;unsigned char rest:5;};
// Original: arm9/main @ 0x02047ED4; symbol: func_02047ed4; size: 0x9C.
extern "C" void Graphics_CopyOptionalSourceAndStageTextureImageData(Object* p,unsigned* offset,const void* source,unsigned length,SafeAllocator* allocator) {
    unsigned vram=(unsigned short)NNS_GfdAllocFrmTexVram(length,0,0)*8;
    bool stage=true;
    if(p->copy&&allocator) {
        void* buffer=allocator->Allocate(length);
        if(buffer) {memcpy(buffer,source,length);source=buffer;stage=false;}
    }
    StageMemoryToVRAM((VRAMSubregion)1,source,vram,length,false,stage);
    *offset=vram;
}
