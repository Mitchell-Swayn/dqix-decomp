#include <globaldefs.h>
ARM
extern "C" void *Zone3D_GetMainInstance(void);
extern "C" void Field_QueuePartyActionAndNotifyConnection(void *, unsigned int);
extern "C" void Field_RemoveAlternateStatusMembersAndResetPartyAction(void *);
// Original: arm9/ov017 @ 0x021CE458; symbol: World_DispatchRecordByGlobalKey; size: 0x3C.
// Compares record halfword+6 with the global key and dispatches using halfword+4 or fallback.
extern "C" void Field_DispatchZoneMatchedPartySceneRequest(void *unused0, void *record, void *unused2, void *context) {
 unsigned short *global = (unsigned short *)Zone3D_GetMainInstance();
 unsigned short key = *(unsigned short *)((char *)record + 6);
 if (key == *global)
  Field_QueuePartyActionAndNotifyConnection(context, *(unsigned short *)((char *)record + 4));
 else
  Field_RemoveAlternateStatusMembersAndResetPartyAction(context);
}
