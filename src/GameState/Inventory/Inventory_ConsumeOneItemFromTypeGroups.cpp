#include "globaldefs.h"
// Original: arm9/main @ 0x0207c894; symbol: ConsumeKeyedCountOrFallbackContainerEntry.
// Original data: arm9/main @ 0x20e8a04; symbol: data_020e8a04.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 10013000c00060009000500070004000.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
struct Fields{unsigned char pad[0xc20];unsigned char key;};extern short InventoryConsumeOneItemFromTypeGroups_UnknownRoleInitializedBytes[];extern "C" int Inventory_SubtractItemQuantityFromTypeGroup(void*,unsigned,int,unsigned);
extern "C" ARM int Inventory_ConsumeOneItemFromTypeGroups(unsigned char*self,int value,unsigned key){if(value<0)return 0;int found=-1;for(int i=0;i<8;i++){if(((Fields*)(self+i))->key==key){found=i;break;}}if(found<0){int count;for(int group=0;group<8;group++){count=InventoryConsumeOneItemFromTypeGroups_UnknownRoleInitializedBytes[group];short *keys=*(short**)(self+0xbd0+group*4);for(int i=0;i<count;i++){if(keys[i]==value){signed char *counts=*(signed char**)(self+0xbf0+group*4);if(counts[i])counts[i]--;if(!counts[i])keys[i]=-1;return 1;}}}}else return Inventory_SubtractItemQuantityFromTypeGroup(self,value,1,found)!=0;return 0;}