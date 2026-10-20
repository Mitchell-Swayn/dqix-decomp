#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* GameState_ReadPResources(void*);
extern "C" char* GameResources_GetInstance();
extern "C" int Script_ReadParameterAsInteger(void*);
extern "C" void _Z13SetBrightnessP13GameResourcesii(void*,int,int);
extern "C" void _Z16SetSubBrightnessP13GameResourcesii(void*,int,int);
extern "C" void _Z17SetMainBrightnessP13GameResourcesii(void*,int,int);
extern "C" void _Z20SetAndLockBrightnessP13GameResourcesii(void*,int,int);
extern "C" void _Z23SetAndLockSubBrightnessP13GameResourcesii(void*,int,int);
extern "C" void _Z24SetAndLockMainBrightnessP13GameResourcesii(void*,int,int);
extern "C" void _Z22UnlockAndSetBrightnessP13GameResourcesii(void*,int,int);
extern "C" void _Z25UnlockAndSetSubBrightnessP13GameResourcesii(void*,int,int);
extern "C" void _Z26UnlockAndSetMainBrightnessP13GameResourcesii(void*,int,int);
// Original: arm9/ov001 @ 0x0215B074; symbol: func_ov001_0215b074; size: 0x258.
extern "C" int Script_SetBrightnessByMode(int mode,char* params,int count) {
 int optional;int notify;int value=Script_ReadParameterAsInteger(params);
 optional=-16;
 if(count>=2)optional=Script_ReadParameterAsInteger(params+8);
 void* resources=GameState_ReadPResources(_ZN9GameState11GetInstanceEv());
 if(!resources)return 0;
 notify=0;
 if(mode==0)_Z13SetBrightnessP13GameResourcesii(resources,notify,value);
 else if(mode==1)_Z13SetBrightnessP13GameResourcesii(resources,optional,value);
 else if(mode==2)_Z16SetSubBrightnessP13GameResourcesii(resources,notify,value);
 else if(mode==3)_Z16SetSubBrightnessP13GameResourcesii(resources,optional,value);
 else if(mode==4)_Z17SetMainBrightnessP13GameResourcesii(resources,notify,value);
 else if(mode==5)_Z17SetMainBrightnessP13GameResourcesii(resources,optional,value);
 else if(mode==6)_Z20SetAndLockBrightnessP13GameResourcesii(resources,notify,value);
 else if(mode==7)_Z20SetAndLockBrightnessP13GameResourcesii(resources,optional,value);
 else if(mode==8)_Z23SetAndLockSubBrightnessP13GameResourcesii(resources,notify,value);
 else if(mode==9)_Z23SetAndLockSubBrightnessP13GameResourcesii(resources,optional,value);
 else if(mode==10)_Z24SetAndLockMainBrightnessP13GameResourcesii(resources,notify,value);
 else if(mode==11)_Z24SetAndLockMainBrightnessP13GameResourcesii(resources,optional,value);
 else if(mode==12)_Z22UnlockAndSetBrightnessP13GameResourcesii(resources,notify,value);
 else if(mode==13)_Z22UnlockAndSetBrightnessP13GameResourcesii(resources,optional,value);
 else if(mode==14)_Z25UnlockAndSetSubBrightnessP13GameResourcesii(resources,notify,value);
 else if(mode==15)_Z25UnlockAndSetSubBrightnessP13GameResourcesii(resources,optional,value);
 else if(mode==16)_Z26UnlockAndSetMainBrightnessP13GameResourcesii(resources,notify,value);
 else if(mode==17)_Z26UnlockAndSetMainBrightnessP13GameResourcesii(resources,optional,value);
 int odd=(mode%2==1)?1:0;
 if(mode%6<4 && odd)notify=1;
 char* gr=GameResources_GetInstance();
 char* display=*(char**)(gr+0x3734);
 if(notify && *(unsigned short*)(display+0xa)<=3)display[0x102]=1;
 return 1;
}
