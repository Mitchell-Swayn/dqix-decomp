#include <globaldefs.h>
#include <Memory/SafeAllocator.h>
#include <std_library_functions.h>
struct DownloadPart {unsigned char prefix[0x88];char name[0x24];int size;};
extern "C" int OnlineContent_DecryptInfoPayload(unsigned char*,int,void*);
extern "C" void OnlineContent_ExecuteMessagePayload(unsigned char*,int,void*);
extern "C" void OnlineContent_ExecuteRandomShopPayload(unsigned char*,int,void*);
extern "C" void OnlineContent_ExecuteQuestPayload(unsigned char*,int,void*);
extern "C" char OnlineContent_DispatchDownloadedParts_TextInfo[],OnlineContent_DispatchDownloadedParts_TextMes[],OnlineContent_DispatchDownloadedParts_TextSell[],OnlineContent_DispatchDownloadedParts_TextAuction[],OnlineContent_DispatchDownloadedParts_TextQuest[];
extern "C" unsigned char ScriptSetPackedStateFields_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov023 @ 0x021F5B9C; symbol: func_ov023_021f5b9c; size: 0x13C.
// Dispatches downloaded records by name, decrypts information payloads in place,
// and updates their payload sizes before clearing the pending transfer state.
extern "C" void OnlineContent_DispatchDownloadedParts(void* input,void* records,int count,void* heap){
 unsigned char* data=(unsigned char*)input; DownloadPart* parts=(DownloadPart*)records;SafeAllocator* allocator=(SafeAllocator*)heap;
 DownloadPart* part; void* buffer; int i;
 buffer=allocator->Allocate(0xc800);
 for(i=0;i<count;++i){
  part=&parts[i];
  bool information=false;
  if(strstr(part->name,OnlineContent_DispatchDownloadedParts_TextInfo)){
   information=true;
   if(!OnlineContent_DecryptInfoPayload(data,part->size,buffer))part->name[0]=0;
  }else if(strstr(part->name,OnlineContent_DispatchDownloadedParts_TextMes))OnlineContent_ExecuteMessagePayload(data,part->size,buffer);
  else if(strstr(part->name,OnlineContent_DispatchDownloadedParts_TextSell)){}
  else if(strstr(part->name,OnlineContent_DispatchDownloadedParts_TextAuction))OnlineContent_ExecuteRandomShopPayload(data,part->size,buffer);
  else if(strstr(part->name,OnlineContent_DispatchDownloadedParts_TextQuest))OnlineContent_ExecuteQuestPayload(data,part->size,buffer);
  data+=part->size;
  if(information)part->size-=4;
 }
 *(unsigned*)(ScriptSetPackedStateFields_UnknownRoleZeroInitializedStorage+4)=0;
}
