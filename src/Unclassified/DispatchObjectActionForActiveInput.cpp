#include <globaldefs.h>
extern "C" void* GetGlobalStatePointer(); extern "C" int TestWordMaskNonzero(void*,unsigned); extern "C" char* ReadWordFieldAtOffset1C(); extern "C" void func_02096c38(void*,unsigned char,unsigned char,unsigned char,unsigned char); extern "C" unsigned char data_02114e54[];
// Original: arm9/main @ 0x02096824; symbol: func_02096824; size: 0x80.
extern "C" ARM void DispatchObjectActionForActiveInput(unsigned char* object) { if(TestWordMaskNonzero(GetGlobalStatePointer(),0x4000)) return; if(!data_02114e54[0x5f] || !*(unsigned short*)(data_02114e54+0x24)) return; char* state=ReadWordFieldAtOffset1C(); if(state && *(void**)(state+0x998)) return; if(object[0x225]) func_02096c38(object,object[0x220],object[0x221],object[0x222],object[0x223]); }
