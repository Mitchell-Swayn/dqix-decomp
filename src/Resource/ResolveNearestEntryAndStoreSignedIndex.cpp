#include <globaldefs.h>
#include <Resource/Script.h>
ARM
extern "C" void* ReadGlobalAt020FDD44();extern "C" unsigned _ZNK8Object3D10GetField06Ev(const void*);extern "C" unsigned char* FindRecordAmongFourByNonnegativeKey(void*,int);extern "C" int Object_FindClosestFixedPointPositionEntryId(void*,void*);extern "C" int IndexedRecordTable_FindRecordIndexByValue(void*,int);
// Original: arm9/main @ 0x02079040; symbol: func_02079040; size: 0x6C.
extern "C" unsigned short ResolveNearestEntryAndStoreSignedIndex(unsigned char* p,unsigned char* output){*output=0;void* table=ReadGlobalAt020FDD44();unsigned char* entry=FindRecordAmongFourByNonnegativeKey(table,_ZNK8Object3D10GetField06Ev(p));if(!entry)return 0;int value=Object_FindClosestFixedPointPositionEntryId(entry+24,p+68);int index=IndexedRecordTable_FindRecordIndexByValue(entry+24,value);if(index!=-1)*(short*)(p+184)=index;return value;}
