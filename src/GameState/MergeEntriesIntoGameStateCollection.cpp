#include <globaldefs.h>
#include <GameState/GameState.h>
#include <std_library_functions.h>
struct Flags{unsigned short active:1;unsigned short other:1;unsigned short rest:14;};
struct Entry{short id;Flags flags;};
extern "C" bool GameState_CopyStatisticsRecord(void*);extern "C" int GameState_StoreStatisticsRecord(const void*);extern "C" void Statistics_AddNewRecipeCount(void*,unsigned);
// Original: arm9/main @ 0x020AC104; symbol: func_020ac104; size: 0x130.
extern "C" int MergeEntriesIntoGameStateCollection(void *unused,Entry *entries,int count){unsigned work[44];unsigned short value;char *collection;GameState *state;int changed;state=GameState::GetInstance();changed=0;collection=(char*)state+0x2c4;for(int i=0;i<count;i++){Entry *input;unsigned short *scan;unsigned index;unsigned j;int id;input=entries+i;id=input->id;if(id>=0){index=0;scan=(unsigned short*)(collection+0x7800);for(j=0;j<0x1d7;j++){unsigned short bits=*scan;int prior=(bits&0xfffc)>>2;index=j;if(prior<=0){if(input->flags.active==1)++changed;break;}if(prior==id){if(((bits&2)>>1)==0&&input->flags.active==1)++changed;break;}++scan;}value=(id<<2)|(input->flags.active<<1)|input->flags.other;memcpy(((char*)state+0x2c4)+0x7800+index*2,&value,2);}}
GameState_CopyStatisticsRecord(work);Statistics_AddNewRecipeCount(work,changed);GameState_StoreStatisticsRecord(work);return 1;}
