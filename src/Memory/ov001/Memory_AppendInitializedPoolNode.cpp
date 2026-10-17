#include <globaldefs.h>
ARM
extern "C" void* Pool_AppendFreeNode(void* pool);
extern "C" void* memcpy(void*, const void*, unsigned);
extern "C" char* strcpy(char*, const char*);
struct PoolNode { unsigned kind, a, b, c, d, e, pad; char name[1]; };
// Original: arm9/ov001 @ 0x0215A364; symbol: func_ov001_0215a364; size: 0x5C.
extern "C" void Memory_AppendInitializedPoolNode(void* pool, unsigned a, unsigned b, unsigned c, unsigned d, unsigned e, const char* name) {
    PoolNode* node = (PoolNode*)Pool_AppendFreeNode(pool);
    if (!node) return;
    node->kind = 2;
    memcpy(&node->a, &a, 0xc);
    node->d = d;
    node->e = e;
    if (name) strcpy(node->name, name);
}
