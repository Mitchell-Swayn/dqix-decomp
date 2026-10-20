#include <globaldefs.h>
ARM
// Original: arm9/ov031 @ 0x022456F0; symbol: OnlineTransfer_RequestLocalWirelessStop; size: 0x20.
// Sets byte35 to five and reports success when byte34 is six or seven.
extern "C" bool OnlineTransfer_RequestLocalWirelessStop(unsigned char* self){
 if(self[0x34]==7||self[0x34]==6){self[0x35]=5;return true;}return false;
}
