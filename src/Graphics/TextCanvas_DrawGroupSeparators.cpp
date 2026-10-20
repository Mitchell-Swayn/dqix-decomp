#include <globaldefs.h>
ARM
struct Table{int pad;short* ids;unsigned char pad8[12];unsigned char count;};extern "C" {void TextCanvas_DrawHorizontalSeparator(void*,int);
// Original: arm9/main @ 0x02081530; symbol: func_02081530; size: 0x44.
void TextCanvas_DrawGroupSeparators(void* unused,void* p,Table* table){if(!table)return;for(unsigned char i=0;i<table->count;i++)TextCanvas_DrawHorizontalSeparator(p,table->ids[i]);}}
