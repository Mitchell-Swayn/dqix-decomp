#include <globaldefs.h>
#include <World/ZonePredicates.h>
extern "C" unsigned short* ReadGlobalValueAt020FB3F0();extern "C" void Object_ConfigureAndSubmitIndexedRecord(void*,int,int,int,int,int,int,int,int,int);
// Original: arm9/main @ 0x0202427C; symbol: func_0202427c; size: 0x13C.
extern "C" void DrawAlignedWidthMarkersForNonGrottoZone(unsigned char* p){unsigned zone=*ReadGlobalValueAt020FB3F0();if(p[1448]&&!IsGrottoZone(zone)){if(zone!=10000&&zone!=10100){int x=256;int width=(*(int*)(p+3044)+7)&~7;if(width>144)width=144;*(short*)(p+1232)=(unsigned short)width>>3;x-=8;Object_ConfigureAndSubmitIndexedRecord(p,x<<12,0,26,83,0,8,255,4096,4096);x-=width;Object_ConfigureAndSubmitIndexedRecord(p,x<<12,0,25,65,0,8,255,4096,4096);Object_ConfigureAndSubmitIndexedRecord(p,(x-8)<<12,0,24,64,0,8,255,4096,4096);}}}
