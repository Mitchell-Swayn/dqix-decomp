#include <globaldefs.h>
ARM
struct Names {const char* names[8];};
extern "C" unsigned data_ov025_021ef988[];
extern "C" Names data_ov025_021eef58;
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* GameState_ReadUnknownB0(void*);
extern "C" unsigned ReadFirstValue_Main0202E09C(void*);
extern "C" char* Object_ReadWordAtOffset21C(void*);
extern "C" int DispatchCombatSelectionProcedure(void*,int,int,int*);
extern "C" char* _ZN9GameState20GetGameObjectByIndexEi(void*,int);
extern "C" bool _ZNK8Object3D19HasAnimationStoppedEv(void*);
extern "C" bool _ZNK8Object3D22HasAnimationReachedEndEv(void*);
extern "C" bool _ZNK8Object3D7GetFlagEi(void*,int);
extern "C" int strcmp(const char*,const char*);
// Original: arm9/ov025 @ 0x021E4868; symbol: func_ov025_021e4868; size: 0x178.
extern "C" bool Combat_TestSelectedObjectAnimationReady(char* record,int selection,int unused,void* context) {
 if(data_ov025_021ef988[7]&4)return false;
 void* game=_ZN9GameState11GetInstanceEv();
 char* object;
 int kind=*(unsigned char*)(record+8);
 if(kind==25) {
 void* special=GameState_ReadUnknownB0(game);
 if(ReadFirstValue_Main0202E09C(special)&16)object=Object_ReadWordAtOffset21C(special);
 else return true;
 } else {
 int indices[8];
 if(DispatchCombatSelectionProcedure(context,selection,kind,indices)!=1)return true;
 object=_ZN9GameState20GetGameObjectByIndexEi(game,indices[0]);
 }
 if(!object)return true;
 int threshold=*(short*)(record+10);
 if(threshold<4096)return *(int*)(object+0x24)>=threshold;
 if(_ZNK8Object3D19HasAnimationStoppedEv(object)||_ZNK8Object3D22HasAnimationReachedEndEv(object))return true;
 if(_ZNK8Object3D7GetFlagEi(object,0x40000))return true;
 if(!(*(unsigned char*)(object+0x19)&1)) {
 const char* name=*(const char**)(object+0x14);
 if(name) {
 unsigned i; Names names=data_ov025_021eef58; const char** p=names.names;
 for(i=0;i<8;i++,p++)if(!strcmp(name,*p))return true;
 }
 }
 return false;
}
