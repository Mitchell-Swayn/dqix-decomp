#pragma thumb off
#pragma optimization_level 4

struct FlagBits{unsigned char active:1, flag1:1, flag2:1, flag3:1, other:4;};
extern "C" void InitializeRecordWithInvalidWord8AndPackedFlags(void*);
// Original: arm9/main @ 0x020416E0; symbol: func_020416e0; size: 0x74.
extern "C" void InitializeTaggedExternalBufferRecord(char* record,unsigned char tag,int value,void* data,int size,int count,unsigned char option){if(!data)return;InitializeRecordWithInvalidWord8AndPackedFlags(record);record[0x17]=tag;*(int*)(record+0x18)=value;*(int*)(record+8)=size;*(void**)record=data;*(int*)(record+4)=count;FlagBits* flags=(FlagBits*)(record+0x16);flags->active=1;flags->flag1=0;flags->flag2=0;flags->flag3=option;}
