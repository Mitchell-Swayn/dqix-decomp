#include <globaldefs.h>
ARM
// Original: arm9/itcm @ 0x01FF83A8; symbol: func_01ff83a8; size: 0xD8.
// Reads cartridge blocks, consuming every ready FIFO word and storing the requested range.
extern "C" void ReadCartridgeRomRange(unsigned address, void* destination, int size) {
 unsigned setup=(*(volatile unsigned*)0x027FFE60 & ~0x07000000u)|0xA1000000u;
 int cursor=-(int)(address & 0x1ff);
 while (*(volatile unsigned*)0x040001A4 & 0x80000000u) {}
 volatile unsigned char* command=(volatile unsigned char*)0x040001A1;
 command[0]=0x80;
 address+=cursor;
 if(cursor>=size)return;
 unsigned state;
 unsigned middle=address>>8;
 do {
 command[7]=0xb7;
 command[8]=address>>24;
 command[9]=address>>16;
 command[10]=middle;
 command[11]=address;
 command[12]=0;command[13]=0;command[14]=0;
 *(volatile unsigned*)(command+3)=setup;
 do {
 state=*(volatile unsigned*)(command+3);
 if(state & 0x800000) {
 unsigned value=*(volatile unsigned*)0x04100010;
 if(cursor>=0 && cursor<size) *(unsigned*)((char*)destination+cursor)=value;
 cursor+=4;
 }
 if(!(state & 0x80000000u))break;
 }while(1);
 middle+=2; address+=512;
 }while(cursor<size);
}
