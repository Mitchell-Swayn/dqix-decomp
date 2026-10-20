#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" void __clear(void*,unsigned);
struct Entry { char pad[0x12]; short subtype; unsigned short key,group; char tail[0x28]; };
struct Database {char prefix[0x5c60];Entry entries[16];char gap[0x8e07-0x6060];unsigned char count;char pad[0x18];int groups;};
struct State {unsigned reserved;Database* database;char pad[0x90];int count;Entry entries[16];int scratchCount;Entry scratch[16];};
// Original: arm9/main @ 0x0209F968; symbol: func_0209f968; size: 0x228.
extern "C" void FilterSixtyFourByteRecordsByMinimumGroupSize(State* state,int original,int key,int minimum)
{
    int groups=state->database->groups;
    if(original) {
        state->count=0;
        unsigned char count=state->database->count;
        for(int group=0;group<groups;group++) {
            for(int subtype=0;subtype<4;subtype++) {
                state->scratchCount=0;memset(state->scratch,0,1024);
                for(int i=0;i<count;i++) {
                    Entry* entry=state->database->entries+i;
                    if(entry&&entry->group==group&&entry->subtype==subtype&&entry->key==key) {
                        int index=state->scratchCount++;
                        memcpy(state->scratch+index,entry,64);
                    }
                }
                if(state->scratchCount>=minimum&&state->scratchCount+state->count<16) {
                    memcpy(state->entries+state->count,state->scratch,state->scratchCount*64);
                    state->count+=state->scratchCount;
                }
            }
        }
    }else {
        state->scratchCount=0;memset(state->scratch,0,1024);
        for(int group=0;group<groups;group++) {
            for(int subtype=0;subtype<4;subtype++) {
                Entry buffer[16];int count=0;__clear(buffer,1024);
                for(int i=0;i<state->count;i++) {
                    Entry* entry=state->entries+i;
                    if(entry->group==group&&entry->subtype==subtype&&entry->key==key) {
                        memcpy(buffer+count++,entry,64);
                    }
                }
                if(count>=minimum&&count+state->scratchCount<16) {
                    memcpy(state->scratch+state->scratchCount,buffer,count*64);
                    state->scratchCount+=count;
                }
            }
        }
        state->count=state->scratchCount;memcpy(state->entries,state->scratch,1024);
    }
}
