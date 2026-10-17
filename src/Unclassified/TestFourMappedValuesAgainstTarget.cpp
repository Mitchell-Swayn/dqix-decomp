#include <globaldefs.h>
extern "C" {
unsigned int Lookup_ReadThirteenByFiveByteTable(void *,int);extern unsigned char data_020ee700[];
// Original: arm9/main @ 0x020DD19C; symbol: func_020dd19c; size: 0x64.
bool TestFourMappedValuesAgainstTarget(void *p,int v){bool result=false;for(unsigned char i=0;i<4;i++){unsigned int n=Lookup_ReadThirteenByFiveByteTable(p,i);if(n&&n<=14&&data_020ee700[n]==v){result=true;break;}}return result;}
}
