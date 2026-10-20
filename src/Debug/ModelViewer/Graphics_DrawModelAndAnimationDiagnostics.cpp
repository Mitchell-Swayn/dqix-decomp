#include <globaldefs.h>
ARM
extern "C" {
unsigned TextContext_GetSharedInstance();int sprintf(char*,const char*,...);void* memset(void*,int,unsigned);void* __clear(void*,unsigned);
void TextMarkup_EncodeTagsAndNewlines(void*,const char*,void*);void TextLayout_ConvertMarkupToCachedGlyphIndices(void*,void*,void*,int);void TextLayout_DrawCachedGlyphRun(void*,void*,int,int,int,int,int,int,int,int);
char* DebugMenu_GetEntryByIndex(char*,int);void* DebugMenu_GetEntryLabel(void*);void* CharacterViewer_FindLoadedAnimation(void*,const char*);
float Graphics_ReadAnimationFixedValue(unsigned char*);float CharacterViewer_GetNormalizedAnimationTime(unsigned char*);void CharacterViewer_DrawModelArenaUsage(unsigned char*);
// Original data: arm9/ov015 @ 0x2194273; symbol: data_ov015_02194273.
// Source-defined character literal. Text: "p\uff3b%s\uff3d". Original zero separators, trailing bytes and padding remain unchanged.
// Initial values: "p\uff3b%s\uff3d".
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov015.md.
extern char Graphics_DrawModelAndAnimationDiagnostics_FormatPFPS2F[],Graphics_DrawModelAndAnimationDiagnostics_FormatPTD[],Graphics_DrawModelAndAnimationDiagnostics_FormatPQD[],GraphicsDrawModelAndAnimationDiagnostics_TextLATINSMALLLETTERPFULLWIDTHLEFTSQUAREBRACKETPERCENTSIGNLATINSMALLLETTERSFULLWIDTHRIGHTSQUAREBRACKET[],Graphics_DrawModelAndAnimationDiagnostics_FormatPSTEP02F[],Graphics_DrawModelAndAnimationDiagnostics_FormatPFRAME02F[],Graphics_DrawModelAndAnimationDiagnostics_FormatPRATE03F[];
}
#define P(p,o) (*(unsigned char**)((p)+(o)))
#define W(p,o) (*(int*)((p)+(o)))
#define U(p,o) (*(unsigned short*)((p)+(o)))
#define H(p,o) (*(short*)((p)+(o)))
#define CONVERT(n) memset(output,0,64);void* state=(void*)TextContext_GetSharedInstance();__clear(converted##n,64);TextMarkup_EncodeTagsAndNewlines(state,text,converted##n);TextLayout_ConvertMarkupToCachedGlyphIndices(state,converted##n,output,0)
#define DRAW(x,y,c) owner[0x19b0]=1;TextLayout_DrawCachedGlyphRun(owner,output+2,x,y,c,8,20,0,1,17)
// Original: arm9/ov015 @ 0x0219050C; symbol: func_ov015_0219050c; size: 0x5C0.
// Displays model counts, selected animation name and fixed-point animation values, with optional allocator diagnostics.
extern "C" void Graphics_DrawModelAndAnimationDiagnostics(unsigned char* self) {
 unsigned char* owner=(unsigned char*)TextContext_GetSharedInstance();
 char text[32];unsigned char output[64];unsigned short converted0[32],converted1[32],converted2[32],converted3[32],converted4[32],converted5[32],converted6[32];
 sprintf(text,Graphics_DrawModelAndAnimationDiagnostics_FormatPFPS2F,(double)*(float*)(self+0x24c));
 {CONVERT(0);DRAW(0,160,0x7fff);}
 unsigned first=0;if(P(self,0x30))first=U(P(self,0x30),0x34);
 sprintf(text,Graphics_DrawModelAndAnimationDiagnostics_FormatPTD,first);
 {CONVERT(1);DRAW(0,170,0x7fff);}
 unsigned second=0;if(P(self,0x30))second=U(P(self,0x30),0x36);
 sprintf(text,Graphics_DrawModelAndAnimationDiagnostics_FormatPQD,second);
 {CONVERT(2);owner[0x19b0]=1;if(second)TextLayout_DrawCachedGlyphRun(owner,output+2,0,180,0x1f,8,20,0,1,17);else TextLayout_DrawCachedGlyphRun(owner,output+2,0,180,0x7fff,8,20,0,1,17);}
 if(W(self,0x194)==1) {
 char* item=DebugMenu_GetEntryByIndex((char*)self+0x2c4,H(P(self,0x30),0x38));if(!item)return;
 void* sub=DebugMenu_GetEntryLabel(item);
 unsigned char* animation=(unsigned char*)CharacterViewer_FindLoadedAnimation(P(self,0x30),(const char*)sub);if(!animation)return;
 sprintf(text,GraphicsDrawModelAndAnimationDiagnostics_TextLATINSMALLLETTERPFULLWIDTHLEFTSQUAREBRACKETPERCENTSIGNLATINSMALLLETTERSFULLWIDTHRIGHTSQUAREBRACKET,animation);
 {CONVERT(3);DRAW(150,150,0x7fff);}
 sprintf(text,Graphics_DrawModelAndAnimationDiagnostics_FormatPSTEP02F,(double)((float)W(animation,0x18)/4096.0f));
 {CONVERT(4);DRAW(160,160,0x7fff);}
 sprintf(text,Graphics_DrawModelAndAnimationDiagnostics_FormatPFRAME02F,(double)Graphics_ReadAnimationFixedValue(P(self,0x30)));
 {CONVERT(5);DRAW(160,170,0x7fff);}
 sprintf(text,Graphics_DrawModelAndAnimationDiagnostics_FormatPRATE03F,(double)CharacterViewer_GetNormalizedAnimationTime(P(self,0x30)));
 {CONVERT(6);DRAW(160,180,0x7fff);}
 }
 if(self[0x1a0] && P(self,0x30))CharacterViewer_DrawModelArenaUsage(P(self,0x30));
}
