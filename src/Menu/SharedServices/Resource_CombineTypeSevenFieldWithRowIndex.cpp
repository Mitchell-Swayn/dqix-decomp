#include <globaldefs.h>
ARM
extern "C" void* TileGrid_ResolveByKey(void*, unsigned);
extern "C" unsigned Menu_GetSelectedGridIndex(unsigned short*);
// Original: arm9/ov004 @ 0x02166684; symbol: Resource_CombineTypeSevenFieldWithRowIndex; size: 0x38.
extern "C" int Resource_CombineTypeSevenFieldWithRowIndex(void* self) {
 short value=0; void* record=TileGrid_ResolveByKey(self,0x5b);
 if(record) value=*(short*)((char*)record+0x5c);
 short scaled=(short)(value*8);
 unsigned index=Menu_GetSelectedGridIndex((unsigned short*)record);
 return (short)((short)index+scaled);
}
