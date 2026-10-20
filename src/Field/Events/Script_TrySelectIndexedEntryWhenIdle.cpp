#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" int _ZNK9GameState21IsMorningDayOrEveningEv(void*);
extern "C" char* Network_GetConnectionManager();
extern "C" int Network_IsSessionActive(void*);
extern "C" int Network_GetLocalMemberId(char*);
extern "C" int _ZNK6Script9Parameter5ToIntEv(const void*);
extern "C" const char* _ZNK6Script9Parameter8ToStringEv(const void*);
extern "C" bool GameState_TrySelectIndexedEntry(int,int);
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
extern "C" signed char ScriptTrySelectIndexedString_UnknownRoleInitializedBytes[];
// Original: arm9/ov017 @ 0x021BA124; symbol: func_ov017_021ba124; size: 0x15C.
extern "C" int Script_TrySelectIndexedEntryWhenIdle(char* params,int count) {
 if(*(int*)(ScriptTrySelectIndexedString_UnknownRoleZeroInitializedStorage+0x10))return 1;
 if(ScriptTrySelectIndexedString_UnknownRoleInitializedBytes[0]>-1)return 1;
 if(ScriptTrySelectIndexedString_UnknownRoleZeroInitializedStorage[1])return 1;
 if(ScriptTrySelectIndexedString_UnknownRoleInitializedBytes[1]>-1)return 1;
 _ZN9GameState11GetInstanceEv();
 char* conn=Network_GetConnectionManager();
 if(!Network_IsSessionActive(conn))return 1;
 if(Network_GetLocalMemberId(conn))return 1;
 int lo=_ZNK6Script9Parameter5ToIntEv(params);
 char* second=params+8;
 params+=16;
 int hi=_ZNK6Script9Parameter5ToIntEv(second);
 if(lo>=0 && (*(int*)(ScriptTrySelectIndexedString_UnknownRoleZeroInitializedStorage+4)<lo || hi<*(int*)(ScriptTrySelectIndexedString_UnknownRoleZeroInitializedStorage+4)))return 1;
 if(count>=5) {
  int flag=_ZNK6Script9Parameter5ToIntEv(params);
  params+=8;
  if(flag) {
   if(_ZNK9GameState21IsMorningDayOrEveningEv(_ZN9GameState11GetInstanceEv()))return 1;
   ScriptTrySelectIndexedString_UnknownRoleZeroInitializedStorage[2]=1;
  }
 } else if(ScriptTrySelectIndexedString_UnknownRoleZeroInitializedStorage[2])return 1;
 int index=_ZNK6Script9Parameter5ToIntEv(params);
 const char* s=_ZNK6Script9Parameter8ToStringEv(params+8);
 if(!s)return 0;
 if(GameState_TrySelectIndexedEntry(index,(int)s))ScriptTrySelectIndexedString_UnknownRoleZeroInitializedStorage[0]=1;
 return 1;
}
