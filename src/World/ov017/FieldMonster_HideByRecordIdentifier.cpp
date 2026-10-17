#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* FindFieldMonsterByRecordIdentifier(void*, void*);
extern "C" ARM void Object3D_InitializeExtendedMovementStateDefaults(char*);
extern "C" void _ZN8Object3D10MakeHiddenEv(void*);
// Original: arm9/ov017 @ 0x021A23B0; symbol: func_ov017_021a23b0; size: 0x34.
extern "C" void FieldMonster_HideByRecordIdentifier(void* owner, void* record) {
    _ZN9GameState11GetInstanceEv();
    void* monster = FindFieldMonsterByRecordIdentifier(owner, record);
    if (monster) {
        Object3D_InitializeExtendedMovementStateDefaults((char*)monster);
        _ZN8Object3D10MakeHiddenEv(monster);
    }
}
