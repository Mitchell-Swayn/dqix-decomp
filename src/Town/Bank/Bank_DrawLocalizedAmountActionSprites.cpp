struct WindowCanvasOwner;
struct WindowCanvasRecord;
#include <globaldefs.h>
ARM
#define W(p,o) (*(int*)((p)+(o)))
#define P(p,o) (*(unsigned char**)((p)+(o)))
#define H(p,o) (*(short*)((p)+(o)))
#define U(p,o) (*(unsigned short*)((p)+(o)))
// Original data: arm9/ov003 @ 0x217f530; symbol: data_ov003_0217f530.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 01.
// Observed span: 1 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov003.md.
// Original data: arm9/ov003 @ 0x217f531; symbol: data_ov003_0217f531.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 06.
// Observed span: 1 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov003.md.
// Original data: arm9/ov003 @ 0x217f532; symbol: data_ov003_0217f532.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 90.
// Observed span: 1 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov003.md.
// Original data: arm9/ov003 @ 0x217f533; symbol: data_ov003_0217f533.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex c6020892c5030c9acb040a8dc3050e8cc2.
// Observed span: 17 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov003.md.
extern "C" {WindowCanvasRecord* Window_FindActiveCanvasById(WindowCanvasOwner*,unsigned);int TextCanvas_IsReady(void*);void* _ZN9GameState11GetInstanceEv();int GameState_ReadSupportedFirmwareLanguage(void*);void Graphics_SubmitTransformedCellToOam(void*,void*);extern unsigned char BankDrawLocalizedAmountActionSprites_UnknownRoleInitializedBytes[],BankDrawLocalizedAmountActionSprites_UnknownRoleInitializedBytes_Variant2[],BankDrawLocalizedAmountActionSprites_UnknownRoleInitializedBytes_Variant3[],BankDrawLocalizedAmountActionSprites_UnknownRoleInitializedBytes_Variant4[];}
// Original: arm9/ov003 @ 0x0216A880; symbol: Graphics_PositionLanguageSpecificRecordPair; size: 0xf4.
// Positions two indexed graphics records using firmware-language coordinate bytes.
extern "C" void Bank_DrawLocalizedAmountActionSprites(unsigned char* self){void* record=(void*)Window_FindActiveCanvasById((WindowCanvasOwner*)(self+0xe4),2);if(!record||!TextCanvas_IsReady(record))return;int language=GameState_ReadSupportedFirmwareLanguage(_ZN9GameState11GetInstanceEv());int x1=0x90000,x2=0xc6000,index=6;for(int i=0;i<5;++i){if(language==BankDrawLocalizedAmountActionSprites_UnknownRoleInitializedBytes[i*4]){x1=BankDrawLocalizedAmountActionSprites_UnknownRoleInitializedBytes_Variant3[i*4]<<12;int next=BankDrawLocalizedAmountActionSprites_UnknownRoleInitializedBytes_Variant4[i*4];index=BankDrawLocalizedAmountActionSprites_UnknownRoleInitializedBytes_Variant2[i*4];x2=next<<12;break;}}int offset=index*40;unsigned char* first=P(self,0x4d4)+offset;W(first,20)=x1;W(first,24)=0x61000;Graphics_SubmitTransformedCellToOam(self+0x480,P(self,0x4d4)+offset);offset=(index+1)*40;unsigned char* second=P(self,0x4d4)+offset;W(second,20)=x2;W(second,24)=0x61000;Graphics_SubmitTransformedCellToOam(self+0x480,P(self,0x4d4)+offset);}
