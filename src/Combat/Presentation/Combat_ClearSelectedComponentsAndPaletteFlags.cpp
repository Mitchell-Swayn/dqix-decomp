#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" int Combat_DispatchSelectionProcedure(void*,void*,int,int*);
extern "C" void* _ZN9GameState19GetCombatantByIndexEi(void*,int);
extern "C" void CombatantMotion_Deactivate(void*);
extern "C" void* BattleScene_GetActiveInstance();
extern "C" int _ZNK8Object3D23GetTexturePaletteOffsetEv(void*);
extern "C" void Util_ClearFlagForMatchingEntry(void*,int);
// Original: arm9/ov025 @ 0x021E697C; symbol: Combat_ClearSelectedComponentsAndPaletteFlags; size: 0x8c.
// Enumerates combat selection, clears indirect component byte56 and matching palette flag.
extern "C" int Combat_ClearSelectedComponentsAndPaletteFlags(unsigned char* record,void* command,void* unused,void* context) {
 void* game=_ZN9GameState11GetInstanceEv();int indices[8];int count=Combat_DispatchSelectionProcedure(context,command,record[8],indices);
 for(int i=0;i<count;++i){void* object=_ZN9GameState19GetCombatantByIndexEi(game,indices[i]);if(object){CombatantMotion_Deactivate(object);void* control=BattleScene_GetActiveInstance();int palette=_ZNK8Object3D23GetTexturePaletteOffsetEv(object);Util_ClearFlagForMatchingEntry(control,palette);}}
 return 1;
}
