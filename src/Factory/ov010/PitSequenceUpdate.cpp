#include "World/ZoneResourceInterfaces.h"
#include "PitSequenceState.h"
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "World/Zone3D.h"

// Partial external layouts: only fields observed in the original callers are
// named. These are declarations, not storage replacing unresolved program data.
struct PitPartySelection {
    char unknown_00_[12];
    unsigned char partyIndex_;
};
// func_020e4bf4 passes the member's BaseCombatStats pointer twice to
// func_020e4b34, which stores those pointers and a packed format flag word.
struct PitTextArguments {
    BaseCombatStats* source_;
    BaseCombatStats* alternate_;
    unsigned int formatFlags_;
};
struct PitTextDisplay {
    PitTextArguments* arguments_;
    char unknown_004_[0x998 - 4];
    int busy_;
};
struct PitObjectMapKey;
struct PitEffectManager;
struct PitEffectMetadata {
    int unknown_00_[2];
    unsigned int objectParameter_ : 8;
    unsigned int unknown_08_upper_ : 24;
};
struct PitEffectCatalog;
struct PitEffectParameters {
    char animation_[16];
    unsigned char animationParameter_;
    unsigned char flag0_ : 1;
    unsigned char flag1_ : 1;
    unsigned char flag2_ : 1;
    unsigned char flag3_ : 1;
    unsigned char flag4_ : 1;
    unsigned char flag5_ : 1;
    unsigned char flag6_ : 1;
    unsigned char flag7_ : 1;
    short parameter_12_;
    short parameter_14_;
    short parameter_16_;
    short parameter_18_;
    short parameter_1a_;
    short parameter_1c_;
    Vector3i parameter_20_;
    Vector3i position_;
    Vector3i rotation_;
    Vector3i scale_;
};

typedef char PitEffectParametersSizeCheck[sizeof(PitEffectParameters) == 0x50 ? 1 : -1];
typedef char PitSavedPositionSizeCheck[sizeof(GameStateSavedPosition) == 8 ? 1 : -1];
typedef char PitSavedPositionOffsetCheck[offsetof(GameState, savedPositions_) == 0x74de ? 1 : -1];
typedef char PitTextureCheckpointOffsetCheck[
    offsetof(GameResources, graphicsRegion_2cc_) +
    offsetof(GameResourceGraphicsRegion, textures_) == 0xf0c ? 1 : -1];

extern "C" {
    PitTextDisplay* func_020421a0();
    int func_020100b0(GameState*);
    int func_020100a8(GameState*);
    void* func_0202ae18();
    Zone3D* func_02012fe4();
    void func_020397cc(GameObject*, int);
    void* func_02012d88(AllocatorUnion*, unsigned int);
    void func_020727d8(PitTextTable*);
    void func_020728ac(PitTextTable*, SafeAllocator*, const void*, unsigned int,
                       void*, unsigned short, unsigned char);
    GameStateSavedPosition* func_020120a0(GameState*, unsigned int);
    PitObjectMapKey* func_02033fa0(GameObject*);
    unsigned short func_0204bd7c(PitObjectMapKey*);
    void func_0205eaa0(void*, int, int);
    const char* func_02072a68(PitTextTable*, short);
    void func_020e4bf4(PitTextArguments*, int);
    void func_02046380(PitTextDisplay*);
    void func_0204500c(PitTextDisplay*, const char*, int, int);
    int func_020457e0(PitTextDisplay*);
    void func_0205ebc0(void*, int, int);
    void func_0205ebfc(void*, int, int);
    void func_0207df90(void*);
    void func_0207dfac(void*);
    PitEffectManager* func_02057924();
    void func_02057de0(PitEffectManager*, int, SafeAllocator*, const void*, unsigned int);
    int func_02057fb4(PitEffectManager*, int, PitEffectParameters*);
    int func_0202c508(void*);
    PitEffectCatalog* func_020797dc();
    PitEffectMetadata* func_02079e2c(PitEffectCatalog*, int);
    void func_02048350(GameObject*, unsigned int);
    void func_020340b4(GameObject*);
    void func_ov017_021d360c(int, unsigned char, unsigned short, Vector3s);
    void func_0205ebec(void*);
    extern AllocatorUnion data_02114e20;
    extern char data_02108760[];
    extern char data_ov010_02184a80[];
    extern char data_ov010_02184a95[];
    extern char data_ov010_02184aa6[];
}

