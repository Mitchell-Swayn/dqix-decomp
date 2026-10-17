#include <globaldefs.h>
#pragma opt_propagation off
struct SystemFlags { unsigned short cartridgeID;unsigned char unknown[3];unsigned char valid:1;unsigned char rejected:1;unsigned char reserved:6;unsigned short headerValue;unsigned gameCode;};
// Original: arm9/main @ 0x020D1344; symbol: func_020d1344; size: 0x18.
extern "C" unsigned char System_ReadSharedFlagsValidByte() {volatile SystemFlags* flags=(volatile SystemFlags*)0x027ffc30;return flags->valid;}
