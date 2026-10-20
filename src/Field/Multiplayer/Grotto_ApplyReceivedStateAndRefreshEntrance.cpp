#include <globaldefs.h>
ARM
struct Flags {unsigned char active:1,pad:1,reset:1;signed char index:5;};
struct Nibbles {unsigned char low:4,high:4;};
struct Message {unsigned first;unsigned short zone;unsigned char type;Flags flags;unsigned char a,b;unsigned short c,x,y,z;unsigned char v;Nibbles n;};
extern "C" int Network_GetLocalMemberId(char*);
extern "C" char* Zone3D_GetMainInstance();
extern "C" void* GameState_ReadUnkF8(void*);
extern "C" char* _ZN9GameState15GetGrottoStructEv(void*);
extern "C" int LinkedList_ContainsTag(void*,int);
extern "C" int _ZNK19TreasureMapMetadata17GetDiscoveryStateEv(void*);
extern "C" void* _ZN9GameState14GetProtagonistEv(void*);
extern "C" unsigned short _ZNK8Object3D10GetField06Ev(void*);
extern "C" int LinkedQueue_GetFrontKindOrInvalid(void*);
extern "C" void _ZN13ZoneState266418ShowEntranceObjectEv(void*,int);
extern "C" void GameState_SetAllGroupedFiveBitFlags(void*);
extern "C" void* _ZN9GameState21GetPartyMemberByIndexEi(void*,int);
extern "C" bool _Z12IsGrottoZonei(int);
// Original: arm9/ov017 @ 0x021CF86C; symbol: func_ov017_021cf86c; size: 0x250.
extern "C" void Grotto_ApplyReceivedStateAndRefreshEntrance(void* unused,Message* message,void* game,char* resources,char* connection) {
 if(message->flags.index>=0&&Network_GetLocalMemberId(connection)!=message->flags.index)return;
 char* global=Zone3D_GetMainInstance();
 char* grotto;
 void* control=*(void**)(resources+0x36fc);
 GameState_ReadUnkF8(game);
 grotto=_ZN9GameState15GetGrottoStructEv(game);
 if(LinkedList_ContainsTag(control,0x4e)) {
 char* pending=*(char**)(resources+0x3ca4);
 *(unsigned short*)(pending+0x3a)=message->zone;
 pending[0x3c]=message->type;
 pending[0x3d]=*((unsigned char*)&message->flags);
 pending[0x3e]=message->a;
 pending[0x3f]=message->b;
 *(unsigned short*)(pending+0x40)=message->c;
 *(unsigned short*)(pending+0x42)=message->x;
 *(unsigned short*)(pending+0x44)=message->y;
 *(unsigned short*)(pending+0x46)=message->z;
 pending[0x48]=message->v;
 pending[0x49]=*((unsigned char*)&message->n);
 pending[0x39]=1;
 } else {
 *(int*)(grotto+12)=message->zone;
 grotto[0x6c]=message->type;
 *(bool*)grotto=message->flags.active?true:false;
 *(int*)(grotto+0x10)=(short)message->x<<7;
 *(int*)(grotto+0x14)=(short)message->y<<7;
 *(int*)(grotto+0x18)=(short)message->z<<7;
 grotto[0x83]=message->a;
 grotto[0x84]=message->b;
 *(unsigned short*)(grotto+0x86)=message->c;
 grotto[6]=message->n.low;
 grotto[5]=message->n.high;
 grotto[8]=message->v;
 grotto[1]=0;
 }
 if(*(unsigned char*)grotto&&(_ZNK19TreasureMapMetadata17GetDiscoveryStateEv(grotto+0x6c)==2||_ZNK19TreasureMapMetadata17GetDiscoveryStateEv(grotto+0x6c)==3)) {
 if(*(int*)(grotto+12)==_ZNK8Object3D10GetField06Ev(_ZN9GameState14GetProtagonistEv(game))&&LinkedQueue_GetFrontKindOrInvalid(control)!=10)
 _ZN13ZoneState266418ShowEntranceObjectEv(global+0x2664,0);
 }
 if(*(unsigned char*)grotto&&message->flags.reset&&(_ZNK19TreasureMapMetadata17GetDiscoveryStateEv(grotto+0x6c)==2||_ZNK19TreasureMapMetadata17GetDiscoveryStateEv(grotto+0x6c)==3))
 GameState_SetAllGroupedFiveBitFlags(game);
 if(_Z12IsGrottoZonei(_ZNK8Object3D10GetField06Ev(_ZN9GameState21GetPartyMemberByIndexEi(game,0)))&&message->flags.reset)
 GameState_SetAllGroupedFiveBitFlags(game);
}
