#include <globaldefs.h>
extern "C" void ReadSignedWord();extern "C" unsigned* RecordList_BinarySearchEightByteEntriesByCallbackKey(unsigned,unsigned,void(*)());
// Original: arm9/main @ 0x020E0440; symbol: func_020e0440; size: 0x2C.
extern "C" ARM unsigned RecordLookup_GetSecondWordOfFoundEntry(unsigned a,unsigned b){if(!a)return 0;unsigned* p=RecordList_BinarySearchEightByteEntriesByCallbackKey(a,b,ReadSignedWord);return p?p[1]:0;}
