#include <globaldefs.h>
ARM
struct State { unsigned char flags[4]; int value; int current; int entry; int busy; };
// Original data: arm9/ov017 @ 0x21d8438; symbol: data_ov017_021d8438.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 36 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov017.md.
extern "C" State ScriptTrySelectIndexedString_UnknownRoleZeroInitializedStorage;
// Original data: arm9/ov017 @ 0x21d7c54; symbol: data_ov017_021d7c54.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex ffff0000.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov017.md.
extern "C" signed char ScriptTrySelectIndexedString_UnknownRoleInitializedBytes[];
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" char* _ZN9GameState20GetGameObjectByIndexEi(void*,int);
extern "C" bool _ZNK9GameState21IsMorningDayOrEveningEv(void*);
extern "C" unsigned int* Network_GetConnectionManager();
extern "C" bool Network_IsClientSession(unsigned int*);
extern "C" int _ZNK6Script9Parameter5ToIntEv(const void*);
extern "C" const char* _ZNK6Script9Parameter8ToStringEv(const void*);
extern "C" bool GameState_TrySelectIndexedEntry(int,const char*);
// Original: arm9/ov017 @ 0x021BA3DC; symbol: func_ov017_021ba3dc; size: 0x148.
extern "C" bool Script_TrySelectIndexedStringWhenObjectReady(char* args,int count) {
 if(ScriptTrySelectIndexedString_UnknownRoleZeroInitializedStorage.busy) return true;
 if(ScriptTrySelectIndexedString_UnknownRoleInitializedBytes[1]>-1) return true;
 void* game=_ZN9GameState11GetInstanceEv();
 if(Network_IsClientSession(Network_GetConnectionManager())) return true;
 int value=*(unsigned short*)(*(char**)(_ZN9GameState20GetGameObjectByIndexEi(game,0)+0x130)+4);
 if(value>0) return true;
 int low=_ZNK6Script9Parameter5ToIntEv(args);
 char* next=args+8; args+=16;
 int high=_ZNK6Script9Parameter5ToIntEv(next);
 if(low>=0 && (ScriptTrySelectIndexedString_UnknownRoleZeroInitializedStorage.value<low || high<ScriptTrySelectIndexedString_UnknownRoleZeroInitializedStorage.value)) return true;
 if(count>=5) {
 int condition=_ZNK6Script9Parameter5ToIntEv(args);
 args+=8;
 if(condition) {
 if(_ZNK9GameState21IsMorningDayOrEveningEv(_ZN9GameState11GetInstanceEv())) return true;
 ScriptTrySelectIndexedString_UnknownRoleZeroInitializedStorage.flags[2]=1;
 }
 } else if(ScriptTrySelectIndexedString_UnknownRoleZeroInitializedStorage.flags[2]) return true;
 int index=_ZNK6Script9Parameter5ToIntEv(args);
 const char* str=_ZNK6Script9Parameter8ToStringEv(args+8);
 if(!str) return false;
 if(GameState_TrySelectIndexedEntry(index,str)) ScriptTrySelectIndexedString_UnknownRoleZeroInitializedStorage.flags[1]=1;
 return true;
}
