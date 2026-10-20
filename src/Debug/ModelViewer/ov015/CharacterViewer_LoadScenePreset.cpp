#include <globaldefs.h>
#include <Memory/AllocatorUnion.h>
ARM
typedef unsigned short ushort;
struct Pair {unsigned first,second;};
struct RecordArray {void* records;Pair* pairs;int count;int pairCount;};
struct Entry {int file;unsigned short field4;unsigned char type,pad;Entry* next;};
struct LoadedNode {unsigned char* object;LoadedNode* next;};
struct EntryConfiguration {int file,duplicateFile;unsigned short field8;unsigned char byteA,byteB;};
extern "C" Pair* CharacterViewer_GetScenePreset(RecordArray*,int);
extern "C" bool Input_TestKeyMask(unsigned short*,unsigned short);
extern "C" void* AllocatorUnion_AllocateFourByteAligned(AllocatorUnion*,unsigned);
extern "C" void Memory_FreeThroughAllocatorUnion(void*,void*);
extern "C" void CharacterViewer_DestroyModelInstanceResources(unsigned char*);
extern "C" void CharacterViewer_InitializeModelInstance(unsigned char*);
extern "C" int Resource_MapTypeAndInitializeObject(unsigned char*,void*,unsigned);
extern "C" int CharacterViewer_LoadModelByKind(unsigned char*,void*);
extern "C" void Graphics_DispatchAnimationLoadByMode(void*,int);
extern "C" unsigned short KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage[];
extern "C" AllocatorUnion Main_UnknownRoleZeroInitializedStorage_Variant3;
// Original: arm9/ov015 @ 0x02191C70; symbol: CharacterViewer_LoadScenePreset; size: 0x234.
// Builds model nodes and attaches following animation entries, preserving owner mode during special animation loads.
extern "C" void CharacterViewer_LoadScenePreset(unsigned char* self,int index) {
 Pair* pair=CharacterViewer_GetScenePreset((RecordArray*)(self+0x3c),index);
 if(!pair)return;
 if(Input_TestKeyMask(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,0x100)) {
  LoadedNode* node=*(LoadedNode**)(self+0x2c);
  while(node) {
   CharacterViewer_DestroyModelInstanceResources(node->object);
   Memory_FreeThroughAllocatorUnion(&Main_UnknownRoleZeroInitializedStorage_Variant3,node->object);
   LoadedNode* old=node;node=node->next;
   Memory_FreeThroughAllocatorUnion(&Main_UnknownRoleZeroInitializedStorage_Variant3,old);
  }
  *(LoadedNode**)(self+0x2c)=0;
 }
 Entry* entry=(Entry*)pair->second;
 int mode;
 LoadedNode* node;
 unsigned char* object=0;
 for(;entry;entry=entry->next) {
  mode=*(int*)(self+0x1a4);
  if(entry->type==8 || entry->type==9 || entry->type==10) {
   switch(entry->type) {case 8:*(int*)(self+0x1a4)=30;break;case 9:*(int*)(self+0x1a4)=31;break;case 10:*(int*)(self+0x1a4)=32;break;}
   if(object)Graphics_DispatchAnimationLoadByMode(object,entry->file);
   *(int*)(self+0x1a4)=mode;
  } else if(entry->type==11) {
   if(object)Graphics_DispatchAnimationLoadByMode(object,entry->file);
  } else {
   node=(LoadedNode*)AllocatorUnion_AllocateFourByteAligned(&Main_UnknownRoleZeroInitializedStorage_Variant3,8);
   if(!node)return;
   node->object=0;node->next=0;
   object=node->object=(unsigned char*)AllocatorUnion_AllocateFourByteAligned(&Main_UnknownRoleZeroInitializedStorage_Variant3,0x5c);
   if(!object) {Memory_FreeThroughAllocatorUnion(&Main_UnknownRoleZeroInitializedStorage_Variant3,node);return;}
   CharacterViewer_InitializeModelInstance(object);
   if(!Resource_MapTypeAndInitializeObject(object,self,entry->type)) {
    Memory_FreeThroughAllocatorUnion(&Main_UnknownRoleZeroInitializedStorage_Variant3,node->object);node->object=0;
    Memory_FreeThroughAllocatorUnion(&Main_UnknownRoleZeroInitializedStorage_Variant3,node);return;
   }
   EntryConfiguration configuration;
   configuration.file=0;configuration.duplicateFile=0;configuration.field8=0;configuration.byteA=0;configuration.byteB=0;
   configuration.file=entry->file;configuration.duplicateFile=entry->file;configuration.field8=entry->field4;
   if(!CharacterViewer_LoadModelByKind(object,&configuration)) {
    CharacterViewer_DestroyModelInstanceResources(node->object);
    Memory_FreeThroughAllocatorUnion(&Main_UnknownRoleZeroInitializedStorage_Variant3,node->object);node->object=0;
    Memory_FreeThroughAllocatorUnion(&Main_UnknownRoleZeroInitializedStorage_Variant3,node);return;
   }
   LoadedNode** tail=(LoadedNode**)(self+0x2c);
   while(*tail)tail=&(*tail)->next;
   *tail=node;
  }
 }
}
