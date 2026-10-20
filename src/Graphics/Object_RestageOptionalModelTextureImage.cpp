#include <globaldefs.h>
ARM
#include <Graphics/Model3D.h>
struct Owner { char pad[28]; Model3D* model; };
// Original: arm9/main @ 0x0205560C; symbol: func_0205560c; size: 0x18.
extern "C" void Object_RestageOptionalModelTextureImage(Owner* p) { Model3D* model=p->model;if(model)model->RestageTextureImage(); }
