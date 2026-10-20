#include <globaldefs.h>
ARM
class Panel;
typedef void (Panel::*Callback)();
// Original data: arm9/ov023 @ 0x21fe0f0; symbol: data_ov023_021fe0f0.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 78b51e020000000080c41e0200000000a4ca1e0200000000.
// Observed span: 24 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov023.md.
extern "C" {void* _ZN9GameState11GetInstanceEv();unsigned _ZNK9GameState12GetTickCountEv(void*);int Window_UpdateCanvasesAndSelection(unsigned char*,unsigned);extern Callback MenuUpdateQueuedRecordPanel_UnknownRoleProcedureReferenceRecords[];void Graphics_UpdatePanelCollapseTransition(char*);void Menu_AdvanceQueuedPanelHorizontalSlide(void*);}
// Original: arm9/ov023 @ 0x021EB43C; symbol: AdvancePanelDisplayAndInvokeModeCallback; size: 0x7c.
// Advances display by nonzero ticks, invokes selected member callback and updates panel transitions.
extern "C" void Menu_UpdateQueuedRecordPanel(unsigned char* self) {unsigned ticks=_ZNK9GameState12GetTickCountEv(_ZN9GameState11GetInstanceEv());if(!ticks)ticks=1;if(self[0x431])Window_UpdateCanvasesAndSelection(self+0xc4,ticks);if(MenuUpdateQueuedRecordPanel_UnknownRoleProcedureReferenceRecords[self[0x431]]) {(((Panel*)self)->*MenuUpdateQueuedRecordPanel_UnknownRoleProcedureReferenceRecords[self[0x431]])();Graphics_UpdatePanelCollapseTransition((char*)self);Menu_AdvanceQueuedPanelHorizontalSlide(self);}}
