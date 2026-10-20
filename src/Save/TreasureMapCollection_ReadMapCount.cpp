extern "C" int GameState_ReadTreasureMapCollectionCount(unsigned char* count);

// Original: arm9/main @ 0x02011804; symbol: func_02011804; size: 0x14.
extern "C" unsigned char TreasureMapCollection_ReadMapCount()
{
    unsigned char count;
    GameState_ReadTreasureMapCollectionCount(&count);
    return count;
}
