extern "C"
{
// Original data: arm9/ov000 @ 0x2184294; symbol: data_ov000_02184294.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov000.md.
    extern unsigned BattleMenuHandleSkillListInput_UnknownRoleZeroInitializedStorage[];
// Original data: arm9/main @ 0x2114e30; symbol: data_02114e30.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
    extern char KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage[];
    int Input_IsKeyMaskNewlyPressed(void*,int);
    int TestSelectedRecordReadyAndByteFlagBitOne(char*,int);
}
// Layout projections describe observed offsets; higher-level ownership is unresolved.
// Original: arm9/ov000 @ 0x0217C594; symbol: func_ov000_0217c594; size: 0x60.
extern "C" bool BattleMenu_TestConfirmInputAfterDelay(unsigned char *p,int delay)
{
    if(p[0x956]<delay)
    {
        ++p[0x956];
        return false;
    }
    BattleMenuHandleSkillListInput_UnknownRoleZeroInitializedStorage[2]=(unsigned)p;
    int a=Input_IsKeyMaskNewlyPressed(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,0x601);
    return (a|TestSelectedRecordReadyAndByteFlagBitOne((char*)p+0x188,20))!=0;
}
