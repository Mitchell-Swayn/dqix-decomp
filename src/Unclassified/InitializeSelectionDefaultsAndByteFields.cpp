// Original ARM access widths/callee argument behavior and relocations reviewed.
#include <globaldefs.h>
#include <Resource/Script.h>
#include <System/Interrupts.h>
ARM
#pragma force_active on
struct Bits{unsigned char a:1,b:7;};struct Flags{unsigned char low:6,b:1,c:1;};extern "C"{void InitializeTag4CRecordAndClearOwnerFields(void*);void AppendLinkedNodeAndMarkActive(void*,void*);char* FindThirtyTwoByteRecordByHalfwordKey(void*,int);void* memcpy(void*,const void*,unsigned);void* memset(void*,int,unsigned);void InitializeRecordWithThreeUnitValues(void*);char* ReadWordFieldAtOffset1C();void Object_SetWordAtOffset1E20(void*,void*);int Object_TestNestedOffset440RecordAbsentOrIdle(void*);void SetLinkedFadeStateThreeAndAmountsToFixedPointOne(void*);void PointField1E20AtEmbedded914(void*);void Object_SetSelectedRecordWord4(void*,int,const void*);extern int data_02111654[];extern char data_02109bb0[];extern int(*data_020f28fc[])();extern unsigned short data_02111220,data_020f226c;}
// Original: arm9/main @ 0x0205BEF8; symbol: func_0205bef8; size: 0x44.
extern "C" void InitializeSelectionDefaultsAndByteFields(char* p){InitializeRecordWithThreeUnitValues(p);*(int*)(p+48)=0;*(short*)(p+52)=0;p[54]=0;p[55]=0;p[56]=0;p[57]=20;p[58]=10;p[60]=1;p[61]=1;}
