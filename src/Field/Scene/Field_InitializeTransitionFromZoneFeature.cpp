#include <globaldefs.h>
ARM
struct GameState;
struct ZoneTintState;
extern "C" {
void* _ZN9GameState11GetInstanceEv();
ZoneTintState* GameState_ReadUnkF8(GameState*);
void FieldTransition_InitializeRequestDefaults(char*);
void* _ZN8Vector3iaSERKS_(void*,const void*);
}
// Original: arm9/ov017 @ 0x0219C6F4; symbol: func_ov017_0219c6f4; size: 0x80.
extern "C" void* Field_InitializeTransitionFromZoneFeature(char* source) {
 char* record=(char*)GameState_ReadUnkF8((GameState*)_ZN9GameState11GetInstanceEv());
 FieldTransition_InitializeRequestDefaults(record);
 *(short*)record=*(int*)(source+0x1c);
 _ZN8Vector3iaSERKS_(record+0x10,source+0x20);
 *(short*)(record+0x1c)=*(short*)(source+0x50);
 *(unsigned char*)(record+0xb)=*(int*)(source+0x6c);
 _ZN8Vector3iaSERKS_(record+0x30,source+0x20);
 _ZN8Vector3iaSERKS_(record+0x3c,source+0x2c);
 _ZN8Vector3iaSERKS_(record+0x48,source+0x38);
 _ZN8Vector3iaSERKS_(record+0x54,source+0x44);
 *(unsigned char*)(record+0xc)=1;
 *(unsigned char*)(record+7)=1;
 return record;
}
