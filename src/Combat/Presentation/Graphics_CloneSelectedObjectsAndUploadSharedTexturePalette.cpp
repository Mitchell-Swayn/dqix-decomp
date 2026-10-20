#include <globaldefs.h>
ARM
extern "C" char* _ZN9GameState11GetInstanceEv();
extern "C" int Combat_DispatchSelectionProcedure(int,int,int,int*);
extern "C" char* BattleScene_GetActiveInstance();
extern "C" char* CombatScene_FindAuxiliaryObjectByIdentifier(void*,int);
extern "C" char* _ZN7Model3D7GetTEX0Ev(void*);
extern "C" char* GameState_FindIndexedObjectWithFlag400(void*,int);
extern "C" void Object3D_ShallowCloneAndRebindExtendedFields(void*,void*);
extern "C" int _ZNK8Object3D23GetTexturePaletteOffsetEv(void*);
extern "C" void _Z25CleanInvalidateCacheRangePKvj(const void*,unsigned);
extern "C" void NSBXX_Tex_WritePaletteVRAMOffset(void*,int);
extern "C" void _Z23StageTexFilePaletteDataPV8NSBXXTexb(void*,int);
extern "C" void BattleScene_SetMonsterHomeFormation(void*);

#define W(p,o) (*(int*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
// Original: arm9/ov025 @ 0x021E7EC0; symbol: Graphics_CloneSelectedObjectsAndUploadSharedTexturePalette; size: 0xF4.
extern "C" int Graphics_CloneSelectedObjectsAndUploadSharedTexturePalette(char* self,int selection,int unused,int procedure){
 int ids[8];char* game=_ZN9GameState11GetInstanceEv();int count=Combat_DispatchSelectionProcedure(procedure,selection,H(self,8),ids);char* control=BattleScene_GetActiveInstance();char* entry=CombatScene_FindAuxiliaryObjectByIdentifier(control,H(self,10));if(!entry)return 1;char* model=P(entry,8);if(!model)return 1;char* tex=_ZN7Model3D7GetTEX0Ev(model);if(!tex)return 1;
 for(int i=0;i<count;++i){char* object=GameState_FindIndexedObjectWithFlag400(game,ids[i]);if(object){Object3D_ShallowCloneAndRebindExtendedFields(entry,object);int offset=_ZNK8Object3D23GetTexturePaletteOffsetEv(object);_Z25CleanInvalidateCacheRangePKvj(tex+W(tex,0x38),H(tex,0x30)<<3);NSBXX_Tex_WritePaletteVRAMOffset(tex,offset);_Z23StageTexFilePaletteDataPV8NSBXXTexb(tex,1);}}
 BattleScene_SetMonsterHomeFormation(control);return 1;
}