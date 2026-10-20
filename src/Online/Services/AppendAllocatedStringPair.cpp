#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" unsigned strlen(const char*);
extern "C" char* strcpy(char*,const char*);
extern "C" char AppendAllocatedStringPair_TextALLOCResultEntryILabel[],AppendAllocatedStringPair_TextALLOCResultEntryIValue[],AppendAllocatedStringPair_TextFREEResultEntryILabel[],AppendAllocatedStringPair_TextFREEResultEntryIValue[];
struct Pair { char* key; char* value; };
struct List { Pair* entries; int capacity; int count; };
typedef char* (*Allocate)(const char*,unsigned);
typedef void (*Free)(const char*,void*,int);
// Original: arm9/ov031 @ 0x02218A38; symbol: func_ov031_02218a38; size: 0x154.
extern "C" int AppendAllocatedStringPair(char* state,List* list,const char* key,const char* value) {
 Allocate alloc=*(Allocate*)(state+0x1010);
 Free free=*(Free*)(state+0x1014);
 if(list->count>list->capacity) return 0;
 list->entries[list->count].key=alloc(AppendAllocatedStringPair_TextALLOCResultEntryILabel,strlen(key)+1);
 if(list->entries[list->count].key) {
 list->entries[list->count].value=alloc(AppendAllocatedStringPair_TextALLOCResultEntryIValue,strlen(value)+1);
 if(list->entries[list->count].value) {
 strcpy(list->entries[list->count].key,key);
 strcpy(list->entries[list->count].value,value);
 list->count++;
 return 1;
 }
 }
 if(list->entries[list->count].key) {
 free(AppendAllocatedStringPair_TextFREEResultEntryILabel,list->entries[list->count].key,0);
 list->entries[list->count].key=0;
 }
 if(list->entries[list->count].value) {
 free(AppendAllocatedStringPair_TextFREEResultEntryIValue,list->entries[list->count].value,0);
 list->entries[list->count].value=0;
 }
 return 0;
}
