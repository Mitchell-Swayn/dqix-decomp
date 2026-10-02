#pragma once

#include "Grotto/Main/ActiveGrottoClass.h"
#include "Memory/SafeAllocator.h"
#include "Graphics/Vector.h"
#include "Graphics/Model3D.h"
#include "Graphics/AtmosphericEffect.h"
#include "Graphics/LightingInfo.h"
#include "Grotto/Main/TileFeatures.h"
#include "ZoneFeatures.h"
#include "MapListLoader.h"
#include "Zone3DContainers.h"

struct Zone3D_StructPtr_8
{
    unsigned short unknown_0_;
    unsigned short unknown_2_ : 15;
    char unk_4;
     // e.g. "F02" or "B01M13", corresponding to file data/map/%s.ambl and similar
    char mapShortName_[7];
    unsigned char unknown_c_low_ : 4;
    unsigned char unknown_c_high_ : 1;
    unsigned char unknown_d_;
    unsigned char unknown_e_low_ : 7;
    unsigned char unknown_e_high_ : 1;
};

// sizeof == 0x2824, as seen in the dynamic allocation of one
// of these in func_ov001_02163b14 (usa).
// In JPN version, sizeof == 0x2864.
// Represents a 3D zone such as a town, field or grotto floor,
// but also a battlefield.
class Zone3D
{
public:
    struct Model3DListNode
    {
        Model3D model_;
        const char* filename_;
        Model3DListNode* pNext_;
    };

    unsigned short currentZoneID_;
    unsigned short previousZoneID_;

    short unknown_4_;
    char unk_6[2];
    Zone3D_StructPtr_8* pUnknownStruct_8_;
    MapListInfo mapListInfo_;
    SafeAllocator* pAllocator_4c_;
    void* unknown_ptr_50_; // referenced in the nsbtx processor, so something graphical
    SafeAllocator internalAllocator_;
    SafeAllocator* pAllocator_68_;

    // Populated from BMBL and BPOS scripts, among other things holds data
    // about warps and placement of stairs/chests in grottos
    ZoneFeatures bFeatures_;
    AtmosphericEffectSet atmosphericEffects_;
    // populated by BATS files.
    // If you remove it, lighting goes weird outdoors, but I don't see any 
    // change in towns / battlefields
    LightingInfo lighting_;
    Model3DListNode* firstModel_418_;
    Zone3D_BMDJStruct* firstBMDJStruct_41c_;
    GrottoTileData* grottoTileMapData_420_;
    int unknown_424_;
    int unknown_428_;
    unsigned char unknown_42c_;
    char unk_42d[3];
    int mapListLoadHandle_; // for loading data/map/maplist9.bin
    int unknown_434_;
    int mapAMBLLoadHandle_; // loads things like data/map/Z02M01.ambl
    int mapAMDJLoadHandle_;
    int atsAMBLLoadHandle_; // data/map/ats_%c.ambl

    Matrix4x3 zoneRotationMatrix_;

    short unknown_474_;
    unsigned char unknown_476_;
    // this seems to include blue and red chests
    unsigned char numChests_;
    ZoneContainerRenderEntry* unknown_478_;
    ZoneChestEntry* unknown_47c_;

    void* containerModels_[6];
    Model3D models_498_[2];
    unsigned int chestPaletteOffsets_[2];
    unsigned int alternateChestPaletteOffsets_[2];
    char unk_600[0x820 - 0x600];
    int unknown_820_;
    Zone3D_BMDJStruct::InstanceEntry** collisionInstances_;
    char unk_828[4];

    int unknown_82c_;

    unsigned char unk_830[4];
    char unknown_834_;
    char unk_835[3];

    int textureImageMemory_;
    int texturePaletteMemory_;

    char unk_840[0x23b8 - 0x840];


