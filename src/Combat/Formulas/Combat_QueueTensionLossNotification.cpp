#include <globaldefs.h>
ARM
extern "C" {void* Combat_ClearCurrentResultNodeSlot(void*);void Combat_AppendResultMessage(void*,void*,unsigned short);void Combat_AppendTargetResultToCategoryList(void*,void*,int);void Combat_SetResultMaskFlag(void*,unsigned long long*,unsigned);void Combat_PopulateResultWithCurrentHealthAndMagic(void*,void*,void*,int,unsigned long long,int);}
// Original: arm9/ov024 @ 0x021E8CFC; symbol: CreateLinkedRecordWithSelectedBitMask; size: 0xc4.
// Creates linked record with optionalF1 and required25C entries and two-word selected bit mask.
extern "C" void* Combat_QueueTensionLossNotification(char* self,void* source,unsigned bit,int extra){void* record=Combat_ClearCurrentResultNodeSlot(*(void**)(self+16));if(!record)return 0;if(extra)Combat_AppendResultMessage(*(void**)(self+16),record,0xf1);Combat_AppendResultMessage(*(void**)(self+16),record,0x25c);Combat_AppendTargetResultToCategoryList(*(void**)(self+12),record,1);++(*(unsigned char**)(self+16))[0x8e02];unsigned long long mask=0;Combat_SetResultMaskFlag(*(void**)(self+16),&mask,(unsigned char)bit);Combat_PopulateResultWithCurrentHealthAndMagic(*(void**)(self+16),record,source,0,mask,0);return record;}
