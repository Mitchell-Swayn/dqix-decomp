// Original data alias: arm9/main @ 0x2111640; symbol: data_02111640.
// 64-bit Timer64Bit.numTimerOverflows member at OS_TimerState + 8. Initially zero; updated at runtime.
// Initial values (hex for initialized storage): zero-filled at load; mutable at runtime.
#include <globaldefs.h>
ARM
extern unsigned short GetMain16BitTimerCounter();
extern "C" volatile unsigned long long OS_TimerOverflowCount;
#define TICK OS_TimerOverflowCount
struct Work {char a[0x3c]; unsigned long vblank; char b[0xb4]; unsigned long mac; unsigned short mac4; char c[0xee]; unsigned long rtc[2]; char d[0x1a0];unsigned long micaddr; unsigned short mic;char e[2];unsigned short rssi;char f[0xe];volatile unsigned short xy;unsigned short touch[2];};
// Community SDK C reference: pret/pokeheartgold @ 14c48938174ec92563afc6d03de5fa162f4cfdce,
// lib/NitroSDK/src/os/os_entropy.c. Reconstructed with local ABI names and layouts.
// Tick counter is at 0x02111640 (existing owning BSS symbol data_02111638 + 8).
// Proposed SDK name: OS_GetLowEntropyData; old function ABI retained for comparison.
// Original: arm9/main @ 0x020C9B10; symbol: func_020c9b10; size: 0xD0.
extern "C" void OS_GetLowEntropyData(unsigned long* data) {
const Work* work=(const Work*)0x027ffc00;
const unsigned char* macAddress=(const unsigned char*)work+0xf4;
unsigned long vcount=*(volatile unsigned short*)0x04000006;
data[0]=GetMain16BitTimerCounter() | (vcount<<16);
data[1]=(*(unsigned short*)(macAddress+4)<<16) ^ (unsigned long)TICK;
data[2]=(unsigned long)(TICK>>32) ^ *(unsigned long*)macAddress ^ work->vblank;
data[2]^=*(volatile unsigned long*)0x04000600;
data[3]=work->rtc[0];data[4]=work->rtc[1];
data[5]=(work->mic<<16) ^ work->micaddr;
data[6]=(work->touch[0]<<16) | work->touch[1];
data[7]=(work->rssi<<16) | (*(volatile unsigned short*)0x04000130 | *(volatile unsigned short*)0x027fffa8);
}