    // 0x20 extra bytes unaccounted for in JPN version
    bool isInMainGrottoFloor_23b8_;
    char unknown_23b9_;
    char currentGrottoFloor_23ba_;
    char copyOfCurrentGrottoFloor_23bb_;
    char unk_23bc[4];
    // when you change zones such that you are no longer in a main
    // grotto floor (e.g. you go to boss zone, leave at the top or cast evac)
    // this stores your character position right before you left
    Vector3i position_23c0_;
    unsigned short unknown_23cc_;
    char unk_23ce[0x23ec - 0x23ce];
    ActiveGrottoClass grotto_; // offset 23ec in USA. this is 0x20 bytes larger in JPN
    char unk_2664[0x2724 - 0x2664];
    char unknown_struct_2724_[0xc];
    char unk_2730[0x2744 - 0x2730];
    unsigned char transitionRequests_;
    unsigned char transitionParameter1_;
    unsigned char transitionParameter2_;
    char unk_2747;
    unsigned short transitionParameter3_;
    char unk_274a[0x2754 - 0x274a];
    char unknown_struct_2754_[0x18];
    char unk_276c[0x27d8 - 0x276c];
    unsigned short unknown_27d8_;
    unsigned short unknown_27da_;
    char unk_27dc[0x281d - 0x27dc];
    unsigned char unknown_281d_;
    unsigned char unknown_281e_;
    char unk_281f;
    unsigned char unknown_2820_;
    char unk_2821[3];
public:
    // usa: func_0201383c
    void SwitchZone(unsigned short newID);

    ZoneContainerRenderEntry* GetContainerRenderEntry(int index);
    ZoneChestEntry* GetChestEntry(int index);
    void UpdateChestDiffuseColor();
    void LoadChestModels(SafeAllocator* temporaryAllocator);
    void SetZoneRotation(int angle);
    void CreateContainerRenderEntries(SafeAllocator* allocator);
    void BindContainerModels();
    void SetContainerBrokenMask(unsigned int mask);

    void Update();
    void DrawChestModels();
    void ReleaseChestsForOwner(int ownerIndex);
    bool HasActiveChest();
    void UpdateBMDJInstances(Zone3D_BMDJStruct* group);
    void UpdateBMDJInstance(Zone3D_BMDJStruct::InstanceEntry* instance);

    // Poll queued map loads, then finish zone activation once all are ready.
    bool ProcessPendingLoads();

    // usa: func_02013fb4
    bool ProcessMaplist9();

    // usa: func_0201403c
    // The ambl is a NARC containing nsbtx, bmbl, dat and bpos files.
    void LoadMapAMBL();
    // usa: func_02014108
    bool UnpackMapAMBL();
    // usa: func_02014390
    bool ProcessBMBLFile(const void* filedata, unsigned int filesize);
    // usa: func_020143d8
    bool ProcessBPOSFile(const void* filedata, unsigned int filesize);
    // usa: func_02014414
    bool ProcessBATSFile(const void* filedata, unsigned int filesize);
    
    // usa: func_0201445c
    bool ProcessNSBTXFile(const void* filedata, unsigned int filesize, const char* filename);

    // usa: func_020145a8
    // The amdj is a narc containing nsbmd, nsbma (?), col2 and bmdj files.
    void LoadMapAMDJ();
    // usa: func_020146fc
    bool UnpackMapAMDJ();
    // usa: func_02014900
    bool ProcessBMDJFile(const void* filedata, unsigned int filesize, ZoneFeatures::Opcode64Entry* misc);

