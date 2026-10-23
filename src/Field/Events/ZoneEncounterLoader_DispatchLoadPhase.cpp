#include <globaldefs.h>
ARM
typedef void (*LoadPhase)(unsigned char*);
struct PhaseTable { LoadPhase entries[9]; };
// Original data: arm9/ov017 @ 0x021D6BD8; symbol: data_ov017_021d6bd8.
extern "C" const PhaseTable ZoneEncounterLoaderDispatchLoadPhase_UnknownRoleProcedureReferenceRecords;
// Original: arm9/ov017 @ 0x021B4710; symbol: func_ov017_021b4710; size: 0x50.
// Copies the phase procedure table and invokes the current loading phase.
extern "C" void ZoneEncounterLoader_DispatchLoadPhase(unsigned char* self) {
    PhaseTable phases = ZoneEncounterLoaderDispatchLoadPhase_UnknownRoleProcedureReferenceRecords;
    phases.entries[self[0x10]](self);
}
