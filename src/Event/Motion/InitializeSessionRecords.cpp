#include <globaldefs.h>
ARM
extern "C" void CutsceneActor_InitializeCommandSession(void*);
extern "C" void Ov001_InitializeSessionRecord(void*);
struct SessionSetup { void* records; int count; unsigned char pad[0x88]; unsigned limit; };
// Original: arm9/ov001 @ 0x02159D44; symbol: func_ov001_02159d44; size: 0x58.
extern "C" void InitializeSessionRecords(SessionSetup* setup, void* records, int count) {
    setup->records = records;
    setup->count = count;
    CutsceneActor_InitializeCommandSession(setup);
    if (setup->records != 0 && setup->count > 0) {
        for (int i = 0; i < setup->count; ++i)
            Ov001_InitializeSessionRecord((char*)setup->records + i * 0x40);
    }
    setup->limit = 0x1000;
}
