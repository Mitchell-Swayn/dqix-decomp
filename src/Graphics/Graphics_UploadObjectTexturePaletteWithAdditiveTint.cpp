#include <globaldefs.h>
#include <GameState/GameState.h>
#include <World/Object3D.h>
#include <Graphics/Model3D.h>
#include <Graphics/NSBXX/NSBXX.h>
#include <Graphics/VRAMStaging.h>
#include <System/LoadToVRAM.h>
#include <System/Cache.h>
#include <Memory/SafeAllocator.h>
ARM
struct PaletteOwner {char prefix[0x18];Object3D* object;};
struct PaletteTintRecord {char prefix[0x20];unsigned short color;};
extern "C" PaletteTintRecord* Actor_GetMotionDescriptor(PaletteOwner*);
// Adds RGB555 tint with channel saturation, then uploads the temporary model palette.
// Zero tint and no object palette override use the original palette upload path.
// Original: arm9/main @ 0x0203DB44; symbol: func_0203db44; size: 0x1A0.
extern "C" void Graphics_UploadObjectTexturePaletteWithAdditiveTint(void* unused,PaletteOwner* owner,SafeAllocator* allocator)
{
 if(!owner->object)return;
 GameState::GetInstance();
 Object3D* object=owner->object;
 PaletteTintRecord* record=Actor_GetMotionDescriptor(owner);
 if(!record)return;
 unsigned short tint=record->color;
 unsigned short red=tint&31;
 unsigned short green=(tint&0x3e0)>>5;
 unsigned short blue=(tint&0x7c00)>>10;
 LockStagedTextureVRAMCopying();
 MemoryMapTexturePalette();
 if(object->pModel_) {
  NSBXXTex* texture; unsigned short* output; texture=object->pModel_->GetTEX0();
  if(texture) {
   if(tint==0 && !object->GetTexturePaletteOffset()) NSBXX_Tex_LoadPaletteToVRAM(texture,false);
   else {
    unsigned offset=texture->block4VRAMLoadOffset_;
    if(object->GetTexturePaletteOffset())offset=object->GetTexturePaletteOffset();
    const unsigned short* source;
    unsigned dataOffset=texture->block4Offset_;
    unsigned length=texture->block4NumEightBytes_<<3;
    unsigned vramOffset=(offset&0xffff)<<3;
    source=(const unsigned short*)((char*)texture+dataOffset);
    output=(unsigned short*)allocator->Allocate(length);
    if(output) {
     for(unsigned i=0;i<length/2;i++) {
      unsigned short color=source[i];
      unsigned short r=color&31;
      unsigned short g=(color&0x3e0)>>5;
      unsigned short b=(color&0x7c00)>>10;
      r+=red;g+=green;b+=blue;
      if(r>31)r=31;
      if(g>31)g=31;
      if(b>31)b=31;
      output[i]=r|(g<<5)|(b<<10);
     }
     CleanInvalidateCacheRange(output,length);
     LoadToTexturePalette(output,vramOffset,length);
    }
   }
  }
 }
 MemoryUnmapTexturePalette();
 UnlockStagedTextureVRAMCopying();
}
