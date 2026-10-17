#include <globaldefs.h>
ARM
extern "C" short data_020e8aaa[];extern "C" void* _ZN9GameState11GetInstanceEv();extern "C" int Object_ReadIndexedBitAtOffset8EC(void*,int);extern "C" int GameState_ReadAttributeBits12To19(void*,int);
// Original: arm9/main @ 0x02086164; symbol: func_02086164; size: 0x6C.
extern "C" int GameState_SumPresentAttributesFromSecondSentinelTable(void* p){void* state=_ZN9GameState11GetInstanceEv();int sum=0;unsigned i=0;while(data_020e8aaa[i]!=-1){int key=data_020e8aaa[i];if(Object_ReadIndexedBitAtOffset8EC(p,key))sum+=GameState_ReadAttributeBits12To19(state,key);i=(i+1)&255;}return sum;}
