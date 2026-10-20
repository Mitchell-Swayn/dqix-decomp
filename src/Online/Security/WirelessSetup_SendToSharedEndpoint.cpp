#include <globaldefs.h>
THUMB
extern "C" void* System_WaitForOrRegisterSharedContext();
extern "C" void Network_WriteBigEndianWord(unsigned,unsigned char*);
extern "C" int WirelessSetup_SendDatagramAndNormalizeError(void*,void*,unsigned,void*,void*);
struct ContextCommand { unsigned char context[4]; unsigned char kind,mode; unsigned short code; int invalid; };
// Original: arm9/ov031 @ 0x02220190; symbol: func_ov031_02220190; size: 0x3C.
// Builds command kind8/mode2/code1e6 with invalid word and the shared context serialized in big-endian order.
// The converter's third opaque word is unused by its owner; the original passes the record address there.
extern "C" int WirelessSetup_SendToSharedEndpoint(void* object,void* mode,void* output)
{
 ContextCommand record;
 record.kind=8;record.mode=2;record.invalid=-1;record.code=0x1e6;
 void* context=System_WaitForOrRegisterSharedContext();
 Network_WriteBigEndianWord((unsigned)context,record.context);
 return WirelessSetup_SendDatagramAndNormalizeError(object,&record.kind,(unsigned)&record,mode,output);
}
