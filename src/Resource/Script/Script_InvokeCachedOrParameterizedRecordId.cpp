#include <globaldefs.h>
ARM
namespace Script { struct Parameter { char data[8]; int ToInt() const; }; }
struct Selection { unsigned short id; unsigned short pad; void *cached; void *context; void *owner; }; extern "C" Selection data_02108d98; extern "C" void AllocateAndInitializeThirtyTwoByteEntries(void *,void *,unsigned short);
// Original: arm9/main @ 0x02071820; symbol: func_02071820; size: 0x54.
extern "C" int Script_InvokeCachedOrParameterizedRecordId(const Script::Parameter *args) { if(data_02108d98.cached&&data_02108d98.id) { AllocateAndInitializeThirtyTwoByteEntries(data_02108d98.owner,data_02108d98.context,data_02108d98.id); } else { unsigned id=args->ToInt(); AllocateAndInitializeThirtyTwoByteEntries(data_02108d98.owner,data_02108d98.context,id); } return 1; }
