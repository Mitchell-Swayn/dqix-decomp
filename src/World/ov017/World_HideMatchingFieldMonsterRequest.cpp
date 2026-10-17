#include <globaldefs.h>
ARM
extern "C" int ReadIndexedSignedField1038(char* p);
extern "C" void FieldMonster_HideByRecordIdentifier(void* owner, void* record);
extern "C" void* OV017_GetEmbeddedField1C(void*);
extern "C" void func_ov017_021b8b6c(void*);
// Original: arm9/ov017 @ 0x021C5E80; symbol: func_ov017_021c5e80; size: 0x80.
extern "C" void World_HideMatchingFieldMonsterRequest(void *unused, unsigned char *input, void *unused2, char *owner, char *state) {
    unsigned index = input[4];
    unsigned short id;
    unsigned char *context = *(unsigned char**)(owner + 0x3718);
    id = *(unsigned short*)(input + 6);
    if (index != ReadIndexedSignedField1038(state)) {
        if (!context[2]) return;
        char *record = (char*)OV017_GetEmbeddedField1C(context);
        if (!record) return;
        if (*(unsigned short*)(record + 8) != id) return;
        func_ov017_021b8b6c(context);
        FieldMonster_HideByRecordIdentifier(owner,(void*)id);
    } else {
        func_ov017_021b8b6c(context);
        FieldMonster_HideByRecordIdentifier(owner,(void*)id);
    }
}
