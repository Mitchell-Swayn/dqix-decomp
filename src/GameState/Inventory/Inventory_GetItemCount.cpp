// Reviewed ARM control flow and widths; surrounding object names remain unresolved.
extern "C" void* memset(void*,int,unsigned int);
// Original: arm9/main @ 0x020A0B3C; symbol: func_020a0b3c; size: 0x50.
extern "C" int Inventory_GetItemCount(char* p,int key){short* keys=*(short**)p;char* values=*(char**)(p+4);short count=*(short*)(p+8);if(key<0)return 0;for(short i=0;i<count;++i)if(keys[i]==key)return values[i];return 0;}
