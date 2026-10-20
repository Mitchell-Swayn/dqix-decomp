#include <globaldefs.h>
ARM
extern "C" void _ZN8Object3D14AdvanceEffectsEv(void*);
extern "C" void GameObject_AdvanceActionResourceSequence(void*);
extern "C" void GameObject_AdvanceBattleMotionAlphaAndAnimation(unsigned char*);
extern "C" void GameState_ProcessTimedComponentNotification(char*);
extern "C" int _fflt(int);
extern "C" unsigned _fmul(unsigned, unsigned);
extern "C" int _ffix(unsigned);
extern "C" int _Z8fix32absi(int);
extern "C" void GameObject_AdvanceTextureSuppressionTimer(char*);
// Original: arm9/main @ 0x02052AE8; symbol: Object3D_AdvanceEffectsAndClampTransitionValue; size: 0x114.
// Advances object effects and moves a paired value toward its target using a clamped fixed-point step.
extern "C" void Object3D_AdvanceEffectsAndClampTransitionValue(char* object) {
    int active = *(signed char*)(object + 0x17c) > 0;
    if (active) {
        _ZN8Object3D14AdvanceEffectsEv(object);
        GameObject_AdvanceActionResourceSequence(object);
    } else {
        GameObject_AdvanceBattleMotionAlphaAndAnimation((unsigned char*)object);
        GameState_ProcessTimedComponentNotification(object);
    }
    if (*(int*)(object + 0x1b4) > 0 || *(int*)(object + 0x1b8) > 0) {
        int amount = _Z8fix32absi(_ffix(_fmul(0x3dcccccd, _fflt(*(int*)(object + 0x1b4) - *(int*)(object + 0x1b8)))));
        if (amount == 0) *(int*)(object + 0x1b8) = *(int*)(object + 0x1b4);
        int threshold = *(int*)(object + 0x1bc);
        if (amount < threshold) {
            *(int*)(object + 0x1bc) = amount;
        } else if (threshold < amount) {
            threshold += 0x14;
            *(int*)(object + 0x1bc) = threshold;
            if (amount < threshold) *(int*)(object + 0x1bc) = amount;
            threshold = *(int*)(object + 0x1bc);
            if (threshold > 0x199) *(int*)(object + 0x1bc) = 0x199;
            amount = *(int*)(object + 0x1bc);
        }
        if (*(int*)(object + 0x1b4) < *(int*)(object + 0x1b8)) {
            *(int*)(object + 0x1b8) = *(int*)(object + 0x1b8) - amount;
            if (*(int*)(object + 0x1b8) < *(int*)(object + 0x1b4)) *(int*)(object + 0x1b8) = *(int*)(object + 0x1b4);
        } else if (*(int*)(object + 0x1b8) < *(int*)(object + 0x1b4)) {
            *(int*)(object + 0x1b8) = *(int*)(object + 0x1b8) + amount;
            if (*(int*)(object + 0x1b4) < *(int*)(object + 0x1b8)) *(int*)(object + 0x1b8) = *(int*)(object + 0x1b4);
        }
    }
    GameObject_AdvanceTextureSuppressionTimer(object);
}
