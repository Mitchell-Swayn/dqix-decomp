#include <globaldefs.h>
ARM
extern "C" unsigned Network_GetWirelessWorkspace();
extern "C" int Util_CompareSixBytes(const unsigned char*,const unsigned char*);
struct KeyNode{unsigned char pad[12];KeyNode* next;unsigned unknown;unsigned char key[6];};
struct KeyList{unsigned unknown;KeyNode* first;};
struct SharedListRegion{unsigned char pad[0x270];KeyList* list;unsigned size;};
// Original: arm9/ov031 @ 0x0220EDE4; symbol: func_ov031_0220ede4; size: 0x6C.
// Searches shared buffer's linked nodes for an equal six-byte key when size>12.
extern "C" KeyNode* Network_FindAccessPointByBssid(const unsigned char* key){
 SharedListRegion* shared=(SharedListRegion*)(Network_GetWirelessWorkspace()+0x2000);
 KeyNode* result=0;
 KeyList* list=shared->list;
 if(!key)return result;
 if(list && shared->size>12){
  result=list->first;
  if(result)do{
   if(Util_CompareSixBytes(result->key,key))break;
   result=result->next;
  }while(result);
 }
 return result;
}
