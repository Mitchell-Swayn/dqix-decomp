#include <globaldefs.h>
ARM
extern "C" int Util_AreFirstSixBytesZero(const void*);
extern "C" int RuntimeMemory_CompareByteRanges(const void*,const void*,unsigned);
extern "C" void* memset(void*,int,unsigned);
extern "C" void* memcpy(void*,const void*,unsigned);
struct Entry{unsigned char key[6];unsigned char age,pad;};
// Original: arm9/ov003 @ 0x02171E1C; symbol: func_ov003_02171e1c; size: 0x164.
extern "C" void Util_TouchSixByteKeyInFiftyEntryCache(char* self,const void* key){
 if(!key)return;if(Util_AreFirstSixBytesZero(key))return;
 Entry* found=0;int age=0;
 Entry* entry=(Entry*)(self+8);
 for(int i=0;i<50;i++,entry++){
  int old=entry->age;
  if(old && !RuntimeMemory_CompareByteRanges(entry,key,6)){entry->age=50;found=entry;age=old;break;}
 }
 if(age==50)return;
 if(age>0){
  Entry* entry=(Entry*)(self+8);
  for(int i=0;i<50;i++,entry++)if(entry->age>age && entry!=found)--entry->age;
  return;
 }
 Entry* free=0;
 Entry* current=(Entry*)(self+8);
 for(int i=0;i<50;i++,current++){
  if(current->age){--current->age;if(!current->age){memset(current,0,6);--*(unsigned char*)(self+0x198);}}
  if(!current->age && !free)free=current;
 }
 if(free){free->age=50;memcpy(free,key,6);++*(unsigned char*)(self+0x198);}
}
