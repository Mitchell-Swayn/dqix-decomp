#include <globaldefs.h>
ARM
extern "C" void* GameState_GetObjectWithFlag100(void*, int);
extern "C" unsigned char *GameObject_GetLinkedIndexedState(void *);
// Original: arm9/ov017 @ 0x021CCAF8; symbol: func_ov017_021ccaf8; size: 0x60.
// Copies six halfwords to the selected object's state at a byte-indexed position.
extern "C" void CopySixHalfwordsToObjectState(void *, unsigned char *record, void *state) {
 unsigned char *p=record+4;
 void *object=GameState_GetObjectWithFlag100(state,*(unsigned short *)(p+12));
 if(!object)return;
 unsigned char *dst=GameObject_GetLinkedIndexedState(object);
 if(!dst)return;
 unsigned int base=p[14];
 for(unsigned char i=0;i<6;i++) *(unsigned short *)(dst+0x16c+2*(i+base))=*(unsigned short *)(p+2*i);
}
