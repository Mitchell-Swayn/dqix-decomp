#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState31GetMaybeWanderingMonsterByIndexEi(void*, int);
extern "C" void* GameState_GetIndexList(void*);
extern "C" int PartyRoster_ContainsActiveObjectIndex(unsigned char*, unsigned int);
extern "C" int LinkedQueue_GetFrontKindOrInvalid(char**);
extern "C" void* GameState_GetObjectWithFlag100(void*, int);
extern "C" void* _ZN8Vector3iaSERKS_(void*, const void*);
extern "C" void SetObjectAngleAndClearFlagC48000(void*, int);
extern "C" void Object3D_SetNormalizedAngleAndUpdatePosition(char*, int);
extern "C" void __clear(void*, unsigned);
// Original: arm9/ov017 @ 0x021CEEE0; symbol: UpdateWanderingMonsterFromIndexedRecord; size: 0x100.
// Applies an indexed monster record's position and angle to its runtime object when its index is eligible.
extern "C" void UpdateWanderingMonsterFromIndexedRecord(void* unused, unsigned char* record, void* state, unsigned char* globals) {
    void* monster;
    char** indirect = *(char***)(globals + 0x36fc);
    monster = _ZN9GameState31GetMaybeWanderingMonsterByIndexEi(state, record[0x12]);
    unsigned char* listed = (unsigned char*)GameState_GetIndexList(state);
    if (PartyRoster_ContainsActiveObjectIndex(listed, record[0x12]) || !monster) return;
    int mode = LinkedQueue_GetFrontKindOrInvalid(indirect);
    if (mode == 10) {
        int indexIsInRange = record[0x12] <= 3;
        if (!indexIsInRange) return;
        if ((*(unsigned short*)monster & 0x80) == 0) return;
        void* object = GameState_GetObjectWithFlag100(state, record[0x12]);
        if (!object) return;
        int localVector[3];
        __clear(localVector, 12);
        localVector[1] = *(short*)(record + 0x10);
        _ZN8Vector3iaSERKS_((char*)object + 0x160, record + 4);
        _ZN8Vector3iaSERKS_((char*)object + 0x16c, localVector);
        return;
    }
    mode = LinkedQueue_GetFrontKindOrInvalid(indirect);
    if (mode == 4) return;
    _ZN8Vector3iaSERKS_((char*)monster + 0x44, record + 4);
    int angle = *(short*)(record + 0x10);
    if (record[0x13] == 0)
        SetObjectAngleAndClearFlagC48000(monster, angle);
    else
        Object3D_SetNormalizedAngleAndUpdatePosition((char*)monster, angle);
}
