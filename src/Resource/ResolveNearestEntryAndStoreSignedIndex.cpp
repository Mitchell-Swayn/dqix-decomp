#include <globaldefs.h>
#include <Resource/Script.h>
ARM
extern "C" void* ZoneState_GetTrackedZoneCache();extern "C" unsigned _ZNK8Object3D10GetField06Ev(const void*);extern "C" unsigned char* ZoneState_FindTrackedZoneByIdentifier(void*,int);extern "C" int ActorPathGraph_FindNearestNodeIdByDistance(void*,void*);extern "C" int IndexedRecordTable_FindRecordIndexByValue(void*,int);
// Original: arm9/main @ 0x02079040; symbol: func_02079040; size: 0x6C.
extern "C" unsigned short ResolveNearestEntryAndStoreSignedIndex(unsigned char* p,unsigned char* output){*output=0;void* table=ZoneState_GetTrackedZoneCache();unsigned char* entry=ZoneState_FindTrackedZoneByIdentifier(table,_ZNK8Object3D10GetField06Ev(p));if(!entry)return 0;int value=ActorPathGraph_FindNearestNodeIdByDistance(entry+24,p+68);int index=IndexedRecordTable_FindRecordIndexByValue(entry+24,value);if(index!=-1)*(short*)(p+184)=index;return value;}
