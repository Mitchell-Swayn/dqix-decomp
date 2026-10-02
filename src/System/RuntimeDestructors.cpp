#pragma optimize_for_size off
#pragma dont_inline on
struct RuntimeDestructorNode {
    RuntimeDestructorNode* next;
    void (*destroy)(void*, int);
    void* object;
};
extern RuntimeDestructorNode* data_020f33b0;
extern "C" void func_0200edf4()
{
    RuntimeDestructorNode* node = data_020f33b0;
    if (node) {
        do {
            data_020f33b0 = node->next;
            node->destroy(node->object, -1);
            node = data_020f33b0;
        } while (node);
    }
}
