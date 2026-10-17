// Reviewed ARM field widths and callee argument/return behavior; symbols follow original relocation targets.
#include <GameState/GameState.h>
#include <Memory/AllocatorUnion.h>
extern "C" {int ReadElement0At021015A0();void ReadLowAndHighBytesIntoOutputPointers(void*,unsigned char*,unsigned char*);void ClearWordHalfwordsAndByteAt0A(void*);void* memset(void*,int,unsigned);void* memcpy(void*,const void*,unsigned);int memcmp(const void*,const void*,unsigned);extern char* data_0210782c[];int Object_FindSignedByteKeyInSixteenEntries(void*,int);int FindSignedByteValueInSixteenSlots(void*,int);void InitializeThirtyTwoRecordsAndOwnerCounters(void*);extern char data_021056b4[];extern char* data_02105244[];}struct Nibbles{unsigned char low:4;unsigned char high:4;};struct SignedSix{signed char value:6;unsigned char rest:2;};
// Original: arm9/main @ 0x0204AF64; symbol: func_0204af64; size: 0x50.
extern "C" void Graphics_InitializeCanvasTransferState(char* p){ClearWordHalfwordsAndByteAt0A(p);p[12]=0;*(unsigned short*)(p+14)=65535;*(int*)(p+16)=0;*(int*)(p+20)=0;*(int*)(p+24)=0;((Nibbles*)(p+28))->low=0;((Nibbles*)(p+28))->high=0;p[29]=0;p[30]=0;p[31]=0;}
