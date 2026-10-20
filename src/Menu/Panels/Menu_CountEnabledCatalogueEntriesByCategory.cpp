#include <globaldefs.h>
ARM
struct CatalogueEntry {
 CatalogueEntry* next;
 void* detail;
 short key;
 unsigned short primaryRank, secondaryRank;
 unsigned char selected:1, enabled:1, category:6;
 unsigned char subtype;
};
struct Catalogue { CatalogueEntry* head; CatalogueEntry* entries; short count; };
// Original: arm9/ov023 @ 0x021E1DE8; symbol: Menu_CountEnabledCatalogueEntriesByCategory; size: 0x124.
struct Detail { unsigned words[2]; unsigned category:4, subtype:5, rest:23; };
// Counts enabled entries with non-null details, optionally aggregating category ranges.
extern "C" short Menu_CountEnabledCatalogueEntriesByCategory(Catalogue* self, int mode, int category, int subtype) {
 short count=self->count;
 short result=0;
 switch(mode) {
 case 0:
  for(short value=0;value<=7;value++) result += Menu_CountEnabledCatalogueEntriesByCategory(self,-1,value,-1);
  return result;
 case 1: case 2: break;
 }
 CatalogueEntry* entries=self->entries;
 for(short index=0;index<count;index++) {
  CatalogueEntry* entry=&entries[index];
  Detail* detail;
  if(!entry->enabled || !(detail=(Detail*)entry->detail)) continue;
  if(category>=0 && subtype>=0) {
   if(category==detail->category && subtype==detail->subtype) result++;
  } else if(category>=0) {
   if(category==detail->category) result++;
  } else if(subtype>=0) {
   if(subtype==detail->subtype) result++;
  }
 }
 return result;
}
