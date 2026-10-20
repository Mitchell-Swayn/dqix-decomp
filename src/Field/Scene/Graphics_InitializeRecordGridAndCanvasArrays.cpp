#include <globaldefs.h>
ARM
struct State;
extern "C" void Graphics_InitializeCanvasTransferState(char*);
extern "C" void TextCanvas_InitializeLayoutAndTransferDefaults(unsigned char*);
extern "C" void Selection_InitializeDisplayController(State*);
// Original: arm9/ov017 @ 0x021996FC; symbol: func_ov017_021996fc; size: 0x84.
extern "C" void Graphics_InitializeRecordGridAndCanvasArrays(unsigned char* p){
 Selection_InitializeDisplayController(*(State**)(p+0x3cb0));
 for(int i=0;i<2;i++)Graphics_InitializeCanvasTransferState((char*)(p+0x3cb4+i*32));
 for(int i=0;i<4;i++)TextCanvas_InitializeLayoutAndTransferDefaults(p+0x3cf4+i*224);
 *(int*)(p+0x4074)=0;
 *(int*)(p+0x4078)=0;
 *(int*)(p+0x407c)=-1;
 *(int*)(p+0x4080)=0;
 *(int*)(p+0x4084)=0;
}
