#include <globaldefs.h>
ARM
typedef unsigned char bool;
typedef struct GameState GameState;typedef struct GameResources GameResources;typedef struct Vec{int x,y,z;} Vec;typedef struct Triple{unsigned x,y,z;} Triple;
void* _ZN9GameState11GetInstanceEv();unsigned BattleScene_GetActiveInstance();int Combat_DispatchSelectionProcedure(void*,void*,int,int*);void* _ZN9GameState19GetCombatantByIndexEi(GameState*,int);void BattleScene_RebuildMonsterFromPrototype(void*,int);void CombatantMotion_Activate(int);void PlaceCombatantAtFirstUnusedGridIndex(void*,void*);bool _ZN8Object3D18SetAnimationByNameEPKci(void*,const char*,int);extern char ActivateSelectedCombatantsAndTurnGroup_TextAppear[];void BattleScene_SetMonsterHomeFormation(void*);void* BattleScene_GetCamera(unsigned char*);GameResources* GameState_ReadPResources(GameState*);int Combat_CollectGroupIndicesByDescriptorFlags(char*,short*,int,unsigned);unsigned char* GameState_FindIndexedObjectWithFlag400(GameState*,unsigned);void* __clear(void*,unsigned);Triple CombatantMotion_GetHomePosition(char*);void Vector3fix_Subtract(const Vec*,const Vec*,Vec*);void Vector3fix_Normalize(const Vec*,Vec*);int fix32_Atan2(int,int);void Object3D_SetNormalizedAngleAndUpdatePosition(char*,int);void CombatantMotion_SetHomeHeadingFromVector(char*,int*);
// Original: arm9/ov025 @ 0x021E604C; symbol: func_ov025_021e604c; size: 0x1BC.
// Marks selected combatants active, then turns eligible group objects using normalized horizontal vectors.
int ActivateSelectedCombatantsAndTurnGroup(void* unused,void* record,int unused2,void* context){
 GameState *game;void *control,*selectedObject;char *camera,*object;int selected[8];Triple returned;Vec rotation,delta;Triple position;Vec source,base;short ids[8];int count,i,angle,j,z,total;GameState* secondGame;
 game=(GameState*)_ZN9GameState11GetInstanceEv();control=(void*)BattleScene_GetActiveInstance();if(!control)return 1;
 count=Combat_DispatchSelectionProcedure(context,record,24,selected);
 for(i=0;i<count;i++){selectedObject=_ZN9GameState19GetCombatantByIndexEi(game,selected[i]);if(selectedObject){BattleScene_RebuildMonsterFromPrototype(control,selected[i]);CombatantMotion_Activate((int)selectedObject);PlaceCombatantAtFirstUnusedGridIndex(control,selectedObject);_ZN8Object3D18SetAnimationByNameEPKci(selectedObject,ActivateSelectedCombatantsAndTurnGroup_TextAppear,1);}}
 BattleScene_SetMonsterHomeFormation(control);camera=(char*)BattleScene_GetCamera((unsigned char*)control);secondGame=(GameState*)_ZN9GameState11GetInstanceEv();GameState_ReadPResources(secondGame);
 total=Combat_CollectGroupIndicesByDescriptorFlags((char*)context,ids,8,0);base=*(Vec*)(camera+0x240);
 z=base.z;
 for(j=0;j<total;j++){object=(char*)GameState_FindIndexedObjectWithFlag400(secondGame,ids[j]);if(!object)continue;
 __clear(&source,12);source.z=z;
 returned=CombatantMotion_GetHomePosition(object);position=returned;position.y=0;Vector3fix_Subtract(&source,(Vec*)&position,&delta);delta.y=0;Vector3fix_Normalize(&delta,&delta);angle=fix32_Atan2(delta.x,delta.z);Object3D_SetNormalizedAngleAndUpdatePosition(object,angle);
 __clear(&rotation,12);rotation.y=angle;CombatantMotion_SetHomeHeadingFromVector(object,&rotation.x);
 }return 1;
}
