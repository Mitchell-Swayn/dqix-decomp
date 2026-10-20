#include <globaldefs.h>
#include <Memory/SafeAllocator.h>
extern "C" { void InitializeOwnerFieldsScaleAndEmbeddedObject3D(void*);
// Original: arm9/main @ 0x02055ED0; symbol: func_02055ed0; size: 0x8C.
 ARM void* FindInactiveLinkedRecordOrAllocateNewNode(unsigned char* self) { unsigned char** slot=(unsigned char**)(self+52); unsigned char* scan; while((scan=*slot)!=0) { if(!scan[44])return scan; slot=(unsigned char**)(scan+328); } unsigned char* node=0; SafeAllocator* allocator=*(SafeAllocator**)(self+40); bool success; if(!allocator)success=false;else { node=(unsigned char*)allocator->Allocate(332);if(!node)success=false;else{InitializeOwnerFieldsScaleAndEmbeddedObject3D(node);*(unsigned int*)(node+328)=0;success=true;} }if(!success)return 0;InitializeOwnerFieldsScaleAndEmbeddedObject3D(node);*(unsigned int*)(node+328)=0;*slot=node;return node; } }
