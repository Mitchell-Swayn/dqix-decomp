#include <globaldefs.h>
ARM
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define S(p,o) (*(signed char*)((char*)(p)+(o)))
#define H(p,o) (*(short*)((char*)(p)+(o)))
#define U(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define W(p,o) (*(unsigned*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
// Original data: arm9/ov017 @ 0x21d65ec; symbol: data_ov017_021d65ec.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 00040000983a0000.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov017.md.
// Original data: arm9/ov017 @ 0x21d65f4; symbol: data_ov017_021d65f4.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 640000007c150000ffffffff.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov017.md.
// Original data: arm9/ov017 @ 0x21d6600; symbol: data_ov017_021d6600.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 52fcffff3d1e0000c351feff0bd7ffffe10200005d0fffff.
// Observed span: 24 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov017.md.
// Original data: arm9/ov017 @ 0x21d6618; symbol: data_ov017_021d6618.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 0b003100ffff000000000000000000000a00ffff000000000000000000000000.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov017.md.
struct Table;struct Entry;extern "C" void* ActorPool_GetGlobalInstance();extern "C" Entry* ActorPool_FindActiveActorById(Table*,unsigned);extern "C" unsigned short* Actor_GetPlacementDescriptor(void*);extern "C" int World_ResolveHorizontalObjectOverlap(char*,char*,int);extern "C" void* _ZN8Vector3iaSERKS_(void*,const void*);extern "C" int WorldFindMatchingActiveOverlapAndCopyPosition_UnknownRoleInitializedBytes_Variant2[];extern "C" signed char WorldFindMatchingActiveOverlapAndCopyPosition_UnknownRoleInitializedBytes[];extern "C" short WorldFindMatchingActiveOverlapAndCopyPosition_UnknownRoleInitializedBytes_Variant4[];struct Vec{int x,y,z;};extern "C" Vec WorldFindMatchingActiveOverlapAndCopyPosition_UnknownRoleInitializedBytes_Variant3[];
// Original: arm9/ov017 @ 0x021A01F4; symbol: World_FindMatchingActiveOverlapAndCopyPosition; size: 0xFC.
extern "C" int World_FindMatchingActiveOverlapAndCopyPosition(int unused,int key,int kind,char* object,void* output){int* keys=WorldFindMatchingActiveOverlapAndCopyPosition_UnknownRoleInitializedBytes_Variant2;for(int i=0;*keys!=-1;keys++,i++){if(*keys!=key)continue;int type=WorldFindMatchingActiveOverlapAndCopyPosition_UnknownRoleInitializedBytes[i];if(type!=kind&&type!=4)continue;Table* table=(Table*)ActorPool_GetGlobalInstance();short* ids=WorldFindMatchingActiveOverlapAndCopyPosition_UnknownRoleInitializedBytes_Variant4+i*8;for(;*ids!=-1;){Entry* entry=ActorPool_FindActiveActorById(table,*ids);if(!entry){ids++;continue;}char* record=(char*)Actor_GetPlacementDescriptor(entry);if(!record){ids++;continue;}if(B(record,2)==1){ids++;continue;}if(World_ResolveHorizontalObjectOverlap(object,(char*)entry,0)){_ZN8Vector3iaSERKS_(output,WorldFindMatchingActiveOverlapAndCopyPosition_UnknownRoleInitializedBytes_Variant3+i);return 1;}ids++;}}return 0;}
