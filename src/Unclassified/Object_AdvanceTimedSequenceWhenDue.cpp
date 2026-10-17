#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" {
struct A{char pad[0x84];unsigned char on:1;unsigned char active:1;};extern unsigned char data_02114e00;extern unsigned int data_02114e50;
// Original: arm9/main @ 0x0204724C; symbol: func_0204724c; size: 0x98.
void Object_AdvanceTimedSequenceWhenDue(A *a){char *p=(char *)a;if(!a->on)return;if(!a->active)return;if(data_02114e00){*(unsigned int *)(p+0x78)=data_02114e50;return;}if(*(unsigned int *)(p+0x7c)>=data_02114e50-*(unsigned int *)(p+0x78))return;unsigned int index=*(unsigned int *)(p+0x70)*12;char *list=*(char **)(p+12);char *entry=*(char **)(list+*(int *)(p+0x74)*8+4)+index;*(unsigned int *)(p+0x70)=*(unsigned int *)entry;*(unsigned int *)(p+0x78)=data_02114e50;*(unsigned int *)(p+0x7c)=*(unsigned int *)(entry+4);}
}
