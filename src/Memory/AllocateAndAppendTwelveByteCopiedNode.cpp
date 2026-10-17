#include <globaldefs.h>
#include <std_library_functions.h>
#include <Memory/SafeAllocator.h>
extern "C" {
extern SafeAllocator *data_0214e33c[];
// Original: arm9/main @ 0x020D78E0; symbol: func_020d78e0; size: 0x6C.
void AllocateAndAppendTwelveByteCopiedNode(char **p,void *record){while(*p)p=(char **)(*p+8);char *q=(char *)data_0214e33c[2]->Allocate(12);*p=q;if(!q)return;*(short *)q=-1;*(short *)(q+2)=-1;*(int *)(q+4)=0;*(int *)(q+8)=0;memcpy(*p,record,8);}
}
