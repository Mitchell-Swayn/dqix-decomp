#include <globaldefs.h>
#include <GameState/GameState.h>
#include <World/Zone3DEmbeddedState.h>
#include <std_library_functions.h>
ARM
#pragma opt_common_subs off
struct PackedObjectValue {unsigned low:10,middle:10,high:10,unknown:2;};
struct Descriptor {unsigned words[2];unsigned unknown:24,kind:2,rest:6;};
struct PackedSelection {unsigned identity:12,unknown:20;};
typedef unsigned int undefined4; // Exact owner-local alias in GameObject_GetLinkedIndexedState.cpp.
extern "C" GameObject* GameState_GetObjectWithFlag100(GameState*,int);
extern "C" unsigned GameState_ReadSupportedFirmwareLanguage(GameState*);
extern "C" unsigned GameObject_GetLinkedIndexedState(int);
extern "C" unsigned TextContext_GetSharedInstance();
extern "C" void TextLayout_ResetFormattingWorkspace(signed char*);
extern "C" void GameState_BuildTwelveByteDescriptorForPartyMember(void*,int);
extern "C" void* ZoneState2754_FindPrimaryRecordByKey(ZoneState2754*,int);
extern "C" int Graphics_SelectObjectRatioColor(char*,int,int,int,unsigned char);
extern "C" void* ResourceStringTable_GetTextByKey(void*,void*);
extern "C" void TextContext_SetNumericArgument(unsigned*,int,unsigned);
extern "C" void TextMarkup_ExpandAndWrapText(void*,int,void*,void*,int,int,unsigned);
extern "C" unsigned char PartyMenuFormatActionTargetStatus_UnknownRoleInitializedBytes[],PartyMenuFormatActionTargetStatus_UnknownRoleInitializedBytes_Variant2[];
extern "C" char PartyMenu_FormatActionTargetStatus_TextXY[],PartyMenuFormatActionTargetStatus_TextD[];
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define W(p,o) (*(unsigned*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
// Original: arm9/ov002 @ 0x0215D214; symbol: PartyMenu_FormatActionTargetStatus; size: 0x440.
// Formats selected object values and a language-dependent suffix, then expands owner text.
// Field and message identifiers retain observed numeric meanings.
extern "C" void PartyMenu_FormatActionTargetStatus(char* self,char* output) {
 if(!output)return;
 GameState* state=GameState::GetInstance();
 S(self,0x1c26)=-1;
 unsigned char* indices=(unsigned char*)self+0x1c68;
 int selected=S(self,0x1bfa);
 if(selected>=0&&selected<32)S(self,0x1c26)=((PackedSelection*)(*(char**)(self+0x24a0+selected*4)+4))->identity;
 if(S(self,0x1c26)<0&&B(self,0x1c84)==7)indices=(unsigned char*)self+0x1c6e;
 int index=indices[S(self,0x1bec)];
 GameObject* object=GameState_GetObjectWithFlag100(state,index);
 if(!object)return;
 char* stats=(char*)GameObject_GetLinkedIndexedState((int)object);
 if(!stats)return;
 char* record=0;
 if(S(self,0x1c26)<0){record=(char*)ZoneState2754_FindPrimaryRecordByKey((ZoneState2754*)(self+0x7ec),S(self,0x1c22));if(!record)return;}
 unsigned* owner=(unsigned*)TextContext_GetSharedInstance();
 TextLayout_ResetFormattingWorkspace((signed char*)owner);
 Descriptor descriptor;GameState_BuildTwelveByteDescriptorForPartyMember(&descriptor,index);
 *owner=(unsigned)&descriptor;
 char* current=P(object,0x130);char* maximum=P(object,0x134);
 int message=0x4ba;unsigned first=H(current,4),second=H(maximum,0x30);int special=1;
 if(record){
  switch(S(record,0x18)){
  case 0x55ff:case 0x5600:case 0x5601:special=0;
  case 0x561e:first=H(current,6);second=H(maximum,0x32);message=0x4bb;break;
  case 0x561f:first=((PackedObjectValue*)stats)[0].low;message=0x1103;break;
  case 0x5622:first=((PackedObjectValue*)stats)[0].high;message=0x1104;break;
  case 0x5621:first=((PackedObjectValue*)stats)[0].middle;message=0x1105;break;
  case 0x5619:first=((PackedObjectValue*)stats)[1].middle;message=0x1106;break;
  case 0x5620:first=((PackedObjectValue*)stats)[1].low;message=0x1107;break;
  case 0x5623:first=((PackedObjectValue*)stats)[2].low;message=0x1108;break;
  case 0x5624:first=((PackedObjectValue*)stats)[1].high;message=0x1109;break;
  case 0x5625:first=H(stats,0x564);message=0x110a;break;
  case 0x561d:break;
  default:special=0;break;
  }
 }else if(S(self,0x1c26)>=0)special=0;
 int ratio=Graphics_SelectObjectRatioColor(self,index,1,1,1);
 int color=15;unsigned suffix=0;
 if(!special){
  int selector=-1;unsigned flags=W(P(object,0x130),0);
  if(flags&1){selector=2;message=0x110d;color=9;}
  else if(flags&2){selector=0;message=0x110b;color=12;}
  else if(flags&4){selector=1;message=0x110c;color=ratio;}
  if(selector>=0){
   unsigned language=GameState_ReadSupportedFirmwareLanguage(GameState::GetInstance());
   for(int i=0;i<5;++i)if(language==PartyMenuFormatActionTargetStatus_UnknownRoleInitializedBytes[i*7]){suffix=(PartyMenuFormatActionTargetStatus_UnknownRoleInitializedBytes_Variant2+i*7+descriptor.kind)[selector*2];break;}
  }
 }
 if(ratio==3)color=3;
 char text[512];sprintf(text,(char*)ResourceStringTable_GetTextByKey(self+0x20,(void*)message),color,ratio);
 if(suffix){char* token=strstr(text,PartyMenu_FormatActionTargetStatus_TextXY);if(token){char replacement[4];sprintf(replacement,PartyMenuFormatActionTargetStatus_TextD,suffix);memcpy(token+4,replacement,2);}}
 TextContext_SetNumericArgument(owner,0,first);
 TextContext_SetNumericArgument(owner,1,second);
 TextMarkup_ExpandAndWrapText(owner,10,text,output,256,0,0);
}
