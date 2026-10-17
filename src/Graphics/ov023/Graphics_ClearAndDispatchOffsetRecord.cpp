#include <globaldefs.h>
ARM
struct IndexedRecordView;
extern "C" void ClearSelectedBufferUsingFormatSizeTable(unsigned char*,void*);
extern "C" void Graphics_CleanConfiguredDestinationCache(void*,int);
extern "C" void DispatchIndexedRecordWithCoordinates(IndexedRecordView*,unsigned,unsigned,unsigned,short,short,short,short,unsigned short);
// Original: arm9/ov023 @ 0x021ECDFC; symbol: func_ov023_021ecdfc; size: 0xA0.
extern "C" void Graphics_ClearAndDispatchOffsetRecord(unsigned char* p) {
unsigned short flags=*(unsigned short*)(p+0x438);
if(flags&0x40 || flags&0x200){
ClearSelectedBufferUsingFormatSizeTable(p+0x64,0);
DispatchIndexedRecordWithCoordinates((IndexedRecordView*)(p+0x64),p[0x43d],0,*(short*)(p+0x43e),*(short*)(p+0x440),(short)(*(short*)(p+0x442)+*(short*)(p+0x43e)),*(short*)(p+0x444),(short)(*(short*)(p+0x446)-*(short*)(p+0x43e)),0xffff);
Graphics_CleanConfiguredDestinationCache(p+0x64,0);
}
}
