#include <globaldefs.h>
ARM
// Original data: arm9/ov017 @ 0x21d8438; symbol: data_ov017_021d8438.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 36 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov017.md.
extern "C" unsigned char ScriptTrySelectIndexedString_UnknownRoleZeroInitializedStorage[];
// Original data: arm9/ov017 @ 0x21d7c54; symbol: data_ov017_021d7c54.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex ffff0000.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov017.md.
extern "C" signed char ScriptTrySelectIndexedString_UnknownRoleInitializedBytes;
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* Network_GetConnectionManager();
extern "C" bool Network_IsClientSession(unsigned*);
extern "C" void* _ZN9GameState20GetGameObjectByIndexEi(void*,int);
extern "C" void* GameState_GetSerializedProgressState();
extern "C" int _ZNK6Script9Parameter5ToIntEv(const void*);
extern "C" const char* _ZNK6Script9Parameter8ToStringEv(const void*);
extern "C" int Script_GetPackedEntryState(volatile unsigned char*,int);
extern "C" unsigned Script_GetEntryActivationFlagMask(unsigned char*,int);
extern "C" unsigned Script_GetEntryHighFlagMask(unsigned char*,int);
extern "C" bool _ZNK9GameState21IsMorningDayOrEveningEv(void*);
extern "C" bool GameState_TrySelectIndexedEntry(int,int);
static inline int ReadFirstHealth(unsigned char *object){return *(unsigned short*)(*(unsigned char**)(object+0x130)+4);}
static inline bool PackedEquals(unsigned char *state,int id,int value){return Script_GetPackedEntryState(state,id)==value;}
// Original: arm9/ov017 @ 0x021BA524; symbol: func_ov017_021ba524; size: 0x2EC.
// Applies packed-state/daytime script gates before selecting an indexed entry.
extern "C" int Script_SelectEntryWithPackedStateGates(unsigned char *args,int count){
 if(*(int*)(ScriptTrySelectIndexedString_UnknownRoleZeroInitializedStorage+16))return 1;
 void *game=_ZN9GameState11GetInstanceEv();if(Network_IsClientSession((unsigned*)Network_GetConnectionManager()))return 1;
 unsigned char *object=(unsigned char*)_ZN9GameState20GetGameObjectByIndexEi(game,0);if(ReadFirstHealth(object)>0)return 1;
 unsigned char *state=(unsigned char*)GameState_GetSerializedProgressState();int id=_ZNK6Script9Parameter5ToIntEv(args);
 if(ScriptTrySelectIndexedString_UnknownRoleInitializedBytes!=id&&ScriptTrySelectIndexedString_UnknownRoleInitializedBytes>-1){
 if(!PackedEquals(state,id,1)&&!PackedEquals(state,id,2)){
 if(!PackedEquals(state,ScriptTrySelectIndexedString_UnknownRoleInitializedBytes,3)||!PackedEquals(state,id,3)||ScriptTrySelectIndexedString_UnknownRoleInitializedBytes>id)return 1;
 }}
 unsigned char *modeParam=args+8;args+=16;int mode=_ZNK6Script9Parameter5ToIntEv(modeParam);
 switch(mode){
 case -1:if(!PackedEquals(state,id,0))return 1;break;
 case 0:if(!PackedEquals(state,id,2))return 1;break;
 case 1:if(!Script_GetEntryActivationFlagMask(state,id))return 1;break;
 case 2:if(!PackedEquals(state,id,3))return 1;break;
 case 3:if(!PackedEquals(state,id,1))return 1;break;
 case 4:if(!Script_GetEntryHighFlagMask(state,id)||!PackedEquals(state,id,0))return 1;break;
 }
 if(count>=5){int night=_ZNK6Script9Parameter5ToIntEv(args);args+=8;if(night){if(_ZNK9GameState21IsMorningDayOrEveningEv(_ZN9GameState11GetInstanceEv()))return 1;ScriptTrySelectIndexedString_UnknownRoleZeroInitializedStorage[2]=1;}}
 else if(ScriptTrySelectIndexedString_UnknownRoleZeroInitializedStorage[2])return 0;
 int selection=_ZNK6Script9Parameter5ToIntEv(args);const char *text=_ZNK6Script9Parameter8ToStringEv(args+8);if(!text)return 0;
 if(GameState_TrySelectIndexedEntry(selection,(int)text))ScriptTrySelectIndexedString_UnknownRoleInitializedBytes=id;
 return 1;
}
