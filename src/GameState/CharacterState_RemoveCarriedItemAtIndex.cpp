#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x0208386C; symbol: func_0208386c; size: 0x58.
extern "C" void CharacterState_RemoveCarriedItemAtIndex(unsigned char* p,int index){if(index<0)return;if(index>=8)return;*(short*)(p+index*2+0x454)=-1;while(index<7){int next=index+1;short v=*(short*)(p+next*2+0x454);*(short*)(p+index*2+0x454)=v;index=next;*(short*)(p+next*2+0x454)=-1;}}
