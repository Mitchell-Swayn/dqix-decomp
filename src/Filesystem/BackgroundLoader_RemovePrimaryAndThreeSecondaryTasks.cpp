#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
struct Obj{char pad[0x1c];volatile int main;int tasks[3];};extern "C" void InitializeEmbeddedListsAndInvalidIndices(Obj*);
// Original: arm9/main @ 0x0207F8BC; symbol: func_0207f8bc; size: 0x58.
extern "C" ARM void BackgroundLoader_RemovePrimaryAndThreeSecondaryTasks(Obj* p){if(p->main>=0)BackgroundLoader::GetInstance()->RemoveTask(p->main);for(int i=0;i<3;i++){BackgroundLoader* loader=BackgroundLoader::GetInstance();int task=p->tasks[i];if(task>=0)loader->RemoveTask(task);}InitializeEmbeddedListsAndInvalidIndices(p);}
