#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Graphics/Vector.h"
extern "C" unsigned char *ReadGlobalValueAt020FB3F0();extern "C" unsigned char *GameState_ReadUnkF8(GameState *);extern "C" void ZoneTransition_WriteThreeWordComponents(Vector3i *,int,int,int);
// Original: arm9/main @ 0x020A696C; symbol: func_020a696c; size: 0x138.
extern "C" void AdjustSpecialZoneDestinationAndSaveWorldCoordinates(unsigned unused,int a,int b){GameState *state=GameState::GetInstance();unsigned char *world=ReadGlobalValueAt020FB3F0();unsigned char *p=GameState_ReadUnkF8(state);if(b==0x170c && ((a>=0x4e20 && a<=0x752f)||a==0x76c)){if(!p[5] && !p[0x62]){unsigned id=*(unsigned short *)(world+0x2786);*(unsigned short *)p=id;switch(id){case 0:case 1:{*(unsigned short *)p=0x170c;Vector3i value;ZoneTransition_WriteThreeWordComponents(&value,-0x7000,0x170c>>3,0x5e66);*(Vector3i *)(p+16)=value;p[7]=1;break;}default:if(id!=0x76c){*(unsigned *)(p+16)=0x100000;*(unsigned *)(p+20)=0;*(unsigned *)(p+24)=0x100000;p[7]=1;}break;}}}if(a==0x2710 && b>=0x4e20 && b<=0x752f){*(unsigned *)(world+0x278c)=*(unsigned *)(world+0x44);*(unsigned *)(world+0x2790)=*(unsigned *)(world+0x48);}}
