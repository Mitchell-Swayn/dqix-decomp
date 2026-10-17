#include <globaldefs.h>
extern "C" void* ReadWordAtOffset0(void*); extern "C" unsigned ReadScriptParameterAsInteger(void*); extern "C" void Object_SetUnsignedIntAtOffset84AndSetUnsignedIntAtOffset88AndSetUnsignedIntAtOffset6C(void*,unsigned,unsigned,unsigned);
// Original: arm9/main @ 0x0209DAA4; symbol: func_0209daa4; size: 0x54.
extern "C" int Script_SetGlobalRecordWords84And88And6C(char* input) { void* state=ReadWordAtOffset0(input); if(!state)return 0; unsigned a=ReadScriptParameterAsInteger(input); unsigned b=ReadScriptParameterAsInteger(input+8); unsigned c=ReadScriptParameterAsInteger(input+16); Object_SetUnsignedIntAtOffset84AndSetUnsignedIntAtOffset88AndSetUnsignedIntAtOffset6C(state,a,b,c); return 1; }
