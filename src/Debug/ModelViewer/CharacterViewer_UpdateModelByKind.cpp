#include <globaldefs.h>
ARM
extern "C" void Graphics_AdvanceEffectsWithInputGate(void *object);
extern "C" void CharacterViewer_AdvanceDollEffects(void *object);
extern "C" void Graphics_AdvanceEffectsWhenReady(void *object);
extern "C" void Ov015_AdvanceEffectsWhenActive(char *object);
extern "C" void Graphics_AdvanceOwnerHandleOrEffectsWithInputGate(void *object);
extern "C" void CharacterViewer_UpdateCameraFromMotionBones(void *object);
// Original: arm9/ov015 @ 0x0218F1C4; symbol: func_ov015_0218f1c4; size: 0x68.
extern "C" void CharacterViewer_UpdateModelByKind(void *object) {
    switch (((unsigned char *)object)[0x1c]) {
    case 0: Graphics_AdvanceEffectsWithInputGate(object); break;
    case 1: CharacterViewer_AdvanceDollEffects(object); break;
    case 3: Ov015_AdvanceEffectsWhenActive((char *)object); break;
    case 2: Graphics_AdvanceEffectsWhenReady(object); break;
    case 4: Graphics_AdvanceOwnerHandleOrEffectsWithInputGate(object); break;
    case 5: CharacterViewer_UpdateCameraFromMotionBones(object); break;
    case 6: CharacterViewer_UpdateCameraFromMotionBones(object); break;
    }
}
