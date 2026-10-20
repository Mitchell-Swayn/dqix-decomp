#include <globaldefs.h>
ARM
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
struct Object;
// Original data: arm9/main @ 0x2108760; symbol: data_02108760.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 208 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char Main_UnknownRoleZeroInitializedStorage[];extern "C" void TextLayout_InitializeSelectionPanel(unsigned char*),Grid_SetOrientationAndCoordinatePointers(unsigned char*,int,int,int),Grid_SetEntryCountAndClampSelection(int*,int),TextLayout_ResetPanelControlCountersAndSetMode(unsigned char*,unsigned char),TextLayout_AppendConvertedLineAndUpdateWidths(char*,void*),TextLayout_ComputeSelectionPanelBounds(Object*,int,short),TextLayout_StartPanelOpening(char*),TextLayout_ShowPanelImmediately(unsigned char*),SoundSfx_StartCurrentSequenceArchiveEntry(char*,int,void*);extern "C" void* ResourceStringTable_GetTextByKey(void*,void*);
#pragma always_inline on
inline void PlacePanel(char* panel,short x,short y){H(panel,0xb4)=x;H(panel,0xb6)=y;TextLayout_ComputeSelectionPanelBounds((Object*)panel,0,-4);}
// Original: arm9/ov013 @ 0x02185990; symbol: func_ov013_02185990; size: 0x11C.
extern "C" void InitializeRightAlignedTwoChoicePanel(char* self){char* panel=self+0x3d4;TextLayout_InitializeSelectionPanel((unsigned char*)panel);B(panel,0xb1)=1;B(panel,0xb0)=1;Grid_SetOrientationAndCoordinatePointers((unsigned char*)panel+0x20,1,2,0);Grid_SetOrientationAndCoordinatePointers((unsigned char*)panel+0x70,1,2,0);Grid_SetEntryCountAndClampSelection((int*)(panel+0x20),2);Grid_SetEntryCountAndClampSelection((int*)(panel+0x70),2);TextLayout_AppendConvertedLineAndUpdateWidths(panel,ResourceStringTable_GetTextByKey(self+0x620,(void*)10));TextLayout_AppendConvertedLineAndUpdateWidths(panel,ResourceStringTable_GetTextByKey(self+0x620,(void*)11));H(panel,0xb4)=194;H(panel,0xb6)=146;TextLayout_ComputeSelectionPanelBounds((Object*)panel,0,-4);B(panel,0x234)=1;TextLayout_ResetPanelControlCountersAndSetMode((unsigned char*)panel+4,1);B(panel,0x233)=1;B(panel,0x234)=1;TextLayout_ResetPanelControlCountersAndSetMode((unsigned char*)panel+4,1);TextLayout_StartPanelOpening(panel);TextLayout_ShowPanelImmediately((unsigned char*)panel);SoundSfx_StartCurrentSequenceArchiveEntry(Main_UnknownRoleZeroInitializedStorage,5,0);PlacePanel(panel,254-S(panel,0xb8),S(panel,0xb6));}
