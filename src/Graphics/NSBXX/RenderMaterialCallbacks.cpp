#include "Graphics/NSBXX/RenderCommands_Common.h"

void MaterialTextureMatrixLoadProc_Type0(MaterialRenderData*);
void MaterialTextureMatrixLoadProc_Type1(MaterialRenderData*);
void MaterialTextureMatrixLoadProc_Type2(MaterialRenderData*);
void MaterialTextureMatrixLoadProc_Type3(MaterialRenderData*);

void (*RenderMeshWithMaterial_UnknownRoleProcedureReferenceRecords[4])(MaterialRenderData*) = {
    MaterialTextureMatrixLoadProc_Type0, MaterialTextureMatrixLoadProc_Type1, MaterialTextureMatrixLoadProc_Type2, MaterialTextureMatrixLoadProc_Type3
};
