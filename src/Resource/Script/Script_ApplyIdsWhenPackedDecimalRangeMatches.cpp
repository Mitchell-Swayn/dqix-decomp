#include <globaldefs.h>
#pragma optimize_for_size off
#pragma opt_common_subs off
#include <Resource/Script.h>
extern "C" {extern unsigned char* data_02109bc8;void Object_AppendHalfwordWithinTwelveEntryLimit(void*,unsigned short);
// Original: arm9/main @ 0x0209BED8; symbol: func_0209bed8; size: 0x124.
ARM int Script_ApplyIdsWhenPackedDecimalRangeMatches(Script::Parameter* params,int count){if(!*(int*)(data_02109bc8+8))return 1;unsigned int key=params->ToInt();if(key!=*(unsigned short*)(data_02109bc8+6))return 1;Script::Parameter* second=params+1;params+=2;int packed=second->ToInt();int a=(packed>>24)&15,b=(packed>>16)&15,c=(packed>>8)&15,d=packed&15;int lower=a*100+b,upper=c*100+d;int value=*(unsigned short*)(data_02109bc8+4);bool selected=false;if(lower<=value && value<=upper){*(int*)(data_02109bc8+8)=0;selected=true;}else if(!a && !b && !c && !d)selected=true;if(selected){for(int i=0;i<count-2;i++){int entry=(params++)->ToInt();unsigned short high=(int)entry>>16,low=entry;if(high)Object_AppendHalfwordWithinTwelveEntryLimit(*(void**)data_02109bc8,high);if(low)Object_AppendHalfwordWithinTwelveEntryLimit(*(void**)data_02109bc8,low);}}return 1;} }
