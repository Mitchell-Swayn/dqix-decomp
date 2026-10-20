#include <globaldefs.h>
#pragma optimization_level 4
extern "C" int Runtime_ParseStringAsBaseTenInteger(const char*);
// Original: arm9/main @ 0x020696BC; symbol: func_020696bc; size: 0x80.
extern "C" ARM int Text_ParseDelimitedSignedIntegerSequence(const char* text,int* output,int count) { for(int i=0;i<count;i++){ char c=*text; if(c && ((c>='0' && c<='9')||c=='-')) { output[i]=Runtime_ParseStringAsBaseTenInteger(text); for(;;){if(!*text) break; if(*text==','||*text=='>'){text++;break;}text++; } }} return 0; }
