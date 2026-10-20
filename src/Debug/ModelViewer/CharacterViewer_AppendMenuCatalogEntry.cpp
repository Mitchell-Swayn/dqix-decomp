#include <globaldefs.h>
struct Record {char* first;char* second;unsigned short value;unsigned char flag1,flag2;}; struct Pair {void* first;void* second;}; struct RecordArray {Record* records;Pair* pairs;int count,pairCount;};
// Original: arm9/ov015 @ 0x0218B9D4; symbol: func_ov015_0218b9d4; size: 0x48.
extern "C" ARM void CharacterViewer_AppendMenuCatalogEntry(RecordArray* p,const Record* value){int index=p->count++;Record* target=p->records+index;target->first=value->first;target->second=value->second;target->value=value->value;target->flag1=value->flag1;target->flag2=value->flag2;}
