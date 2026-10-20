#include <globaldefs.h>
ARM
extern "C" void* Network_GetConnectionManager();
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" char* GameState_ReadUnkF8(void*);
extern "C" unsigned short* Zone3D_GetMainInstance();
extern "C" int _ZN13ZoneState084018IsValueInRangeC3b5Ei(char*,int);
extern "C" int _ZN13ZoneState084024IsValueAtHundredBoundaryEi(char*,int);
extern "C" int _ZN13ZoneState084018IsValueInRangeC545Ei(char*,int);
extern "C" void _ZN13ZoneState084020UpdateEntryCountTierEv(char*);
extern "C" char* _ZN9GameState14GetProtagonistEv(void*);
extern "C" bool Network_IsParentOrOffline(unsigned*);
extern "C" bool Network_IsClientSession(unsigned*);
extern "C" void Network_QueueBoundaryZoneTier(unsigned char);
extern "C" void GameState_ReplacePendingFieldTransition(void*,void*);
// Original: arm9/main @ 0x02097CAC; symbol: func_02097cac; size: 0x21C.
extern "C" void World_UpdateBoundaryZoneTier(char* self){
 unsigned* connection=(unsigned*)Network_GetConnectionManager();
 void* state=_ZN9GameState11GetInstanceEv();
 char* zone=GameState_ReadUnkF8(state);
 unsigned short* global=Zone3D_GetMainInstance();
 int current=*(unsigned short*)zone;
 char* protagonist;int previous=*global;
 if(!_ZN13ZoneState084018IsValueInRangeC3b5Ei(self,current) && !_ZN13ZoneState084018IsValueInRangeC3b5Ei(self,previous))return;
 protagonist=_ZN9GameState14GetProtagonistEv(state);
 if(_ZN13ZoneState084024IsValueAtHundredBoundaryEi(self,current) && (!_ZN13ZoneState084024IsValueAtHundredBoundaryEi(self,previous) || *(unsigned char*)(zone+0x65))){
  if(Network_IsParentOrOffline(connection) && !(*(unsigned*)(*(char**)(protagonist+0x130))&1))_ZN13ZoneState084020UpdateEntryCountTierEv(self);
  unsigned tier=*(unsigned*)(self+0x1b3c);
  Network_QueueBoundaryZoneTier((unsigned char)tier);
  switch(tier){case 0:break;case 1:case 2:*(unsigned short*)zone=0xc3b5;break;case 3:case 4:*(unsigned short*)zone=0xc419;break;case 5:*(unsigned short*)zone=0xc47d;break;case 6:*(unsigned short*)zone=0xc4e1;break;}
  GameState_ReplacePendingFieldTransition(state,zone);return;
 }
 if(!Network_IsClientSession(connection) || !*(unsigned char*)(zone+0x65))return;
 unsigned tier=*(unsigned*)(self+0x1b3c);
 if(!_ZN13ZoneState084018IsValueInRangeC3b5Ei(self,current))return;
 if(_ZN13ZoneState084018IsValueInRangeC545Ei(self,current))return;
 if(current==0xc3bb)return;
 if(current==0xc3bc)return;
 if(current==0xc3bd)return;
 if(current==0xc3be)return;
 int value=(int)*(unsigned short*)zone%100+0xc350;
 switch(tier){case 0:break;case 1:case 2:*(unsigned short*)zone=value+100;break;case 3:case 4:*(unsigned short*)zone=value+200;break;case 5:*(unsigned short*)zone=value+300;break;case 6:*(unsigned short*)zone=value+400;break;}
}
