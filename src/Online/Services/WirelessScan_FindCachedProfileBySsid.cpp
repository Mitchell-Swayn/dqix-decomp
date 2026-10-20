#include <globaldefs.h>
#include <std_library_functions.h>
ARM
extern "C" int WirelessScan_ClassifySpecialAccessPoint(unsigned char*,unsigned char*);
// Original: arm9/ov031 @ 0x02213910; symbol: func_ov031_02213910; size: 0x90.
extern "C" int WirelessScan_FindCachedProfileBySsid(unsigned char* request,unsigned char* list) {
if(*(unsigned short*)(request+10)==32){int result=WirelessScan_ClassifySpecialAccessPoint(request,list);if(result>0)return result;}
int i;unsigned char* row;char* name;short count;unsigned int length;
count=list[0xd12];
i=0;
if(count>0){
length=*(unsigned short*)(request+10);
row=list;
name=(char*)list+0x47c;
do {
if(length==*(unsigned short*)(row+0x47a) && !strncmp((char*)request+12,name,length))return (list+i*4)[0x445];
++i;row+=0xc0;name+=0xc0;
}while(i<count);
}
return -1;
}
