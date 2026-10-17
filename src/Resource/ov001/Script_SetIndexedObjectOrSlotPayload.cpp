#include <globaldefs.h>
ARM
struct GameState; struct IntegerParameterView; struct FourWordState;
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* _ZN9GameState20GetGameObjectByIndexEi(void*,int);
extern "C" int GameState_ReadProtagonistObjectIndex(GameState*);
extern "C" void* Object_GetGlobalThirtyTwoEntryContainer();
extern "C" unsigned int* GetBoundedSlotUnlessFlag8000(unsigned int**,unsigned int);
extern "C" void InitializeFourWordState(FourWordState*);
extern "C" int ConvertNegativeIndexToBiasedMagnitude(int);
extern "C" int func_ov001_02164214(unsigned char*,int,unsigned,unsigned,void*);
extern "C" int SetIndexedTypedPayload(unsigned char*,int,unsigned,unsigned,unsigned);
extern "C" int ReadScriptParameterAsInteger(IntegerParameterView*);
extern "C" unsigned char* data_ov001_02165880[];
// Original: arm9/ov001 @ 0x0215BDD0; symbol: func_ov001_0215bdd0; size: 0x164.
extern "C" int Script_SetIndexedObjectOrSlotPayload(unsigned char* args) {
 void* game=_ZN9GameState11GetInstanceEv();
 int value;
 int index=ReadScriptParameterAsInteger((IntegerParameterView*)args);
 value=ReadScriptParameterAsInteger((IntegerParameterView*)(args+8));
 int type=ReadScriptParameterAsInteger((IntegerParameterView*)(args+16));
 value=ConvertNegativeIndexToBiasedMagnitude(value);
 InitializeFourWordState((FourWordState*)(data_ov001_02165880[1]+index*16));
 if(type==0 || type==1 || (unsigned)(type-4)<=1) {
  void* object=0;
  if(type==0) object=_ZN9GameState20GetGameObjectByIndexEi(game,GameState_ReadProtagonistObjectIndex((GameState*)game));
  else if(type==1) object=_ZN9GameState20GetGameObjectByIndexEi(game,value);
  else if(type==4) object=_ZN9GameState20GetGameObjectByIndexEi(game,0);
  else if(type==5) object=_ZN9GameState20GetGameObjectByIndexEi(game,value);
  if(!object) return 0;
  return func_ov001_02164214(data_ov001_02165880[1],index,type,value,object);
 }
 else if(type==2 || type==6) {
  unsigned int* slot=GetBoundedSlotUnlessFlag8000((unsigned int**)Object_GetGlobalThirtyTwoEntryContainer(),value);
  if(!slot) return 0;
  slot[0]|=0x10000;
  return SetIndexedTypedPayload(data_ov001_02165880[1],index,type,value,(unsigned)slot);
 }
 return 0;
}
