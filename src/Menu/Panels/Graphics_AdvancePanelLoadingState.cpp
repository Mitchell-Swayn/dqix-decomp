struct WindowCanvasOwner;
struct WindowCanvasRecord;
#include <globaldefs.h>
#include <std_library_functions.h>
ARM
#include <GameState/GameState.h>
struct State{char pad[0x98];void* a;void* b;char gap[0x13];unsigned char mode;};
struct Record { char pad[0xc4]; unsigned char id; char rest[0x1b]; };
struct Owner { char pad[0x98]; void* ready; Record* records; char pad2[0x13]; unsigned char count,stop; };
extern "C" void Window_PopCanvasesAndResetSelection(State*,int);
extern "C" void PartyGrowthPanel_AppendStatComparisonRows(void*,void*,unsigned);
extern "C" void PartyGrowthPanel_OpenCenteredWindow(void*,void*,int,int);
extern "C" WindowCanvasRecord* Window_FindActiveCanvasById(WindowCanvasOwner*,unsigned);
extern "C" int Window_ReplaceCanvasTextById(Owner*,unsigned,void*,unsigned,unsigned char);
// Original: arm9/ov023 @ 0x021D90D0; symbol: func_ov023_021d90d0; size: 0x14C.
// Advances the panel-loading state, prepares each buffer stage, and loads a ready record when its delay expires.
extern "C" void Graphics_AdvancePanelLoadingState(char* self) {
    unsigned ticks = GameState::GetInstance()->GetTickCount();
    if (!ticks) ticks = 1;

    unsigned char state = *(unsigned char*)(self + 0x11c);
    if (state == 0) {
        Window_PopCanvasesAndResetSelection((State*)(self + 0x20), 1);
        ++*(unsigned char*)(self + 0x11c);
        return;
    }

    if (state == 1) {
        *(unsigned char*)(self + 0x118) = 0;
        *(unsigned char*)(self + 0x11d) = 5;
        memset(*(void**)(self + 4), 0, 0x960);
        PartyGrowthPanel_AppendStatComparisonRows(self, *(void**)(self + 4), *(unsigned char*)(self + 0x118));
        PartyGrowthPanel_OpenCenteredWindow(self, *(void**)(self + 4), 0x1a, 0x14);
        ++*(unsigned char*)(self + 0x11c);
        return;
    }

    if (state != 2) return;
    if (*(signed char*)(self + 0x11d) > 0) {
        *(unsigned char*)(self + 0x11d) = (unsigned char)(*(signed char*)(self + 0x11d) - (signed char)ticks);
        return;
    }

    *(unsigned char*)(self + 0x11d) = 5;
    ++*(unsigned char*)(self + 0x118);
    memset(*(void**)(self + 4), 0, 0x960);
    PartyGrowthPanel_AppendStatComparisonRows(self, *(void**)(self + 4), *(unsigned char*)(self + 0x118));

    Owner* records = (Owner*)(self + 0x20);
    Record* record = (Record*)Window_FindActiveCanvasById((WindowCanvasOwner*)(records), 0);
    if (record) {
        ((unsigned char*)record)[0xd8] |= 4;
        Window_ReplaceCanvasTextById(records, 0, *(void**)(self + 4), 1, 0);
        ((unsigned char*)record)[0xd8] &= ~4;
    }

    if (*(unsigned char*)(self + 0x118) == 9) ++*(unsigned char*)(self + 0x11c);
}
