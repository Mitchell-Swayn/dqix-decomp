#pragma once

// Layout carrier for the original contiguous Zone3D string pool.
// This grouping does not imply an original source struct.
struct Zone3DPathStrings
{
    char mapList[22];
    char grottoFloorAMBL[16];
    char mapRoot[9];
    char grottoEntranceAMBL[16];
    char zoneAMBL[11];
    char archiveMount[4];
    char textureExtension[7];
    char mapBinaryExtension[6];
    char dataExtension[5];
    char positionExtension[6];
    char grottoFloorAMDJ[16];
    char grottoEntranceAMDJ[16];
    char zoneObjectsVariantB[12];
    char zoneObjectsVariantA[12];
    char zoneObjects[11];
    char objectsExtension[6];
    char grottoRoom0[10];
    char grottoRoom1[10];
    char grottoRoom2[10];
    char grottoRoom3[10];
    char atmosphereArchive[15];
    char atmosphereBinary[8];
    char archiveMember[8];
    char extensionSeparator[2];
    char modelExtension[6];
    char collisionExtension[5];
    char openAnimation[5];
    char openAnimation2[6];
    char closeAnimation[6];
    char closeAnimation2[7];
    char doorSprite[23];
    char potBreakAnimation[10];
    char archivePath[7];
    char dungeonModel03[15];
    char dungeonModel04[15];
    char dungeonModel01[15];
};

extern Zone3DPathStrings gZone3DPaths;
