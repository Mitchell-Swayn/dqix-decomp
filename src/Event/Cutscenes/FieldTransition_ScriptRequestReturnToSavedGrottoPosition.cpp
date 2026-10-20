#include <globaldefs.h>
ARM
struct GameState; struct ZoneTintState;
struct Vector { int x,y,z; };
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" ZoneTintState* GameState_ReadUnkF8(GameState*);
extern "C" void* Zone3D_GetMainInstance();
extern "C" void* _ZN8Vector3iaSERKS_(void*,const void*);
extern "C" void FieldTransition_InitializeRequestDefaults(char*);
extern "C" void* GameState_ReplacePendingFieldTransition(void*,const void*);
// Original: arm9/ov001 @ 0x021620BC; symbol: func_ov001_021620bc; size: 0x8C.
extern "C" int FieldTransition_ScriptRequestReturnToSavedGrottoPosition() {
 GameState* state=(GameState*)_ZN9GameState11GetInstanceEv();
 char* record=(char*)GameState_ReadUnkF8(state);
 char* source=(char*)Zone3D_GetMainInstance();
 Vector position;
 _ZN8Vector3iaSERKS_(&position,source+0x23c0);
 short angle=*(short*)(source+0x23cc);
 FieldTransition_InitializeRequestDefaults(record);
 record[2]=1;
 record[7]=1;
 *(short*)record=*(signed char*)(source+0x23bb)+0x9c40;
 _ZN8Vector3iaSERKS_(record+0x10,&position);
 *(short*)(record+0x1c)=angle;
 record[0x68]=1;
 GameState_ReplacePendingFieldTransition(state,record);
 return 1;
}
