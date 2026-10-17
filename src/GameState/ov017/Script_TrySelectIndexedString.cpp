#include <globaldefs.h>
ARM
struct State {unsigned char flags[4];int value;int current;int entry;int busy;};
extern "C" State data_ov017_021d8438;
extern "C" signed char data_ov017_021d7c54[];
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" bool _ZNK9GameState21IsMorningDayOrEveningEv(void*);
extern "C" int _ZNK6Script9Parameter5ToIntEv(const void*);
extern "C" const char* _ZNK6Script9Parameter8ToStringEv(const void*);
extern "C" bool GameState_TrySelectIndexedEntry(int,const char*);
// Original: arm9/ov017 @ 0x021B9D00; symbol: func_ov017_021b9d00; size: 0x130.
extern "C" bool Script_TrySelectIndexedString(char* args,int count) {
 if(data_ov017_021d8438.busy) return true;
 if(data_ov017_021d8438.flags[0]) return true;
 if(data_ov017_021d7c54[0]>-1) return true;
 if(data_ov017_021d8438.flags[1]) return true;
 if(data_ov017_021d7c54[1]>-1) return true;
 _ZN9GameState11GetInstanceEv();
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
 GameState_TrySelectIndexedEntry(index,str);
 return true;
}
