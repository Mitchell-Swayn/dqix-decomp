#include <globaldefs.h>
extern "C" void Graphics_CacheFourMainBackgroundControlsOnce(volatile void*);
extern "C" void SnapshotSubBackgroundControlRegistersOnce(void*);
extern "C" void ClearRecordAndInvalidateTwoIndices(char*);
extern "C" void Graphics_InitializeCanvasTransferState(char*);
extern "C" void TextCanvas_InitializeLayoutAndTransferDefaults(unsigned char*);
extern "C" void InitializeRecordGridAndFlagDefaults(void*);
// Original: arm9/ov023 @ 0x021EB138; symbol: func_ov023_021eb138; size: 0x134.
extern "C" ARM void TextCanvas_InitializeState(void* p, unsigned char mode) {
 char* s=(char*)p;
 s[0x430]=mode; s[0x3a]=0; s[0x3b]=0;
 Graphics_CacheFourMainBackgroundControlsOnce(s+0x2a);
 SnapshotSubBackgroundControlRegistersOnce(s+0x2a);
 *(unsigned*)(s+0x3c)=(*(volatile unsigned*)0x04000000 & 0x1f00)>>8;
 *(unsigned*)(s+0x40)=(*(volatile unsigned*)0x04001000 & 0x1f00)>>8;
 *(unsigned*)s=0;
 ClearRecordAndInvalidateTwoIndices(s+4);
 for(int i=0;i<2;i++) Graphics_InitializeCanvasTransferState(s+0x44+i*0x20);
 for(int i=0;i<2;i++) Graphics_InitializeCanvasTransferState(s+0x84+i*0x20);
 for(int i=0;i<3;i++) TextCanvas_InitializeLayoutAndTransferDefaults((unsigned char*)(s+0x180+i*0xe0));
 InitializeRecordGridAndFlagDefaults(s+0xc4);
 *(unsigned*)(s+0x420)=0; *(unsigned*)(s+0x424)=0; *(unsigned*)(s+0x428)=0; *(unsigned*)(s+0x42c)=0;
 *(unsigned*)(s+0x20)=0; *(unsigned*)(s+0x24)=0;
 s[0x28]=0; s[0x431]=0; s[0x432]=0; s[0x433]=0;
 *(unsigned*)(s+0x434)=0xffffffff;
 *(unsigned short*)(s+0x438)=0; *(unsigned short*)(s+0x43a)=0;
 s[0x43c]=0; s[0x43d]=0;
 *(unsigned short*)(s+0x43e)=0; *(unsigned short*)(s+0x440)=0; *(unsigned short*)(s+0x442)=0; *(unsigned short*)(s+0x444)=0; *(unsigned short*)(s+0x446)=0; *(unsigned short*)(s+0x448)=0;
 s[0x44a]=0;
}
