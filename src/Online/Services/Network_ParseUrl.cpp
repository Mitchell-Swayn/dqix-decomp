#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" {
unsigned int strlen(const char*);
char* strncpy(char*, const char*, unsigned int);
char* strstr(const char*, const char*);
int Runtime_ParseStringAsBaseTenInteger(const char*);
// Original data: arm9/ov031 @ 0x2249f38; symbol: data_ov031_02249f38.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 3a000000.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
// Original data: arm9/ov031 @ 0x2249f3c; symbol: data_ov031_02249f3c.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 2f000000.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern char Network_ParseUrl_PathHttp[], Network_ParseUrl_PathHttps[], NetworkParseUrl_UnknownRoleInitializedBytes[], NetworkParseUrl_UnknownRoleInitializedBytes_Variant2[];
}
// Original: arm9/ov031 @ 0x022188E4; symbol: func_ov031_022188e4; size: 0x154.
extern "C" int Network_ParseUrl(char* self, const char* url) {
 char* port = 0;
 if (strlen(url) >= 256) return 0;
 strncpy(self+0x1024,url,256);
 if (strlen(url) != strlen(self+0x1024)) return 0;
 char* p = strstr(self+0x1024,Network_ParseUrl_PathHttp);
 if (p) {
  *(char**)(self+0x1124)=self+0x102b;
  *(int*)(self+0x1130)=0;
  *(unsigned short*)(self+0x1134)=80;
 } else {
  p=strstr(self+0x1024,Network_ParseUrl_PathHttps);
  if (!p) return 0;
  *(char**)(self+0x1124)=p+8;
  *(int*)(self+0x1130)=1;
  *(unsigned short*)(self+0x1134)=443;
 }
 p=strstr(*(char**)(self+0x1124),NetworkParseUrl_UnknownRoleInitializedBytes);
 if(p) { *p=0; port=p+1; }
 p=strstr(*(char**)(self+0x1124),NetworkParseUrl_UnknownRoleInitializedBytes_Variant2);
 if(!p) *(char**)(self+0x1128)=0;
 else { *p=0; *(char**)(self+0x1128)=p+1; }
 if(port) *(unsigned short*)(self+0x1134)=Runtime_ParseStringAsBaseTenInteger(port);
 return 1;
}
