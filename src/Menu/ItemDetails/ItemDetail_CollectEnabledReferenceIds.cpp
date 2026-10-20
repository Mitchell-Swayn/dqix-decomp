#include <globaldefs.h>
ARM
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
extern "C" int Runtime_ParseStringAsBaseTenInteger(const char*);extern "C" int ItemDetail_ParseCategoryReferenceId(char*);
// Original: arm9/ov023 @ 0x021DB314; symbol: CollectNumericAndUppercaseRecordTokens; size: 0xac.
extern "C" void ItemDetail_CollectEnabledReferenceIds(char* self,unsigned short* output,short* count){
char* records=P(self,8);char* entry=P(records,4);int used=0;short total=*(short*)(records+2);for(int i=0;i<total;i++,entry+=8){if(B(entry,1)&&P(entry,4)){char* text=P(entry,4);int first=*(signed char*)text;if(first=='f'){output[used]=Runtime_ParseStringAsBaseTenInteger(text+5);used=(short)(used+1);}else if(first>='A'&&first<='Z'){unsigned short value=ItemDetail_ParseCategoryReferenceId(text);if(value){output[used]=value;used=(short)(used+1);}}}}*count=used;
}
