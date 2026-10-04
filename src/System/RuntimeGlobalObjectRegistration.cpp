#include "System/RuntimeState.h"

extern "C" void __register_global_object(
    void* object, void (*destructor)(void*, int), RuntimeDestructorNode* node)
{
    node->next = data_020f33b0;
    node->destroy = destructor;
    node->object = object;
    data_020f33b0 = node;
}
