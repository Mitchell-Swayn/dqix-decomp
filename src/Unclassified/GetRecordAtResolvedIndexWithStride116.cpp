// Original assembly and callee argument/return behavior reviewed.
extern "C" {int ReadElement0At021015A0();int Object_FindSignedByteKeyInSixteenEntries(void*,int);char* FindNonnegativeKeyInEntryArray(void*,int);void* GetGlobalStatePointer();void SetWordMaskBits_Main020466E4(void*,unsigned);char* LinkedList_FindNodeByUnsignedKey(void*,int);void* Object_GetGlobalConnectionState();int IsFirstWordNonzero(void*);char* FindKeyAmongFourRecords(void*,int);void* FindRecordValueByKeyOrZero(void*,int);}struct Nibbles{unsigned char low:4;unsigned char high:4;};
// Original: arm9/main @ 0x0202C178; symbol: func_0202c178; size: 0x24.
extern "C" char* GetRecordAtResolvedIndexWithStride116(char* p,int key){int i=Object_FindSignedByteKeyInSixteenEntries(p,key);if(i<0)return 0;return p+0xbc0+i*0x74;}
