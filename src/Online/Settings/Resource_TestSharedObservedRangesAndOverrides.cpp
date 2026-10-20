#include <globaldefs.h>
ARM
extern "C" unsigned char* WfcUtility_GetEditableConnectionProfile();
extern "C" bool WfcUtility_IsValidIpv4LeadingOctet(void*);
extern "C" bool WfcUtility_HasValidIpv4HostBits(void*,void*);
// Original: arm9/ov031 @ 0x02230DF0; symbol: Resource_TestSharedObservedRangesAndOverrides; size: 0xa0.
// Requires shared active flag and observed ranges unless override bytes F5/F6 are set.
extern "C" bool Resource_TestSharedObservedRangesAndOverrides() {
 unsigned char* self=WfcUtility_GetEditableConnectionProfile();if(!self[0x40])return false;
 if(!self[0xf6]&&!WfcUtility_IsValidIpv4LeadingOctet(self+0xc8)&&!WfcUtility_IsValidIpv4LeadingOctet(self+0xcc))return false;
 if(!self[0xf5]){if(!WfcUtility_IsValidIpv4LeadingOctet(self+0xc0))return false;if(!WfcUtility_IsValidIpv4LeadingOctet(self+0xc4))return false;if(!WfcUtility_HasValidIpv4HostBits(self+0xc0,self+0xf0))return false;}return true;
}
