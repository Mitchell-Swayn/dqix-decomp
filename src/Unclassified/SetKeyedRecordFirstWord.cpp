// Original assembly and callee argument/return behavior reviewed.
extern "C" {int ReadElement0At021015A0();int Object_FindSignedByteKeyInSixteenEntries(void*,int);char* FindNonnegativeKeyInEntryArray(void*,int);void* GetGlobalStatePointer();void SetWordMaskBits_Main020466E4(void*,unsigned);char* LinkedList_FindNodeByUnsignedKey(void*,int);void* Object_GetGlobalConnectionState();int IsFirstWordNonzero(void*);char* FindKeyAmongFourRecords(void*,int);void* FindRecordValueByKeyOrZero(void*,int);}struct Nibbles{unsigned char low:4;unsigned char high:4;};
// Original: arm9/main @ 0x02080F8C; symbol: func_02080f8c; size: 0x1C.
extern "C" void SetKeyedRecordFirstWord(char* p,int i,int v){char* q=FindNonnegativeKeyInEntryArray(p+4,i);if(q)*(int*)q=v;}
