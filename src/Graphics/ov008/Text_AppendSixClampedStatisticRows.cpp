#include <globaldefs.h>
ARM
struct Selected {unsigned padA:14,A:17,zA:1;unsigned padB:14,B:17,zB:1;unsigned unused;unsigned C:10,E:14,zC:8;unsigned D:9,F:14,zD:9;};
struct Source {unsigned u[2];unsigned B:17,zB:15;unsigned A:17,zA:15;unsigned C:9,E:14,zC:9;unsigned D:8,F:14,zD:10;};
struct Base {char pad[0x44];unsigned B:24,D:8;unsigned low:14,E:14,high:4;unsigned C:9,F:14,z:9;};
extern "C" {
unsigned ReadWordFieldAtOffset1C();void* _ZN9GameState11GetInstanceEv();
int GameState_CopyFourByteFieldAtOffset7AC0(void*);
void ClearOwnerBuffersAndResetSignedByteSentinels(signed char*);
void SetOneOfSixteenWordFieldsAtOffset8B0(unsigned*,int,unsigned);
void Object_WriteBoundedSixteenByteArrayElementAtOffset8F1(char*,int,int);
void WriteBoundedIndexedByteAt902(char*,int,int);
int Text_AppendFormattedIntegerFragmentAt020EFF74(char*,int);
void* ReadGlobalValueAt02108844();unsigned ReadNonnegativeIndexedBit(void*,unsigned char*,int);
int AppendFormattedPair_Main02041A90(char*,int,int);
void __clear(void*,unsigned);
void* ResolveIndexedRecordAndReturnSecondWord(void*,void*);
unsigned strlen(const char*);void* memcpy(void*,const void*,unsigned);char* strstr(const char*,const char*);
int AppendFormatText(char*,const char*);
extern char data_ov008_0218b4c3[];
}
// Original: arm9/ov008 @ 0x02187B20; symbol: func_ov008_02187b20; size: 0x44C.
extern "C" void Text_AppendSixClampedStatisticRows(char* self,char* text,unsigned* source){
 char temp[64];int a,b,d;
 if(!text)return;
 char* base;char* output=(char*)ReadWordFieldAtOffset1C();a=0;
 base=(char*)_ZN9GameState11GetInstanceEv()+0x7504;
 int c,e,f;
 unsigned* selected=*(unsigned**)(self+0xb34);
 if(selected){
 b=(*(Selected**)(self+0xb34))->B;a=(*(Selected**)(self+0xb34))->A;
 c=(*(Selected**)(self+0xb34))->C;d=(*(Selected**)(self+0xb34))->D;e=(*(Selected**)(self+0xb34))->E;f=(*(Selected**)(self+0xb34))->F;
 }else if(source){
 b=((Source*)source)->B;a=((Source*)source)->A;
 c=((Source*)source)->C;d=((Source*)source)->D;e=((Source*)source)->E;f=((Source*)source)->F;
 }else{
 b=((Base*)base)->B;
 GameState_CopyFourByteFieldAtOffset7AC0(&a);
 c=((Base*)base)->C;d=((Base*)base)->D;e=((Base*)base)->E;f=((Base*)base)->F;
 }
 if(*(int*)(self+0xb0c))c--;
 if(b>99999)b=99999;if(a>99999)a=99999;if(c>999)c=999;if(d>999)d=999;if(e>9999)e=9999;if(f>9999)f=9999;
 ClearOwnerBuffersAndResetSignedByteSentinels((signed char*)output);
 SetOneOfSixteenWordFieldsAtOffset8B0((unsigned*)output,0,b);WriteBoundedIndexedByteAt902(output,0,5);Object_WriteBoundedSixteenByteArrayElementAtOffset8F1(output,0,1);
 SetOneOfSixteenWordFieldsAtOffset8B0((unsigned*)output,1,a);WriteBoundedIndexedByteAt902(output,1,5);Object_WriteBoundedSixteenByteArrayElementAtOffset8F1(output,1,1);
 SetOneOfSixteenWordFieldsAtOffset8B0((unsigned*)output,2,c);WriteBoundedIndexedByteAt902(output,2,5);Object_WriteBoundedSixteenByteArrayElementAtOffset8F1(output,2,1);
 SetOneOfSixteenWordFieldsAtOffset8B0((unsigned*)output,3,d);WriteBoundedIndexedByteAt902(output,3,5);Object_WriteBoundedSixteenByteArrayElementAtOffset8F1(output,3,1);
 SetOneOfSixteenWordFieldsAtOffset8B0((unsigned*)output,4,e);WriteBoundedIndexedByteAt902(output,4,5);Object_WriteBoundedSixteenByteArrayElementAtOffset8F1(output,4,1);
 SetOneOfSixteenWordFieldsAtOffset8B0((unsigned*)output,5,f);WriteBoundedIndexedByteAt902(output,5,5);Object_WriteBoundedSixteenByteArrayElementAtOffset8F1(output,5,1);
 Text_AppendFormattedIntegerFragmentAt020EFF74(text,14);
 output=(char*)ReadGlobalValueAt02108844();
 unsigned char mask=0;
 if(source){for(int i=0;i<6;i++)mask+=1<<i;}
 else{
 mask+=1;
 if(ReadNonnegativeIndexedBit(output,(unsigned char*)output+0x8c,0x1198))mask+=2;
 mask+=4;
 if(((Base*)base)->D)mask+=8;
 if(((Base*)base)->E)mask+=16;
 if(ReadNonnegativeIndexedBit(output,(unsigned char*)output+0x8c,0x1199))mask+=32;
 }
 int y;int row=0;
 for(int i=0;i<6;i++){
 if(!(mask&(1<<i)))continue;
 y=row*14;
 AppendFormattedPair_Main02041A90(text,2,y+7);
 __clear(temp,64);
 char* label=(char*)ResolveIndexedRecordAndReturnSecondWord(self+0xa0,(void*)(short)(i+0x78));
 memcpy(temp,label,strlen(label));
 char* split=strstr(temp,data_ov008_0218b4c3);if(split)*split=0;
 AppendFormatText(text,temp);
 AppendFormattedPair_Main02041A90(text,0x62,y+7);
 AppendFormatText(text,(char*)ResolveIndexedRecordAndReturnSecondWord(self+0xa0,(void*)(short)(i+0x1f4)));
 row++;
 }
}
