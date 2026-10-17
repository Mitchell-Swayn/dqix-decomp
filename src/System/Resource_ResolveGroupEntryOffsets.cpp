#include <globaldefs.h>
ARM
struct ResourceEntry { unsigned value; void* payload; };
struct ResourceGroup { short value; short count; ResourceEntry* entries; };
struct ResourceOffsets { unsigned short groupCount; unsigned short unknown; unsigned flags; ResourceEntry* entries; char* payloadBase; };
// Original: arm9/main @ 0x020DF77C; symbol: func_020df77c; size: 0x90.
// Converts a group entry index and its payload offsets into in-memory pointers.
// The serialized sentinel -1 becomes null; callback always reports success.
extern "C" int Resource_ResolveGroupEntryOffsets(ResourceOffsets* root,ResourceGroup* group)
{
 int index=(int)group->entries;
 if(index==-1) group->entries=0;
 else {
  int count;
  ResourceEntry* entry;
  entry=root->entries+root->groupCount+index;
  group->entries=entry;
  count=group->count;
  for(int i=0;i<count;i++,entry++){
   int invalid=1;
   int offset=(char*)entry->payload-(char*)0;
   if(offset!=-1 && root->payloadBase!=0) invalid=0;
   entry->payload=invalid?0:root->payloadBase+offset;
  }
 }
 return 1;
}
