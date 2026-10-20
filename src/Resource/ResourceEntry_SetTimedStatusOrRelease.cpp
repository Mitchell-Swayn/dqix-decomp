#include <globaldefs.h>
ARM
struct State { char pad[0x1C]; unsigned timer[4]; unsigned char status; };
extern "C" void ResourceEntry_StopHandleAndRelease(State*);
extern "C" void NNSi_SndFaderSet(unsigned*, int, int);
extern "C" void ChangeEntryRankAndReinsertInOwnerList(State*, int);
// Original: arm9/main @ 0x020BC548; symbol: func_020bc548; size: 0x4C.
extern "C" void ResourceEntry_SetTimedStatusOrRelease(State* self, int flag) {
 if (!self || !self->status) return;
 if (!flag) { ResourceEntry_StopHandleAndRelease(self); return; }
 NNSi_SndFaderSet(self->timer, 0, flag);
 ChangeEntryRankAndReinsertInOwnerList(self, 0);
 self->status = 2;
}
