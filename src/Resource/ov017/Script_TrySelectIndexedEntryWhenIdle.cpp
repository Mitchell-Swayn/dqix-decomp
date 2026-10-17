#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" int _ZNK9GameState21IsMorningDayOrEveningEv(void*);
extern "C" char* Object_GetGlobalConnectionState();
extern "C" int IsFirstWordNonzero(void*);
extern "C" int ReadIndexedSignedField1038(char*);
extern "C" int _ZNK6Script9Parameter5ToIntEv(const void*);
extern "C" const char* _ZNK6Script9Parameter8ToStringEv(const void*);
extern "C" bool GameState_TrySelectIndexedEntry(int,int);
extern "C" unsigned char data_ov017_021d8438[];
extern "C" signed char data_ov017_021d7c54[];
// Original: arm9/ov017 @ 0x021BA124; symbol: func_ov017_021ba124; size: 0x15C.
extern "C" int Script_TrySelectIndexedEntryWhenIdle(char* params,int count) {
 if(*(int*)(data_ov017_021d8438+0x10))return 1;
 if(data_ov017_021d7c54[0]>-1)return 1;
 if(data_ov017_021d8438[1])return 1;
 if(data_ov017_021d7c54[1]>-1)return 1;
 _ZN9GameState11GetInstanceEv();
 char* conn=Object_GetGlobalConnectionState();
 if(!IsFirstWordNonzero(conn))return 1;
 if(ReadIndexedSignedField1038(conn))return 1;
 int lo=_ZNK6Script9Parameter5ToIntEv(params);
 char* second=params+8;
 params+=16;
 int hi=_ZNK6Script9Parameter5ToIntEv(second);
 if(lo>=0 && (*(int*)(data_ov017_021d8438+4)<lo || hi<*(int*)(data_ov017_021d8438+4)))return 1;
 if(count>=5) {
  int flag=_ZNK6Script9Parameter5ToIntEv(params);
  params+=8;
  if(flag) {
   if(_ZNK9GameState21IsMorningDayOrEveningEv(_ZN9GameState11GetInstanceEv()))return 1;
   data_ov017_021d8438[2]=1;
  }
 } else if(data_ov017_021d8438[2])return 1;
 int index=_ZNK6Script9Parameter5ToIntEv(params);
 const char* s=_ZNK6Script9Parameter8ToStringEv(params+8);
 if(!s)return 0;
 if(GameState_TrySelectIndexedEntry(index,(int)s))data_ov017_021d8438[0]=1;
 return 1;
}
