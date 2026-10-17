#include <globaldefs.h>
struct Record {char pad[10];unsigned short type;};
struct Object {char pad[0x3734];Record* record;};
extern "C" Object* GameResources_GetInstance();
// Original: arm9/main @ 0x020AE4C8; symbol: func_020ae4c8; size: 0x24.
extern "C" bool IsCurrentResourceRecordTypeFour() {return GameResources_GetInstance()->record->type==4;}
