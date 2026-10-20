// Reviewed ARM control flow and widths; surrounding object names remain unresolved.
extern "C" void* memset(void*,int,unsigned int);
// Original: arm9/main @ 0x020A0B8C; symbol: func_020a0b8c; size: 0x40.
extern "C" int Inventory_CountOccupiedSlots(char* p){char* values=*(char**)(p+4);short count=*(short*)(p+8);short n=0;for(short i=0;i<count;++i)if(values[i])++n;return n;}
