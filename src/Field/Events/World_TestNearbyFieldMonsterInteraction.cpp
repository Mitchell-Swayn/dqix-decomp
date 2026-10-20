#include <globaldefs.h>
ARM
#pragma always_inline on
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" char* _ZN9GameState20GetUnknownGameObjectEv(void*);
extern "C" int _Z8fix32absi(int);
extern "C" unsigned short _ZNK8Object3D10GetField06Ev(void*);
extern "C" int GameObject_GetLadderTraversalActive(void*);
extern "C" bool LinkedQueue_IsEmpty(const int*);
extern "C" int LinkedList_ContainsTag(void*,int);
struct Vec {int x,y,z;};
extern "C" int Vector3fix_Distance(const Vec*,const Vec*);
extern "C" char* GameResources_GetInstance();
extern "C" char* FieldMonster_FindByPersistentRecordIdentifier(void*,unsigned);
extern "C" void Ov017_SetOwnerActiveAndUpdateSound(void*,int);
extern "C" char* FieldBattle_GetEncounterRequest(void*);
struct Embedded { char pad[8]; unsigned short id; unsigned short GetId(){return id;} bool Matches(int other){return id==other;} };
struct Player {char pad[0xc3]; unsigned char value; int GetValue(){return value;} };
struct Monster {char pad[0x17d]; unsigned char flags; unsigned char GetFlag() {return flags&0x80;} };
// Original: arm9/ov017 @ 0x021C5C5C; symbol: func_ov017_021c5c5c; size: 0x1CC.
extern "C" int World_TestNearbyFieldMonsterInteraction(void* unused,short id) {
 void* game=_ZN9GameState11GetInstanceEv();
 char* resources=GameResources_GetInstance();
 char* player;
 int* gate=*(int**)(resources+0x36fc);
 player=_ZN9GameState20GetUnknownGameObjectEv(game);
 if(!player) return 0;
 if(*(unsigned char*)(resources+0x42e7)) return 0;
 char* context=*(char**)(resources+0x3718);
 if(((unsigned char*)context)[2]) {
 if(((Embedded*)FieldBattle_GetEncounterRequest(context))->Matches(id)) return 1;
 }
 if(!(**(unsigned**)(player+0x130)&1) && !(*(unsigned*)(player+0x18c)&1) && ((Player*)player)->GetValue()>0) return 0;
 char* monster=FieldMonster_FindByPersistentRecordIdentifier(resources,id);
 if(!monster) return 0;
 if(((Monster*)monster)->GetFlag()) return 0;
 *(unsigned char*)(monster+0x17d)|=0x80;
 unsigned short zone=_ZNK8Object3D10GetField06Ev(player);
 if(zone!=_ZNK8Object3D10GetField06Ev(monster)) return 0;
 if(GameObject_GetLadderTraversalActive(player)) return 0;
 Vec playerPosition=*(Vec*)(player+0x44);
 Vec monsterPosition=*(Vec*)(monster+0x44);
 if(_Z8fix32absi(playerPosition.y-monsterPosition.y)>0x1800) return 0;
 if(Vector3fix_Distance(&monsterPosition,&playerPosition)>0xf000) return 0;
 char* manager=*(char**)(resources+0x3b0c);
 if(LinkedList_ContainsTag(gate,26) && *(int*)(manager+0x64)) return 0;
 if(((unsigned char*)manager)[3] && !((unsigned char*)manager)[1]) Ov017_SetOwnerActiveAndUpdateSound(manager,0);
 else if(!LinkedQueue_IsEmpty(gate)) return 0;
 return 1;
}
