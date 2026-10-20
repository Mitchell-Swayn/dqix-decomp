#include <globaldefs.h>
ARM
extern "C" int CharacterViewer_ReloadPlayerModelParts(unsigned char*,void*);
extern "C" int CharacterViewer_ReloadDollModelParts(unsigned char*,void*);
extern "C" int CharacterViewer_LoadMonsterModel(unsigned char*,void*);
extern "C" int Graphics_LoadModelArchiveWithSavedTextureState(unsigned char*,void*);
extern "C" int CharacterViewer_OpenEffectArchive(unsigned char*,void*);
extern "C" int Graphics_LoadNamedModelAndConfigureBones(unsigned char*,void*);
// Original: arm9/ov015 @ 0x0218F27C; symbol: DispatchModelConfigurationByByte1C; size: 0x8c.
extern "C" int CharacterViewer_LoadModelByKind(unsigned char* self,void* entry){
int result=1;switch(self[28]){case 0:result=CharacterViewer_ReloadPlayerModelParts(self,entry);break;case 1:result=CharacterViewer_ReloadDollModelParts(self,entry);break;case 3:result=CharacterViewer_LoadMonsterModel(self,entry);break;case 2:result=Graphics_LoadModelArchiveWithSavedTextureState(self,entry);break;case 4:result=CharacterViewer_OpenEffectArchive(self,entry);break;case 5:result=Graphics_LoadNamedModelAndConfigureBones(self,entry);break;case 6:result=Graphics_LoadNamedModelAndConfigureBones(self,entry);break;}return result;
}
