#include <globaldefs.h>
ARM
#include <Filesystem/FileIO.h>
struct Pair{const char* name;int* object;};struct Table{Pair entries[10];};extern "C" {extern Table data_020e7844;void func_02047b40(int*,const void*,int);
// Original: arm9/main @ 0x02039F04; symbol: func_02039f04; size: 0xE8.
void ZoneContainer_LoadTenNamedNarcRenderParts(unsigned char* p,int value,void* narc){Table table=data_020e7844;unsigned int size;const void* file;table.entries[0].object=(int*)(p+0x0);table.entries[1].object=(int*)(p+0x88);table.entries[2].object=(int*)(p+0x110);table.entries[3].object=(int*)(p+0x198);table.entries[4].object=(int*)(p+0x220);table.entries[5].object=(int*)(p+0x2a8);table.entries[6].object=(int*)(p+0x330);table.entries[7].object=(int*)(p+0x3b8);table.entries[8].object=(int*)(p+0x440);table.entries[9].object=(int*)(p+0x4c8);for(int i=0;i<10;i++){size=0;file=0;GetFileInNarc(narc,table.entries[i].name,&file,&size,0);int* object=table.entries[i].object;func_02047b40(object,file,value);*object=0x3e;}}}