    bool ProcessAtmosphericEffects();
    Zone3D_BMDJStruct::InstanceEntry* FindBMDJInstance(int groupID, unsigned short instanceID);
    ZoneFeatures::Opcode6aEntry* FindNearestType10Feature(const Vector3fix* point);
    ZoneFeatures::Opcode6aEntry* FindType10Feature(unsigned short id);
    ZoneFeatures::Opcode6aEntry* FindNearestType11Feature(const Vector3fix* point);
    Zone3D_BMDJStruct::InstanceEntry* FindLastBMDJInstance(int groupID, int instanceID);
    void ApplyBMDJFlag4Overrides(bool alternate);
    void RestoreBMDJFlag4Overrides();
    Zone3D_BMDJStruct* GetBMDJGroupAtIndex(int index);
    bool IsZoneInRuleList(int zoneID);
    void UpdateZone170cInstances(bool first, bool second, bool alternate);
    void RequestBMDJObjectStateReset(int groupID, int instanceID);
    void ResetGrottoStateOutsideGrotto();
    void ProcessTransitionRequests();
    void SetGrottoTransitionRequest(bool enabled, unsigned char first, unsigned char second, unsigned short third);
    void SetTransitionRequest1(bool enabled);
    void SetTransitionRequest2(bool enabled);
    void SetTransitionRequest(int index, bool enabled);
    int GetTransitionRequest(int index);
    void SetUnknown27d8(unsigned short value);
    void SetUnknown27da(unsigned short value);
    bool HasMapFlag10OutsideExcludedZones();
    void ClearInstanceFlag4(int instanceID, int groupID);
    void SetInstanceFlag4(int instanceID, int groupID);
    bool IsInstanceFlag4Clear(int instanceID, int groupID);
    void RecordCurrentZoneFlag();
    int GetZoneRecordFlag(int zoneID);
    void RecordBMDJFlag4State();
    void RestoreBMDJFlag4State();
    void ApplyType2InstanceFlags();
    void ActivateType2Feature(ZoneFeatures::Opcode6aEntry* feature, bool playSound, bool force, int notify);
    void ReverseType2FeatureMotion(ZoneFeatures::Opcode6aEntry* feature);
    void ResetType2FeaturePosition(ZoneFeatures::Opcode6aEntry* feature);
    void ApplyType2FeatureMask(unsigned int mask);
    Zone3D_BMDJStruct::InstanceEntry* FindType2BMDJInstance(ZoneFeatures::Opcode6aEntry* feature);
    int GetType2FeatureIndex(ZoneFeatures::Opcode6aEntry* feature);
    ZoneFeatures::Opcode6aEntry* GetType2Feature(int index);
    void SetBMDJStateRequests();
    void ClearBMDJStateRequests();
    void BuildBMDJInstances(Zone3D_BMDJStruct* group, SafeAllocator* allocator);
    bool BuildBMDJObjects(Zone3D_BMDJStruct* group);
    bool LoadBMDJModel(Zone3D_BMDJStruct* group, Zone3D_BMDJStruct::ObjectEntry* entry, Zone3D_BMDJStruct::StructSizeC* definition);
    bool LoadBMDJAnimatedObject(Zone3D_BMDJStruct::ObjectEntry* entry, Zone3D_BMDJStruct::StructSizeC* definition);
    bool LoadBMDJCollision(Zone3D_BMDJStruct::ObjectEntry* entry, Zone3D_BMDJStruct::StructSizeC* definition);

    // usa: func_02014b04
    void QueueLoadATS_AMBL();
    // usa: func_02014c04
    bool UnpackATS_AMBL();

    // Grotto functionality, this is also part of the class but we keep it in a separate
    // file for now. (It will probably need to go in one file eventually to make
    // data/rodata positioning work)

    // features and floorMap are optional and will default to the instances within
    // the class if NULL. If output is null, then the extended data array at offset
    // 0x420 will be populated instead.
    int ComputeGrottoTileTypes(int floor, ZoneFeatures* features, TileFeaturePlacementData* output, FloorMap* floorMap);
    void RotateGrottoTileFeaturePlacementData(unsigned char* placementArray, int numTurns);
    void RotateGrottoObjectDirectionBitmask(unsigned char* mask, int numTurns);
    int GetGrottoObjectPositionOrientation(int tileX, int tileY, fix32_t* outX, fix32_t* outY,
        const TileFeaturePlacementData* tileDataArray, bool preferFaceDown);

    // pass the contents of data/scenario/treasure.nsarc
    bool PlaceGrottoChestsAndDetermineContents(const void* treasureArchive);
};
