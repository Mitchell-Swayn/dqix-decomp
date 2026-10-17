#include <globaldefs.h>
ARM
extern "C" void* ReadGlobalAt02105AB4();extern "C" void ReadGlobalValueAt021056B4(void*);extern "C" void ReadGlobalAt021052B4(void*);
// Original: arm9/main @ 0x020DB2DC; symbol: func_020db2dc; size: 0x28.
extern "C" void Object_ReleaseGlobalResourceUnlessRetained(void*,int retain){void* q=ReadGlobalAt02105AB4();ReadGlobalValueAt021056B4(q);if(retain)return;ReadGlobalAt021052B4(q);}
