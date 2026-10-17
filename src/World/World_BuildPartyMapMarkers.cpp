#include <globaldefs.h>
ARM
#pragma optimization_level 3
#pragma opt_loop_invariants off
#pragma opt_repositioncode off
#pragma opt_rotateloops off
struct Vec {int x,y,z;};
struct Marker {Vec pos;unsigned char kind,icon,variant; signed char order;unsigned char category,hidden,protagonist,member,index,pad[3];};
struct List {unsigned short a;unsigned char count,pad;unsigned short* keys;unsigned char rest[8];List* next;};
extern "C" {
void* _ZN9GameState11GetInstanceEv();
void* _ZN9GameState14GetProtagonistEv(void*);
void* _ZN9GameState21GetPartyMemberByIndexEi(void*,int);
void* GameState_GetObjectWithFlag100(void*,int);
void* GameState_FindIndexedObjectWithFlag1000(void*,int);
int GameState_ReadProtagonistObjectIndex(void*);
void* ReadGlobalValueAt020FB3F0();
int FindCoordinatePairByHalfwordAndByteKeys(void*,unsigned,unsigned,short*,short*);
void* Object_GetGlobalConnectionState();
unsigned short _ZNK8Object3D10GetField06Ev(void*);
unsigned char Object_ReadCharAtOffset1C9(void*);
bool TestWordMaskNonzero(const unsigned*,unsigned);
void Object_ReadWordsAtOffsets1A8And1AC(void*,int*,int*);
unsigned char ReadByteFieldAtOffset1B0(void*);
void* ReadGlobalValueAt02108844();
unsigned ReadNonnegativeIndexedBit(void*,unsigned char*,int);
void VectorizedMemset(void*,int,unsigned);
void* GetGlobalStatePointer();
char* GameResources_GetInstance();
extern unsigned short data_020e704c[];
}
// Original: arm9/main @ 0x020236DC; symbol: func_020236dc; size: 0x3C0.
extern "C" int World_BuildPartyMapMarkers(Marker* out,unsigned char* categories,Vec* protagonistPos){
 register int count;
 void* game=_ZN9GameState11GetInstanceEv();
 count=(int)GameResources_GetInstance();
 void* protagonist=_ZN9GameState14GetProtagonistEv(game);
 unsigned char* state=(unsigned char*)ReadGlobalValueAt020FB3F0();
 Object_GetGlobalConnectionState();
 unsigned char* flags=(unsigned char*)ReadGlobalValueAt02108844();
 void* global=GetGlobalStatePointer();
 char* map=*(char**)((char*)count+0x36d0);
 count=0;
 for(int i=0;i<4;i++){
  unsigned char* obj=(unsigned char*)GameState_GetObjectWithFlag100(game,i);
  if(!obj||!(*(unsigned*)(obj+0x18c)&8))continue;
  if(GameState_FindIndexedObjectWithFlag1000(game,i)){
   unsigned char j=0; unsigned key=*(unsigned short*)(state+4); int found=0;
   while(data_020e704c[j]){if(key==data_020e704c[j]){found=true;break;}j++;}
   if(found)continue;
  }
  Marker* marker=out+count;
  marker->index=i;count++;
  marker->hidden=(*(unsigned short*)(obj+0x1b2)&&!TestWordMaskNonzero((unsigned*)global,0x80000))?1:0;
  marker->protagonist=protagonist?(_ZNK8Object3D10GetField06Ev(protagonist)==_ZNK8Object3D10GetField06Ev(obj)):0;
  if(*(unsigned*)(obj+0x18c)&16){
   Object_ReadWordsAtOffsets1A8And1AC(obj,&marker->pos.x,&marker->pos.z);
   marker->category=ReadByteFieldAtOffset1B0(obj);
   marker->order=categories[marker->category];categories[marker->category]++;
   if(i==GameState_ReadProtagonistObjectIndex(game)){protagonistPos->x=marker->pos.x;protagonistPos->z=marker->pos.z;}
  }else{
   Vec pos=*(Vec*)(obj+0x44);marker->pos.x=pos.x;marker->pos.y=pos.y;marker->pos.z=pos.z;marker->order=-1;
  }
  marker->kind=5;marker->icon=*(short*)(obj+4)+4;
  void* member=_ZN9GameState21GetPartyMemberByIndexEi(game,i);
  void* indexed=GameState_FindIndexedObjectWithFlag1000(game,i);
  if(member&&(!*(short*)(obj+4)||indexed))marker->variant=Object_ReadCharAtOffset1C9(member)+0x58;
  else marker->variant=*(short*)(obj+4)+0x5b;
  if(member)marker->member=Object_ReadCharAtOffset1C9(member);
  if(**(unsigned**)(obj+0x130)&1){marker->kind=6;marker->icon=6;}
 }
 bool found=false;
 char* resource2=GameResources_GetInstance();
 char* second=*(char**)(resource2+0x36d0);
 if(second){
  List* list=*(List**)(second+0x754);
  while(list){for(int i=0;i<list->count;i++){unsigned key=list->keys[i]; unsigned current=*(unsigned short*)(state+0x2786);if(key==current){found=true;break;}}list=list->next;}
 }
 if(found&&ReadNonnegativeIndexedBit(flags,flags+0x8c,0x2b)){
  short y=0,x=0;
  if(FindCoordinatePairByHalfwordAndByteKeys(map,*(unsigned short*)(state+0x2786),(unsigned char)*(short*)(state+0x2784),&y,&x)){
   Marker* marker=out+count;count++;VectorizedMemset(marker,0,24);
   marker->order=-1;marker->index=255;marker->pos.x=y<<12;marker->pos.z=x<<12;marker->kind=27;marker->icon=7;marker->variant=0x74;
  }
 }
 return count;
}
