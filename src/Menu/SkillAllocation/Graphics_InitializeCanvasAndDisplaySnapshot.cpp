#include <globaldefs.h>
ARM
struct State;
extern "C" {void Graphics_InitializeCanvasTransferState(char*);void MessageTextTable_Reset(char*);void Graphics_CacheFourMainBackgroundControlsOnce(volatile State*);void Graphics_SnapshotSubBackgroundControlRegistersOnce(State*);void InitializeLinkedListHeadAndCount(void*);}
// Original: arm9/ov013 @ 0x02186EEC; symbol: func_ov013_02186eec; size: 0xB4.
extern "C" void Graphics_InitializeCanvasAndDisplaySnapshot(unsigned char* p,unsigned char screen){
*(unsigned*)p=0;InitializeLinkedListHeadAndCount(p+12);MessageTextTable_Reset((char*)p+4);
p[0x24]=0;p[0x25]=0;Graphics_InitializeCanvasTransferState((char*)p+0x28);
*(int*)(p+0x5c)=-1;p[0x64]=screen;p[0x65]=0;p[0x66]=0;*(signed char*)(p+0x67)=-1;p[0x68]=0;p[0x69]=0;
*(unsigned*)(p+0x48)=0;*(unsigned*)(p+0x4c)=0;*(unsigned*)(p+0x50)=0;*(unsigned*)(p+0x54)=0;*(unsigned*)(p+0x58)=0;
*(signed char*)(p+0x6a)=-1;
unsigned control;
if(p[0x64]==0){Graphics_CacheFourMainBackgroundControlsOnce((State*)(p+0x14));control=*(volatile unsigned*)0x04000000;}
else {Graphics_SnapshotSubBackgroundControlRegistersOnce((State*)(p+0x14));control=*(volatile unsigned*)0x04001000;}
*(unsigned*)(p+0x60)=(control&0x1f00)>>8;
}
