#include <globaldefs.h>
ARM
extern "C" void *SpriteResources_GetCellByIndex(void *, int);
extern "C" void Graphics_SubmitTransformedCellToOam(void *, void *);
// Original data: arm9/ov003 @ 0x217fa14; symbol: data_ov003_0217fa14.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 0b0a09081600000000000000.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov003.md.
extern "C" signed char TagModeDrawCenteredNoticeLabels_UnknownRoleInitializedBytes[];
// Original: arm9/ov003 @ 0x02173BD8; symbol: Resource_ConfigureIndexedObjectEffectRecord; size: 0x68.
// For active object mode and index 0–3, resolves the indexed record, sets its fixed-point fields, and configures it against object+0x130.
extern "C" void Resource_ConfigureIndexedObjectEffectRecord(void *object) {
 unsigned char mode = *((unsigned char *)object + 0xec);
 if (!mode) return;
 if (mode == 1 && *((unsigned char *)object + 0xee) < 2) return;
 unsigned char index = *((unsigned char *)object + 0xd4);
 if (index > 3) return;
 void *record = SpriteResources_GetCellByIndex((char *)object + 0x130, TagModeDrawCenteredNoticeLabels_UnknownRoleInitializedBytes[index]);
 *(unsigned int *)((char *)record + 0x14) = 0xb8000;
 *(unsigned int *)((char *)record + 0x18) = 0x2f000;
 Graphics_SubmitTransformedCellToOam((char *)object + 0x130, record);
}
