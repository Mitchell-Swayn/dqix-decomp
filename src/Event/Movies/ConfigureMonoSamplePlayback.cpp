#include <globaldefs.h>
ARM
extern "C" void _Z15CleanCacheRangePKvj(const void*,unsigned);
extern "C" void SoundCommand_SubmitOpcodeTwentySix(unsigned,unsigned);
extern "C" void SoundCommand_SubmitPackedPcmChannelSetup(unsigned,unsigned,unsigned,unsigned,unsigned,unsigned,unsigned,unsigned,unsigned,unsigned);
extern "C" void SoundCommand_SubmitOpcodeEighteenWithResolvedValue(unsigned,unsigned,unsigned,unsigned,unsigned);
extern "C" void SoundCommand_SubmitOpcodeTwelve(unsigned,unsigned,unsigned,unsigned);
extern "C" void SoundCommand_FlushPendingBatch(unsigned);
extern "C" void Movie_AdvanceDualScreenAudioPlaybackClock();
// Original data: arm9/ov016 @ 0x219d144; symbol: data_ov016_0219d144.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov016.md.
extern "C" unsigned char MoviePlayDualScreenFiles_UnknownRoleZeroInitializedStorage_Variant2[];
// Original: arm9/ov016 @ 0x0218CF58; symbol: func_ov016_0218cf58; size: 0xDC.
// Configures a mono sample buffer, timer period, and callback through sound commands.
extern "C" void ConfigureMonoSamplePlayback(unsigned rate,unsigned count) {
 unsigned period=0xffb0ff/rate;
 unsigned span=(count>>6)*(period*2);
 _Z15CleanCacheRangePKvj(*(void**)(MoviePlayDualScreenFiles_UnknownRoleZeroInitializedStorage_Variant2+0x2c),(*(unsigned*)(MoviePlayDualScreenFiles_UnknownRoleZeroInitializedStorage_Variant2+0x24)*count)*2);
 SoundCommand_SubmitOpcodeTwentySix(1,0);
 SoundCommand_SubmitPackedPcmChannelSetup(0,1,*(unsigned*)(MoviePlayDualScreenFiles_UnknownRoleZeroInitializedStorage_Variant2+0x2c),1,0,(*(unsigned*)(MoviePlayDualScreenFiles_UnknownRoleZeroInitializedStorage_Variant2+0x24)*count)>>1,127,0,period,64);
 SoundCommand_SubmitOpcodeEighteenWithResolvedValue(0,span,span,(unsigned)Movie_AdvanceDualScreenAudioPlaybackClock,0);
 SoundCommand_SubmitOpcodeTwelve(1,0,1,0);
 SoundCommand_FlushPendingBatch(1);
}
