#include <globaldefs.h>
#include "GameState/GameState.h"
ARM

extern "C" unsigned FieldBattle_GetCombatContext(void*);
extern "C" void* FieldBattle_GetEncounterRequest(void*);
extern "C" unsigned FieldBattle_GetScene(void*);
extern "C" void* _ZN9GameState19GetCombatantByIndexEi(void*,int);
extern "C" int GameState_ReadProtagonistObjectIndex(GameState*);
struct PackedTen {unsigned a:3,b:3,c:3,d:3,e:3,f:3,g:3,h:3,i:3,j:3,pad:2;};
struct Packet {unsigned header;unsigned short owner,index;PackedTen first,second;unsigned short value;unsigned char mode;};
// Original: arm9/ov017 @ 0x021C787C; symbol: func_ov017_021c787c; size: 0x310.
// Unpacks twenty three-bit values into one of two combatant byte ranges.
extern "C" void Combat_ApplyRemoteCombatantPackedValueBanks(void*,Packet *packet,GameState *game,unsigned char *resources){
 void *node=*(void**)(resources+0x3718);unsigned char *owner=(unsigned char*)FieldBattle_GetEncounterRequest(node);if(!owner)return;
 if(!FieldBattle_GetScene(node))return;if(!FieldBattle_GetCombatContext(node))return;
 if(*(signed char*)(owner+0x2a)==GameState_ReadProtagonistObjectIndex(game))return;
 if(*(unsigned short*)(owner+8)!=packet->owner)return;
 unsigned char *object=(unsigned char*)_ZN9GameState19GetCombatantByIndexEi(game,packet->index);if(!object)return;
 unsigned char *entry=*(unsigned char**)(object+0x138);
 switch(packet->mode){case 1:
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
 return;default:
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