extern "C" int func_ov010_02184354(PitSequenceState* state)
{
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    PitTextDisplay* display = func_020421a0();
    GameState* game = GameState::GetInstance();
    GameObject* member;
    Zone3D* zone;
    PitPartySelection* selection = (PitPartySelection*)func_ov017_0218b5b0()->unknown_ptr_array_3afc[43];
    member = game->GetPartyMemberByIndex(selection->partyIndex_);
    GameObject* selected = game->GetPartyMemberByIndex(func_020100b0(game));
    void* context = func_0202ae18();
    GameResources* field = func_ov017_0218b5b0();
    zone = func_02012fe4();
    if (!member || !selected) {
        func_ov010_021842d8(state);
        return 1;
    }
    if (state->phase_ == 0) {
        func_020397cc(selected, 1);
        void* memory = func_02012d88(&data_02114e20, 0x7800);
        if (!memory) { func_ov010_021842d8(state); return 1; }
        state->allocator_.CreateTypeA(memory, 0x7800);
        state->loadTask_ = loader->QueueLoadFileInGP2(data_ov010_02184a80,
                                                   data_ov010_02184a95, 0);
        state->phase_ = 1;
    } else if (state->phase_ == 1) {
        if (!loader->GetTaskStatus(state->loadTask_)) return 0;
        if (loader->GetDetailedTaskStatus(state->loadTask_) != 2) {
            func_ov010_021842d8(state); return 1;
        }
        void* textData;
        unsigned int textLength;
        loader->GetLoadedFileByID(state->loadTask_, &textData, &textLength);
        func_020727d8(&state->text_);
        func_020728ac(&state->text_, &state->allocator_, textData, textLength, 0, 0, 0);
        loader->RemoveTask(state->loadTask_);
        GameStateSavedPosition* saved = func_020120a0(game, func_020100a8(game));
        if (!saved) { func_ov010_021842d8(state); return 1; }
        Zone3D_StructPtr_8* zoneInfo = zone->pUnknownStruct_8_;
        if (!zoneInfo) { func_ov010_021842d8(state); return 1; }
        state->effectEnabled_ = 1;
        if (!zoneInfo->unknown_c_low_) {
            PitObjectMapKey* key = func_02033fa0(member);
            if (key) {
                void* lookup = func_02011584(game);
                Zone3D_StructPtr_8* map = func_02099950(lookup, func_0204bd7c(key));
                if (map && map->unknown_e_bits_2_5_) state->effectEnabled_ = 0;
            }
        } else {
            Zone3D_StructPtr_8* map = zone->pUnknownStruct_8_;
            if (map) {
                int enabled = 1;
                if (!map->unknown_e_bit_6_) enabled = 0;
                state->effectEnabled_ = enabled;
            }
        }
        int textID;
        if (!state->effectEnabled_) { state->phase_ = 3; textID = 2; }
        else if (saved->zone_) { state->phase_ = 2; textID = 1; }
        else { state->phase_ = 4; textID = 0; func_0205eaa0(data_02108760, 100, 0); }
        const char* text = func_02072a68(&state->text_, (short)textID);
        PitTextArguments arguments;
        func_020e4bf4(&arguments, selection->partyIndex_);
        func_02046380(display);
        display->arguments_ = &arguments;
        func_0204500c(display, text, 0, 0xe3);
        display->busy_ = 1;
    } else if (state->phase_ == 2) {
        if (display->busy_) return 0;
        if (!func_020457e0(display)) {
            const char* text = func_02072a68(&state->text_, 0);
            PitTextArguments arguments;
            func_020e4bf4(&arguments, selection->partyIndex_);
            func_02046380(display);
            display->arguments_ = &arguments;
            func_0204500c(display, text, 0, 0xe3);
            display->busy_ = 1;
            func_0205eaa0(data_02108760, 100, 0);
            GameStateSavedPosition* saved = func_020120a0(game, func_020100a8(game));
            if (saved) saved->zone_ = 0;
            state->phase_ = 4;
        } else { func_ov010_021842d8(state); return 1; }
    } else if (state->phase_ == 4) {
        state->loadTask_ = loader->QueueLoadFile(data_ov010_02184aa6, 0);
        state->phase_ = 5;
        state->delay_ = 0;
    } else if (state->phase_ == 5) {
        if (!loader->GetTaskStatus(state->loadTask_)) return 0;
        if (loader->GetDetailedTaskStatus(state->loadTask_) != 2) {
            func_ov010_021842d8(state); return 1;
        }
        if (state->delay_ < 15) { ++state->delay_; return 0; }
        func_0205ebc0(data_02108760, 0x74, 0x74);
        func_0205ebfc(data_02108760, 0, 0);
        void* effectData;
        unsigned int effectLength;
        loader->GetLoadedFileByID(state->loadTask_, &effectData, &effectLength);
        GameResourceGraphicsRegion* graphics = &field->graphicsRegion_2cc_;
        Vector3i position = member->obj3D_.position_;
        func_0207df50(&graphics->textures_);
        func_0207df90(&graphics->textures_);
        PitEffectManager* effects = func_02057924();
        func_02057de0(effects, 17, &state->allocator_, effectData, effectLength);
        func_0207dfac(&graphics->textures_);
        PitEffectParameters params;
        params.animation_[0] = 0;
        params.parameter_12_ = 0;
        params.parameter_20_.x = 0; params.parameter_20_.y = 0; params.parameter_20_.z = 0;
        params.position_.x = 0; params.position_.y = 0; params.position_.z = 0;
        params.rotation_.x = 0; params.rotation_.y = 0; params.rotation_.z = 0;
        params.parameter_1c_ = -0x1000;
        params.animationParameter_ = 1;
        params.parameter_14_ = -1; params.parameter_16_ = -1;
        params.parameter_18_ = -1; params.parameter_1a_ = -1;
        params.scale_.x = 0x1000; params.scale_.y = 0x1000; params.scale_.z = 0x1000;
        Vector3i effectScale;
        effectScale.x = 0x10a; effectScale.y = 0x10a; effectScale.z = 0x10a;
        params.flag0_ = 0; params.flag1_ = 0; params.flag2_ = 1; params.flag3_ = 0;
        params.flag4_ = 0; params.flag5_ = 0; params.flag6_ = 0; params.flag7_ = 0;
        params.position_ = position;
        params.scale_ = effectScale;
        state->effectObjectIndex_ = func_02057fb4(effects, 17, &params);
        Vector3s compactPosition;
        compactPosition.x = position.x >> 4;
        compactPosition.y = position.y >> 4;
        compactPosition.z = position.z >> 4;
        if (func_0202c508(context)) {
            GameStateSavedPosition* saved = func_020120a0(game, func_020100a8(game));
            if (saved) {
                saved->zone_ = zone->currentZoneID_;
                saved->position_.x = compactPosition.x;
                saved->position_.y = compactPosition.y;
                saved->position_.z = compactPosition.z;
            }
        }
        PitEffectMetadata* metadata = func_02079e2c(func_020797dc(), 0xd2);
        if (metadata) func_02048350(member, metadata->objectParameter_);
        GameObject* object = game->GetUnknownGameObject();
        if (object) func_020340b4(object);
        func_ov017_021d360c(0, (unsigned char)func_020100a8(game), zone->currentZoneID_, compactPosition);
        state->phase_ = 3;
    } else if (state->phase_ == 3) {
        GameState* currentGame = GameState::GetInstance();
        int finished = 0;
        if (state->effectEnabled_) {
            if (!currentGame->GetGameObjectByIndex(state->effectObjectIndex_) && !display->busy_) finished = 1;
        } else if (!display->busy_) finished = 1;
        if (finished) {
            func_ov010_021842d8(state);
            func_0205ebec(data_02108760);
            return 1;
        }
    }
    return 0;
}
