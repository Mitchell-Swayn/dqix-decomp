#include <globaldefs.h>
ARM
extern "C" void* memset(void*,int,unsigned);
extern "C" void TextSprite_ReleaseCachedText(void*);
extern "C" int BattleMenu_HasCommandBlockingStatus(void*);
extern "C" void __clear(void*,unsigned);
extern "C" int Graphics_FormatPriorityFlaggedPartyLabel(void*,char*);
extern "C" void TextSprite_FormatAndUpdateTextReference(void*,const char*);
extern "C" void BattleMenu_RefreshUncontrolledMemberLabel(void*);
// Original: arm9/ov000 @ 0x0217F518; symbol: ResetSelectionSentinelsAndSubmitOptionalLabel; size: 0xb8.
extern "C" void BattleMenu_ResetPartyCommandSelection(char* self) {
 memset(self+16,0,8);self[16]=13;self[24]=0;self[28]=0;self[29]=-1;self[32]=-1;*(short*)(self+30)=-1;self[34]=-1;self[33]=-1;*(short*)(self+44)=-1;self[46]=-1;*(short*)(self+38)=0;TextSprite_ReleaseCachedText(self+80);self[0x43d]=-1;
 if(BattleMenu_HasCommandBlockingStatus(self)){char label[128];__clear(label,128);if(Graphics_FormatPriorityFlaggedPartyLabel(self,label)>=0)TextSprite_FormatAndUpdateTextReference(self+80,label);self[16]=100;}BattleMenu_RefreshUncontrolledMemberLabel(self);
}
