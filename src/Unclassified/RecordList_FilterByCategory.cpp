#pragma opt_propagation off
#pragma thumb off
extern "C" void* memcpy(void*, const void*, unsigned);
extern "C" void* memset(void*, int, unsigned);
typedef struct FilterEntry { char prefix[0x12]; short kind; char middle[0x10]; unsigned char category; char tail[0x1b]; } FilterEntry;
typedef struct FilterSource { char prefix[0x5c60]; FilterEntry records[0xc6]; char rest[0x8e07-0x5c60-0xc6*0x40]; unsigned char count; } FilterSource;
typedef struct FilterState { unsigned unknown; FilterSource* source; char prefix[0x90]; int count; FilterEntry records[16]; int scratchCount; FilterEntry scratch[16]; } FilterState;
// Builds a category-filtered list from the backing source, or refines the current list.
// Record kinds 7 through 18 are excluded in both paths.
// Original: arm9/main @ 0x0209F634; symbol: func_0209f634; size: 0x140.
extern "C" void RecordList_FilterByCategory(FilterState* state, int refine, int category)
{
 if (!refine) {
  int count;
  int i=0;
  state->count=0;

  count=state->source->count;
  for (;i<count;i++) {
   FilterEntry* entry=&state->source->records[i];
   if(entry) {
    int skip=0;
    if(entry->kind>=7 && entry->kind<=18) skip=1;
    if(!skip && entry->category==category) memcpy(&state->records[state->count++],entry,0x40);
   }
  }
 } else {
  FilterEntry* input;
  int i=0;
  state->scratchCount=0;
  memset(state->scratch,0,0x400);
  input=state->records;

  for(i=0;i<state->count;i++) {
   FilterEntry* entry=&input[i]; int skip=0;
   if(entry->kind>=7 && entry->kind<=18) skip=1;
   if(!skip && entry->category==category) memcpy(&state->scratch[state->scratchCount++],entry,0x40);
  }
  state->count=state->scratchCount;
  memcpy(state->records,state->scratch,0x400);
 }
}
