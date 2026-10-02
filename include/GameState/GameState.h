#pragma once

#include "Combat/Main/BattleList.h"
#include "Resource/GameResources.h"
#include "World/Object3D.h"
#include "World/WorldPlacementSource.h"
#include "Filesystem/NitroVM.h"
#include "GameState/TimeOfDay.h"
#include "Grotto/Main/GrottoStruct.h"

// Represents a party member, monster in battle, monster on the field
// or grotto boss. 
class GameObject
{
public:
    Object3D obj3D_; // might be inherited instead
    char unk_ac[0x134 - 0xac];
    BaseCombatStats* baseStats_;
    ModifiableCombatStats* currentStats_;
};

// Four GameState records are indexed by a signed object index. A negative
// index marks a free record; the other fields have not yet been recovered.
struct GameStateIndexedRecord {
    char unknown_000[0x568];
    short objectIndex_;
    char unknown_56a;
    unsigned char lowNibble_56b_ : 4;
    unsigned char highNibble_56b_ : 4;
    char unknown_56c[0x964 - 0x56c];
};

struct GameStateIndexList {
    char unknown_000[0xf78];
    unsigned char objectIndices_[4];
    unsigned char count_;
};

// The table lookup at 0x0209a594 reads 12-byte records. It searches the
// low eleven bits of identifier_, or uses the requested index directly.
struct GameStateAttributeRecord {
    unsigned short identifier_;
    unsigned short unknown_02_;
    unsigned int attributes_;
    unsigned int unknown_08_;
};

struct GameStateAttributeTable {
    GameStateAttributeRecord* records_;
    int count_;
};

struct NativeIdentity {
    unsigned char bytes_[6];
    inline bool IsZero() const {
        for (int i = 0; i < 6; ++i)
            if (bytes_[i] != 0) return false;
        return true;
    }
};

// Sixteen stored identities track a sub-minute byte and a saturating counter.
struct GameStateStoredIdentity {
    NativeIdentity identity_;
    char unknown_06_[0x11 - 6];
    unsigned char partialTicks_;
    unsigned short counter_ : 14;
    unsigned short active_ : 1;
    unsigned short unknownFlag_ : 1;
    char unknown_14_[0x2c - 0x14];
};

struct GameStatePeerIdentity {
    NativeIdentity identity_;
    signed char objectIndex_;
    unsigned char unknown_07_;
    unsigned char unknown_08_;
    signed char unknown_09_;
};

struct GameStateIdentityRecord {
    NativeIdentity identity_;
    unsigned char lowFlag_ : 1;
    unsigned char upperFlags_ : 7;
    char unknown_07_;
    float timer_;
};

struct GameStateByteSlots {
    unsigned char unknown_00_;
    unsigned char unknown_01_;
    unsigned char bytes_02_[4];
    unsigned char unknown_06_;
};

// func_020120a0 indexes four eight-byte records at +0x74de. ov010 saves
// the current zone and the position after shifting each component right four.
struct GameStateSavedPosition {
    unsigned short zone_;
    Vector3s position_;
};

// sizeof is probably 0x7ff4 but could be 0x7ff8. (Definitely no lower/higher)
// For lower bound, look at initialize/reset function func_0200f3a4
// which writes a byte at offset 0x7ff2.
// For upper bound, note an instance of this occurs at 0x020f33d8, constructed
// in the static initializer at 0x020e5920, while data at 0x020fb3d0 is initialized
// by the next static initializer at 0x020e59c8. data_020fb3cc is explicitly written
// to so size is probably 0x7ff4.
// Generic game class used for pretty much everything. 
class GameState
{
public:
    GameResources* pResources_;
    char unk_4[1];
    unsigned char language_;
    char unk_6[2];
    GameObject* objects_[0xe9];
    int protagonistObjectIndex_;
    void* unknown_3b0_; // see func_020100bc, LightingManager::MaybeComputeHorizonPosition. Probably a high level camera
    unsigned int effectiveDeltaTimeMilliseconds_;
    unsigned int trueDeltaTimeMilliseconds_;
    fix16_t gameSpeed_; // effective delta time is true delta time rescaled by this
    fix32_t animationDeltaTime_; // for use with frame-based things such as nsbca
    unsigned int numTicks_;
    unsigned int currentNumTicks_;
    float dayTimer_;
    float dayLength_;
    float daySpeed_;
    CBool dayTimerRunning_;
    TimeOfDay timeOfDay_;
    float unknown_3e0_;
    char unk_3e4[4];
    uint64_t mainTimestamp_; // current timestamp - this one is used for chest timer
    uint64_t altTimestamp_; // not sure about usage

#if defined(usa)
    char unk_3f8[0x474 - 0x3f8];
    GameStateIndexedRecord indexedRecords_[4];
    GameStateIndexList indexList_;
#elif defined(jpn)
    char unk_3f8[0x371c - 0x3f8];
    unsigned char unknownObjectIndex_397c_; // jpn: offset 0x731c instead
    unsigned char unknownObjectIndices_397d_[3];
    unsigned char unknownObjectIndexCount_3980_;
#endif
    char unk_3981[0x5718 - 0x3981];
    unsigned char unknownByteBuffer_5718_[4];
    unsigned char unknownByteBufferLength_571c_;
    signed char unknownByteBuffer_571d_[4];
    unsigned char unknownByteBufferLength_5721_;
    char unk_5722[0x572c - 0x5722];
    GameStateAttributeTable attributeTable_;
    unsigned char attributeTableBuffer_[0x570];
    char unk_5ca4[0x5cb0 - 0x5ca4];
    unsigned int unknown_5cb0_;
    unsigned int unknown_5cb4_;
    unsigned int unknown_5cb8_;
    unsigned int unknown_5cbc_;
    char unk_5cc0[0x5cd0 - 0x5cc0];
    unsigned char unknownBitFlags_5cd0_[10];
    unsigned char unknownPlacementByte_5cda_;
    char unk_5cdb[1];
    WorldPlacementSource::PersistentState placementStates_[100];
    char unk_5e6c[0x63e0 - 0x5e6c];

