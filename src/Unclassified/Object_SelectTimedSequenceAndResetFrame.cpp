#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" {
struct A{char pad[0x84];unsigned char enabled:1;};extern unsigned int data_02114e50;
// Original: arm9/main @ 0x020478BC; symbol: func_020478bc; size: 0x70.
void Object_SelectTimedSequenceAndResetFrame(A *a,int id){char *p=(char *)a;if(!a->enabled)return;if(*(int *)(p+0x14)<=0)return;if(*(int *)(p+0x74)==id||id==0)return;*(int *)(p+0x70)=0;*(int *)(p+0x74)=id;*(int *)(p+0x78)=data_02114e50;char *data=*(char **)(p+12);char *entry=*(char **)(data+*(int *)(p+0x74)*8+4);*(int *)(p+0x7c)=*(int *)(entry+*(int *)(p+0x70)*12+4);}
}
