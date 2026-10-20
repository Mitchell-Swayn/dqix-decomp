struct WindowCanvasOwner;
struct WindowCanvasRecord;
#include <globaldefs.h>
ARM
extern "C" WindowCanvasRecord* Window_FindActiveCanvasById(WindowCanvasOwner*,unsigned);
extern "C" int Window_ReplaceCanvasTextById(...);
extern "C" void memset(...);
extern "C" void Text_AppendIndexedRecordList(...);
extern "C" void Church_FormatPartyStatusList(...);
extern "C" void Graphics_AppendTwoIndexedLabelsWithCursor(...);
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define U(p,o) (*(unsigned*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
// Original: arm9/ov003 @ 0x0215C01C; symbol: Graphics_UpdateReadyTextRecordAndPrefix; size: 0xd0.
// Toggles record flag40, builds one of three indexed texts with optional prefix, and refreshes ready record.
extern "C" void Church_SetWindowEmphasisAndRefreshText(char* self,int id,int enabled){char* record=(char*)Window_FindActiveCanvasById((WindowCanvasOwner*)(self+0xf4),id);if(!record)return;if(enabled)B(record,0xc5)|=64;else B(record,0xc5)&=~64;int prefix=0;if(B(record,0xc5)&2)prefix=1;memset(P(self,0x7c),0,2400);switch(id){case 1:Text_AppendIndexedRecordList(self,P(self,0x7c),prefix);break;case 2:Church_FormatPartyStatusList(self,P(self,0x7c),prefix);break;case 3:Graphics_AppendTwoIndexedLabelsWithCursor(self,P(self,0x7c),prefix);break;}Window_ReplaceCanvasTextById(self+0xf4,id,P(self,0x7c),1,0);}
