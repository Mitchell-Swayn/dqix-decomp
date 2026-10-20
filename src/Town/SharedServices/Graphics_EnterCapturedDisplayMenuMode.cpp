#include <globaldefs.h>
ARM
#define W(p,o) (*(int*)((p)+(o)))
#define P(p,o) (*(unsigned char**)((p)+(o)))
#define H(p,o) (*(short*)((p)+(o)))
#define U(p,o) (*(unsigned short*)((p)+(o)))
extern "C" {void* GameResources_GetInstance();void GameState_CopyElapsedTimeIntoTwoConfigurationRecords(int);void Graphics_CacheFourMainBackgroundControlsOnce(void*);void GameResources_SetPrimaryFlags(unsigned*,unsigned);void GameResources_SetSecondaryFlags(int,unsigned);void G3X_SetClearColor(unsigned,unsigned,unsigned short,unsigned,int);unsigned char* NavigationMessage_GetGlobalInstance();void BackgroundLoader_CancelTaskAndSetCleanupModeFlags(char*);void NavigationMessage_ResetAndEnable(void*);void* SystemState_GetGlobalFlags();void SystemState_SetFlags(unsigned*,unsigned);}
#define REG(a) (*(volatile unsigned*)(a))
#define HW(a) (*(volatile unsigned short*)(a))
// Original: arm9/ov003 @0x021728fc; symbol:Graphics_EnterCapturedDisplayMenuMode; size:0x118.
// Caches backgrounds and configures capture, priorities, display manager and global flag for menu entry.
extern "C" void Graphics_EnterCapturedDisplayMenuMode(unsigned char* self){void* resources=GameResources_GetInstance();if(self[0xee])return;GameState_CopyElapsedTimeIntoTwoConfigurationRecords(0);Graphics_CacheFourMainBackgroundControlsOnce(self+0xfa);W(self,0x120)=(REG(0x4000000)&0x1f00)>>8;REG(0x4000000)=(REG(0x4000000)&~0x1f00)|0x1300;HW(0x4000008)&=~3;HW(0x400000a)=(HW(0x400000a)&~3)|1;HW(0x400000c)=(HW(0x400000c)&~3)|2;HW(0x400000e)=(HW(0x400000e)&~3)|3;HW(0x400000a)=(HW(0x400000a)&0x43)|0xf00;GameResources_SetPrimaryFlags((unsigned*)resources,4);GameResources_SetSecondaryFlags((int)resources,0x8de);G3X_SetClearColor(0,0,0x7fff,0,0);unsigned char* manager=NavigationMessage_GetGlobalInstance();BackgroundLoader_CancelTaskAndSetCleanupModeFlags((char*)manager);manager[0x3c9]=(manager[0x3c9]&~1)|1;NavigationMessage_ResetAndEnable(manager);SystemState_SetFlags((unsigned*)SystemState_GetGlobalFlags(),0x1000);self[0xec]=1;self[0xee]=0;}
