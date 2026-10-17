#include <globaldefs.h>
ARM
struct State {unsigned char flags[4];int value;int current;int entry;int busy;};
extern "C" State data_ov017_021d8438;
extern "C" signed char data_ov017_021d7c54[];
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" bool _ZNK9GameState21IsMorningDayOrEveningEv(void*);
extern "C" void* Object_GetGlobalConnectionState();
extern "C" int IsFirstWordNonzero(void*);
extern "C" int ReadIndexedSignedField1038(char*);
extern "C" int _ZNK6Script9Parameter5ToIntEv(const void*);
extern "C" const char* _ZNK6Script9Parameter8ToStringEv(const void*);
extern "C" bool GameState_TrySelectIndexedEntry(int,const char*);

// Original: arm9/ov017 @ 0x021BA280; symbol: func_ov017_021ba280; size: 0x15C.
extern "C" bool Script_TrySelectIndexedStringWhenConnected(char* args,int count) {
 if(data_ov017_021d8438.busy) return true;
 if(data_ov017_021d7c54[0]>-1) return true;
 if(data_ov017_021d8438.flags[1]) return true;
 if(data_ov017_021d7c54[1]>-1) return true;
 _ZN9GameState11GetInstanceEv();
 void* connection=Object_GetGlobalConnectionState();
 if(!IsFirstWordNonzero(connection)) return true;
 if(!ReadIndexedSignedField1038((char*)connection)) return true;

 int low=_ZNK6Script9Parameter5ToIntEv(args);
 char* next=args+8; args+=16;
 int high=_ZNK6Script9Parameter5ToIntEv(next);
 if(low>=0 && (data_ov017_021d8438.value<low || high<data_ov017_021d8438.value)) return true;
 if(count>=5) {
 int condition=_ZNK6Script9Parameter5ToIntEv(args);
 args+=8;
 if(condition) {
 if(_ZNK9GameState21IsMorningDayOrEveningEv(_ZN9GameState11GetInstanceEv())) return true;
 data_ov017_021d8438.flags[2]=1;
 }
 } else if(data_ov017_021d8438.flags[2]) return true;
 int index=_ZNK6Script9Parameter5ToIntEv(args);
 const char* str=_ZNK6Script9Parameter8ToStringEv(args+8);
 if(!str) return false;
 if(GameState_TrySelectIndexedEntry(index,str)) data_ov017_021d8438.flags[0]=1;
 return true;
}
