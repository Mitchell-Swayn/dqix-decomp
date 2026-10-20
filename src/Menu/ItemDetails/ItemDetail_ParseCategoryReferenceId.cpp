#include <globaldefs.h>
ARM
extern "C" {void __clear(void*,unsigned);char* strncpy(char*,const char*,unsigned);int Runtime_ParseStringAsBaseTenInteger(const char*);}
// Original: arm9/ov023 @ 0x021DB564; symbol: Text_ParsePrefixedHundredsIdentifier; size: 0xd0.
extern "C" int ItemDetail_ParseCategoryReferenceId(const char* text){char token[5];int result=0;__clear(token,5);strncpy(token,text,4);token[3]=0;unsigned short value=(short)Runtime_ParseStringAsBaseTenInteger(token+1)*(short)100;if(token[0]=='C')result=value;else if(token[0]=='M')result=value+1000;else if(token[0]=='X')result=value+4000;else if(token[0]=='D')result=value+7000;else if(token[0]=='T')result=value+9000;else if(token[0]=='S')result=value+5000;else if(token[0]=='H'){result=value+15000;if(result==15800)result=20056;}return result;}
