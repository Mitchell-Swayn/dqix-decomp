#include <globaldefs.h>
#include "Graphics/Model3D.h"
#include "Graphics/VRAMStaging.h"
#include "System/Cache.h"
ARM
struct Triple {unsigned value[3];};
extern "C" {extern char data_02109928[],data_021099b0[],data_02109a30[];extern const Triple data_020e8e14,data_020e8e20;}
// Original: arm9/main @ 0x02099E18; symbol: func_02099e18; size: 0xDC.
// Copies three selected palette slices into TEX0 block4, cleans cache and stages it.
// Proposed name: Graphics_ReplaceThreeIndexedModelPaletteSlices; old ABI for proof.
extern "C" void Graphics_ReplaceThreeIndexedModelPaletteSlices(Model3D* model,int largeIndex,int firstIndex,int secondIndex){
 if(model){NSBXXTex* tex=model->GetTEX0();if(tex){
 char* palette=(char*)tex+tex->block4Offset_;
 unsigned length=tex->block4NumEightBytes_<<3;
 const void* sources[3]={data_02109928+firstIndex*4,data_02109a30+secondIndex*4,data_021099b0+largeIndex*16};
 Triple sizes=data_020e8e14;
 Triple offsets=data_020e8e20;
 for(int i=0;i<3;++i)memcpy(palette+offsets.value[i],sources[i],sizes.value[i]);
 CleanInvalidateCacheRange(palette,length);
 StageTexFilePaletteData(tex,true);
 }}
}
