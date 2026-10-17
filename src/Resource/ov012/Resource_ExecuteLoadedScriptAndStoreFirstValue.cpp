#include <globaldefs.h>
ARM
extern "C" {
void* _ZN16BackgroundLoader11GetInstanceEv();
void _ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(void*,int,void**,unsigned*);
void _ZN16BackgroundLoader10RemoveTaskEi(void*,int);
void _ZN13SafeAllocator5ResetEv(void*);
void Script_ExecuteCodeWithGlobalContextValues(void*,void*,const void*,unsigned,void*,unsigned short,unsigned char);
unsigned FindRecordValueByKeyOrZero(void*,int);
}
// Original: arm9/ov012 @ 0x02185E18; symbol: func_ov012_02185e18; size: 0x90.
extern "C" void Resource_ExecuteLoadedScriptAndStoreFirstValue(unsigned char* p) {
 void* loader=_ZN16BackgroundLoader11GetInstanceEv();
 void* code;
 unsigned size;
 _ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(loader,*(int*)(p+0x1380),&code,&size);
 _ZN13SafeAllocator5ResetEv(p+0x34);
 Script_ExecuteCodeWithGlobalContextValues(p+0x133c,p+0x34,code,size,0,0,0);
 *(unsigned*)(p+0x1378)=FindRecordValueByKeyOrZero(p+0x133c,0);
 _ZN16BackgroundLoader10RemoveTaskEi(loader,*(int*)(p+0x1380));
 *(int*)(p+0x1380)=-1;
}
