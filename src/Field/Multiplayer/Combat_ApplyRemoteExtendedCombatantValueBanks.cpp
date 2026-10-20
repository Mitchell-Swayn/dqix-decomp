#include <globaldefs.h>
#include "GameState/GameState.h"
ARM

extern "C" unsigned FieldBattle_GetCombatContext(void*);
extern "C" int GameState_ReadProtagonistObjectIndex(GameState*);
struct PackedTen {unsigned a:3,b:3,c:3,d:3,e:3,f:3,g:3,h:3,i:3,j:3,pad:2;};
struct Packet {unsigned header;unsigned short owner,index;PackedTen first,second;unsigned short value;unsigned char mode;};
// Original: arm9/ov017 @ 0x021CB2F4; symbol: func_ov017_021cb2f4; size: 0x304.
// Unpacks twenty three-bit values into one of two combatant byte ranges.
extern "C" void Combat_ApplyRemoteExtendedCombatantValueBanks(void*,Packet *packet,GameState *game,unsigned char *resources){
 unsigned char *state=(unsigned char*)FieldBattle_GetCombatContext(*(void**)(resources+0x3718));
 if(!state)return;unsigned char *owner=*(unsigned char**)(state+0x8e18);if(!owner)return;
 if(*(signed char*)(owner+0x2a)==GameState_ReadProtagonistObjectIndex(game))return;
 if(*(unsigned short*)(owner+8)!=packet->owner)return;
 int index=packet->index-0xc0;if(index<0||index>=8)return;
 unsigned char *entry=owner+0x158+index*0xa4;
 if(packet->mode==1){
 entry[92]=packet->first.a;
 entry[93]=packet->first.b;
 entry[94]=packet->first.c;
 entry[95]=packet->first.d;
 entry[96]=packet->first.e;
 entry[97]=packet->first.f;
 entry[98]=packet->first.g;
 entry[99]=packet->first.h;
 entry[100]=packet->first.i;
 entry[101]=packet->first.j;
 entry[102]=packet->second.a;
 entry[103]=packet->second.b;
 entry[104]=packet->second.c;
 entry[105]=packet->second.d;
 entry[106]=packet->second.e;
 entry[107]=packet->second.f;
 entry[108]=packet->second.g;
 entry[109]=packet->second.h;
 entry[110]=packet->second.i;
 entry[111]=packet->second.j;
 *(unsigned short*)(entry+0x36)=packet->value;
 }else{
 entry[127]=packet->first.a;
 entry[128]=packet->first.b;
 entry[129]=packet->first.c;
 entry[130]=packet->first.d;
 entry[131]=packet->first.e;
 entry[132]=packet->first.f;
 entry[133]=packet->first.g;
 entry[134]=packet->first.h;
 entry[135]=packet->first.i;
 entry[136]=packet->first.j;
 entry[137]=packet->second.a;
 entry[138]=packet->second.b;
 entry[139]=packet->second.c;
 entry[140]=packet->second.d;
 entry[141]=packet->second.e;
 entry[142]=packet->second.f;
 entry[143]=packet->second.g;
 entry[144]=packet->second.h;
 entry[145]=packet->second.i;
 entry[146]=packet->second.j;
 }
}
