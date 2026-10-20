#pragma thumb off
#pragma optimization_level 2

struct CountBits{unsigned count:12,other:20;};struct SearchTable{CountBits flags;char* entries;};
// Original: arm9/main @ 0x0206F470; symbol: func_0206f470; size: 0x80.
extern "C" char* MonsterData_FindEntryByExtractedKey(const SearchTable* table,int target,int(*key)(const void*)){char* base=table->entries;if(!base || !key)return 0;unsigned count=table->flags.count;if(!count)return 0;int low=0;int high=count-1;while(low<=high){int mid=low+((high-low+1)>>1);char* entry=base+mid*28;int value=key(entry);if(value==target)return entry;if(value>target)high=mid-1;else low=mid+1;}return 0;}
