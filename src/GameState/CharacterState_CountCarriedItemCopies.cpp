#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x02083994; symbol: func_02083994; size: 0x48.
extern "C" int CharacterState_CountCarriedItemCopies(unsigned char* p,int key) { if(key<0)return 0;int count=0;for(int i=0;i<8;i++) { unsigned char* entry=p+i*2;int value=*(short*)(entry+0x454);if(value<0)break;if(value==key)++count; }return count; }
