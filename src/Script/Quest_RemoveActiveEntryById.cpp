#include <globaldefs.h>
struct KeyRecord { unsigned int key:9; unsigned int flags:23; unsigned int payload[3]; };
struct CountedKeyRecords { unsigned char count; unsigned char reserved[3]; KeyRecord records[8]; unsigned char unknown84[0x424]; unsigned char idBits[26]; };
extern "C" {
void Quest_ClearBoundedIdFlag(void*,unsigned char*,int);
void* memcpy(void*,const void*,unsigned int);
void* memset(void*,int,unsigned int);
}
// Counted 16-byte records use a nine-bit key; removing one also clears its indexed bit.
// Original: arm9/main @ 0x0209645C; symbol: func_0209645c; size: 0xC8.
extern "C" int Quest_RemoveActiveEntryById(CountedKeyRecords* self,int key) {
    if(key<0 || self->count==0) return 0;
    int i;
    for(i=0;i<self->count;++i) if(self->records[i].key==key) break;
    if(i==self->count) return 0;
    Quest_ClearBoundedIdFlag(self,self->idBits,key);
    KeyRecord temporary[9];
    memset(temporary,0,sizeof(temporary));
    memcpy(temporary,self->records,0x80);
    memcpy(&self->records[i],&temporary[i+1],(self->count-i)*sizeof(KeyRecord));
    --self->count;
    return 1;
}
