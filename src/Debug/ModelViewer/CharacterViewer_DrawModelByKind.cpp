#include <globaldefs.h>
ARM
extern "C" void CharacterViewer_DrawPlayerModelParts(void *object);
extern "C" void Graphics_DrawBoneAttachedObjectParts(void *object);
extern "C" void CharacterViewer_DrawMonsterAndBounds(void *object);
extern "C" void CharacterViewer_DrawSingleModelAndCollectPolygonCounts(void *object);
extern "C" void Graphics_DrawHandleOrObjectAndCollectCounts(void *object);
// Original: arm9/ov015 @ 0x0218F22C; symbol: func_ov015_0218f22c; size: 0x50.
extern "C" void CharacterViewer_DrawModelByKind(void *object) {
    switch (((unsigned char *)object)[0x1c]) {
    case 0: CharacterViewer_DrawPlayerModelParts(object); break;
    case 1: Graphics_DrawBoneAttachedObjectParts(object); break;
    case 3: CharacterViewer_DrawMonsterAndBounds(object); break;
    case 2: CharacterViewer_DrawSingleModelAndCollectPolygonCounts(object); break;
    case 4: Graphics_DrawHandleOrObjectAndCollectCounts(object); break;
    }
}
