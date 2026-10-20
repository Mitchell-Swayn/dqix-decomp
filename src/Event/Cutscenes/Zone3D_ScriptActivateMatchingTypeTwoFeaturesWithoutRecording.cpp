#include <globaldefs.h>
ARM
extern "C" int Zone3D_GetMainInstance(...);
extern "C" int Script_ReadParameterAsInteger(...);
extern "C" int _ZN12ZoneFeatures14GetTypeEntriesEi(...);
extern "C" int _ZN6Zone3D20ActivateType2FeatureEPN12ZoneFeatures13Opcode6aEntryEbbi(...);
extern "C" int _ZN6Zone3D21FindType2BMDJInstanceEPN12ZoneFeatures13Opcode6aEntryE(...);
extern "C" void* memcpy(void*,const void*,unsigned);extern "C" void* memset(void*,int,unsigned);extern "C" char* strcpy(char*,const char*);extern "C" int sprintf(char*,const char*,...);

#define P(p,o) (*(char**)((char*)(p)+(o)))
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define C(x) ((char*)(x))
// Original: arm9/ov001 @ 0x0215FA40; symbol: ScriptActivateMatchingTypeTwoFeaturesAndFlagInstances.
extern "C" int Zone3D_ScriptActivateMatchingTypeTwoFeaturesWithoutRecording(char*parameters,int count){
int first=Script_ReadParameterAsInteger(parameters);char*secondParameter=parameters+8;parameters+=16;int second=Script_ReadParameterAsInteger(secondParameter);int active=1,visible=1;if(count>2){active=Script_ReadParameterAsInteger(parameters);parameters+=8;}if(count>3)visible=Script_ReadParameterAsInteger(parameters);int zone=Zone3D_GetMainInstance();char*entry=C(_ZN12ZoneFeatures14GetTypeEntriesEi(C(zone)+108,2));while(entry){struct Flags{unsigned short low:4;unsigned short state:12;};Flags*f=(Flags*)(entry+46);unsigned state=f->state;if(!(state&1)&&B(entry,44)==first&&B(entry,45)==second){f->state=state|512;_ZN6Zone3D20ActivateType2FeatureEPN12ZoneFeatures13Opcode6aEntryEbbi(zone,entry,active,visible,0);char*instance=C(_ZN6Zone3D21FindType2BMDJInstanceEPN12ZoneFeatures13Opcode6aEntryE(zone,entry));H(instance,2)|=64;}entry=P(entry,112);}return 1;
}
