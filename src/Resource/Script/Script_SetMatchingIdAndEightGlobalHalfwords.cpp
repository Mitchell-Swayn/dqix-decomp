#include <globaldefs.h>
#include <Resource/Script.h>
extern "C" {extern int data_020f0d2c;extern unsigned short *data_02108dd8;}
// Original: arm9/main @ 0x02074060; symbol: func_02074060; size: 0xB4.
extern "C" ARM int Script_SetMatchingIdAndEightGlobalHalfwords(Script::Parameter *p){int i;int id=(p++)->ToInt();if(id!=data_020f0d2c)return 1;data_02108dd8[0]=(unsigned short)id;for(i=0;i<3;i++){(data_02108dd8+i)[1]=(unsigned short)p->ToInt();Script::Parameter*r=p+1;p+=2;(data_02108dd8+i)[4]=(unsigned short)r->ToInt();}data_02108dd8[7]=(unsigned short)p->ToInt();data_02108dd8[8]=(unsigned short)(p+1)->ToInt();data_02108dd8[9]=0;return 1;}
