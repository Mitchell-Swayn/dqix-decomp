#include <globaldefs.h>
ARM
extern "C" void* memcpy(void*,const void*,unsigned);extern "C" void* memset(void*,int,unsigned);

#define P(p,o) (*(char**)((char*)(p)+(o)))
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define C(x) ((char*)(x))
// Original: arm9/main @ 0x02089EDC; symbol: AppendSixtyFourByteRecordWithTypedFieldCopies.
extern "C" void CharacterTemplate_AppendEntry(char* self,char* source){
if(!P(self,0))return;int count=S(self,4);if(S(self,6)<=count)return;char* target=P(self,0)+count*64;*(signed char*)target=*(signed char*)source;W(target,4)=W(source,4);B(target,8)=B(source,8);H(target,10)=S(source,10);W(target,12)=W(source,12);B(target,16)=B(source,16);B(target,17)=B(source,17);B(target,18)=B(source,18);W(target,20)=W(source,20);W(target,24)=W(source,24);struct Halfwords{short value[10];};*(Halfwords*)(target+28)=*(Halfwords*)(source+28);struct Bytes{char value[13];};*(Bytes*)(target+48)=*(Bytes*)(source+48);B(target,61)=B(source,61);B(target,62)=B(source,62);B(target,63)=B(source,63);H(self,4)=S(self,4)+1;
}
