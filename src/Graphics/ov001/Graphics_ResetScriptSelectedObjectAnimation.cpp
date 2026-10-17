#include <globaldefs.h>
ARM
struct Entry { unsigned kind,pad[2]; unsigned char* object; };
extern "C" { void _ZN8Object3D24MaybeSetRegularAnimationEPKci(void*,const char*,int); void WriteWordIndex23Flag8(unsigned*,int); bool WritePositiveFloatAt40(char*,float); int ReadScriptParameterAsInteger(void*); extern Entry* data_ov001_02165880[]; extern char data_ov001_02165769[]; }
// Original: arm9/ov001 @ 0x0216013C; symbol: func_ov001_0216013c; size: 0xBC.
extern "C" int Graphics_ResetScriptSelectedObjectAnimation(void* parameter) {
 unsigned char* other;
 int index=ReadScriptParameterAsInteger(parameter);
 Entry* entries=data_ov001_02165880[1];
 unsigned kind=entries[index].kind;
 if(kind==2 || kind==6) {
  unsigned char* object=0;
  if(entries) object=entries[index].object;
  if(!object) return 0;
  if(*(void**)(object+0x14)) WriteWordIndex23Flag8(*(unsigned**)(object+0x14),0);
  if(*(void**)(object+0x14)) WritePositiveFloatAt40(*(char**)(object+0x14),1.0f);
 } else if(kind==1 || kind==0 || kind-4<=1) {
  other=0;
  if(entries) other=entries[index].object;
  if(!other) return 0;
  _ZN8Object3D24MaybeSetRegularAnimationEPKci(other,data_ov001_02165769,0);
 }
 return 1;
}
