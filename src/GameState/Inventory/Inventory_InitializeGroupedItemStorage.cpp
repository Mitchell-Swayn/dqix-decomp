#include <globaldefs.h>
// Original data: arm9/main @ 0x20e8a24; symbol: data_020e8a24.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 10013000c00060009000500070004000.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" short InventoryInitializeGroupedItemStorage_UnknownRoleInitializedBytes[];struct Inventory{char pad[0xbd0];short* slots[8];signed char* counts[8];short lengths[8];unsigned char kinds[8],unknown[8];};
// Original: arm9/main @ 0x0207C258; symbol: func_0207c258; size: 0x120.
extern "C" ARM void Inventory_InitializeGroupedItemStorage(Inventory* p){char* base=(char*)p;p->slots[0]=(short*)base;p->slots[1]=(short*)(base+0x330);p->slots[2]=(short*)(base+0x3c0);p->slots[3]=(short*)(base+0x600);p->slots[4]=(short*)(base+0x720);p->slots[5]=(short*)(base+0x8d0);p->slots[6]=(short*)(base+0x9c0);p->slots[7]=(short*)(base+0xb10);p->counts[0]=(signed char*)(base+0x220);p->counts[1]=(signed char*)(base+0x390);p->counts[2]=(signed char*)(base+0x540);p->counts[3]=(signed char*)(base+0x6c0);p->counts[4]=(signed char*)(base+0x840);p->counts[5]=(signed char*)(base+0x970);p->counts[6]=(signed char*)(base+0xaa0);p->counts[7]=(signed char*)(base+0xb90);for(int i=0;i<8;++i){p->lengths[i]=InventoryInitializeGroupedItemStorage_UnknownRoleInitializedBytes[i];p->kinds[i]=i;}for(int i=0;i<8;++i){short* slots=p->slots[i];signed char* counts=p->counts[i];short length=p->lengths[i];for(int j=0;j<length;++j){slots[j]=-1;counts[j]=0;}p->unknown[i]=0;}}
