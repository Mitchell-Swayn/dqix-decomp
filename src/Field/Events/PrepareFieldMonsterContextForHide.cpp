#include <globaldefs.h>
ARM
extern "C" void FieldBattle_ReleaseSceneAndRestoreField(void *);
// Original: arm9/ov017 @ 0x021B8B6C; symbol: PrepareFieldMonsterContextForHide; size: 0x28.
// When field +0x6B4 equals one, resets the field-monster context and sets record byte +1; its caller is the hide-by-record-identifier routine.
extern "C" void PrepareFieldMonsterContextForHide(unsigned char *p) {
    if (*(unsigned short *)(p + 0x6b4) != 1) return;
    FieldBattle_ReleaseSceneAndRestoreField(p);
    p[1] = 1;
}
