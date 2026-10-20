#include <globaldefs.h>
ARM
extern "C" int _ZNK6Script9Parameter5ToIntEv(const void*);
extern "C" float _ZNK6Script9Parameter7ToFloatEv(void*);
extern "C" char* ZoneState2754_FindPrimaryRecordByKey(void*,int);
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* GameState_GetIndexList(void*);
extern "C" void* _Z11GetBTRandomv();
extern "C" float _Z22NextRandomFloatBetweenP6Randomff(void*,float,float);
struct Flags{unsigned short bits:13;unsigned short high:3;};
struct Context {unsigned char pad,done;unsigned short gap;void* table;unsigned unused;char* object;};
// Original data: arm9/ov023 @ 0x21fff08; symbol: data_ov023_021fff08.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov023.md.
extern "C" Context ScriptSetPackedStateFields_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov023 @ 0x021F5848; symbol: func_ov023_021f5848; size: 0x1D4.
extern "C" int Script_SetRecordRandomThresholdResult(char* params){
 if(ScriptSetPackedStateFields_UnknownRoleZeroInitializedStorage.done)return 1;
 int key=_ZNK6Script9Parameter5ToIntEv(params);
 if(key==*(short*)(ScriptSetPackedStateFields_UnknownRoleZeroInitializedStorage.object+0xf8)){
  if(!ScriptSetPackedStateFields_UnknownRoleZeroInitializedStorage.table){ScriptSetPackedStateFields_UnknownRoleZeroInitializedStorage.done=1;((Flags*)(ScriptSetPackedStateFields_UnknownRoleZeroInitializedStorage.object+0x10c))->bits|=2;return 0;}
  char* record=ZoneState2754_FindPrimaryRecordByKey(ScriptSetPackedStateFields_UnknownRoleZeroInitializedStorage.table,(short)key);
  if(!record){ScriptSetPackedStateFields_UnknownRoleZeroInitializedStorage.done=1;((Flags*)(ScriptSetPackedStateFields_UnknownRoleZeroInitializedStorage.object+0x10c))->bits|=2;return 0;}
  GameState_GetIndexList(_ZN9GameState11GetInstanceEv());
  float lo=_ZNK6Script9Parameter7ToFloatEv(params+8);
  float hi=_ZNK6Script9Parameter7ToFloatEv(params+16);
  void* random=_Z11GetBTRandomv();
  unsigned value=*(unsigned short*)(record+0x1a);
  float factor=_Z22NextRandomFloatBetweenP6Randomff(random,lo,hi);
  int threshold=(int)((float)value*factor);
  char* object=ScriptSetPackedStateFields_UnknownRoleZeroInitializedStorage.object;
  if(threshold>=*(unsigned short*)(object+0xfc) || (((Flags*)(object+0x10c))->bits&4))((Flags*)(object+0x10c))->bits|=1;
  else ((Flags*)(object+0x10c))->bits|=2;
  ScriptSetPackedStateFields_UnknownRoleZeroInitializedStorage.done=1;
 }
 return 1;
}
