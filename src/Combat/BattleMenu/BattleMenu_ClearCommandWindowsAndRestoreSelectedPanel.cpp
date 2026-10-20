#include <globaldefs.h>
ARM
extern "C" {void Window_ClearResourceBuffers(void*);void Graphics_ResetCountedThirtyTwoByteTransfers(void*);void Window_ResetResourceTransfers(void*);void Window_PopCanvasesAndResetSelection(void*,int);void BattleMenu_UpdateMemberRowPositions(void*);}
// Original: arm9/ov000 @ 0x0218048C; symbol: ResetEntryResourcesAndMarkFourSelectedRecords; size: 0x9c.
// Resets indexed resources, marks eligible selected records and resets selection words.
extern "C" void BattleMenu_ClearCommandWindowsAndRestoreSelectedPanel(char* self){Window_ClearResourceBuffers(self+0x188);Graphics_ResetCountedThirtyTwoByteTransfers(self+0x188);Window_ResetResourceTransfers(self+0x188);Window_PopCanvasesAndResetSelection(self+0x188,1);char* base=self+0x958;for(int i=0;i<4;++i){char* p=self+0x958+0x448**(signed char*)((self+i)+0x6c);if((unsigned char)p[0x24]&2){*(unsigned char*)(p+0x24)|=4;*(int*)(self+0x17c)=*(int*)(p+0x4c);}}*(unsigned short*)(self+0x1d72)&=~8;*(int*)(self+0x914)=0;*(int*)(self+0x910)=0;BattleMenu_UpdateMemberRowPositions(self);}
