#include <globaldefs.h>
struct Object { int index; }; typedef void (Object::*Method)(); struct Methods { Method entries[3]; }; extern "C" Methods data_020e8f08;
// Original: arm9/main @ 0x020A0DEC; symbol: func_020a0dec; size: 0x5C.
 extern "C" void Object_InvokeIndexedMemberMethod(Object* p) { Methods methods=data_020e8f08; (p->*methods.entries[p->index])(); }
