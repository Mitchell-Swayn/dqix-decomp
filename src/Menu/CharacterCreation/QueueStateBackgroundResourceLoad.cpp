#include <globaldefs.h>
ARM
extern "C" {
void* _ZN16BackgroundLoader11GetInstanceEv();
void* ResourceStringTable_GetTextByKey(void*,void*);
unsigned _ZN16BackgroundLoader18QueueLoadFileInGP2EPKcS1_P13SafeAllocator(void*,const char*,const char*,void*);
unsigned _ZN16BackgroundLoader13GetTaskStatusEi(void*,unsigned);
}
// Original: arm9/ov009 @ 0x02184D70; symbol: func_ov009_02184d70; size: 0xE8.
// Queues the current state's indexed GP2 resource and advances its load-status byte.
extern "C" void QueueStateBackgroundResourceLoad(unsigned char* p) {
 if(!(*(unsigned*)(p+0xd9c)&0x80) || p[0xd94]==2)return;
 void* loader=_ZN16BackgroundLoader11GetInstanceEv();
 int mode=*(signed char*)(p+0xc58);
 if(p[0xd94]==0) {
  short index=mode;
  if((mode==3) | ((mode==2) | (mode==5)))index=(short)(index+100*p[0xda3]);
  const char* second=(const char*)ResourceStringTable_GetTextByKey(p+0xe0,(void*)(short)(index+50));
  const char* first=(const char*)ResourceStringTable_GetTextByKey(p+0xe0,(void*)index);
  *(unsigned*)(p+0xd90)=_ZN16BackgroundLoader18QueueLoadFileInGP2EPKcS1_P13SafeAllocator(loader,first,second,0);
  p[0xd94]=1;
 }else if(p[0xd94]==1) {
  if(_ZN16BackgroundLoader13GetTaskStatusEi(loader,*(unsigned*)(p+0xd90)))p[0xd94]=2;
 }
}
