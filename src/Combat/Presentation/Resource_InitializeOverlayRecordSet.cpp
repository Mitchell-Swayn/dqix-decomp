#include <globaldefs.h>
ARM
extern "C" void Combat_ResetTimedPresentationRecord(void *);
extern "C" unsigned int BattleScene_GetActiveInstance(void *);
extern "C" void Resource_ResetPendingAndStatusFields(void *);
extern "C" void BattleScene_ResetTargetResultPresentation(unsigned char *);
// Original: arm9/ov025 @ 0x021EBAB4; symbol: Resource_InitializeOverlayRecordSet; size: 0x70.
// Initializes twelve 0x40-byte records, clears status fields, reads the second overlay control word, resets pending state and fills the selected control record.
extern "C" void Resource_InitializeOverlayRecordSet(void *object) {
 for (int i = 0; i < 12; ++i) Combat_ResetTimedPresentationRecord((char *)object + i * 0x40);
 *(unsigned char *)((char *)object + 0x300) = 0;
 *(unsigned short *)((char *)object + 0x302) = 0;
 *(unsigned short *)((char *)object + 0x304) = 0;
 *(unsigned char *)((char *)object + 0x301) = 0;
 *(unsigned char *)((char *)object + 0x306) = 0;
 void *control = (void *)BattleScene_GetActiveInstance((char *)object + 0x300);
 Resource_ResetPendingAndStatusFields(control);
 BattleScene_ResetTargetResultPresentation((unsigned char *)control);
 *(unsigned int *)((char *)object + 0x308) = 0;
 *(unsigned int *)((char *)object + 0x30c) = 0;
 *(unsigned char *)((char *)object + 0x310) = 1;
 *(unsigned char *)((char *)object + 0x311) = 0;
}
