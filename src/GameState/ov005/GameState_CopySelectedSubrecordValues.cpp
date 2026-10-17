#include <globaldefs.h>
#include <Resource/GameResources.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* GameState_GetObjectWithFlag100(void*, int);
extern "C" void* Object_GetNestedOffset150Subrecord488(char*);
extern "C" void* OV017_ReadWordField1C(void*);
extern "C" unsigned char data_ov005_0215cbd4[];
struct Entry { short value; char flag; char pad[25]; };
// Original: arm9/ov005 @ 0x02155544; symbol: func_ov005_02155544; size: 0x7C.
extern "C" void GameState_CopySelectedSubrecordValues(char* p) {
 void* state = _ZN9GameState11GetInstanceEv();
 char* res = (char*)GameResources_GetInstance();
 char* obj = (char*)OV017_ReadWordField1C(*(void**)(res+0x3708));
 char* out;
 short* values = (short*)Object_GetNestedOffset150Subrecord488((char*)GameState_GetObjectWithFlag100(state, *(int*)(obj+0x4fc)));
 out = p+0x2d90;
 for(int i=0;i<8;i++) { short value=values[data_ov005_0215cbd4[i]]; char* entry=p+0x2d90+i*28; *(short*)entry=value; entry[2]=1; }
}
