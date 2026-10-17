#include <globaldefs.h>
ARM
extern "C" void* _ZN16BackgroundLoader11GetInstanceEv();
extern "C" void _ZN16BackgroundLoader10RemoveTaskEi(void*, int);
// Original: arm9/ov013 @ 0x0218782C; symbol: func_ov013_0218782c; size: 0x84.
extern "C" void Resource_SetLoadSelection(char* p, int a, unsigned int b) {
if(p[0x67]==a && *(unsigned char*)(p+0x68)==b) return;
bool valid;
if(a>=0 && a<=3) valid=true; else valid=false;
if(!valid) return;
if(b>=5) return;
p[0x67]=a; p[0x68]=b;
if(*(int*)(p+0x5c)>=0) {
void* loader = _ZN16BackgroundLoader11GetInstanceEv();
_ZN16BackgroundLoader10RemoveTaskEi(loader,*(int*)(p+0x5c));
*(int*)(p+0x5c)=-1;
}
*(unsigned char*)(p+0x69)|=1;
p[0x66]=0;
}
