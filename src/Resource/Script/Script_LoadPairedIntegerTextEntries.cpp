#include <globaldefs.h>
#include <Resource/Script.h>
extern "C" { extern unsigned char data_020fdc4c[]; void ClearTwentyEntryBufferAndFlags(void*); void AllocateByteCountTimesTwentySixRecordStorage(void*,unsigned char); void Object_SetBoundedNamedTwentySixByteEntry(void*,unsigned char,unsigned short,const char*);
// Original: arm9/main @ 0x0201F8D0; symbol: func_0201f8d0; size: 0x80.
 ARM int Script_LoadPairedIntegerTextEntries(Script::Parameter* params,int count) { int n=count/2; ClearTwentyEntryBufferAndFlags(*(void**)(data_020fdc4c+16));AllocateByteCountTimesTwentySixRecordStorage(*(void**)(data_020fdc4c+16),n); for(int i=0;i<n;i++){ int key=params->ToInt(); Script::Parameter* text=params+1;params+=2; const char* value=text->ToString();Object_SetBoundedNamedTwentySixByteEntry(*(void**)(data_020fdc4c+16),i,key,value); }return 1; } }
