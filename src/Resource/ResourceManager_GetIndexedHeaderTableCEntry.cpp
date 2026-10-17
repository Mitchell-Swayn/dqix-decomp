#include <globaldefs.h>
extern "C" unsigned* data_02110370;
// Original: arm9/main @ 0x020BD4B8; symbol: func_020bd4b8; size: 0x64.
extern "C" unsigned ResourceManager_GetIndexedHeaderTableCEntry(int index) { unsigned* root=data_02110370; unsigned base=root[35]; unsigned off=*(unsigned*)(base+12); unsigned* table=(off==0) ? 0 : (unsigned*)(base+off); if(!table)return 0; if(index<0)return 0; if((unsigned)index>=*table)return 0; unsigned item=(table+index)[1]; unsigned data=root[35]; return item==0 ? 0 : data+item; }
