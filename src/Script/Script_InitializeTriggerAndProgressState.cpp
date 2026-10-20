extern "C" void Script_ResetSerializedProgressState();
extern "C" void Script_ResetTriggerGroupsAndProgressState(void*);
// Original: arm9/main @ 0x02064D1C; symbol: func_02064d1c; size: 0x1C.
extern "C" void* Script_InitializeTriggerAndProgressState(void* object)
{
    Script_ResetSerializedProgressState();
    Script_ResetTriggerGroupsAndProgressState(object);
    return object;
}
