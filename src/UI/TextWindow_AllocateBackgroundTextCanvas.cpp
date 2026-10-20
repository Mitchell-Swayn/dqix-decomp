#include <globaldefs.h>
ARM
extern "C" void TextCanvas_InitializeLayoutAndTransferDefaults(void*);extern "C" void* _Z25AllocateVRAMStagingMemoryj(unsigned);extern "C" void* memset(void*,int,unsigned);
// Original: arm9/main @ 0x02044C74; symbol: func_02044c74; size: 0x98.
extern "C" void TextWindow_AllocateBackgroundTextCanvas(unsigned char* self,unsigned char* p){TextCanvas_InitializeLayoutAndTransferDefaults(p);void* buffer=_Z25AllocateVRAMStagingMemoryj(0x4800);if(!buffer)return;if(self[6605]){self[6605]=0;memset(buffer,0,0x4800);}*(short*)(p+172)=0;*(short*)(p+174)=6;*(short*)(p+168)=32;*(short*)(p+170)=18;*(void**)(p+8)=buffer;*(unsigned*)(p+164)=0x4800;*(unsigned*)(p+160)=0;*(short*)(p+194)=0;*(short*)(p+176)=0;*(short*)(p+178)=0;*(short*)(p+180)=8;*(short*)(p+182)=8;*(short*)(p+184)=8;*(short*)(p+186)=8;}