    unsigned char* treasureMapLanguageData_;
    GrottoStruct grottoInfo_;

#if defined(usa)
    char unk_6fcc[0x7200 - 0x6fcc];
    GameStateStoredIdentity storedIdentities_[16];
    GameStatePeerIdentity peerIdentities_[3];
    GameStateSavedPosition savedPositions_[4];
    NativeIdentity nativeIdentity_;
    char unk_7504[0x7f6c - 0x7504];
    unsigned int unknown_7f6c_;
    unsigned char unknown_7f70_;
    char unk_7f71[0x7f74 - 0x7f71];
    GameStateByteSlots byteSlots_7f74_;
    char unk_7f7b[0x7f8c - 0x7f7b];
    GameStateIdentityRecord identityRecords_[3];
    char unk_7fb0[0x7ff4 - 0x7fb0];
#else
    char unk_6fc0[0x7ff4 - 0x6fc0];
#endif

public:
    // --- GameStateInstance.cpp ---
    static GameState* GetInstance();

    // -- GameStateObjects.cpp ---

    GameObject* GetGameObjectByIndex(int idx);
    // Like GetCombatantByIndex() but checks for bitmask 0x2 instead. This is set
    // in the same cases as 0x20, but replacing this function to always return null
    // only disables wandering monsters, while keeping whistle spawns and grotto
    // bosses in tact
    GameObject* GetMaybeWanderingMonsterByIndex(int idx);
    GameObject* GetProtagonist();
    // Seems to also be the protagonist, checks the bit at 0x397c
    GameObject* GetUnknownGameObject();
    // Like GetCombatantByIndex() but checks for bitmask 0x800 instead.
    GameObject* GetPartyMemberByIndex(int idx);
    // Like GetCombatantByIndex() but checks for bitmask 0x20 instead. In practice
    // this bit is set for monsters out of battle, and replacing this function to
    // always return null disables monster spawns, including through whistle, and
    // removes grotto bosses.
    GameObject* GetMaybeFieldMonsterByIndex(int idx);
    // Index into the object array, but only return it if its obj3D.unk_0
    // has bit 0x80 set. In practice this seems to be for enemies in battle
    // and party members universally. In a fight with multiple enemies, you can
    // clear this bit on one enemy and kill the others, and the battle will end
    // prematurely.
    GameObject* GetCombatantByIndex(int idx);

    // --- GameTime.cpp ---

    // usa: func_02010150
    void CalculateDeltaTime(uint64_t microseconds);
    // usa: func_02010208
    unsigned int GetEffectiveDeltaTime() const;
    // usa: func_02010210
    unsigned int GetTrueDeltaTime() const;
    // usa: func_02010218
    fix32_t GetAnimationDeltaTime() const;
    // usa: func_02010220
    unsigned int GetTickCount() const;
    // usa: func_02010228
    void SetGameSpeed(fix32_t speed);
    // usa: func_02010234
    fix32_t GetGameSpeed() const;
    // usa: func_02010240
    void AdvanceDayTimer();
    // usa: func_02010280
    float GetDayTimer() const;
    // usa: func_02010288
    void SetDayTimer(float to);
    // usa: func_02010354
    void SetDayTimerRunning(CBool to);
    // usa: func_0201035c
    TimeOfDay GetTimeOfDay() const;
    // usa: func_02010364
    void SetTimeOfDay(TimeOfDay);
    // usa: func_020103b4
    // used for determining inn dialogue, whether you can enter
    // Mirage Mahal/Stornway Castle etc. Not used for town music
    bool IsMorningDayOrEvening() const;

    // --- Grotto/Main/GrottoNameDataFile.cpp ---
    unsigned char* GetTreasureMapLanguageData();
    void SetTreasureMapLanguageDataPtr(unsigned char*);

    // --- Grotto/Main/GrottoStruct.cpp ---
    GrottoStruct* GetGrottoStruct();
};
