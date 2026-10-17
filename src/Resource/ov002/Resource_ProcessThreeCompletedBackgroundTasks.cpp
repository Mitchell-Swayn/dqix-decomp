#include <globaldefs.h>
ARM
extern "C" void* _ZN16BackgroundLoader11GetInstanceEv();
extern "C" unsigned _ZN16BackgroundLoader13GetTaskStatusEi(void*,unsigned);
extern "C" void _ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(void*,int,void**,unsigned*);
extern "C" void _ZN16BackgroundLoader10RemoveTaskEi(void*,int);
extern "C" void _ZN13SafeAllocator5ResetEv(void*);
extern "C" void Initialize2RecordFields_Main0209A338(void*);
extern "C" void Script_Allocate3444ByteBufferAndExecuteCode(void*,void*,void*,unsigned);
extern "C" void Initialize1RecordFields_Main0209A804(void*);
extern "C" void AllocateZeroed550ByteScriptState(void*,void*,void*,unsigned);
extern "C" void _ZN13ZoneState27545ResetEv(void*);
extern "C" void _ZN13ZoneState275421BuildAlternateForKeysEP13SafeAllocatorPvjPKss(void*,void*,void*,unsigned,const short*,short);
extern "C" short data_ov002_0216c96e[];
// Original: arm9/ov002 @ 0x02156C7C; symbol: func_ov002_02156c7c; size: 0x214.
extern "C" void Resource_ProcessThreeCompletedBackgroundTasks(char* self) {
 if(!(*(unsigned*)(self+0x247c)&0x10)) return;
 void* loader=_ZN16BackgroundLoader11GetInstanceEv();
 unsigned char ready=0;
 for(unsigned char i=0;i<3;i++) if(_ZN16BackgroundLoader13GetTaskStatusEi(loader,*(int*)(self+4*i+0x1ba4))) ready++;
 if(ready!=3) return;
 void* file1;unsigned size1;void* file2;unsigned size2;void* file3;unsigned size3;
 {
 int* slot=(int*)(self+0x1ba4);
 if(_ZN16BackgroundLoader13GetTaskStatusEi(loader,*slot)) {
 _ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(loader,*slot,&file1,&size1);
 _ZN13SafeAllocator5ResetEv(self+0x810);
 _ZN13ZoneState27545ResetEv(self+0x7ec);
 _ZN13ZoneState275421BuildAlternateForKeysEP13SafeAllocatorPvjPKss(self+0x7ec,self+0x810,file1,size1,data_ov002_0216c96e,2);
 _ZN16BackgroundLoader10RemoveTaskEi(loader,*slot);*slot=-1;
 }
 }
 {
 int* slot=(int*)(self+0x1ba8);
 if(_ZN16BackgroundLoader13GetTaskStatusEi(loader,*slot)) {
 _ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(loader,*slot,&file2,&size2);
 Initialize1RecordFields_Main0209A804(self+0x2444);
 if(file2 && size2) AllocateZeroed550ByteScriptState(self+0x2444,self+0x88c,file2,size2);
 _ZN16BackgroundLoader10RemoveTaskEi(loader,*slot);*slot=-1;
 }
 }
 {
 int* slot=(int*)(self+0x1bac);
 if(_ZN16BackgroundLoader13GetTaskStatusEi(loader,*slot)) {
 if(!*(unsigned char*)(self+0x2485)) {
 _ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(loader,*slot,&file3,&size3);
 _ZN13SafeAllocator5ResetEv(self+0x850);
 Initialize2RecordFields_Main0209A338(self+0x243c);
 if(file3 && size3) Script_Allocate3444ByteBufferAndExecuteCode(self+0x243c,self+0x850,file3,size3);
 }
 _ZN16BackgroundLoader10RemoveTaskEi(loader,*slot);*slot=-1;
 }
 }
 *(unsigned*)(self+0x247c)|=0x20;
}
