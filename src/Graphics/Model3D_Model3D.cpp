#include <globaldefs.h>
#include <Graphics/Model3D.h>
ARM
// Complete constructor ABI entry: clear the object and return its address.
// Naming this entry explicitly avoids generating an unowned C2 alias.
// Original: arm9/main @ 0x0207E23C; symbol: _ZN7Model3DC1Ev; size: 0x14.
extern "C" Model3D* _ZN7Model3DC1Ev(Model3D* self){self->Clear();return self;}
