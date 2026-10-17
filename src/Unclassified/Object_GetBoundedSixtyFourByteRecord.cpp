#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" {
struct A{unsigned int count:12;unsigned int rest:20;char *data;};
// Original: arm9/main @ 0x020A939C; symbol: func_020a939c; size: 0x34.
char *Object_GetBoundedSixtyFourByteRecord(A *p,int i){if(i<0||i>=(int)p->count||p->data==0)return 0;return p->data+i*64;}
}
