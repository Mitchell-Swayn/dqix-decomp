// Reviewed ARM field widths and callee argument/return behavior; symbols follow original relocation targets.
#include <GameState/GameState.h>
#include <Memory/AllocatorUnion.h>
extern "C" {int ReadElement0At021015A0();void ReadLowAndHighBytesIntoOutputPointers(void*,unsigned char*,unsigned char*);void ClearWordHalfwordsAndByteAt0A(void*);void* memset(void*,int,unsigned);void* memcpy(void*,const void*,unsigned);int memcmp(const void*,const void*,unsigned);extern char* data_0210782c[];int Object_FindSignedByteKeyInSixteenEntries(void*,int);int FindSignedByteValueInSixteenSlots(void*,int);void InitializeThirtyTwoRecordsAndOwnerCounters(void*);extern char data_021056b4[];extern char* data_02105244[];}struct Nibbles{unsigned char low:4;unsigned char high:4;};struct SignedSix{signed char value:6;unsigned char rest:2;};
// Original: arm9/main @ 0x0203BD24; symbol: func_0203bd24; size: 0x54.
extern "C" void Graphics_InitializeSubOamStagingState(char* p){*(int*)(p+8)=0;p[12]=1;p[13]=1;*(int*)p=4096;*(int*)(p+4)=224;InitializeThirtyTwoRecordsAndOwnerCounters(p+16);*(void**)(p+16)=data_021056b4;data_02105244[0]=p+16;}
