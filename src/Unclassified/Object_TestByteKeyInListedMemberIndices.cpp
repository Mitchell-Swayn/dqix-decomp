#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x02086EF0; symbol: func_02086ef0; size: 0x34.
extern "C" int Object_TestByteKeyInListedMemberIndices(unsigned char* p,unsigned int value) { for(int i=0;i<p[0xf7c];++i) { unsigned char* entry=p+i;if(value==entry[0xf78])return 1; }return 0; }
