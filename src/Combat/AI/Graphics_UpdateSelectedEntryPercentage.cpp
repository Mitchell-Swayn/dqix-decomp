#include <globaldefs.h>
ARM
struct SourceFlags {unsigned pad:3;signed state:3;unsigned rest:26;};
struct Config {unsigned char pad[0x14];unsigned low:7;unsigned value:7;unsigned rest:18;unsigned char pad2[0x1a];short index;};
extern "C" void BattleAI_CacheActionPolicyEntry(void*,int);
extern "C" void SubmitPercentScaledDisplayRecord(void*,float,int);
extern "C" void Effect_ApplyMagnitudeAndChannelSetting(void*,int);
// Original: arm9/ov024 @ 0x021FD504; symbol: func_ov024_021fd504; size: 0xBC.
extern "C" void Graphics_UpdateSelectedEntryPercentage(unsigned char* p){
 unsigned char* source=*(unsigned char**)(*(unsigned char**)(p+0x668)+0x138);
 if(((SourceFlags*)(source+0x58))->state<=-2)return;
 unsigned count=source[0x50];
 if(!count)return;
 if(p[0x661]){
 Config* config=*(Config**)(p+0x64c);
 float value=(float)config->value*((float)count/100.0f);
 if(value>100.0f)value=100.0f;
 if(config->index>=0)return;
 BattleAI_CacheActionPolicyEntry(p,13);
 SubmitPercentScaledDisplayRecord(p,value,18);
 }else Effect_ApplyMagnitudeAndChannelSetting(p,18);
}
