#include <globaldefs.h>
ARM
struct Descriptor { unsigned header;unsigned code:12;unsigned rest:20; };
extern "C" void __clear(void*,unsigned);
extern "C" unsigned ReadWordFieldAtOffset1C();
extern "C" void FormatOutputThroughContextTables(int,char*);
extern "C" void ProcessSixStagesUsingSharedWordScratchBuffer(void*,int,void*,void*,int,int,unsigned);
// Original: arm9/ov002 @ 0x0215EEC0; symbol: func_ov002_0215eec0; size: 0xA0.
extern "C" void Graphics_FormatSelectedDescriptorOutput(char* self,void* context) {
if(context) {
*(short*)(self+0x1c26)=-1;
int index=*(short*)(self+0x1bfa);
if(index>=0 && index<32) *(short*)(self+0x1c26)=(*(Descriptor**)(self+index*4+0x24a0))->code;
char buffer[256];
__clear(buffer,256);
FormatOutputThroughContextTables(*(short*)(self+0x1c26),buffer);
unsigned p=ReadWordFieldAtOffset1C();
ProcessSixStagesUsingSharedWordScratchBuffer((void*)p,12,buffer,context,0x74,0,0);
}
}
