#include <globaldefs.h>
ARM
extern "C" char data_02108760[];extern "C" unsigned short* ReadGlobalValueAt020FB3F0();extern "C" unsigned _ZNK8Object3D10GetField06Ev(void*);extern "C" void DispatchStoredHalfwordIndexWithTwoArguments(void*,int,int);
struct Field {unsigned short value:15;unsigned short flag:1;};
// Original: arm9/main @ 0x02034044; symbol: func_02034044; size: 0x58.
extern "C" void Object_SetPackedOffsetC4ValueAndNotifyCurrentZone(char* p,unsigned short value){unsigned short key=*ReadGlobalValueAt020FB3F0();if(key==_ZNK8Object3D10GetField06Ev(p))DispatchStoredHalfwordIndexWithTwoArguments(data_02108760,96,0);((Field*)(p+196))->value=value;}
