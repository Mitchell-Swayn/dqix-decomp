#include <globaldefs.h>
#include "Graphics/Model3D.h"
#include "Graphics/VRAMStaging.h"
#include "System/Cache.h"
ARM
struct Triple {unsigned value[3];};
// Original data: arm9/main @ 0x20e8e14; symbol: data_020e8e14.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 040000000400000010000000.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x20e8e20; symbol: data_020e8e20.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 040000000800000010000000.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x2109928; symbol: data_02109928.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 40 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x21099b0; symbol: data_021099b0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 120 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x2109a30; symbol: data_02109a30.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 36 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" {extern char ScriptReadTenPairsIntoGlobalTable_UnknownRoleZeroInitializedStorage[],ScriptReadEightByEightGlobalTable_UnknownRoleZeroInitializedStorage[],ScriptFillSecondEightByTwoIntegerTable_UnknownRoleZeroInitializedStorage[];extern const Triple GraphicsReplaceThreeIndexedModelPaletteSlices_UnknownRoleInitializedBytes,GraphicsReplaceThreeIndexedModelPaletteSlices_UnknownRoleInitializedBytes_Variant2;}
// Original: arm9/main @ 0x02099E18; symbol: func_02099e18; size: 0xDC.
// Copies three selected palette slices into TEX0 block4, cleans cache and stages it.
// Proposed name: Graphics_ReplaceThreeIndexedModelPaletteSlices; old ABI for proof.
extern "C" void Graphics_ReplaceThreeIndexedModelPaletteSlices(Model3D* model,int largeIndex,int firstIndex,int secondIndex){
 if(model){NSBXXTex* tex=model->GetTEX0();if(tex){
 char* palette=(char*)tex+tex->block4Offset_;
 unsigned length=tex->block4NumEightBytes_<<3;
 const void* sources[3]={ScriptReadTenPairsIntoGlobalTable_UnknownRoleZeroInitializedStorage+firstIndex*4,ScriptFillSecondEightByTwoIntegerTable_UnknownRoleZeroInitializedStorage+secondIndex*4,ScriptReadEightByEightGlobalTable_UnknownRoleZeroInitializedStorage+largeIndex*16};
 Triple sizes=GraphicsReplaceThreeIndexedModelPaletteSlices_UnknownRoleInitializedBytes;
 Triple offsets=GraphicsReplaceThreeIndexedModelPaletteSlices_UnknownRoleInitializedBytes_Variant2;
 for(int i=0;i<3;++i)memcpy(palette+offsets.value[i],sources[i],sizes.value[i]);
 CleanInvalidateCacheRange(palette,length);
 StageTexFilePaletteData(tex,true);
 }}
}
