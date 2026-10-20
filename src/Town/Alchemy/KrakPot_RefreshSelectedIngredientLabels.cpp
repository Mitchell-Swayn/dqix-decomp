#include <globaldefs.h>
ARM
struct Buffers {char text[3][128];};
extern "C" void __clear(void*,unsigned);extern "C" char** Text_LookupNameTableEntry(void*,int);extern "C" void String_ReplaceBracketedNamesByRowColumnTable(const char*,char*,int,unsigned,unsigned,int);extern "C" void ItemDetail_SetQuantityRow(char*,unsigned,unsigned,unsigned char,unsigned char,unsigned char);extern "C" void ItemDetail_SetBatchQuantity(void*,unsigned char);extern "C" void Ov006_ProcessObjectWhenFlag800Set(unsigned char*);
// Original: arm9/ov006 @ 0x021553BC; symbol: ConfigureThreeExpandedNameRecords; size: 0xC4.
// Expands three optional record names, sets indexed colors and enables the embedded owner.
extern "C" void KrakPot_RefreshSelectedIngredientLabels(unsigned char* self,short* ids,unsigned char* colors){char* text[3];__clear(text,12);unsigned char last=0;for(unsigned char i=0;i<3;i++){if(*(void**)(self+0x1ac)){char** record=Text_LookupNameTableEntry(*(void**)(self+0x1ac),ids[i]);if(record){String_ReplaceBracketedNamesByRowColumnTable(*record,((Buffers*)self)->text[i],1,0,0,0);text[i]=(char*)self+i*128;}ItemDetail_SetQuantityRow((char*)self+0xae4,i,(unsigned)text[i],colors[i],colors[i],last);}}ItemDetail_SetBatchQuantity(self+0xae4,1);Ov006_ProcessObjectWhenFlag800Set(self);}
