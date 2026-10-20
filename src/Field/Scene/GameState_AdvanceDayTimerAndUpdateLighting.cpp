#include <globaldefs.h>
ARM
struct Nibble {unsigned char value:4,rest:4;};
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" char* Zone3D_GetMainInstance();
extern "C" unsigned* Network_GetConnectionManager();
extern "C" int LinkedQueue_GetFrontKindOrInvalid(void*);
extern "C" unsigned GameState_ReadByteAtOffset4(void*);
extern "C" int GameState_GetStartupDispatchMode(void*);
extern "C" int _ZNK9GameState12GetTimeOfDayEv(void*);
extern "C" void _ZN9GameState15AdvanceDayTimerEv(void*);
extern "C" bool Network_IsParentOrOffline(unsigned*);
extern "C" void Field_QueueDayTimerSynchronization();
extern "C" bool FieldBattle_IsSceneActive(void*);
extern "C" char* _ZN15LightingManager11GetInstanceEv();
extern "C" char* GameState_GetSerializedProgressState();
extern "C" void BitArray_SetIndexedBoolean(void*,void*,int,int);
extern "C" float _ZNK9GameState11GetDayTimerEv(void*);
// Original: arm9/ov017 @ 0x0218D0EC; symbol: func_ov017_0218d0ec; size: 0x16C.
extern "C" void GameState_AdvanceDayTimerAndUpdateLighting(char* self) {
 void* game=_ZN9GameState11GetInstanceEv();
 char* global=Zone3D_GetMainInstance();
 unsigned* connection=Network_GetConnectionManager();
 if(LinkedQueue_GetFrontKindOrInvalid(*(void**)(self+0x36fc))==3)return;
 if(GameState_ReadByteAtOffset4(game)==6)return;
 if(GameState_GetStartupDispatchMode(game)==5)return;
 unsigned kind=((Nibble*)(*(char**)(global+8)+12))->value;
 int advance=1;
 if(kind!=0&&kind!=7)advance=0;
 int before=_ZNK9GameState12GetTimeOfDayEv(game);
 if(advance)_ZN9GameState15AdvanceDayTimerEv(game);
 int after=_ZNK9GameState12GetTimeOfDayEv(game);
 if(Network_IsParentOrOffline(connection)&&before!=after)Field_QueueDayTimerSynchronization();
 if(LinkedQueue_GetFrontKindOrInvalid(*(void**)(self+0x36fc))==10) {
 if(FieldBattle_IsSceneActive(*(void**)(self+0x3718)))return;
 }
 if(LinkedQueue_GetFrontKindOrInvalid(*(void**)(self+0x36fc))==4)return;
 if(LinkedQueue_GetFrontKindOrInvalid(*(void**)(self+0x36fc))==22)return;
 char* lighting=_ZN15LightingManager11GetInstanceEv();
 int previous=*(int*)(lighting+0x98);
 if(previous!=_ZNK9GameState12GetTimeOfDayEv(game)) {
 if(_ZNK9GameState12GetTimeOfDayEv(game)==1||_ZNK9GameState12GetTimeOfDayEv(game)==0) {
 char* state=GameState_GetSerializedProgressState();
 BitArray_SetIndexedBoolean(state,state+0x8c,0x1140,1);
 }
 }
 *(float*)(lighting+0x94)=_ZNK9GameState11GetDayTimerEv(game);
 *(int*)(lighting+0x98)=_ZNK9GameState12GetTimeOfDayEv(game);
}
