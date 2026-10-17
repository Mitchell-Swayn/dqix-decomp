#include <globaldefs.h>
ARM
extern "C" void* memset(void* dst, int value, unsigned int length);
extern "C" int strncmp(const char* lhs, const char* rhs, unsigned int count);
extern "C" char data_ov017_021d82d4[];
struct Context { unsigned state, a,b; int count; char *entries; unsigned c; char *end,*reserved; int count2; char *entries2; unsigned d; char *end2; unsigned pad[5]; char *file,*data; };
// Original: arm9/ov017 @ 0x021D4C04; symbol: func_ov017_021d4c04; size: 0xBC.
extern "C" void Resource_InitializeSb2ScriptBuffers(Context *self, char *file, char *entries, int count, char *entries2, int count2) {
    self->entries = entries;
    self->count = count;
    self->entries2 = entries2;
    self->count2 = count2;
    self->end = self->entries + count * 8;
    self->end2 = self->entries2 + count2 * 12;
    self->file = file;
    self->data = file + *(unsigned*)(file + 8);
    if (strncmp(self->file,data_ov017_021d82d4,3)) return;
    self->state = 2;
    self->reserved = self->entries;
    self->entries += *(unsigned*)(self->file + 0x18) * 8;
    self->count -= *(unsigned*)(self->file + 0x18);
    memset(self->reserved,0,*(unsigned*)(self->file + 0x18) * 8);
}
