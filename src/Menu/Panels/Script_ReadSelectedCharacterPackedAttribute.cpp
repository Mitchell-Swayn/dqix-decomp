#include <globaldefs.h>
ARM
struct IntegerParameterView;
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" int Script_ReadParameterAsInteger(IntegerParameterView*);
extern "C" void Script_WriteIntegerReferenceOutput(void*,int);
extern "C" char* Script_ResolveCharacterFromSignedSelector(int);
struct Packed {unsigned first:10,second:10,third:10,pad:2;};
// Original: arm9/ov023 @ 0x021E94CC; symbol: func_ov023_021e94cc; size: 0x1DC.
extern "C" int Script_ReadSelectedCharacterPackedAttribute(char* params) {
 _ZN9GameState11GetInstanceEv();
 char* character=Script_ResolveCharacterFromSignedSelector(Script_ReadParameterAsInteger((IntegerParameterView*)params));
 if(!character)return 0;
 switch(Script_ReadParameterAsInteger((IntegerParameterView*)(params+8))) {
 case 0: Script_WriteIntegerReferenceOutput(params+16,(unsigned short)((*(Packed**)(character+0x150))[0].first)); break;
 case 1: Script_WriteIntegerReferenceOutput(params+16,(unsigned short)((*(Packed**)(character+0x150))[0].second)); break;
 case 2: Script_WriteIntegerReferenceOutput(params+16,(unsigned short)((*(Packed**)(character+0x150))[0].third)); break;
 case 3: Script_WriteIntegerReferenceOutput(params+16,(unsigned short)((*(Packed**)(character+0x150))[1].first)); break;
 case 4: Script_WriteIntegerReferenceOutput(params+16,(unsigned short)((*(Packed**)(character+0x150))[1].second)); break;
 case 5: Script_WriteIntegerReferenceOutput(params+16,(unsigned short)((*(Packed**)(character+0x150))[1].third)); break;
 case 6: Script_WriteIntegerReferenceOutput(params+16,(unsigned short)((*(Packed**)(character+0x150))[2].first)); break;
 case 7: Script_WriteIntegerReferenceOutput(params+16,*(unsigned short*)(*(char**)(character+0x134)+48)); break;
 case 8: Script_WriteIntegerReferenceOutput(params+16,*(unsigned short*)(*(char**)(character+0x134)+50)); break;
 case 9: Script_WriteIntegerReferenceOutput(params+16,*(unsigned short*)(*(char**)(character+0x134)+52)); break;
 case 10: Script_WriteIntegerReferenceOutput(params+16,*(unsigned short*)(*(char**)(character+0x134)+54)); break;
 case 11: Script_WriteIntegerReferenceOutput(params+16,(unsigned short)((*(Packed**)(character+0x150))[3].first));break;
 }
 return 1;
}
