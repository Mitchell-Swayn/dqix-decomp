#include <globaldefs.h>
ARM
#pragma optimize_for_size off
extern "C" void* Object_GetGlobalConnectionState();extern "C" int IsFirstWordNonzero(void*);extern "C" void Object_ConfigureAndSubmitIndexedRecord(void*,int,int,int,int,int,int,int,int,int);
// Original: arm9/main @ 0x0202720C; symbol: func_0202720c; size: 0x7C.
extern "C" void Graphics_DrawMarkerWithConditionalSelector(void* p){int selector=5;*(volatile unsigned*)0x04001000=(*(volatile unsigned*)0x04001000&~0x1f00)|0x1300;if(IsFirstWordNonzero(Object_GetGlobalConnectionState()))selector+=16;Object_ConfigureAndSubmitIndexedRecord(p,selector<<12,0x5000,0x17,0x40,1,0xff,0xff,0x1000,0x1000);}
