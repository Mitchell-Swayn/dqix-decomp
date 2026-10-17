#include <globaldefs.h>
ARM
extern "C" void* Object_GetGlobalConnectionState();
extern "C" int IsFirstWordNonzero(void*);
extern "C" void CombineTableOriginAndMatchingEntryGeometry(char*,int,int,short*,short*,short*,short*);
extern "C" bool Object_TestTextureRecordExistsForKey(void*,int);
extern "C" void func_ov003_021604f4(void*,short,short,int,int);
struct Keys { short value[3]; };
struct Source { char padding[0x28]; Keys keys; };
extern "C" Source data_ov003_0217f3ec;
extern "C" short data_ov003_0217f448[][2];
// Original: arm9/ov003 @ 0x0216052C; symbol: func_ov003_0216052c; size: 0x14C.
extern "C" void Graphics_DrawAvailableTextureGeometryLabels(char* self) {
 if(!*(void**)(self+0x324)) return;
 if(IsFirstWordNonzero(Object_GetGlobalConnectionState())) return;
 char* object=*(char**)(self+0x324);
 if(!(*(unsigned*)(self+0x464)&0x10000)) return;
 Keys keys=data_ov003_0217f3ec.keys;
 for(int i=0;i<3;i++) {
 unsigned char j,label;
 short key=keys.value[i];
 if(Object_TestTextureRecordExistsForKey(object,key)) {
 label=1;
 short x,y,a,b;
 for(j=0;j<2;j++) {
 int id=data_ov003_0217f448[i][j];
 if(id<0) continue;
 CombineTableOriginAndMatchingEntryGeometry(object,key,id,&x,&y,&a,&b);
 b=(16-b)>>1;
 unsigned current=label++;
 func_ov003_021604f4(self,(short)(x+a+6),(short)(y-b+1),0,current);
 }
 break;
 }
 }
}
