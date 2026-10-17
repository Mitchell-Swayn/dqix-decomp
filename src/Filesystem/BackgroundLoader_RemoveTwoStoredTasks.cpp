#include <globaldefs.h>
class BackgroundLoader {
public:
    static BackgroundLoader *GetInstance();
    void RemoveTask(int);
};
ARM
// Original: arm9/main @ 0x020E3ED8; symbol: func_020e3ed8; size: 0x44.
extern "C" void BackgroundLoader_RemoveTwoStoredTasks(unsigned char *p) {
    BackgroundLoader *loader=BackgroundLoader::GetInstance();
    for (int i=0; i<2; ++i) { int task=*(int *)(p+0x14+i*4); if (task != -1) loader->RemoveTask(task); }
}
