#include <globaldefs.h>
ARM
struct Triple{int x,y,z;};struct Matrix{int value[12];};
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" char* _ZN9GameState20GetGameObjectByIndexEi(void*,int);
extern "C" void BattleCamera_ResetShotAndTransitions(void*,int,int,int);
extern "C" void Vector3fix_Subtract(const Triple*,const Triple*,Triple*);
extern "C" void Vector3fix_Normalize(const Triple*,Triple*);
extern "C" void Math_BuildYUpBasisAndTranslation(const Triple*,const Triple*,Matrix*);
extern "C" void Camera_SetParentTransform(char*,Matrix*);
extern "C" void _ZN8Vector3iaSERKS_(void*,const Triple*);
extern "C" void Camera_SetOrbitParameters(void*,const Triple*);
extern "C" Triple BattleCamera_ConfigureDirectedPairShot_FormationTransformTemplate;

// Original: arm9/ov000 @ 0x0216DE00; symbol: World_OrientObjectFromTwoIndexedPositions; size: 0x100.
extern "C" void BattleCamera_ConfigureDirectedPairShot(char* self,int first,int second){
void *game=_ZN9GameState11GetInstanceEv();char *a=_ZN9GameState20GetGameObjectByIndexEi(game,first),*b=_ZN9GameState20GetGameObjectByIndexEi(game,second);
 if(a&&b){BattleCamera_ResetShotAndTransitions(self,1,1,1);Triple pa=*(Triple*)(a+0x44),pb=*(Triple*)(b+0x44),direction;Vector3fix_Subtract(&pa,&pb,&direction);Vector3fix_Normalize(&direction,&direction);Matrix basis;Math_BuildYUpBasisAndTranslation(&direction,&pb,&basis);Camera_SetParentTransform(self,&basis);
 Triple rotation=BattleCamera_ConfigureDirectedPairShot_FormationTransformTemplate;Triple position;position.x=0x3244;position.y=0;position.z=0x1000;_ZN8Vector3iaSERKS_(self+16,&rotation);Camera_SetOrbitParameters(self,&position);}
}
