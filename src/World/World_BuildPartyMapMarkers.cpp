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
void* Zone3D_GetMainInstance();
int WorldMap_FindShipMarkerPosition(void*,unsigned,unsigned,short*,short*);
void* Network_GetConnectionManager();
unsigned short _ZNK8Object3D10GetField06Ev(void*);
unsigned char GameObject_GetPartyFormationOrder(void*);
bool SystemState_TestAnyFlags(const unsigned*,unsigned);
void GameObject_GetMapMarkerCoordinates(void*,int*,int*);
unsigned char GameObject_GetMapMarkerCategory(void*);
void* GameState_GetSerializedProgressState();
unsigned BitArray_ReadNonnegativeIndexMask(void*,unsigned char*,int);
void VectorizedMemset(void*,int,unsigned);
void* SystemState_GetGlobalFlags();
char* GameResources_GetInstance();
// Original data: arm9/main @ 0x20e704c; symbol: data_020e704c.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 0410cc10941101190000.
// Observed span: 10 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern unsigned short WorldBuildPartyMapMarkers_UnknownRoleInitializedBytes[];
}
// Original: arm9/main @ 0x020236DC; symbol: func_020236dc; size: 0x3C0.
extern "C" int World_BuildPartyMapMarkers(Marker* out,unsigned char* categories,Vec* protagonistPos){
 register int count;
 void* game=_ZN9GameState11GetInstanceEv();
 count=(int)GameResources_GetInstance();
 void* protagonist=_ZN9GameState14GetProtagonistEv(game);
 unsigned char* state=(unsigned char*)Zone3D_GetMainInstance();
 Network_GetConnectionManager();
 unsigned char* flags=(unsigned char*)GameState_GetSerializedProgressState();
 void* global=SystemState_GetGlobalFlags();
 char* map=*(char**)((char*)count+0x36d0);
 count=0;
 for(int i=0;i<4;i++){
  unsigned char* obj=(unsigned char*)GameState_GetObjectWithFlag100(game,i);
  if(!obj||!(*(unsigned*)(obj+0x18c)&8))continue;
  if(GameState_FindIndexedObjectWithFlag1000(game,i)){
   unsigned char j=0; unsigned key=*(unsigned short*)(state+4); int found=0;
   while(WorldBuildPartyMapMarkers_UnknownRoleInitializedBytes[j]){if(key==WorldBuildPartyMapMarkers_UnknownRoleInitializedBytes[j]){found=true;break;}j++;}
   if(found)continue;
  }
  Marker* marker=out+count;
  marker->index=i;count++;
  marker->hidden=(*(unsigned short*)(obj+0x1b2)&&!SystemState_TestAnyFlags((unsigned*)global,0x80000))?1:0;
  marker->protagonist=protagonist?(_ZNK8Object3D10GetField06Ev(protagonist)==_ZNK8Object3D10GetField06Ev(obj)):0;
  if(*(unsigned*)(obj+0x18c)&16){
   GameObject_GetMapMarkerCoordinates(obj,&marker->pos.x,&marker->pos.z);
   marker->category=GameObject_GetMapMarkerCategory(obj);
   marker->order=categories[marker->category];categories[marker->category]++;
   if(i==GameState_ReadProtagonistObjectIndex(game)){protagonistPos->x=marker->pos.x;protagonistPos->z=marker->pos.z;}
  }else{
   Vec pos=*(Vec*)(obj+0x44);marker->pos.x=pos.x;marker->pos.y=pos.y;marker->pos.z=pos.z;marker->order=-1;
  }
  marker->kind=5;marker->icon=*(short*)(obj+4)+4;
  void* member=_ZN9GameState21GetPartyMemberByIndexEi(game,i);
  void* indexed=GameState_FindIndexedObjectWithFlag1000(game,i);
  if(member&&(!*(short*)(obj+4)||indexed))marker->variant=GameObject_GetPartyFormationOrder(member)+0x58;
  else marker->variant=*(short*)(obj+4)+0x5b;
  if(member)marker->member=GameObject_GetPartyFormationOrder(member);
  if(**(unsigned**)(obj+0x130)&1){marker->kind=6;marker->icon=6;}
 }
 bool found=false;
 char* resource2=GameResources_GetInstance();
 char* second=*(char**)(resource2+0x36d0);
 if(second){
  List* list=*(List**)(second+0x754);
  while(list){for(int i=0;i<list->count;i++){unsigned key=list->keys[i]; unsigned current=*(unsigned short*)(state+0x2786);if(key==current){found=true;break;}}list=list->next;}
 }
 if(found&&BitArray_ReadNonnegativeIndexMask(flags,flags+0x8c,0x2b)){
  short y=0,x=0;
  if(WorldMap_FindShipMarkerPosition(map,*(unsigned short*)(state+0x2786),(unsigned char)*(short*)(state+0x2784),&y,&x)){
   Marker* marker=out+count;count++;VectorizedMemset(marker,0,24);
   marker->order=-1;marker->index=255;marker->pos.x=y<<12;marker->pos.z=x<<12;marker->kind=27;marker->icon=7;marker->variant=0x74;
  }
 }
 return count;
}
