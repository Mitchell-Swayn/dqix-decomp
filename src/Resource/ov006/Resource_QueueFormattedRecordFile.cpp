#include <globaldefs.h>
ARM
extern "C" {
int sprintf(char*,const char*,...);
extern char data_ov006_02160360[];
void* _ZN16BackgroundLoader11GetInstanceEv();
unsigned _ZN16BackgroundLoader13QueueLoadFileEPKcP13SafeAllocator(void*,const char*,void*);
void* ReadGlobalAt02105AB4();
unsigned char* ReadGlobalValueAt021056B4();
void InitializeWordRecordWithFixedPointScaleDefaults(unsigned*);
unsigned ReadPreferredHalfwordOrAlternateWith999Sentinel(void*,int);
}
struct Fields { unsigned low:20; unsigned file:8; unsigned high:4; };
// Original: arm9/ov006 @ 0x0215FE34; symbol: func_ov006_0215fe34; size: 0x98.
extern "C" void Resource_QueueFormattedRecordFile(unsigned char* object,unsigned char* source) {
 char path[64];
 if(source) {
  void* loader=_ZN16BackgroundLoader11GetInstanceEv();
  InitializeWordRecordWithFixedPointScaleDefaults((unsigned*)(object+0x3b8));
  *(int*)(object+0x3f4)=5;
  object[0x416]=1;
  ReadGlobalAt02105AB4();
  *(void**)(object+0x3cc)=ReadGlobalValueAt021056B4()+0x1b8;
  *(int*)(object+0x3f0)=0x10000;
  *(int*)(object+0x3f8)=0;
  unsigned index=ReadPreferredHalfwordOrAlternateWith999Sentinel(source,0);
  sprintf(path,data_ov006_02160360,((Fields*)(source+16))->file,index);
  *(unsigned*)(object+0x428)=_ZN16BackgroundLoader13QueueLoadFileEPKcP13SafeAllocator(loader,path,0);
 }
}
