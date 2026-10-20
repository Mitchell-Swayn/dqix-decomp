#include <globaldefs.h>
ARM
#pragma opt_treetransformation off
#pragma opt_foldconstants off
#pragma opt_rebuildlogicals off
#pragma opt_rebuildconditionals off
#pragma opt_arithtransformation off
#pragma always_inline on
#pragma force_active on
struct IntegerParameterView;
extern "C" int Script_ReadParameterAsInteger(IntegerParameterView*);
// Original data: arm9/ov001 @ 0x02165880; symbol: data_ov001_02165880.
// Mutable zero-initialized storage; observed offsets belong to this consumer, not a proven object extent.
// Initial value: zero-filled. Full initialized state and references: docs/data-symbols/ov001.md.
extern "C" char EventGetObjectSession_UnknownRoleZeroInitializedStorage[];
extern "C" void* GameResources_GetInstance();
extern "C" void _ZN8Object3D10SetField9eEh(void*,unsigned char);
extern "C" int Resource_ApplyUpdateOnlyWhenValidationPasses(void*,unsigned,unsigned);
extern "C" void ModifyTexturePaletteWhenIndexedFlagsAllow(void*,int,unsigned short);
struct BoundObject {char prefix[4];short index;};
struct BoundRecord {int type;unsigned unused[2];BoundObject* object;};
inline bool IsPartyTextureIndex(short index)
{
    bool valid;
    if (index >= 0 && index <= 3) valid = true;
    else valid = false;
    return valid;
}
// Original: arm9/ov001 @ 0x0215CF98; symbol: func_ov001_0215cf98; size: 0xF4.
// Packs a script RGB tint and updates a supported bound object's texture palette.
extern "C" int Script_SetBoundObjectTextureTint(char* args,int count)
{
    void* resources = GameResources_GetInstance();
    int id = Script_ReadParameterAsInteger((IntegerParameterView*)args);
    BoundRecord* records = *(BoundRecord**)(EventGetObjectSession_UnknownRoleZeroInitializedStorage + 4);
    BoundRecord* record = records + id;
    int type = record->type;
    if (type != 0 && type != 1 && type != 4 && type != 5 && type != 6) goto complete;
    {
        BoundObject* object = record->object;
        if (object) {
            short index = object->index;
            int red = Script_ReadParameterAsInteger((IntegerParameterView*)(args + 8));
            int green = Script_ReadParameterAsInteger((IntegerParameterView*)(args + 16));
            int blue = Script_ReadParameterAsInteger((IntegerParameterView*)(args + 24));
            unsigned short color = red | (green << 5) | (blue << 10);
            int mode = 0;
            if (count - 4 > 0) {
                mode = Script_ReadParameterAsInteger((IntegerParameterView*)(args + 32));
            }
            _ZN8Object3D10SetField9eEh(object, (unsigned char)mode);
            bool partyMember = IsPartyTextureIndex(index);
            if (partyMember) {
                Resource_ApplyUpdateOnlyWhenValidationPasses(resources, index, color);
            } else {
                ModifyTexturePaletteWhenIndexedFlagsAllow(resources, index, color);
            }
        }
    }
complete:
    return 1;
}
