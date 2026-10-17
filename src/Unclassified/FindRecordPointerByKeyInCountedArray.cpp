#include <globaldefs.h>
ARM
struct Record {short key;unsigned char rest[42];};struct Records {Record* records;short count;};
// Original: arm9/main @ 0x020725D8; symbol: func_020725d8; size: 0x40.
extern "C" Record* FindRecordPointerByKeyInCountedArray(Records* list,int key){for(int i=0;i<list->count;i++){if(list->records[i].key==key)return list->records+i;}return 0;}
