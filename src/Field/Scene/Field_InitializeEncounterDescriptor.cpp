#include <globaldefs.h>
ARM
// Original: arm9/ov017 @ 0x02196C08; symbol Descriptor_InitializeFields; size 0x44.
extern "C" void Field_InitializeEncounterDescriptor(void* p){unsigned char* b=(unsigned char*)p;b[0]=1;b[1]=0;*(unsigned short*)(b+2)=0;*(unsigned short*)(b+4)=0;*(int*)(b+8)=-1;b[12]=0;b[13]=0;b[14]=0;*(short*)(b+16)=-1;b[15]=0;*(int*)(b+20)=0;b[18]=2;}
