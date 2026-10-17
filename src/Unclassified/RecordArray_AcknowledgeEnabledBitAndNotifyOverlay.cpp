#include <globaldefs.h>
ARM
extern "C" void Object_GetGlobalConnectionState();extern "C" int TestActiveWordAndGlobalStateNonzero();extern "C" unsigned char* RecordArray_FindFourEntryTagAndOptionalKeyMatch(void*,unsigned,void*);extern "C" void QueueTaggedRecordOperationMessage34(int,unsigned,void*);
// Original: arm9/main @ 0x020E3A50; symbol: func_020e3a50; size: 0x80.
extern "C" void RecordArray_AcknowledgeEnabledBitAndNotifyOverlay(void* p,unsigned bit,unsigned id,void* context){Object_GetGlobalConnectionState();if(TestActiveWordAndGlobalStateNonzero()){QueueTaggedRecordOperationMessage34(1,id&255,context);return;}unsigned char* entry=RecordArray_FindFourEntryTagAndOptionalKeyMatch(p,id,context);if(!entry)return;if(!(entry[5]&(1u<<bit)))return;entry[6]|=1u<<bit;QueueTaggedRecordOperationMessage34(3,id&255,context);}
