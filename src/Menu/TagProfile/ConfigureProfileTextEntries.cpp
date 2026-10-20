#include <globaldefs.h>
#include <std_library_functions.h>
ARM
extern "C" void Graphics_ConfigureProfilePageLayout(unsigned char*,unsigned,int,int);
extern "C" void Window_PushTextCanvas(void*,void*,int,int,int,int,int,int);
extern "C" void Window_SetCanvasDisplayAttribute(char*,int,int);
extern "C" void Text_AppendFormattedRecordValueAndCenteredCaption(unsigned char*,void*,int);
extern "C" void Text_AppendIndexedRecordValueAndCenteredCaption(unsigned char*,void*,int);
extern "C" void Text_AppendByteRecordValueAndCenteredCaption(unsigned char*,void*,int);
// Original: arm9/ov012 @ 0x0218A054; symbol: func_ov012_0218a054; size: 0x1A0.
// Configures four profile text entries from cleared layout output buffers.
extern "C" void ConfigureProfileTextEntries(unsigned char* p) {
 Graphics_ConfigureProfilePageLayout(p,16,23,21);
 memset(*(void**)(p+0x1374),0,0x960);
 Window_PushTextCanvas(p+0xac,*(void**)(p+0x1374),0,0,0,1,0,0);
 Graphics_ConfigureProfilePageLayout(p,8,10,8);
 memset(*(void**)(p+0x1374),0,0x960);
 Text_AppendIndexedRecordValueAndCenteredCaption(p,*(void**)(p+0x1374),0);
 Window_PushTextCanvas(p+0xac,*(void**)(p+0x1374),0,1,0,1,0,0);
 Graphics_ConfigureProfilePageLayout(p,7,19,8);
 memset(*(void**)(p+0x1374),0,0x960);
 Text_AppendFormattedRecordValueAndCenteredCaption(p,*(void**)(p+0x1374),0);
 Window_PushTextCanvas(p+0xac,*(void**)(p+0x1374),0,1,0,1,0,0);
 Graphics_ConfigureProfilePageLayout(p,*(unsigned char*)(p+0x1371),1,8);
 memset(*(void**)(p+0x1374),0,0x960);
 Text_AppendByteRecordValueAndCenteredCaption(p,*(void**)(p+0x1374),0);
 Window_PushTextCanvas(p+0xac,*(void**)(p+0x1374),0,1,0,1,0,0);
 Window_SetCanvasDisplayAttribute((char*)p+0xac,16,0);
}
