#include <globaldefs.h>
#include <GameState/GameState.h>
#include <Graphics/Vector.h>
#include <World/Object3D.h>

extern "C" void GameObject_GetAuthorityPosition(Vector3fix* out, void* monster);
extern "C" void SetObjectAngleAndClearFlagC48000(Object3D* object, int angle);
extern "C" void GameObject_ChangeMotionStateAndRefreshAnimation(Object3D* object, int mode);
extern "C" void* Network_GetConnectionManager();
extern "C" int Network_IsSessionActive(void* state);
extern "C" int Network_GetLocalMemberId(void* state);
extern "C" void GameState_QueueObjectTransform(unsigned int, int, int,
                                     Vector3fix, Vector3fix, unsigned int);

// Original: arm9/main @ 0x02078754; symbol: func_02078754; size: 0x140.
extern "C" ARM int Object3D_FaceIndexedMonsterAndRestoreVisibility(Object3D* input)
{
    Object3D* object = input;
    GameState* game = GameState::GetInstance();
    const unsigned short monsterIndex =
        *reinterpret_cast<unsigned short*>(reinterpret_cast<unsigned char*>(object) + 0x166);
    void* found = game->GetMaybeWanderingMonsterByIndex(monsterIndex);
    int result;
    if (found == 0) {
        result = 0;
    } else {
        int copy[3];
        int direction[3];
        int target[3];
        GameObject_GetAuthorityPosition(reinterpret_cast<Vector3fix*>(target), found);
        COPY_ARRAY(copy, target);
        Vector3fix_Subtract(reinterpret_cast<Vector3fix*>(copy),
                            reinterpret_cast<Vector3fix*>(reinterpret_cast<unsigned char*>(object) + 0x44),
                            reinterpret_cast<Vector3fix*>(direction));
        Vector3fix_Normalize(reinterpret_cast<Vector3fix*>(direction),
                             reinterpret_cast<Vector3fix*>(direction));
        SetObjectAngleAndClearFlagC48000(object, fix32_Atan2(direction[0], direction[2]));
        *reinterpret_cast<unsigned short*>(reinterpret_cast<unsigned char*>(object) + 0xb2) = 0;
        GameObject_ChangeMotionStateAndRefreshAnimation(object, 0);
        object->EnableFlag(0x80);
        object->SetInheritedAlpha(0x1f);
        *(reinterpret_cast<unsigned char*>(object) + 0x17a) = 0;

        void* state = Network_GetConnectionManager();
        if (Network_IsSessionActive(state) && !Network_GetLocalMemberId(state)) {
            const unsigned int field = object->GetField06();
            Vector3fix* position = (Vector3fix*)((char*)object + 0x44);
            Vector3fix* rotation = (Vector3fix*)((char*)object + 0x50);
            const short y = *reinterpret_cast<short*>(reinterpret_cast<unsigned char*>(object) + 2);
            const short x = *reinterpret_cast<short*>(reinterpret_cast<unsigned char*>(object) + 4);
            const int remainder = (x - 0x70) % 12;
            if (remainder >= 0 && remainder < 12) {
                unsigned char* bytes = reinterpret_cast<unsigned char*>(object);
                GameState_QueueObjectTransform(field, remainder, y,
                    *position, *rotation, 0xffffffff);
            }
        }
        result = 1;
    }
    return result;
}
