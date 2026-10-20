#include <globaldefs.h>
#include <std_library_functions.h>
#include <Memory/SafeAllocator.h>
ARM
struct OffsetBase { unsigned words[2]; unsigned char* base; };
struct StringEntry { union { struct { short key; unsigned short unknown; char* text; }; unsigned words[2]; }; inline int ReadKey() const { return key; } };
struct StringList { unsigned count:12, flags:20; StringEntry* entries; unsigned char* base; };
typedef int (*RecordValueProc)(int);
extern "C" {
int InitializeRelocatedBlobPointersAndMarkProcessed(char*,char*,unsigned char*,int);
int ResourceStringTable_FindEntryByCallbackKey(unsigned*,int,RecordValueProc);
unsigned char* ResourceStringTable_ResolvePayloadOffset(OffsetBase*,unsigned char*,unsigned char*);
char* Allocator_DuplicateTerminatedString(SafeAllocator*,char*);
int ResourceStringTable_GetEntryKey(short*);
}
// Original: arm9/main @ 0x020E0028; symbol: ResourceStringTable_CopyEntriesForKeys; size: 0x258.
// Copies requested keyed strings from a relocated blob and sorts the owned entries.
extern "C" bool ResourceStringTable_CopyEntriesForKeys(StringList* out,SafeAllocator* allocator,char* blob,unsigned size,short* keys,volatile unsigned short count)
{
 if(!allocator || !blob || !size || !keys || !count)return false;
 memset(out,0,12);
 StringList source;
 StringEntry temps[2];
 memset(&source,0,12);
 unsigned char changed;
 InitializeRelocatedBlobPointersAndMarkProcessed((char*)&source,blob,&changed,0);
 short* cursor;
 int found=0;
 unsigned short n;
 {int i=found;
 cursor=keys;
 n=count;
 for(;i<n;i++,cursor++)
  if(ResourceStringTable_FindEntryByCallbackKey((unsigned*)&source,*cursor,(RecordValueProc)ResourceStringTable_GetEntryKey))found++;
 }
 out->entries=(StringEntry*)allocator->Allocate(found*8);
 StringEntry* dest;
 StringEntry* back;
 int first;
 if(out->entries){
  out->count=found;
  cursor=keys;
  dest=out->entries;
  for(int i=0;i<n;i++,cursor++){
   StringEntry* entry=(StringEntry*)ResourceStringTable_FindEntryByCallbackKey((unsigned*)&source,*cursor,(RecordValueProc)ResourceStringTable_GetEntryKey);
   if(entry){
    char* text=(char*)ResourceStringTable_ResolvePayloadOffset((OffsetBase*)&source,(unsigned char*)entry->text,0);
    dest->key=entry->key;
    dest->text=Allocator_DuplicateTerminatedString(allocator,text);
    dest++;
   }
  }
 }
 if(found>=2 && out){
  int total=out->count;
  if(out->entries && total){
  int last;
  int end=total-1;
  int begin=0;
  for(;;){
   found=begin;
   dest=out->entries+begin;
   last=-1;
   for(;found<end;dest++,found++){
    int left=dest->ReadKey();
    int right=dest[1].ReadKey();
    if(left>right){
     COPY_ARRAY(temps[0].words,dest->words);
     dest->key=right;dest->text=dest[1].text;
     dest[1].key=temps[0].key;dest[1].text=temps[0].text;
     last=found;
    }
   }
   if(last==-1)break;
   end=last;
   back=out->entries+last;
   first=-1;
   for(;last>begin;last--){
    dest=back-1;
    if(dest->key>back->key){
     COPY_ARRAY(temps[1].words,back->words);
     back->key=dest->key;back->text=dest->text;
     dest->key=temps[1].key;dest->text=temps[1].text;
     first=last;
    }
    back=dest;
   }
   if(first==-1)break;
   begin=first;
  }
 }}
 return true;
}
