#include <globaldefs.h>
ARM
struct IntegerParameterView;
struct Object3D;
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* _ZN9GameState20GetGameObjectByIndexEi(void*,int);
extern "C" void* GameState_ReadUnknownB0(void*);
extern "C" void GameState_SetUnknown3b0(void*,void*);
extern "C" int GameState_GetFieldAddress5CA4(int);
extern "C" char* _ZN13SafeAllocator8AllocateEj(unsigned,unsigned);
extern "C" void _ZN8Object3D10EnableFlagEi(void*,int);
extern "C" void InitializeObjectFlag10AndResourceIndices(unsigned char*);
extern "C" void Object3D_EnableBoneTrackingAndLinkedFlagBitTwo(char*,Object3D*);
extern "C" void CopyResourceNameAndInvalidateIndex(void*,const char*);
extern "C" void CopyNameAndInvalidateCachedIndex(int,char*);
extern "C" void Object_Invokestrcpy(int,const char*);
extern "C" void Object_SetWordAtOffset220(int,unsigned);
extern "C" int ConvertNegativeIndexToBiasedMagnitude(int);
extern "C" int ReadScriptParameterAsInteger(IntegerParameterView*);
extern "C" unsigned OV017_ReadWordField04(void*);
extern "C" unsigned data_ov001_021658b8;
// Original: arm9/ov001 @ 0x02160768; symbol: func_ov001_02160768; size: 0x134.
extern "C" int Script_CreateLinkedBoneTrackingObject(unsigned char* args) {
 void* game=_ZN9GameState11GetInstanceEv();
 unsigned allocator=data_ov001_021658b8;
 unsigned char* field=(unsigned char*)GameState_GetFieldAddress5CA4((int)game);
 int first=ReadScriptParameterAsInteger((IntegerParameterView*)args);
 unsigned resource=OV017_ReadWordField04(args+8);
 unsigned name=OV017_ReadWordField04(args+16);
 unsigned extra=OV017_ReadWordField04(args+24);
 int second=ReadScriptParameterAsInteger((IntegerParameterView*)(args+32));
 first=ConvertNegativeIndexToBiasedMagnitude(first);
 second=ConvertNegativeIndexToBiasedMagnitude(second);
 void* source=_ZN9GameState20GetGameObjectByIndexEi(game,first);
 if(!source)return 0;
 void* target=_ZN9GameState20GetGameObjectByIndexEi(game,second);
 if(!target)return 0;
 char* object=_ZN13SafeAllocator8AllocateEj(allocator,0x268);
 *(void**)(field+4)=GameState_ReadUnknownB0(game);
 InitializeObjectFlag10AndResourceIndices((unsigned char*)object);
 Object3D_EnableBoneTrackingAndLinkedFlagBitTwo(object,(Object3D*)source);
 CopyResourceNameAndInvalidateIndex(object,(const char*)resource);
 CopyNameAndInvalidateCachedIndex((int)object,(char*)name);
 Object_Invokestrcpy((int)object,(const char*)extra);
 Object_SetWordAtOffset220((int)object,(unsigned)target);
 _ZN8Object3D10EnableFlagEi(source,1);
 _ZN8Object3D10EnableFlagEi(source,0x20);
 GameState_SetUnknown3b0(game,object);
 return 1;
}
