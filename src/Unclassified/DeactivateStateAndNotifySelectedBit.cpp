#include <globaldefs.h>
struct Owner {unsigned char a,b,c,unused;bool active;unsigned char flags;};extern "C" {extern char data_02108760[];void InvokeObjectWithStoredFieldC0(void*,int);void* Object_GetGlobalConnectionState();int ReadIndexedSignedField1038(void*);void System_QueuePackedRecordAE(unsigned,unsigned,unsigned,unsigned,unsigned,unsigned,unsigned);
// Original: arm9/main @ 0x020A8874; symbol: func_020a8874; size: 0x74.
void DeactivateStateAndNotifySelectedBit(Owner* p){if(!p->active)return;p->active=false;InvokeObjectWithStoredFieldC0(data_02108760,0);int bit=ReadIndexedSignedField1038(Object_GetGlobalConnectionState());p->flags&=~(1u<<bit);System_QueuePackedRecordAE(p->a,p->b,p->c,0,(unsigned char)bit,0,0);} }
