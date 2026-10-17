#include <globaldefs.h>
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" unsigned char* _ZN9GameState21GetPartyMemberByIndexEi(void*,int);
extern "C" void* Object_GetGlobalConnectionState();
extern "C" unsigned char* GameResources_GetInstance();
extern "C" int TestActiveWordAndGlobalStateNonzero(void*);
extern "C" void ClearRecordAndInitializeInvalidIndices(void*);
extern "C" int sprintf(char*,const char*,...);
extern "C" unsigned ClassifyIntegerIntoTenThousandRanges(int);
extern "C" void Object_CopyBytesToBytesAndCopyAToAAndCopyBToBAndCopyCToC(void*,void*);
// Original: arm9/main @ 0x02094030; symbol: func_02094030; size: 0x180.
extern "C" ARM int InsertRecordByDescendingClassification(unsigned char* self,short type,int unused,signed char member) { unsigned char* party=_ZN9GameState21GetPartyMemberByIndexEi(_ZN9GameState11GetInstanceEv(),member); void* context=Object_GetGlobalConnectionState(); unsigned char* resources=GameResources_GetInstance(); if(TestActiveWordAndGlobalStateNonzero(context) && type==10000) return 1; if(*(signed char*)(self+0x3cb)>=8) return 1; unsigned char* record=self+*(signed char*)(self+0x3cb)*0x34; ClearRecordAndInitializeInvalidIndices(record); if(!party || type==3) { unsigned char* text=resources+0x435c+member*0x30; if(!*(signed char*)text) return 1; sprintf((char*)record,(char*)text); } else if(party) { sprintf((char*)record,*(char**)(party+0x134)); } *(short*)(record+0x30)=type; record[0x32]=member; if(*(signed char*)(self+0x3cb)<=0) self[0x3cd]|=1; unsigned key=ClassifyIntegerIntoTenThousandRanges(*(short*)(record+0x30)); ++*(signed char*)(self+0x3cb); for(int i=*(signed char*)(self+0x3cb)-1;i>=2;--i) { if(ClassifyIntegerIntoTenThousandRanges(*(short*)(self+(i-1)*0x34+0x30))<=key) break; unsigned char temporary[0x34]; Object_CopyBytesToBytesAndCopyAToAAndCopyBToBAndCopyCToC(temporary,self+i*0x34); Object_CopyBytesToBytesAndCopyAToAAndCopyBToBAndCopyCToC(self+i*0x34,self+(i-1)*0x34); Object_CopyBytesToBytesAndCopyAToAAndCopyBToBAndCopyCToC(self+(i-1)*0x34,temporary); } return 0; }
