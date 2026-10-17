#include <globaldefs.h>
ARM
extern "C" int _ZNK6Script9Parameter5ToIntEv(const void*);
extern "C" float _ZNK6Script9Parameter7ToFloatEv(void*);
extern "C" char* FindSerializedPrimaryRecordByKey(void*,int);
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* GameState_GetIndexList(void*);
extern "C" void* _Z11GetBTRandomv();
extern "C" float _Z22NextRandomFloatBetweenP6Randomff(void*,float,float);
struct Flags{unsigned short bits:13;unsigned short high:3;};
struct Context {unsigned char pad,done;unsigned short gap;void* table;unsigned unused;char* object;};
extern "C" Context data_ov023_021fff08;
// Original: arm9/ov023 @ 0x021F5848; symbol: func_ov023_021f5848; size: 0x1D4.
extern "C" int Script_SetRecordRandomThresholdResult(char* params){
 if(data_ov023_021fff08.done)return 1;
 int key=_ZNK6Script9Parameter5ToIntEv(params);
 if(key==*(short*)(data_ov023_021fff08.object+0xf8)){
  if(!data_ov023_021fff08.table){data_ov023_021fff08.done=1;((Flags*)(data_ov023_021fff08.object+0x10c))->bits|=2;return 0;}
  char* record=FindSerializedPrimaryRecordByKey(data_ov023_021fff08.table,(short)key);
  if(!record){data_ov023_021fff08.done=1;((Flags*)(data_ov023_021fff08.object+0x10c))->bits|=2;return 0;}
  GameState_GetIndexList(_ZN9GameState11GetInstanceEv());
  float lo=_ZNK6Script9Parameter7ToFloatEv(params+8);
  float hi=_ZNK6Script9Parameter7ToFloatEv(params+16);
  void* random=_Z11GetBTRandomv();
  unsigned value=*(unsigned short*)(record+0x1a);
  float factor=_Z22NextRandomFloatBetweenP6Randomff(random,lo,hi);
  int threshold=(int)((float)value*factor);
  char* object=data_ov023_021fff08.object;
  if(threshold>=*(unsigned short*)(object+0xfc) || (((Flags*)(object+0x10c))->bits&4))((Flags*)(object+0x10c))->bits|=1;
  else ((Flags*)(object+0x10c))->bits|=2;
  data_ov023_021fff08.done=1;
 }
 return 1;
}
