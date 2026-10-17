#pragma opt_propagation off
#include <globaldefs.h>
struct Relocated551 { void* header; int base; };
extern "C" {
int* ReadSignedWordAtOffset4(Relocated551*);int* Object_ReadInitialOptionalResourceWord(Relocated551*);int* ReadResolvedRecordWord4OrZero(Relocated551*);
int* ReadResolvedRecordWordTwoOrZero(Relocated551*);int* Object_ReadOptionalResourceWordC(Relocated551*);int* Object_ReadOptionalResourceWord18(Relocated551*);
int* ReadResolvedRecordWord1COrZero(Relocated551*);int* ReadResolvedRecordWordField20OrZero(Relocated551*);int* Object_ReadOptionalResolvedValue(Relocated551*);void AllocateAndAppendResourcePayloadNodesAcrossLists(Relocated551*);
}
// Original: arm9/main @ 0x02055180; symbol: func_02055180; size: 0x22C.
extern "C" ARM int RelocateSerializedPointerTables(Relocated551* s,void* header,void* base,void* required){
 if(!header)return 0;if(!base)return 0;if(!required)return 0;
 s->header=header;s->base=(int)base;
 volatile int* baseOffset=&s->base;
 int* p=ReadSignedWordAtOffset4(s);if(!p)return 0;
 for(int i=0;i<9;i++){int base=*baseOffset;int value=p[i];p[i]=base+value;}
 p=Object_ReadInitialOptionalResourceWord(s);if(!p)return 0;{int base=*baseOffset;int value=p[0];p[0]=base+value;}{int base=*baseOffset;int value=p[1];p[1]=base+value;}
 p=ReadResolvedRecordWord4OrZero(s);if(!p)return 0;
 for(int i=0;i<3;i++){int* q=p+i;int base=*baseOffset;int value=p[i];p[i]=base+value;base=*baseOffset;value=q[3];q[3]=base+value;base=*baseOffset;value=q[6];q[6]=base+value;}
 p=ReadResolvedRecordWordTwoOrZero(s);if(!p)return 0;{int base=*baseOffset;int value=p[0];p[0]=base+value;}
 p=Object_ReadOptionalResourceWordC(s);if(!p)return 0;for(int i=0;i<4;i++){int base=*baseOffset;int value=p[i];p[i]=base+value;}
 p=Object_ReadOptionalResourceWord18(s);if(!p)return 0;for(int i=0;i<2;i++){int base=*baseOffset;int value=p[i];p[i]=base+value;}
 p=ReadResolvedRecordWord1COrZero(s);if(!p)return 0;for(int i=0;i<2;i++){int base=*baseOffset;int value=p[i];p[i]=base+value;}
 p=ReadResolvedRecordWordField20OrZero(s);if(!p)return 0;{int base=*baseOffset;int value=p[1];p[1]=base+value;}
 p=Object_ReadOptionalResolvedValue(s);if(!p)return 0;for(int i=0;i<4;i++){int base=*baseOffset;int value=p[i];p[i]=base+value;}
 AllocateAndAppendResourcePayloadNodesAcrossLists(s);return 1;
}
