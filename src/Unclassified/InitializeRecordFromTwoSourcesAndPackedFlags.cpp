#include <globaldefs.h>
ARM
extern "C" void Object_InitializePackedCountersWeightsAndTimers(),CopyBytesAndTwoScalarFields(void*,void*);
struct Bits {unsigned x:10,y:10,z:10,rest:2;};struct Mode{unsigned short mode:2,rest:14;};
// Original: arm9/main @ 0x0208936C; symbol: func_0208936c; size: 0x128.
extern "C" void InitializeRecordFromTwoSourcesAndPackedFlags(unsigned char* p,unsigned char* source,unsigned char* data){
 Object_InitializePackedCountersWeightsAndTimers();*(unsigned short*)p=*(unsigned short*)(source+4);*(unsigned short*)(p+2)=*(unsigned short*)(source+6);*(unsigned short*)(p+4)=*(unsigned short*)(data+48);*(unsigned short*)(p+6)=*(unsigned short*)(data+50);CopyBytesAndTwoScalarFields(p+62,source+9);
 p[36]=source[8];unsigned mask=*(unsigned*)source;*(unsigned*)(p+20)=mask;if(mask&2)((Mode*)(p+34))->mode=1;
 unsigned char byte=p[36];if(byte){*(unsigned*)(p+20)|=0x800000;p[36]=byte;}
 *(unsigned short*)(p+12)=*(unsigned short*)(data+56);*(unsigned short*)(p+8)=*(unsigned short*)(data+52);*(unsigned short*)(p+10)=*(unsigned short*)(data+54);
 Bits* to=(Bits*)(p+16);Bits* from=(Bits*)(data+60);to->x=(unsigned short)from->x;to->y=(unsigned short)from->y;to->z=(unsigned short)from->z;p[38]=1;
}
