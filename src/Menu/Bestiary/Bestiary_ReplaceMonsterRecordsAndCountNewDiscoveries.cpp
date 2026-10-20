#include <globaldefs.h>
ARM
#pragma always_inline on
#include <std_library_functions.h>
struct Packed { unsigned value:10; unsigned rest:22; };
#include <GameState/GameState.h>
extern "C" bool GameState_CopyStatisticsRecord(void*);
extern "C" void Statistics_AddNewMonsterSpeciesCount(char*,unsigned);
extern "C" int GameState_StoreStatisticsRecord(const void*);
inline int MergePacked(const short* indices,const Packed* values,int count) {
 int i; int added;
 Packed* table=(Packed*)((char*)GameState::GetInstance()+0x75f0);
 added=0;
 for(i=0;i<count;i++) {
  short index=indices[i]-1;
  const Packed* source=&values[i];
  if(index>=0 && index<0x134) {
   if(table[index].value==0 && source->value!=0) added++;
   memcpy((char*)table+index*4,source,4);
  }
 }
 char state[0xb0];
 GameState_CopyStatisticsRecord(state);
 Statistics_AddNewMonsterSpeciesCount(state,added);
 GameState_StoreStatisticsRecord(state);
 return 1;
}

// Original: arm9/main @ 0x020ABE84; symbol: Bestiary_ReplaceMonsterRecordsAndCountNewDiscoveries; size: 0xB4.
// Copies valid indexed packed records and counts newly nonzero low-ten-bit entries.
extern "C" int Bestiary_ReplaceMonsterRecordsAndCountNewDiscoveries(void* unused,const short* indices,const Packed* values,int count) {return MergePacked(indices,values,count);}
