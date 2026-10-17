// Original assembly and callee argument/return behavior reviewed.
extern "C" {int ReadElement0At021015A0();int Object_FindSignedByteKeyInSixteenEntries(void*,int);char* FindNonnegativeKeyInEntryArray(void*,int);void* GetGlobalStatePointer();void SetWordMaskBits_Main020466E4(void*,unsigned);char* LinkedList_FindNodeByUnsignedKey(void*,int);void* Object_GetGlobalConnectionState();int IsFirstWordNonzero(void*);char* FindKeyAmongFourRecords(void*,int);void* FindRecordValueByKeyOrZero(void*,int);}struct Nibbles{unsigned char low:4;unsigned char high:4;};
// Original: arm9/main @ 0x02080854; symbol: func_02080854; size: 0x24.
extern "C" void WriteResolvedHalfwordPair6And8(char* p,int i,int a,int b){char* q=FindNonnegativeKeyInEntryArray(p+4,i);if(q){*(short*)(q+6)=a;*(short*)(q+8)=b;}}
