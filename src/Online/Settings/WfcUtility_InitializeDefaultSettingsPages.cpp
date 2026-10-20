#include <globaldefs.h>
ARM
extern "C" void MIi_CpuClear16(int,void*,unsigned);
extern "C" void MI_CpuCopy8(const void*,void*,unsigned);
extern "C" void WfcUtility_GenerateMissingPersistentIdentifier(void*);
extern "C" void* WfcUtility_EncodePersistentIdentifierFields(void*);
// Original: arm9/ov031 @ 0x0221BDB8; symbol: InitializeFourPageBufferAndCopyDefaultRecords; size: 0x80.
extern "C" int WfcUtility_InitializeDefaultSettingsPages(char *buffer) {
 MIi_CpuClear16(0,buffer,1024);
 {int i=0; do { *(unsigned char*)(buffer+(i<<8)+0xe7)=255; }while(++i<3); }
 unsigned int temp[5];WfcUtility_GenerateMissingPersistentIdentifier(temp);void *source=WfcUtility_EncodePersistentIdentifierFields(temp);
 int j=0; do { MI_CpuCopy8(source,buffer+0xf0,14); ++j; buffer+=256; }while(j<2);
 return 0;
}
