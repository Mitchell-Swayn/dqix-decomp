#include <globaldefs.h>
ARM
struct Record {short key;unsigned short first:1,second:1,rest:14;};
// Original: arm9/ov006 @ 0x02153E54; symbol: func_ov006_02153e54; size: 0x38.
// Invalidates the packed key and clears its two flags and remaining fourteen bits sequentially.
extern "C" void InitializeInvalidPackedKeyRecord(Record* record) {
 record->key=-1;record->first=0;record->second=0;record->rest=0;
}
