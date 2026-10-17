#include <globaldefs.h>
#include <Grotto/Main/TreasureMapMetadata.h>
#include <std_library_functions.h>
ARM
extern "C" char* _ZN9GameState11GetInstanceEv();
extern "C" unsigned GameState_TransferAvailableGrottoDescriptorAndTexts(void*,void*,char*,char*);
extern "C" char* ReadGlobalValueAt020FB3F0();
extern "C" char* _ZN13ZoneState084016FindEntryByValueEi(void*,int);
extern "C" unsigned _Z24GetMain16BitTimerCounterv();
extern "C" void MI_CpuCopy8(const void*,void*,unsigned);
extern "C" void func_ov011_021848a0(void*,unsigned);
extern "C" char* data_ov004_02171010;
struct Descriptor { unsigned char type,parameter; unsigned short seed; };
// Original: arm9/ov004 @ 0x02164F48; symbol: func_ov004_02164f48; size: 0x19C.
extern "C" int Grotto_AppendTransferredTreasureMap(void* self) {
 char* game=_ZN9GameState11GetInstanceEv();
 Descriptor desc;
 char discovered[10];
 char cleared[10];
 discovered[0]=0;
 cleared[0]=0;
 if(GameState_TransferAvailableGrottoDescriptorAndTexts(game,&desc,discovered,cleared)) {
 func_ov011_021848a0(self,0x69);
 srand(_Z24GetMain16BitTimerCounterv());
 TreasureMapMetadata* map=(TreasureMapMetadata*)(data_ov004_02171010+*(unsigned char*)(data_ov004_02171010+0x18f4)*28);
 if(desc.type==1) map->InitialiseAsNonLegacyMap(desc.parameter,desc.seed);
 else if(desc.type==2) {
 map->InitialiseAsLegacyBossMap(desc.parameter,(unsigned char)desc.seed);
 if(*(unsigned short*)(game+0x647e)) map->SeedOrMinTurns=*(unsigned short*)(game+0x647e);
 } else map->InitialiseAsNonLegacyMap(0,0);
 if(!discovered[0]) map->DiscoveredBy[0]=0;
 else MI_CpuCopy8(discovered,map->DiscoveredBy,10);
 if(!cleared[0]) map->ClearedBy[0]=0;
 else MI_CpuCopy8(cleared,map->ClearedBy,10);
 if(*(int*)(game+0x6478)!=-1) map->Location=*(int*)(game+0x6478);
 if(*(unsigned char*)(game+0x647c)) map->TreasureDiscoveryFlags=*(unsigned char*)(game+0x647c);
 ++*(unsigned char*)(data_ov004_02171010+0x18f4);
 int id=*(int*)(game+0x6474);
 if(id>=0) {
 char* entry=_ZN13ZoneState084016FindEntryByValueEi(ReadGlobalValueAt020FB3F0()+0x840,id);
 if(entry) ((unsigned char*)entry)[0xb]&=~0x80;
 }
 *(int*)(game+0x6474)=-1;
 } else func_ov011_021848a0(self,0x69);
 return 0;
}
