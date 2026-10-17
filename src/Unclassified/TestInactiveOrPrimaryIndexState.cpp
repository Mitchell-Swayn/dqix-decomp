// Reviewed ARM field widths and callee argument/return behavior; symbols follow original relocation targets.
#include <GameState/GameState.h>
#include <Memory/AllocatorUnion.h>
extern "C" {int ReadElement0At021015A0();void ReadLowAndHighBytesIntoOutputPointers(void*,unsigned char*,unsigned char*);void ClearWordHalfwordsAndByteAt0A(void*);void* memset(void*,int,unsigned);void* memcpy(void*,const void*,unsigned);int memcmp(const void*,const void*,unsigned);extern char* data_0210782c[];int Object_FindSignedByteKeyInSixteenEntries(void*,int);int FindSignedByteValueInSixteenSlots(void*,int);void InitializeThirtyTwoRecordsAndOwnerCounters(void*);extern char data_021056b4[];extern char* data_02105244[];}struct Nibbles{unsigned char low:4;unsigned char high:4;};struct SignedSix{signed char value:6;unsigned char rest:2;};
// Original: arm9/main @ 0x0202C508; symbol: func_0202c508; size: 0x38.
extern "C" bool TestInactiveOrPrimaryIndexState(unsigned* p){unsigned exists=*p!=0;if(exists)return ReadElement0At021015A0()==0;return true;}
