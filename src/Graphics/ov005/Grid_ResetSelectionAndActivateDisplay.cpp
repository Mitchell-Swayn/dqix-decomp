#include <globaldefs.h>
ARM
struct State;struct GameResources;
extern "C" {void Object_ResetSelectionAndApplyConfiguredMode(State*,int);void Grid_ChangeDisplayModeAndTransitionFlags(void*,unsigned char);GameResources* GameResources_GetInstance();void* OV017_ReadWordField1C(void*);}
// Original: arm9/ov005 @ 0x02159850; symbol: func_ov005_02159850; size: 0xB4.
extern "C" void Grid_ResetSelectionAndActivateDisplay(unsigned char* p){
if(p[0x3ddc])return;
Object_ResetSelectionAndApplyConfiguredMode((State*)(p+0xee4),1);
int index=*(signed char*)(p+0x3dbb);
if(index>=0&&index<8)Grid_ChangeDisplayModeAndTransitionFlags(p,3);
else if(index>=8&&index<24)Grid_ChangeDisplayModeAndTransitionFlags(p,4);
p[0x3ddc]=0;p[0x3dde]=0;p[0x3ddf]=0;
char* resources=(char*)GameResources_GetInstance();char* object=(char*)OV017_ReadWordField1C(*(void**)(resources+0x3708));
*(unsigned short*)(object+0x634)|=0x81;
*(unsigned*)(p+0x3dcc)|=12;
}
