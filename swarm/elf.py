"""Minimal little-endian ELF32 reader: sections, symbols and relocations."""
import struct

SHT_SYMTAB, SHT_RELA, SHT_NOBITS, SHT_REL = 2, 4, 8, 9
STT_FUNC, STT_SECTION = 2, 3
SHN_UNDEF = 0


class Elf:
    def __init__(self, data):
        if len(data) < 52 or data[:6] != b'\x7fELF\x01\x01':
            raise ValueError('not a little-endian ELF32 object')
        self.data = data
        shoff, = struct.unpack_from('<I', data, 32)
        shentsize, shnum, shstrndx = struct.unpack_from('<HHH', data, 46)
        self.sections = []
        for i in range(shnum):
            name, kind, flags, addr, off, size, link, info, align, entsize = struct.unpack_from(
                '<10I', data, shoff + i * shentsize)
            self.sections.append(dict(index=i, name_off=name, type=kind, flags=flags, offset=off,
                                      size=size, link=link, info=info, entsize=entsize))
        names = self.raw(self.sections[shstrndx])
        for s in self.sections:
            s['name'] = _cstr(names, s['name_off'])
        self.symbols = []
        symtab = next((s for s in self.sections if s['type'] == SHT_SYMTAB), None)
        if symtab:
            strings = self.raw(self.sections[symtab['link']])
            raw = self.raw(symtab)
            for pos in range(0, len(raw), 16):
                name, value, size, info, other, shndx = struct.unpack_from('<IIIBBH', raw, pos)
                self.symbols.append(dict(name=_cstr(strings, name), value=value, size=size,
                                         type=info & 15, bind=info >> 4, shndx=shndx))
        # Relocations grouped by the section they apply to.
        self.relocations = {}
        for s in self.sections:
            if s['type'] not in (SHT_REL, SHT_RELA):
                continue
            raw, step = self.raw(s), 12 if s['type'] == SHT_RELA else 8
            target = self.sections[s['info']]
            rows = self.relocations.setdefault(s['info'], [])
            for pos in range(0, len(raw), step):
                offset, info = struct.unpack_from('<II', raw, pos)
                if s['type'] == SHT_RELA:
                    addend, = struct.unpack_from('<i', raw, pos + 8)
                else:  # Implicit addend: only meaningful for ABS32 words.
                    addend, = struct.unpack_from('<i', self.raw(target), offset)
                rows.append(dict(offset=offset, type=info & 0xff, symbol=self.symbols[info >> 8], addend=addend))

    def raw(self, section):
        if section['type'] == SHT_NOBITS:
            return b''
        return self.data[section['offset']:section['offset'] + section['size']]

    def functions(self):
        """Defined, sized function symbols in executable sections."""
        return [s for s in self.symbols if s['type'] == STT_FUNC and s['size'] and s['shndx'] != SHN_UNDEF
                and s['shndx'] < len(self.sections) and self.sections[s['shndx']]['flags'] & 4]


def _cstr(table, offset):
    return table[offset:table.index(b'\0', offset)].decode('utf-8', 'replace')
