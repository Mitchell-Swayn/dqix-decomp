#pragma thumb off
#pragma optimization_level 2
#pragma optimize_for_size off

struct ByteWriter { unsigned remaining; unsigned char* cursor; };
// Original: arm9/main @ 0x020D3084; symbol: func_020d3084; size: 0x30.
extern "C" void StringWriter_AppendByteAndAdvancePastCapacity(ByteWriter* writer, unsigned char value) {
    if (writer->remaining) { *writer->cursor = value; --writer->remaining; }
    ++writer->cursor;
}
