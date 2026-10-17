// Original ARM access widths/callee argument behavior and relocations reviewed.
#include <globaldefs.h>
#include <Resource/Script.h>
#include <System/Interrupts.h>
ARM
#pragma force_active on
struct Bits{unsigned char a:1,b:7;};struct Flags{unsigned char low:6,b:1,c:1;};extern "C"{void InitializeTag4CRecordAndClearOwnerFields(void*);void AppendLinkedNodeAndMarkActive(void*,void*);char* FindThirtyTwoByteRecordByHalfwordKey(void*,int);void* memcpy(void*,const void*,unsigned);void* memset(void*,int,unsigned);void InitializeRecordWithThreeUnitValues(void*);char* ReadWordFieldAtOffset1C();void Object_SetWordAtOffset1E20(void*,void*);int Object_TestNestedOffset440RecordAbsentOrIdle(void*);void SetLinkedFadeStateThreeAndAmountsToFixedPointOne(void*);void PointField1E20AtEmbedded914(void*);void Object_SetSelectedRecordWord4(void*,int,const void*);extern int data_02111654[];extern char data_02109bb0[];extern int(*data_020f28fc[])();extern unsigned short data_02111220,data_020f226c;}
// Original: arm9/main @ 0x0204A984; symbol: func_0204a984; size: 0x40.
extern "C" void InvokeCallbackWithBlockPayloadAndSize(unsigned* p,void(*f)(void*,unsigned,unsigned),char* q){if(q){unsigned n;memcpy(&n,q+12,4);f(q+16,*p,n);}}
