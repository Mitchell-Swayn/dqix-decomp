#include <globaldefs.h>
ARM
struct Flags {unsigned char enabled:1,visible:1,rest:6;};
extern "C" void Graphics_ApplyNonzeroZRotation(int),BuildAndDispatchYRotationMatrixWhenAngleNonzero(int),Graphics_SubmitNonzeroXRotation(int);extern "C" void func_02047448(char*,int,int);
// Original: arm9/main @ 0x020472E4; symbol: func_020472e4; size: 0xE4.
extern "C" void Graphics_DrawEnabledVisibleFrameGeometry(char* p,int value){
 volatile unsigned* reg=(volatile unsigned*)0x04000444;if(!((Flags*)(p+0x84))->enabled)return;if(!((Flags*)(p+0x84))->visible)return;if(*(short*)(p+0x82)<=0)return;
 int frame=*(int*)(p+0x70);char* data=*(char**)(*(char**)(p+12)+*(int*)(p+0x74)*8+4)+frame*12;*reg=0;
 unsigned c=*(unsigned*)(p+0x24),b=*(unsigned*)(p+0x20),a=*(unsigned*)(p+0x1c);reg[11]=a;reg[11]=b;reg[11]=c;
 c=*(unsigned*)(p+0x3c);b=*(unsigned*)(p+0x38);a=*(unsigned*)(p+0x34);reg[10]=a;reg[10]=b;reg[10]=c;
 if(*(int*)(p+0x30))Graphics_ApplyNonzeroZRotation(*(int*)(p+0x30));if(*(int*)(p+0x2c))BuildAndDispatchYRotationMatrixWhenAngleNonzero(*(int*)(p+0x2c));if(*(int*)(p+0x28))Graphics_SubmitNonzeroXRotation(*(int*)(p+0x28));
 func_02047448(p,*(int*)(data+8),value);*(volatile unsigned*)0x04000448=1;
}
