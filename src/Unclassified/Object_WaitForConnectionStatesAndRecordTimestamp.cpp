#include <globaldefs.h>
ARM
extern "C" int Object_ReadElement4();extern "C" void TransitionGlobalStateTwoToThree();extern "C" void _Z19SleepCurrentContextj(unsigned);extern "C" void ConfigureNetworkStateFromMode(int,void*);extern "C" char data_020feffc[];extern "C" char* _ZN9GameState11GetInstanceEv();extern "C" unsigned long long _Z19GetCurrentTimestampv();
// Original: arm9/main @ 0x0202B840; symbol: func_0202b840; size: 0xC0.
extern "C" int Object_WaitForConnectionStatesAndRecordTimestamp(unsigned* p,int id){if(id<0)return 1;int n=0;while(Object_ReadElement4()==2){TransitionGlobalStateTwoToThree();if(++n>5000)return 0;_Z19SleepCurrentContextj(1);}n=0;while(Object_ReadElement4()!=1){if(++n>5000)return 0;_Z19SleepCurrentContextj(1);}ConfigureNetworkStateFromMode(5,data_020feffc+id*192);*p=6;char* state=_ZN9GameState11GetInstanceEv();*(unsigned long long*)(state+1008)=_Z19GetCurrentTimestampv();return 1;}
