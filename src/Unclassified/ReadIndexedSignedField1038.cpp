// Original assembly and callee argument/return behavior reviewed.
extern "C" {int ReadElement0At021015A0();int Object_FindSignedByteKeyInSixteenEntries(void*,int);char* FindNonnegativeKeyInEntryArray(void*,int);void* GetGlobalStatePointer();void SetWordMaskBits_Main020466E4(void*,unsigned);char* LinkedList_FindNodeByUnsignedKey(void*,int);void* Object_GetGlobalConnectionState();int IsFirstWordNonzero(void*);char* FindKeyAmongFourRecords(void*,int);void* FindRecordValueByKeyOrZero(void*,int);}struct Nibbles{unsigned char low:4;unsigned char high:4;};
// Original: arm9/main @ 0x0202C1A4; symbol: func_0202c1a4; size: 0x1C.
extern "C" int ReadIndexedSignedField1038(char* p){return *((signed char*)p+ReadElement0At021015A0()+0x1038);}
