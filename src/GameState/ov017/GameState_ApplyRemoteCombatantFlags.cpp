#include <globaldefs.h>
ARM
struct GameState { char* GetCombatantByIndex(int); };
extern "C" int GameState_ReadProtagonistObjectIndex(GameState*);
extern "C" void* OV017_ReadWordField6AC(void*);
extern "C" void* OV017_ReadWordField6B0(void*);
extern "C" void* OV017_GetEmbeddedField1C(void*);
struct Bits { unsigned char a:1,b:1,c:1,d:1,e:4; };
struct Packet { char pad[17]; Bits flags; char pad2; unsigned char last:7; unsigned char flag:1; };
struct Target { char pad[0x3a]; unsigned char flag; Bits flags; };
// Original: arm9/ov017 @ 0x021C7334; symbol: func_ov017_021c7334; size: 0x150.
extern "C" void GameState_ApplyRemoteCombatantFlags(void*, Packet* p, GameState* gs, char* ctx) {
void* x=*(void**)(ctx+0x3718);
char* field=(char*)OV017_GetEmbeddedField1C(x);
if(!field)return;
if(!OV017_ReadWordField6AC(x))return;
if(!OV017_ReadWordField6B0(x))return;
if(*(signed char*)(field+0x2a)==GameState_ReadProtagonistObjectIndex(gs))return;
if(*(unsigned short*)(field+8)!=*(unsigned short*)((char*)p+4))return;
char* obj=gs->GetCombatantByIndex(*(unsigned short*)((char*)p+6));
if(!obj)return;
(*(Target**)(obj+0x138))->flags.a=p->flags.a;
(*(Target**)(obj+0x138))->flags.b=p->flags.b;
(*(Target**)(obj+0x138))->flags.c=p->flags.c;
(*(Target**)(obj+0x138))->flags.d=p->flags.d;
(*(Target**)(obj+0x138))->flags.e=p->flags.e;
(*(Target**)(obj+0x138))->flag=p->flag != 0;
}
