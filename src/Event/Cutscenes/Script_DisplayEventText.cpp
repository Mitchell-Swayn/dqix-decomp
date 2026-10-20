#include <globaldefs.h>
ARM
#include <std_library_functions.h>
#define U(p,o) (*(unsigned*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define S(p,o) (*(signed char*)((char*)(p)+(o)))
extern "C" unsigned Script_ReadParameterString(...);
extern "C" unsigned Script_ReadParameterAsInteger(...);
extern "C" unsigned TextContext_GetSharedInstance(...);
extern "C" unsigned TextWindow_StartFormattedMessage(...);
extern "C" unsigned Script_FindTextTableEntry(...);
// Original data: arm9/ov001 @ 0x21658d8; symbol: data_ov001_021658d8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov001.md.
extern "C" unsigned char ScriptDisplayEventText_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov001 @ 0x0215e2a4; symbol: DisplayScriptTextParameterByKind.
extern "C" int Script_DisplayEventText(char* p,int count){char* owner=(char*)TextContext_GetSharedInstance();switch(U(p,0)){case 0:{int id=Script_ReadParameterAsInteger(p);char* record=(char*)Script_FindTextTableEntry(ScriptDisplayEventText_UnknownRoleZeroInitializedStorage,id);if(!record)return 0;U(owner,0x1838)=-1;int mode=1;if(count>=2){if(Script_ReadParameterAsInteger(p+8)&1)mode=0;}TextWindow_StartFormattedMessage(owner,U(record,4),mode,0xe3);U(owner,0x998)=1;break;}case 2:{unsigned text=Script_ReadParameterString(p);U(owner,0x1838)=-1;TextWindow_StartFormattedMessage(owner,text,1,0xe3);U(owner,0x998)=1;break;}}return 1;}
