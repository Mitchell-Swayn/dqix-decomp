#include <globaldefs.h>
ARM
struct Record {char pad[18];short kind;char rest[28];short counters[8];};
struct Owner {char pad[4];char* source;char gap[0x90];int count;Record records[16];int scratchCount;Record scratch[16];};
extern "C" void* memcpy(void*,const void*,unsigned);
extern "C" void* memset(void*,int,unsigned);
// Original: arm9/main @ 0x0209F498; symbol: func_0209f498; size: 0x19C.
extern "C" void GameState_FilterRecordsWithoutPositiveCounters(Owner* self,int mode) {
 if(mode==0) {
 self->count=0;
 int count=*(unsigned char*)(self->source+0x8e07);
 for(int i=0;i<count;i++) {
 Record* record=(Record*)(self->source+0x5c60+i*64);
 if(!record)continue;
 int excluded=0;
 if(record->kind>=7&&record->kind<=18)excluded=1;
 if(excluded)continue;
 int positive=0;
 for(int j=0;j<8;j++)if(record->counters[j]>0){positive=1;break;}
 if(positive)continue;
 memcpy(&self->records[self->count++],record,64);
 }
 } else {
 self->scratchCount=0;
 memset(self->scratch,0,1024);
 for(int i=0;i<self->count;i++) {
 Record* record=&self->records[i];
 int excluded=0;
 if(record->kind>=7&&record->kind<=18)excluded=1;
 if(excluded)continue;
 int positive=0;
 for(int j=0;j<8;j++)if(record->counters[j]>0){positive=1;break;}
 if(positive)continue;
 memcpy(&self->scratch[self->scratchCount++],record,64);
 }
 self->count=self->scratchCount;
 memcpy(self->records,self->scratch,1024);
 }
}
