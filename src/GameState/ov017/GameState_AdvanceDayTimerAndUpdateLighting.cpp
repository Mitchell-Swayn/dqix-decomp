#include <globaldefs.h>
ARM
struct Nibble {unsigned char value:4,rest:4;};
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" char* ReadGlobalValueAt020FB3F0();
extern "C" unsigned* Object_GetGlobalConnectionState();
extern "C" int ReadIndirectByteOrMinusOne(void*);
extern "C" unsigned GameState_ReadByteAtOffset4(void*);
extern "C" int GameState_ReadWordAtOffset7F6C(void*);
extern "C" int _ZNK9GameState12GetTimeOfDayEv(void*);
extern "C" void _ZN9GameState15AdvanceDayTimerEv(void*);
extern "C" bool TestInactiveOrPrimaryIndexState(unsigned*);
extern "C" void QueueDayTimerMessage93();
extern "C" bool func_ov017_021b8b54(void*);
extern "C" char* _ZN15LightingManager11GetInstanceEv();
extern "C" char* ReadGlobalValueAt02108844();
extern "C" void BitArray_SetIndexedBoolean(void*,void*,int,int);
extern "C" float _ZNK9GameState11GetDayTimerEv(void*);
// Original: arm9/ov017 @ 0x0218D0EC; symbol: func_ov017_0218d0ec; size: 0x16C.
extern "C" void GameState_AdvanceDayTimerAndUpdateLighting(char* self) {
 void* game=_ZN9GameState11GetInstanceEv();
 char* global=ReadGlobalValueAt020FB3F0();
 unsigned* connection=Object_GetGlobalConnectionState();
 if(ReadIndirectByteOrMinusOne(*(void**)(self+0x36fc))==3)return;
 if(GameState_ReadByteAtOffset4(game)==6)return;
 if(GameState_ReadWordAtOffset7F6C(game)==5)return;
 unsigned kind=((Nibble*)(*(char**)(global+8)+12))->value;
 int advance=1;
 if(kind!=0&&kind!=7)advance=0;
 int before=_ZNK9GameState12GetTimeOfDayEv(game);
 if(advance)_ZN9GameState15AdvanceDayTimerEv(game);
 int after=_ZNK9GameState12GetTimeOfDayEv(game);
 if(TestInactiveOrPrimaryIndexState(connection)&&before!=after)QueueDayTimerMessage93();
 if(ReadIndirectByteOrMinusOne(*(void**)(self+0x36fc))==10) {
 if(func_ov017_021b8b54(*(void**)(self+0x3718)))return;
 }
 if(ReadIndirectByteOrMinusOne(*(void**)(self+0x36fc))==4)return;
 if(ReadIndirectByteOrMinusOne(*(void**)(self+0x36fc))==22)return;
 char* lighting=_ZN15LightingManager11GetInstanceEv();
 int previous=*(int*)(lighting+0x98);
 if(previous!=_ZNK9GameState12GetTimeOfDayEv(game)) {
 if(_ZNK9GameState12GetTimeOfDayEv(game)==1||_ZNK9GameState12GetTimeOfDayEv(game)==0) {
 char* state=ReadGlobalValueAt02108844();
 BitArray_SetIndexedBoolean(state,state+0x8c,0x1140,1);
 }
 }
 *(float*)(lighting+0x94)=_ZNK9GameState11GetDayTimerEv(game);
 *(int*)(lighting+0x98)=_ZNK9GameState12GetTimeOfDayEv(game);
}
