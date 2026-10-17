#include <globaldefs.h>
ARM
extern void* data_02105244;extern "C" void __clear(void*,unsigned);extern "C" int sprintf(char*,const char*,...);extern "C" void IncrementIndexedEntryFlagAndActiveCount(void*,int);extern "C" void ReleaseIndexedRecordAndInvalidateIndex(void*);extern "C" void TextCache_FindOrAllocateConvertedTextEntry(void*,char*,void*);extern "C" void DecrementIndexedReferenceAndActiveRecordCount(void*,int);
// Original: arm9/main @ 0x0203C108; symbol: func_0203c108; size: 0x90.
extern "C" void FormatAndSubmitTextToGlobalContext(unsigned char* object,const char* format){char buffer[256];if(data_02105244 && format && *format){__clear(buffer,256);sprintf(buffer,format);short value=*(short*)(object+20);IncrementIndexedEntryFlagAndActiveCount(data_02105244,value);ReleaseIndexedRecordAndInvalidateIndex(object);TextCache_FindOrAllocateConvertedTextEntry(data_02105244,buffer,object+20);DecrementIndexedReferenceAndActiveRecordCount(data_02105244,value);}}
