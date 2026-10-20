#include <globaldefs.h>
ARM
extern "C" void Graphics_RestoreTextureImageAndPaletteVRAMState(void*);extern "C" void Object_InvokeSaveTextureImageVRAMState(void*);extern "C" int Object3D_LoadCHRArchiveAndOptionalAuxiliaryResource(void*,unsigned,void*,void*,void*);
// Original: arm9/main @ 0x020555A0; symbol: func_020555a0; size: 0x6C.
extern "C" void Object3D_LoadPendingCHRResourcesAndClearStaging(unsigned* p){if(p[1]&&p[3]&&p[4]&&p[2]){Graphics_RestoreTextureImageAndPaletteVRAMState((void*)p[2]);Object3D_LoadCHRArchiveAndOptionalAuxiliaryResource(p,p[0],(void*)p[1],(void*)p[3],(void*)p[4]);Object_InvokeSaveTextureImageVRAMState((void*)p[2]);}p[2]=0;p[3]=0;p[4]=0;}
