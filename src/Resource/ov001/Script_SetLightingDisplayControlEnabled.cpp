#include <globaldefs.h>
ARM
#pragma always_inline on
struct IntegerParameterView;
extern "C" char* _ZN15LightingManager11GetInstanceEv();
extern "C" int ReadScriptParameterAsInteger(IntegerParameterView*);
extern "C" void Graphics_WriteHalfwordRegister35CAndDisplayControl(int,int,int,unsigned);
struct Settings { unsigned unknown,mode,offset,color; unsigned remaining[10]; };
inline Settings GetLightingSettings() { return *(Settings*)(_ZN15LightingManager11GetInstanceEv()+0x4c); }
// Original: arm9/ov001 @ 0x02161E8C; symbol: func_ov001_02161e8c; size: 0xB0.
extern "C" int Script_SetLightingDisplayControlEnabled(IntegerParameterView* params) {
 char* lighting=_ZN15LightingManager11GetInstanceEv();
 if(!ReadScriptParameterAsInteger(params)) {
  lighting[0x85]=0;
  Graphics_WriteHalfwordRegister35CAndDisplayControl(0,0,0,0);
 } else {
  Settings settings=GetLightingSettings();
  lighting[0x85]=1;
  Graphics_WriteHalfwordRegister35CAndDisplayControl(1,settings.mode,settings.offset,settings.color);
 }
 return 1;
}
