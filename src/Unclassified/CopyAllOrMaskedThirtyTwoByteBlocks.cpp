#include <std_library_functions.h>
typedef void (*Copy)(void*,int,unsigned int);
#pragma always_inline on
static inline void Reconstruct_func_0204abcc(const unsigned short *header,Copy copy,unsigned char *source) { unsigned int size; memcpy(&size,source+8,4); if(header[1]==65535)copy(source+12,0,size);else{int i;int bits=header[1]&255;for(i=0;i<16;i++){if(bits&1)copy(source+12+i*32,i*32,32);bits=(unsigned char)(bits>>1);}} }
// Original: arm9/main @ 0x0204ABCC; symbol: func_0204abcc; size: 0x94.
extern "C" void CopyAllOrMaskedThirtyTwoByteBlocks(const unsigned short *header,Copy copy,unsigned char *source) { Reconstruct_func_0204abcc(header, copy, source); }
