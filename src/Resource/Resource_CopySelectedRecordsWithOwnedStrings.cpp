#include <globaldefs.h>
ARM
#pragma optimization_level 4
struct Header{unsigned payload:31,ready:1;};
struct Group {Header header;char* start;char* end;};
struct Count {unsigned count:12,other:20;};
struct Owner{Count flags;char* entries;};
extern "C" {
// Original data: arm9/main @ 0x2108d14; symbol: data_02108d14.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern Owner* ResourceCopySelectedRecordsWithOwnedStrings_UnknownRoleZeroInitializedStorage;
void MonsterData_RelocateRecordStrings(void*);
int MonsterData_GetRecordId(const void*);
int MonsterData_BindAndRelocateSerializedDataOnce(Group*,const void*,bool*,void(*)(void*));
char* MonsterData_FindEntryByExtractedKey(const Group*,int,int(*)(const void*));
void* memmove(void*,const void*,unsigned);
void* memcpy(void*,const void*,unsigned);
char* _ZN13SafeAllocator8AllocateEj(void*,unsigned);
char* Allocator_DuplicateTerminatedString(void*,char*);
}
// Original: arm9/main @ 0x0206F230; symbol: func_0206f230; size: 0x240.
extern "C" void Resource_CopySelectedRecordsWithOwnedStrings(Owner* out,void* allocator,const void* source,unsigned,const short* ids,int num,void* stringAllocator,const unsigned char* sizes){
ResourceCopySelectedRecordsWithOwnedStrings_UnknownRoleZeroInitializedStorage=out;
if(!num)return;
short selected[512];Group group;bool ready=false;
MonsterData_BindAndRelocateSerializedDataOnce(&group,source,&ready,MonsterData_RelocateRecordStrings);
short count=0;
const short* cursor=ids;
for(int i=0;i<num;i++,cursor++){
short id=*cursor;
if(MonsterData_FindEntryByExtractedKey(&group,id,MonsterData_GetRecordId)){
short* at=selected;int insert=1;
for(int j=0;j<count;j++,at++){
if(*at==id){insert=0;break;}
if(*at>id){memmove(at+1,at,(count-j)*2);break;}
}
if(insert){*at=id;count++;if(count>=512)break;}
}
}
out->entries=_ZN13SafeAllocator8AllocateEj(allocator,count*28);
if(!out->entries)return;
if(stringAllocator && sizes)_ZN13SafeAllocator8AllocateEj(allocator,128-count*8);
short actual=0;char* dest=out->entries;
short* at=selected;
for(int i=0;i<count;i++,at++){
char* entry=MonsterData_FindEntryByExtractedKey(&group,*at,MonsterData_GetRecordId);
if(entry){
memcpy(dest,entry,28);
if(stringAllocator && sizes){
*(char**)dest=Allocator_DuplicateTerminatedString(stringAllocator,*(char**)entry);
*(char**)(dest+20)=Allocator_DuplicateTerminatedString(stringAllocator,*(char**)(entry+20));
_ZN13SafeAllocator8AllocateEj(allocator,sizes[i]);
}else{
*(char**)dest=Allocator_DuplicateTerminatedString(allocator,*(char**)entry);
*(char**)(dest+20)=Allocator_DuplicateTerminatedString(allocator,*(char**)(entry+20));
}
*(char**)(dest+4)=Allocator_DuplicateTerminatedString(allocator,*(char**)(entry+4));
short next=actual+1;dest+=28;actual=next;
}
}
out->flags.count=actual;
}
