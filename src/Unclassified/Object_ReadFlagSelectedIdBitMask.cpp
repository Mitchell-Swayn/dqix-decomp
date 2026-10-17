struct Record { unsigned short id; unsigned char padding[12]; unsigned char flags; unsigned char last; }; struct Table { Record *records; int count; };
// Original: arm9/main @ 0x02099A68; symbol: func_02099a68; size: 0x5C.
 extern "C" int Object_ReadFlagSelectedIdBitMask(Table *table,unsigned int id) { for(int i=0;i<table->count;i++) { if(id==table->records[i].id) { unsigned int bits=((unsigned int)table->records[i].flags<<26)>>28; return bits==8?0:1<<bits; } } return 0; }
