#include <globaldefs.h>
#include <Filesystem/BackgroundLoader.h>
#include <Memory/SafeAllocator.h>
struct ScriptBundle {void* primary;unsigned first[2],second[2];SafeAllocator* allocator;unsigned saved;int archiveTask,tasks[3];};
extern "C" {
 void ClearWordAndTwoHalfwords_Main020727D8(void*);
 void Script_ExecuteCodeWithGlobalContextValues(void*,void*,const void*,unsigned,void*,unsigned short,unsigned char);
 void Script_ExecuteCodeAndFinalizeGlobalContext(void*,void*,const void*,unsigned);
 void Script_ExecuteCodeWithOptionalContext(void*,void*,const void*,unsigned);
 char* FindVariableLengthBlockByIndex(char*,int,char**,unsigned*);
 int ResourceFile_CountActiveStrideRecords(void*);
 char* ReadWordFieldAtOffset1C();
// Original: arm9/main @ 0x0207F9F4; symbol: func_0207f9f4; size: 0x278.
 ARM int PollArchiveAndThreeBackgroundTasks(ScriptBundle* self) {
  char* codes[3];
  unsigned sizes[3];
  void* code;
  unsigned size;
  char* entry;
  char* archive;
  unsigned archiveSize;
  if (self->archiveTask < 0) {
   int* tasks = self->tasks;
   if (tasks[0]<0 && tasks[1]<0 && tasks[2]<0) return -1;
   BackgroundLoader* loader=BackgroundLoader::GetInstance();
   bool ready=true;
   for(int i=0;i<3;++i) if(!loader->GetTaskStatus(tasks[i])) ready=false;
   if(ready) {
   loader->GetLoadedFileByID(tasks[0],&code,&size);
   self->primary=self->allocator->Allocate(8);
   ClearWordAndTwoHalfwords_Main020727D8(self->primary);
   if(code)Script_ExecuteCodeWithGlobalContextValues(self->primary,self->allocator,code,size,0,0,0);
   loader->GetLoadedFileByID(tasks[1],&code,&size);
   if(code)Script_ExecuteCodeAndFinalizeGlobalContext(self->first,self->allocator,code,size);
   loader->GetLoadedFileByID(tasks[2],&code,&size);
   if(code)Script_ExecuteCodeWithOptionalContext(self->second,self->allocator,code,size);
   for(int i=0;i<3;++i){loader->RemoveTask(*tasks);*tasks=-1;++tasks;}
   self->saved=*(unsigned*)(ReadWordFieldAtOffset1C()+0x5c);
   return 0;
   } else return 1;
  }
  BackgroundLoader* loader=BackgroundLoader::GetInstance();
  if(loader->GetTaskStatus(self->archiveTask)) {
  loader->GetLoadedFileByID(self->archiveTask,(void**)&archive,&archiveSize);
  int count=ResourceFile_CountActiveStrideRecords(archive);
  for(int i=0;i<count;++i)codes[i]=FindVariableLengthBlockByIndex(archive,i,&entry,&sizes[i]);
  self->primary=self->allocator->Allocate(8);
  ClearWordAndTwoHalfwords_Main020727D8(self->primary);
  Script_ExecuteCodeWithGlobalContextValues(self->primary,self->allocator,codes[0],sizes[0],0,0,0);
  Script_ExecuteCodeAndFinalizeGlobalContext(self->first,self->allocator,codes[1],sizes[1]);
  Script_ExecuteCodeWithOptionalContext(self->second,self->allocator,codes[2],sizes[2]);
  loader->RemoveTask(self->archiveTask);
  self->archiveTask=-1;
  self->saved=*(unsigned*)(ReadWordFieldAtOffset1C()+0x5c);
  return 0;
  } else return 1;
 }
}
