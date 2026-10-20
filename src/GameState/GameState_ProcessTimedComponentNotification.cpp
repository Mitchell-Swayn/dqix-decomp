#include <globaldefs.h>
#include <std_library_functions.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" char* _ZN9GameState20GetUnknownGameObjectEv(void*);
extern "C" unsigned char* GameState_GetIndexList(void*);
extern "C" void* Zone3D_GetMainInstance();
extern "C" int _ZN6Zone3D32HasMapFlag10OutsideExcludedZonesEv(void*);
extern "C" bool LinkedQueue_IsEmpty(const int*);
extern "C" int PartyRoster_ContainsActiveObjectIndex(unsigned char*,unsigned);
extern "C" unsigned long long _Z19GetCurrentTimestampv();
extern "C" void* Script_ReadGlobalExecutionValue();
extern "C" void Text_EnqueueThreeEntryMessage(void*,const char*,unsigned char,unsigned char,unsigned char,unsigned char);
extern "C" const char* Text_LookupStandardString(unsigned);
extern "C" char* GameResources_GetInstance();
extern "C" void Field_UpdateCombatantAppearanceFlags(void*,int,int,int);
extern "C" void Network_QueueTypeSeventeenRecord(void*,short,short,short);
// Original: arm9/main @ 0x02052BFC; symbol: func_02052bfc; size: 0x180.
extern "C" void GameState_ProcessTimedComponentNotification(char* object) {
 if(!*(void**)(object+0x150)) return;
 void* game=_ZN9GameState11GetInstanceEv();
 char* resources=GameResources_GetInstance();
 int* gate=*(int**)(resources+0x36fc);
 unsigned char* indices=GameState_GetIndexList(game);
 void* zone=Zone3D_GetMainInstance();
 unsigned char index=*(short*)(object+4);
 if(!PartyRoster_ContainsActiveObjectIndex(indices,index) || !*(unsigned char*)(*(char**)(object+0x150)+0x56c)) return;
 unsigned long long elapsed=((_Z19GetCurrentTimestampv()-*(unsigned long long*)(*(char**)(object+0x150)+0x480))<<6)/0x1ff6210;
 if(!LinkedQueue_IsEmpty(gate)) return;
 if((long long)elapsed<300 && _ZN6Zone3D32HasMapFlag10OutsideExcludedZonesEv(zone)) return;
 *(unsigned char*)(*(char**)(object+0x150)+0x56c)=0;
 if(index==*(short*)(_ZN9GameState20GetUnknownGameObjectEv(game)+4)) {
 char message[128];
 if(*(unsigned char*)(*(char**)(object+0x150)+0x56d)) strcpy(message,Text_LookupStandardString(0x33));
 else strcpy(message,Text_LookupStandardString(0x32));
 Text_EnqueueThreeEntryMessage(Script_ReadGlobalExecutionValue(),message,0,0,1,1);
 }
 Field_UpdateCombatantAppearanceFlags(resources,0,index,2);
 Network_QueueTypeSeventeenRecord(0,1,0,index);
}
