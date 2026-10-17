#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" {
unsigned int strlen(const char*);
char* strncpy(char*, const char*, unsigned int);
char* strstr(const char*, const char*);
int Runtime_ParseStringAsBaseTenInteger(const char*);
extern char data_ov031_02249f24[], data_ov031_02249f2c[], data_ov031_02249f38[], data_ov031_02249f3c[];
}
// Original: arm9/ov031 @ 0x022188E4; symbol: func_ov031_022188e4; size: 0x154.
extern "C" int Network_ParseUrl(char* self, const char* url) {
 char* port = 0;
 if (strlen(url) >= 256) return 0;
 strncpy(self+0x1024,url,256);
 if (strlen(url) != strlen(self+0x1024)) return 0;
 char* p = strstr(self+0x1024,data_ov031_02249f24);
 if (p) {
  *(char**)(self+0x1124)=self+0x102b;
  *(int*)(self+0x1130)=0;
  *(unsigned short*)(self+0x1134)=80;
 } else {
  p=strstr(self+0x1024,data_ov031_02249f2c);
  if (!p) return 0;
  *(char**)(self+0x1124)=p+8;
  *(int*)(self+0x1130)=1;
  *(unsigned short*)(self+0x1134)=443;
 }
 p=strstr(*(char**)(self+0x1124),data_ov031_02249f38);
 if(p) { *p=0; port=p+1; }
 p=strstr(*(char**)(self+0x1124),data_ov031_02249f3c);
 if(!p) *(char**)(self+0x1128)=0;
 else { *p=0; *(char**)(self+0x1128)=p+1; }
 if(port) *(unsigned short*)(self+0x1134)=Runtime_ParseStringAsBaseTenInteger(port);
 return 1;
}
