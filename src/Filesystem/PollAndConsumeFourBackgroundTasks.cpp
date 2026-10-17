#include <globaldefs.h>
ARM
#include "Filesystem/BackgroundLoader.h"
extern "C" void ResourceLoader_LoadTwoNamedGP2FilesUnderLocks(void*,void*,int,int); extern "C" void InvokeRendererWithPairedResources(void*,void*,unsigned); extern "C" void InitializeTwoInvalidIndicesAndByteFlag(void*);
struct Task { unsigned key,unknown; int id; }; struct Object { unsigned char pad[8]; unsigned current; unsigned char unknown,flags,kind,pad2[5]; Task tasks[4]; };
// Original: arm9/main @ 0x020DA8E0; symbol: func_020da8e0; size: 0x140.
extern "C" int PollAndConsumeFourBackgroundTasks(Object* object) {BackgroundLoader* loader=BackgroundLoader::GetInstance();if(!loader)return 0;Task* task=object->tasks;bool complete=true;int x=3210-110,y=3210-100;for(unsigned char i=0;i<4;i++,task++){int id=task->id;if(id!=-1){if(!loader->GetTaskStatus(id))complete=false;else{unsigned length=0;void* data=0;loader->GetLoadedFileByID(id,&data,&length);switch(object->kind){case 1:ResourceLoader_LoadTwoNamedGP2FilesUnderLocks(object,data,x,y);break;case 2:ResourceLoader_LoadTwoNamedGP2FilesUnderLocks(object,data,3200,3210);break;case 3:InvokeRendererWithPairedResources(object,data,length);break;}object->current=task->key;object->flags|=4;loader->RemoveTask(id);InitializeTwoInvalidIndicesAndByteFlag(task);}}}if(complete)object->flags&=~1;return 1;}
