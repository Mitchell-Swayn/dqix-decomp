#include <globaldefs.h>
struct Fields { char prefix[0x1cc]; unsigned char active; char pad[7]; unsigned mainBanks,subBanks; };
struct GlobalState { char pad[0x998]; unsigned field998,field99c,field9a0; };
extern "C" void* Resource_GetSharedLoadState();
extern "C" unsigned Menu_ReadScriptArgumentAsInteger(void*);
extern "C" void* Menu_GetDisplayRecordRegistry(void*);
extern "C" void Menu_WriteScriptIntegerReference(void*, unsigned);
extern "C" void* MenuRecordList_LocateByKey(void*,unsigned);
extern "C" unsigned MenuRecord_GetType();
extern "C" void Menu_SetActiveSelectionGrid(void*,unsigned);
extern "C" void Menu_SetBackgroundLoadTicket(void*,unsigned);
extern "C" unsigned Menu_GetBackgroundLoadTicket(void*);
extern "C" void Menu_SetReferencedDisplayRecordId(void*,unsigned);
extern "C" void Menu_SetChoiceResultCallbacks(void*,unsigned,unsigned);
extern "C" void Menu_SetChoiceResultScriptEntries(void*,unsigned,unsigned);
extern "C" GlobalState* TextContext_GetSharedInstance();
extern "C" void TextWindow_ResetGlyphBuffersAndFrameContexts();
extern "C" void Graphics_ClearAndStageSharedBuffers(void*);
extern "C" unsigned TextWindow_GetChoiceResult(void*);
extern "C" void* GameResources_GetInstance();
extern "C" unsigned _Z28IsBrightnessTransitionActiveP13GameResources(void*);
extern "C" void MenuRecordList_ResetInputGroup(void*,unsigned);
extern "C" unsigned MenuRecordList_HasPendingLoads(void*);
extern "C" void _ZN23ZoneContainerRenderPart12ResetIfFlag0Ev(void*);
extern "C" void _ZN21ZoneRenderPartEntries5ResetEv(void*);
extern "C" void MapVRAMBanksToMainBG(unsigned);
extern "C" void MapVRAMBanksToSubBG(unsigned);
extern "C" void* _ZN16BackgroundLoader11GetInstanceEv();
extern "C" void _ZN16BackgroundLoader10RemoveTaskEi(void*,unsigned);
extern "C" unsigned _ZN16BackgroundLoader13GetTaskStatusEi(void*,unsigned);
extern "C" void MenuTextCanvas_ResetLayoutAndDisplayFlags(void*);
extern "C" void Memory_ZeroBufferUsingElementCountAndStride(void*);
// Original: arm9/ov011 @ 0x02187F04; symbol: func_ov011_02187f04; size: 0x34.
extern "C" unsigned Menu_SetChoiceResultScriptDispatchIndices(void* self) { unsigned first=Menu_ReadScriptArgumentAsInteger(self); unsigned second=Menu_ReadScriptArgumentAsInteger((char*)self+8); Menu_SetChoiceResultScriptEntries(Resource_GetSharedLoadState(),first,second); return 1; }
