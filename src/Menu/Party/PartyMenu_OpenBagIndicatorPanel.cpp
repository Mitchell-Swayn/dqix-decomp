struct PartyMenuState;
#include <globaldefs.h>
ARM
#include <std_library_functions.h>
#define U(p,o) (*(unsigned*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define S(p,o) (*(signed char*)((char*)(p)+(o)))
extern "C" unsigned Window_SetCanvasEnabled(...);
extern "C" unsigned Window_UpdateCanvasesAndSelection(...);
extern "C" unsigned TextMarkup_ExpandAndWrapText(...);
extern "C" unsigned TextContext_GetSharedInstance(...);
extern "C" unsigned TextMarkup_AppendLineTag(...);
extern "C" unsigned Window_PushTextCanvas(...);
extern "C" void PartyMenu_ConfigurePanelLayout(PartyMenuState*,int,int,int);
// Original data: arm9/ov002 @ 0x216d26c; symbol: data_ov002_0216d26c.
// Source-defined character literal. Text: " ". Original zero separators, trailing bytes and padding remain unchanged.
// Initial values: " ".
// Observed span: 2 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov002.md.
extern "C" unsigned char PartyMenuOpenBagIndicatorPanel_TextSPACE[];
// Original: arm9/ov002 @ 0x0215c028; symbol: FormatAndRefreshIndexedTextPanel.
extern "C" void PartyMenu_OpenBagIndicatorPanel(char* p){PartyMenu_ConfigurePanelLayout((PartyMenuState*)(p),40,21,19);void* formatter=(void*)TextContext_GetSharedInstance();memset((void*)U(p,0x1bd0),0,0x960);TextMarkup_ExpandAndWrapText(formatter,8,PartyMenuOpenBagIndicatorPanel_TextSPACE,U(p,0x1bd0),256,0,0);TextMarkup_AppendLineTag(U(p,0x1bd0),17);Window_PushTextCanvas(p+0xec8,U(p,0x1bd0),0,0,0,1,0,0);Window_UpdateCanvasesAndSelection(p+0xec8,4);Window_SetCanvasEnabled(p+0xec8,0,40);}
