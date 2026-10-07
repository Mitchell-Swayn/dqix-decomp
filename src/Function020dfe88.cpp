#include "Filesystem/BackgroundLoader.h"

extern "C" int func_020dfe88(void* request)
{
    unsigned char* bytes = static_cast<unsigned char*>(request);
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    int taskID = *reinterpret_cast<int*>(bytes + 0x10);

    if (taskID >= 0) {
        loader->RemoveTask(taskID);
        *reinterpret_cast<int*>(bytes + 0x10) = -1;
    }
    *reinterpret_cast<unsigned short*>(bytes + 0x0e) = 0;
    *reinterpret_cast<unsigned int*>(bytes + 0x14) = 0;
    return 1;
}
