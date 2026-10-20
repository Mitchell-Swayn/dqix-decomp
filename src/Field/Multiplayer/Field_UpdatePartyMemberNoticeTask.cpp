#include <globaldefs.h>
ARM
extern "C" int BackgroundLoader_RemoveObjectTaskAndResetLoadFields(...);
extern "C" int TextLayout_ResetFormattingWorkspace(...);
extern "C" int GameResources_GetInstance(...);
extern "C" int GameState_BuildTwelveByteDescriptorForPartyMember(...);
extern "C" int Text_LookupStandardString(...);
extern "C" int GameObject_DisableMovementInput(...);
extern "C" int TextContext_GetSharedInstance(...);
extern "C" int GameObject_RequestMovementInputEnable(...);
extern "C" int _ZN9GameState11GetInstanceEv(...);
extern "C" int _ZN9GameState20GetUnknownGameObjectEv(...);
extern "C" int _ZN9GameState21GetPartyMemberByIndexEi(...);
extern "C" int TextWindow_StartFormattedMessage(...);
extern "C" void* memcpy(void*,const void*,unsigned);extern "C" void* memset(void*,int,unsigned);extern "C" char* strcpy(char*,const char*);extern "C" int sprintf(char*,const char*,...);

#define P(p,o) (*(char**)((char*)(p)+(o)))
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define C(x) ((char*)(x))
// Original: arm9/ov017 @ 0x021C3194; symbol: AdvancePartyMemberMessageUntilDismissed.
extern "C" void Field_UpdatePartyMemberNoticeTask(char*self){
int state=_ZN9GameState11GetInstanceEv();GameResources_GetInstance();int actor=_ZN9GameState20GetUnknownGameObjectEv(state);int member=_ZN9GameState21GetPartyMemberByIndexEi(state,B(self,9));char*owner=C(TextContext_GetSharedInstance());if(!member)B(self,8)=2;if(B(self,8)==0){if(actor){BackgroundLoader_RemoveObjectTaskAndResetLoadFields(actor);GameObject_DisableMovementInput(actor,1);}TextLayout_ResetFormattingWorkspace(owner);char*buffer=P(owner,92);sprintf(buffer,(const char*)Text_LookupStandardString(37));char descriptor[12];GameState_BuildTwelveByteDescriptorForPartyMember(descriptor,B(self,9));P(owner,16)=descriptor;TextWindow_StartFormattedMessage(owner,buffer,0,227);B(owner+0x1000,0x9b2)=0;W(owner,2456)=1;B(self,8)=1;}else if(B(self,8)==1){if(!W(owner,2456))B(self,8)=2;}else if(B(self,8)==2){GameObject_RequestMovementInputEnable(actor);B(self,1)=1;}
}
