#include <globaldefs.h>
ARM
extern "C" int strncmp(const char*,const char*,unsigned);
extern "C" int Util_ClassifyEnabledRecordByPriorityState(void*);
struct Entry {unsigned char pad,result,pad2,length;char text[32];};
// Original: arm9/ov031 @ 0x02213894; symbol: func_ov031_02213894; size: 0x7C.
extern "C" int Util_FindLengthMatchedStringResult(unsigned char* p,int count,Entry* entries){
 if(*(unsigned short*)(p+10)==32){
 int result=Util_ClassifyEnabledRecordByPriorityState(p);
 if(result>0)return result;
 }
 unsigned char shortLength;
 int i=0;
 if(count>0){
 unsigned length=*(unsigned short*)(p+10);
 shortLength=length;
 do{
 if(shortLength==entries->length && !strncmp((char*)p+12,entries->text,length))return entries->result;
 i++;entries++;
 }while(i<count);
 }
 return -1;
}
