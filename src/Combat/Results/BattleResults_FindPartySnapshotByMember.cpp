#include <globaldefs.h>
ARM
struct Record {unsigned char key;char rest[0x99b];};
struct Owner {char pad[0x2788];unsigned char count;};
// Original: arm9/ov023 @ 0x021F0360; symbol: func_ov023_021f0360; size: 0x40.
// Searches the counted 0x99c-byte records beginning at offset 0x118 for a first-byte key.
extern "C" void* BattleResults_FindPartySnapshotByMember(Owner* self,int key){
 Record* record=(Record*)((char*)self+0x118);
 for(int i=0;i<self->count;record++,i++)if(record->key==key)return record;
 return 0;
}
