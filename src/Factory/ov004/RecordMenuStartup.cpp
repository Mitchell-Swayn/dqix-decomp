#include "System/RuntimeState.h"

extern "C" {
extern unsigned char data_ov004_021708c8[];
extern RuntimeDestructorNode data_ov004_0217082c;
void func_ov004_021633e4(void*);
void func_ov004_02163408(void*, int);
void __register_global_object(void*, void (*)(void*, int), RuntimeDestructorNode*);
}

#pragma define_section init ".init" RX
extern "C" __declspec(section "init") void __sinit_ov004_0217031c()
{
    func_ov004_021633e4(data_ov004_021708c8);
    __register_global_object(data_ov004_021708c8, func_ov004_02163408,
                             &data_ov004_0217082c);
}
