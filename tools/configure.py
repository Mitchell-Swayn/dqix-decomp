#!/usr/bin/env python3

import os
from pathlib import Path
import argparse
import json
import re
import sys

import ninja_syntax
from linker_retention import retained_data_symbols
from get_platform import get_platform


DEFAULT_WIBO_PATH = "./wibo"


parser = argparse.ArgumentParser(description="Generates build.ninja")
parser.add_argument('-w', type=str, default=DEFAULT_WIBO_PATH, dest="wine", required=False, help="Path to Wine/Wibo (linux only)")
parser.add_argument("--compiler", type=Path, required=False, help="Path to pre-installed compiler root directory")
parser.add_argument('--objdiff', type=Path, help='Path to pre-installed objdiff CLI')
parser.add_argument('--keep-symbol', action='append', default=[], help='Preserve an original unused function during linking (repeatable)')
parser.add_argument("--no-extract", action="store_true", help="Skip extract step")
parser.add_argument("--dsd", type=Path, required=False, help="Path to pre-installed dsd CLI")
parser.add_argument('version', help='Game version')
args = parser.parse_args()


# Config
GAME = "dqix"
DSD_VERSION = 'v0.10.2'
WIBO_VERSION = '0.6.16'
OBJDIFF_VERSION = 'v2.7.1'
MWCC_VERSION = "2.0/sp2p2" # minimum version required to match fixed point s64 arithmetic around 0x02030f30 (not sdk code). might need p3 or p4?
DECOMP_ME_COMPILER = "mwcc_30_137"
CC_FLAGS = " ".join([
    "-O2",                  # Optimize maximally, omit p: it optimizes out things that the game doesn't normally
    "-enum int",            # Use int-sized enums
    "-char signed",         # Char type is signed
    "-str noreuse",         # Equivalent strings are different objects
    "-proc arm946e",        # Target processor
    "-gccext,on",           # Enable GCC extensions
    "-fp soft",             # Compute float operations in software
    "-inline noauto",       # Inline only functions marked with 'inline'
    "-lang=c++",            # Set language to C++
    "-Cpp_exceptions off",  # Disable C++ exceptions
    "-RTTI off",            # Disable runtime type information
    "-interworking",        # Enable ARM/Thumb interworking
    "-w off",               # Disable warnings
    "-sym on",              # Debug info, including line numbers
    "-gccinc",              # Interpret #include "..." and #include <...> equally
    "-nolink",              # Do not link
    "-msgstyle gcc",        # Use GCC-like messages (some IDEs will make file names clickable)
    "-str pool,reuse"       # Pool and reuse strings within translation units
])
active_function_name = "-force_active func_ov030_021d8a40,func_ov020_0218b5a0,func_ov011_02184a18"
if args.version == "jpn":
    active_function_name = "-force_active func_ov029_021d9300,func_ov030_021d9300"
if any(not re.fullmatch(r'[A-Za-z_][A-Za-z0-9_]*', name) for name in args.keep_symbol):
    parser.error('keep-symbol must be a plain symbol identifier')
try:
    declarative_retained_data = retained_data_symbols(Path(__file__).resolve().parents[1], args.version)
except (OSError, ValueError, KeyError, TypeError) as error:
    parser.error(str(error))
retained_data_names = ','.join(declarative_retained_data)
from runtime_code_retention import all_retained_symbols
declarative_retained_code = all_retained_symbols(Path(__file__).resolve().parents[1], verify_original=False)
retained_code_names = ','.join(declarative_retained_code)
if declarative_retained_code:
    active_function_name += ',' + retained_code_names
if declarative_retained_data:
    active_function_name += ',' + ','.join(declarative_retained_data)
# Accept historical identities used by existing build commands after source renaming.
naming_registry = Path(__file__).resolve().parents[1] / 'config' / args.version / 'function_names.json'
if naming_registry.exists():
    renamed_functions = json.loads(naming_registry.read_text())['functions'].values()
    historical_names = {row['old_symbol']: row['new_symbol'] for row in renamed_functions}
    args.keep_symbol = [historical_names.get(name, name) for name in args.keep_symbol]
if args.keep_symbol:
    active_function_name += ',' + ','.join(args.keep_symbol)
LD_FLAGS = " ".join([
    "-proc arm946e",        # Target processor
    "-nostdlib",            # No C/C++ standard library
    "-interworking",        # Enable ARM/Thumb interworking
    "-m Entry",             # Set entry function
    "-map closure,unused",  # Generate map file
    "-msgstyle gcc",        # Use GCC-like messages (some IDEs will make file names clickable)
    "-dead",                # Don't allow dead code
    active_function_name    # fix issue with overlay 30 being excluded by the previous command
])
DSD_OBJDIFF_ARGS = " ".join([
    "--scratch",                        # Metadata for creating decomp.me scratches
    f"--compiler {DECOMP_ME_COMPILER}", # decomp.me compiler name
    f'--c-flags "{CC_FLAGS} -lang=c++"',# decomp.me compiler flags
    "--custom-make ninja",              # Command for rebuilding files
])


# Paths
current_path     = Path(__name__)
root_path        = current_path.parent
build_ninja_path = root_path / "build.ninja"
arm7_bios_path   = root_path / "arm7_bios.bin"
config_path      = root_path / "config"
build_path       = root_path / "build"
src_path         = root_path / "src"
libs_path        = root_path / "libs"
extract_path     = root_path / "extract"
tools_path       = root_path / "tools"
mwcc_root        = args.compiler or tools_path / "mwccarm"
mwcc_path        = mwcc_root / MWCC_VERSION


# Includes
includes = [
    str(root_path / "include")
]
for root, dirs, _ in os.walk(libs_path):
    for dir in dirs:
        if dir == "include":
            includes.append(Path(root) / dir)
CC_INCLUDES = " ".join(f"-i {include}" for include in includes)


# Platform info
platform = get_platform()
if platform is None:
    exit(1)
EXE = platform.exe
WINE = args.wine if platform.system != "windows" else ""
DSD = str(args.dsd or os.path.join('.', str(root_path / f"dsd{EXE}")))
OBJDIFF = str(args.objdiff or os.path.join('.', str(root_path / f"objdiff-cli{EXE}")))
from objdiff_profile import resolve_objdiff
OBJDIFF_POLICY = config_path / args.version / "objdiff_tool.json"
OBJDIFF = resolve_objdiff(root_path, args.version, OBJDIFF)
OBJDIFF_PROFILE_DEPS = ([str(OBJDIFF_POLICY), "tools/objdiff_profile.py",
    "tools/patches/objdiff-2.7.1-arm-empty-map.patch"] if OBJDIFF_POLICY.exists() else [])
CC = os.path.join('.', str(mwcc_path / "mwccarm.exe"))
LD = os.path.join('.', str(mwcc_path / "mwldarm.exe"))
AS = os.path.join('.', str(mwcc_path / "mwasmarm.exe"))
PYTHON = sys.executable


class Project:
    def __init__(self, game_version: str):
        self.game_version = game_version
        '''Version of the game'''
        self.game_config = config_path / game_version
        '''Root directory for dsd configs'''

        if not self.game_config.is_dir():
            print(f"Version '{game_version}' not recognized")
            exit(1)

        self.game_build = build_path / game_version
        '''Path to build directory'''
        self.game_extract = extract_path / game_version
        '''Path to extract directory'''

        self.delinks_files = get_config_files(self.game_config, "delinks.txt")
        '''Paths to every delinks.txt file'''
        self.relocs_files = get_config_files(self.game_config, "relocs.txt")
        '''Paths to every relocs.txt file'''
        self.symbols_files = get_config_files(self.game_config, "symbols.txt")
        '''Paths to every symbols.txt file'''

    def dsd_configs(self) -> list[str]:
        return self.delinks_files + self.relocs_files + self.symbols_files

    def arm9_config_yaml(self) -> Path:
        return self.game_config / "arm9" / "config.yaml"

    def baserom(self) -> Path:
        return extract_path / f'baserom_{GAME}_{self.game_version}.nds'

    def build_rom(self) -> str:
        return f"{GAME}_{self.game_version}.nds"

    def baserom_config(self) -> Path:
        return self.game_extract / 'config.yaml'

    def build_rom_config(self) -> Path:
        return self.game_build / "build" / "rom_config.yaml"

    def source_object_files(self) -> list[str]:
        return [
            str(self.game_build / source_file.with_suffix(".o"))
            for source_file in get_c_cpp_files([src_path, libs_path])
        ]

    def arm9_lcf(self) -> Path:
        return self.game_build / "arm9.lcf"

    def arm9_objects_txt(self) -> Path:
        return self.game_build / "objects.txt"

    def arm9_delink_completion(self) -> Path:
        return self.game_build / "delinks" / "completion.json"

    def arm9_o(self) -> Path:
        return self.game_build / "arm9.o"

    def arm9_delinks(self) -> Path:
        return self.game_build / "delinks"

    def objdiff_report(self) -> Path:
        return self.game_build / "report.json"


def main():
    project = Project(args.version)

    with build_ninja_path.open("w") as file:
        n = ninja_syntax.Writer(file)
        n.variable("ninja_required_version", "1.10")  # Dynamic delink outputs.
        n.newline()

        n.rule(
            name="download_tool",
            command=f'{PYTHON} tools/download_tool.py $tool $tag --path $path'
        )
        n.newline()

        if arm7_bios_path.is_file():
            n.variable("arm7_bios_flag", f"--arm7-bios {arm7_bios_path.relative_to(root_path)}")
        else:
            n.variable("arm7_bios_flag", "")
        n.newline()

        n.rule(
            name="extract",
            command=f"{DSD} rom extract --rom $in --output-path $output_path $arm7_bios_flag"
        )
        n.newline()

        n.rule(
            name="delink",
            command=f'"{PYTHON}" tools/delink_outputs.py run --dsd "{DSD}" --config "$config_path" --directory "$directory" --plan "$plan" --completion "$completion"'
        )
        n.newline()

        n.rule(
            name="delink_plan",
            command=f'"{PYTHON}" tools/delink_outputs.py plan --objdiff objdiff.json --extract "$extract" --directory "$directory" --plan "$plan" --completion "$completion" --dyndep "$dyndep_file" --depfile "$dyndep_file.d"',
            depfile="$dyndep_file.d",
        )
        n.newline()

        # -MMD excludes all includes instead of just system includes for some reason, so use -MD instead.
        mwcc_cmd = f'{WINE} "{CC}" {CC_FLAGS} {CC_INCLUDES} $cc_flags -d $game_version -MD -c $in -o $basedir'
        mwcc_implicit = [CC]
        if platform.system != "windows":
            transform_dep = "tools/transform_dep.py"
            mwcc_cmd += f' && "{PYTHON}" {transform_dep} $basefile.d $basefile.d'
            mwcc_implicit.append(transform_dep)
        n.rule(
            name="mwcc",
            command=mwcc_cmd,
            depfile="$basefile.d",
        )
        n.newline()

        n.rule(name="mwcc_profile", command=f'{WINE} "$profile_cc" $profile_flags {CC_INCLUDES} -d $game_version -MD -c $in -o $basedir && "{PYTHON}" tools/transform_dep.py $basefile.d $basefile.d', depfile="$basefile.d")
        n.rule(name="mwcc_profile_member_aliases", command=f'{WINE} "$profile_cc" $profile_flags {CC_INCLUDES} -d $game_version -MD -c $in -o $basedir && "{PYTHON}" tools/transform_dep.py $basefile.d $basefile.d && "{PYTHON}" tools/normalize_source_member_aliases.py $out $in $profile_policy "$profile_cc"', depfile="$basefile.d")
        n.rule(name="mwcc_profile_source_extents", command=f'{WINE} "$profile_cc" $profile_flags {CC_INCLUDES} -d $game_version -MD -c $in -o $basedir && "{PYTHON}" tools/transform_dep.py $basefile.d $basefile.d && "{PYTHON}" tools/normalize_source_extents.py $out $in $profile_policy "$profile_cc"', depfile="$basefile.d")
        n.rule(name="mwcc_profile_absolute_symbols", command=f'{WINE} "$profile_cc" $profile_flags {CC_INCLUDES} -d $game_version -MD -c $in -o $basedir && "{PYTHON}" tools/transform_dep.py $basefile.d $basefile.d && "{PYTHON}" tools/partial_link_absolute_symbols.py $out $in $profile_policy "$profile_cc"', depfile="$basefile.d")
        n.rule(name="mwcc_runtime_inline", command=f'{WINE} "{CC}" {CC_FLAGS} {CC_INCLUDES} -lang=c++ -d $game_version -MD -c $in -o $basedir && "{PYTHON}" tools/transform_dep.py $basefile.d $basefile.d && "{PYTHON}" tools/normalize_runtime_inline.py $out $in', depfile="$basefile.d", deps="gcc")
        n.rule(name="mwasm", command=f'{WINE} "{AS}" -gnu -case -proc arm5TE -32 -c $in -o $out && "{PYTHON}" tools/normalize_asm_mapping.py $out')
        n.newline()

        n.rule(
            name="lcf",
           # command=f"{DSD} lcf -c $config_path --lcf-file $lcf_file --objects-file $objects_file"
            command=f'{PYTHON} tools/generate_lcf.py --dsd "{DSD}" --config-path $config_path --lcf-path $lcf_file'
        )
        n.newline()

        n.rule(
            name="mwld",
            command=(f'{PYTHON} tools/runtime_code_retention.py --root . --expected "{retained_code_names}" && '
                     f'{PYTHON} tools/linker_retention.py --root . --version {args.version} '
                     f'--expected "{retained_data_names}" && '
                     f'{PYTHON} tools/prepare_link_objects.py --objects "$objects_file" '
                     f'--fallback-dir "$fallback_dir" --output-dir "$link_objects_dir" '
                     f'--output-list "$link_objects_file" --report "$link_objects_report" '
                     f'--symbol-config "$symbol_config" --lcf "$lcf_file" --link-command '
                     f'{WINE} "{LD}" {LD_FLAGS} @"$link_objects_file" $lcf_file -o $out')
        )
        n.newline()

        n.rule(
            name="rom_config",
            command=(f'{PYTHON} tools/stable_rom_config.py --dsd "{DSD}" '
                     f'--elf $in --config $config_path --output $out'),
            restat=True,
        )
        n.newline()

        n.rule(
            name="rom_build",
            command=(f'"{PYTHON}" tools/guard_rom_files.py --input "$baserom" '
                     f'--output "$out" $final_output_flag -- '
                     f'"{DSD}" rom build --config $in --rom $out $arm7_bios_flag')
        )
        n.newline()

        n.rule(
            name="objdiff",
            command=f"{DSD} objdiff --config-path $config_path {DSD_OBJDIFF_ARGS}"
        )
        n.newline()

        n.rule(
            name="objdiff_report",
            command=f"{OBJDIFF} report generate -o $out"
        )
        n.newline()

        n.rule(
            name="m2ctx",
            command=f"{PYTHON} tools/m2ctx.py -f $out $in"
        )
        n.newline()

        n.rule(
            name="check_modules",
            command=f"{DSD} check modules --config-path $config_path --fail"
        )
        n.newline()

        n.rule(
            name="check_symbols",
            command=f"{DSD} check symbols --config-path $config_path --elf-path $elf_path --fail"
        )
        n.newline()

        n.rule(
            name="sha1",
            command=f"{PYTHON} tools/sha1.py $in -c $sha1_file"
        )
        n.newline()

        add_download_tool_builds(n)
        add_extract_build(n, project)
        add_delink_and_lcf_builds(n, project)
        add_mwcc_builds(n, project, mwcc_implicit)
        add_mwld_and_rom_builds(n, project)
        add_check_builds(n, project)
        add_objdiff_builds(n, project)


def add_download_tool_builds(n: ninja_syntax.Writer):
    if args.dsd is None:
        n.build(
            rule="download_tool",
            outputs=DSD,
            variables={
                "tool": "dsd",
                "tag": DSD_VERSION,
                "path": DSD,
            },
        )
        n.newline()

    if args.objdiff is None and not OBJDIFF_POLICY.exists():
        n.build(
            rule="download_tool",
            outputs=OBJDIFF,
            variables={
                "tool": "objdiff",
                "tag": OBJDIFF_VERSION,
                "path": OBJDIFF,
            }
        )
        n.newline()

    if args.compiler is None:
        n.build(
            rule="download_tool",
            outputs=[CC, LD],
            variables={
                "tool": "mwccarm",
                "tag": "latest",
                "path": tools_path,
            },
        )
        n.newline()

    if platform.system != "windows" and WINE == DEFAULT_WIBO_PATH:
        n.build(
            rule="download_tool",
            outputs=WINE,
            variables={
                "tool": "wibo",
                "tag": WIBO_VERSION,
                "path": WINE,
            },
        )
        n.newline()


def add_extract_build(n: ninja_syntax.Writer, project: Project):
    if not args.no_extract:
        n.build(
            inputs=str(project.baserom()),
            implicit=DSD,
            rule="extract",
            outputs=str(project.baserom_config()),
            variables={
                "output_path": str(project.game_extract)
            }
        )
        n.newline()


def add_mwld_and_rom_builds(n: ninja_syntax.Writer, project: Project):
    lcf_file = str(project.arm9_lcf())
    objects_file = str(project.arm9_objects_txt())
    delink_file = str(project.arm9_delink_completion())
    elf_file = str(project.arm9_o())
    n.build(
        inputs=project.source_object_files() + [lcf_file, objects_file, delink_file],
        implicit=[LD, "tools/prepare_link_objects.py", "tools/short_link.py", "tools/linker_retention.py", "tools/runtime_code_retention.py", "config/usa/arm9/runtime_support.json"] +
                 [str(path) for path in sorted((project.game_config / "arm9").rglob("retained_data.json"))],
        rule="mwld",
        outputs=elf_file,
        variables={
            "target_dir": project.game_build,
            "fallback_dir": project.arm9_delinks(),
            "symbol_config": project.game_config / "arm9" / "symbols.txt",
            "link_objects_dir": project.game_build / "link_objects",
            "link_objects_file": project.game_build / "link_objects.txt",
            "link_objects_report": project.game_build / "link_objects_report.json",
            "objects_file": objects_file,
            "lcf_file": lcf_file,
        }
    )
    n.newline()

    n.build(
        inputs=elf_file,
        rule="phony",
        outputs="arm9",
    )
    n.newline()

    rom_config_file = str(project.build_rom_config())
    n.build(
        inputs=elf_file,
        implicit=[DSD, "tools/stable_rom_config.py"],
        rule="rom_config",
        outputs=rom_config_file,
        variables={
            "config_path": project.arm9_config_yaml(),
        }
    )
    n.newline()

    rom_file = project.build_rom()
    # ROM metadata can be unchanged after an ARM9 relink. The ROM must still
    # package the freshly linked program even when restat skips ARM7 rebuilding.
    rom_implicit = [DSD, "tools/guard_rom_files.py", elf_file]
    if project.game_version == "usa":
        arm7_units_path = project.game_config / "arm7" / "source_units.json"
        arm7_units = json.loads(arm7_units_path.read_text())
        arm7_output = project.game_build / "arm7"
        arm7_rom_config = str(project.game_build / "build" / "rom_config_arm7.yaml")
        arm7_depfile = str(arm7_output / "arm7.d")
        runner_flag = f' --runner "{WINE}"' if WINE else ""
        n.rule(
            name="arm7_source",
            command=(f'{PYTHON} tools/arm7_build.py --compiler "{mwcc_path}"'
                     f' --output "{arm7_output}" --rom-config $rom_config'
                     f' --output-rom-config "{arm7_rom_config}"'
                     f' --depfile "{arm7_depfile}" --dep-target "{arm7_rom_config}"{runner_flag}'),
            depfile=arm7_depfile,
        )
        n.build(
            inputs=rom_config_file,
            implicit=[str(project.baserom()), str(arm7_units_path),
                      "config/usa/arm7/baseline.json", "tools/arm7_build.py",
                      "tools/check_arm7.py", "tools/arm7_dependencies.py", CC, LD] +
                     [unit["source"] for unit in arm7_units["units"]] +
                     [unit["assembly_exception"] for unit in arm7_units["units"]
                      if "assembly_exception" in unit],
            rule="arm7_source",
            outputs=[arm7_rom_config, str(arm7_output / "arm7.bin"),
                     str(arm7_output / "report.json")],
            variables={"rom_config": rom_config_file},
        )
        n.newline()
        rom_config_file = arm7_rom_config
        rom_implicit.append(str(arm7_output / "arm7.bin"))

    n.build(
        inputs=rom_config_file,
        implicit=rom_implicit,
        rule="rom_build",
        outputs=str(project.game_build / "unfinalized.nds") if project.game_version == "usa" else rom_file,
        variables={"baserom": project.baserom(),
                   "final_output_flag": f'--output "{rom_file}"' if project.game_version == "usa" else ""},
    )
    n.newline()

    if project.game_version == "usa":
        n.rule(
            name="finalize_usa_header",
            command=(f"{PYTHON} tools/finalize_rom_header.py $in $out"
                     f" --baserom {project.baserom()}"),
        )
        n.build(
            inputs=str(project.game_build / "unfinalized.nds"),
            implicit=[str(project.baserom()), "tools/finalize_rom_header.py", "tools/guard_rom_files.py"],
            rule="finalize_usa_header",
            outputs=rom_file,
        )
        n.newline()

    n.build(
        inputs=rom_file,
        rule="phony",
        outputs="rom",
    )
    n.newline()

    n.build(
        inputs=rom_file,
        rule="sha1",
        variables={
            "sha1_file": str(Path(rom_file).with_suffix(".sha1"))
        },
        outputs="sha1",
    )
    n.newline()


def add_mwcc_builds(n: ninja_syntax.Writer, project: Project, mwcc_implicit: list[Path]):
    import hashlib, shlex
    profile_path = Path("config") / project.game_version / "compiler_profiles.json"
    profiles = json.loads(profile_path.read_text()).get("sources", {}) if profile_path.exists() else {}
    member_layout_outputs = set()
    for source_file in get_c_cpp_files([src_path, libs_path]):
        src_obj_path = project.game_build / source_file
        if source_file.suffix == ".s":
            n.build(inputs=str(source_file), implicit=[AS, 'tools/normalize_asm_mapping.py'], rule="mwasm",
                    outputs=str(src_obj_path.with_suffix(".o")))
            n.newline()
            continue
        cc_flags = []
        runtime_inline = source_file.parent == Path("src/RuntimeSupport") and source_file.suffix == ".cpp"
        if is_cpp(source_file): cc_flags.append("-lang=c++")
        elif is_c(source_file): cc_flags.append("-lang=c")
        profile = profiles.get(str(source_file))
        profile_variables = {}
        profile_dependencies = []
        if profile:
            if runtime_inline:
                raise ValueError("Runtime assembly cannot silently use a C compiler profile")
            executable = Path(CC if profile["executable"] == "configured_default" else profile["executable"])
            if hashlib.sha256(executable.read_bytes()).hexdigest() != profile["executable_sha256"]:
                raise ValueError("Profile compiler hash mismatch: " + str(executable))
            profile_variables = {"profile_cc": str(executable), "profile_flags": shlex.join(profile["flags"])}
            profile_dependencies = [str(profile_path)] + [str(p) for p in executable.parent.iterdir() if p.is_file()]
            if profile.get("absolute_linker_symbols"):
                if profile.get("member_aliases") or profile.get("function_extents"):
                    raise ValueError("Combining source metadata transforms needs explicit review")
                profile_variables["profile_policy"] = str(profile_path)
                profile_dependencies += ["tools/partial_link_absolute_symbols.py", "tools/normalize_source_member_aliases.py", profile["absolute_linker_symbols"]["policy"]]
            if profile.get("function_extents"):
                if profile.get("member_aliases"):
                    raise ValueError("Source extent and member-alias policies must be reviewed separately")
                profile_variables["profile_policy"] = str(profile_path)
                profile_dependencies += ["tools/normalize_source_extents.py", "tools/normalize_source_member_aliases.py"]
            if profile.get("member_aliases"):
                profile_variables["profile_policy"] = str(profile_path)
                profile_dependencies += ["tools/normalize_source_member_aliases.py"]
                for alias in profile["member_aliases"]:
                    profile_dependencies += [alias["owner_source"], alias["layout_header"], alias["owner_object"]]
                    profile_dependencies += [alias["layout_source"], alias["layout_object"]]
                    if alias["layout_object"] not in member_layout_outputs:
                        layout_object = Path(alias["layout_object"])
                        n.build(inputs=alias["layout_source"], outputs=str(layout_object), rule="mwcc_profile",
                                implicit=[str(profile_path), str(executable), alias["layout_header"]],
                                variables={"profile_cc": str(executable), "profile_flags": shlex.join(profile["flags"]),
                                           "game_version": project.game_version, "basedir": str(layout_object.parent),
                                           "basefile": str(layout_object.with_suffix(""))})
                        member_layout_outputs.add(alias["layout_object"])


        n.build(
            inputs=str(source_file),
            implicit=(profile_dependencies if profile else mwcc_implicit) + (["tools/normalize_runtime_inline.py", "config/usa/arm9/runtime_support.json"] if runtime_inline else []),
            rule=("mwcc_profile_absolute_symbols" if profile.get("absolute_linker_symbols") else "mwcc_profile_source_extents" if profile.get("function_extents") else "mwcc_profile_member_aliases" if profile.get("member_aliases") else "mwcc_profile") if profile else ("mwcc_runtime_inline" if runtime_inline else "mwcc"),
            outputs=str(src_obj_path.with_suffix(".o")),
            variables={
                "game_version": project.game_version,
                "cc_flags": " ".join(cc_flags),
                "basedir": os.path.dirname(src_obj_path),
                "basefile": str(src_obj_path.with_suffix("")),
                **profile_variables,
            },
        )
        n.newline()

        extension = source_file.suffix
        ctx_file = str(project.game_build / source_file.with_suffix(f".ctx{extension}"))
        n.build(
            inputs=str(source_file),
            rule="m2ctx",
            outputs=ctx_file,
        )
        n.newline()


def get_c_cpp_files(dirs: list[Path]):
    for dir in dirs:
        for root, _, files in os.walk(dir):
            root = Path(root)
            for file in files:
                if is_cpp(file) or is_c(file) or Path(file).suffix == ".s":
                    yield root / file


def is_cpp(name: str):
    return Path(name).suffix in [".cpp"]


def is_c(name: str):
    return Path(name).suffix in [".c"]


def add_delink_and_lcf_builds(n: ninja_syntax.Writer, project: Project):
    n.comment("Track every real dsd ELF output, including dynamic fallback units")
    rom_config = str(project.baserom_config())
    delinks_path = project.arm9_delinks()
    completion = str(project.arm9_delink_completion())
    plan = str(delinks_path / "outputs.json")
    dyndep = str(delinks_path / "outputs.dd")
    common = {"directory": delinks_path, "completion": completion, "plan": plan}
    n.build(
        outputs=[dyndep, plan], rule="delink_plan",
        inputs=["objdiff.json", rom_config],
        implicit=["tools/delink_outputs.py"],
        variables={**common, "extract": project.game_extract, "dyndep_file": dyndep},
    )
    n.newline()
    n.build(
        inputs=project.dsd_configs() + [rom_config, str(project.arm9_config_yaml()), plan],
        implicit=[DSD, "tools/delink_outputs.py"],
        order_only=[dyndep], rule="delink", outputs=completion,
        variables={**common, "config_path": project.arm9_config_yaml(), "dyndep": dyndep},
    )
    n.newline()
    n.build(inputs=completion, rule="phony", outputs="delink")
    n.newline()

    from lcf_tool import dependencies as lcf_tool_dependencies
    lcf_file = project.arm9_lcf()
    objects_file = project.arm9_objects_txt()
    n.build(
        inputs=project.delinks_files + project.symbols_files + [str(rom_config), str(project.arm9_config_yaml())],
        implicit=[DSD, "tools/generate_lcf.py", "tools/runtime_support.py", "tools/lcf_tool.py"] + [str(path) for path in project.arm9_config_yaml().parent.parent.glob("keep_symbols.txt")] + lcf_tool_dependencies(root_path, project.arm9_config_yaml()) + [str(path) for path in project.arm9_config_yaml().parent.glob("runtime_support.json")] + [
            str(path) for path in sorted(project.arm9_config_yaml().parent.rglob("linker_symbols.json"))
        ],
        rule="lcf",
        outputs=[str(lcf_file), str(objects_file)],
        variables={
            "config_path": project.arm9_config_yaml(),
            "lcf_file": lcf_file,
            "objects_file": objects_file,
        }
    )
    n.newline()


def add_check_builds(n: ninja_syntax.Writer, project: Project):
    check_inputs = ["check_modules", "check_symbols"]
    if project.game_version == "usa":
        # dsd verifies only ARM9. Keep the cartridge ARM7 preservation check
        # separate and explicit: binary equality does not earn source coverage.
        n.rule(
            name="check_arm7",
            command=f"{PYTHON} tools/check_arm7.py",
        )
        n.build(
            inputs=[project.build_rom(), str(project.baserom()),
                    "config/usa/arm7/baseline.json", "tools/check_arm7.py"],
            rule="check_arm7",
            outputs="check_arm7",
        )
        check_inputs.append("check_arm7")
        n.rule(name="check_progress", command=f"{PYTHON} tools/check_progress.py")
        n.build(
            inputs=[str(project.objdiff_report()), "docs/inventory-usa-report.json.gz",
                    "tools/check_progress.py"],
            rule="check_progress",
            outputs="check_progress",
        )
        check_inputs.append("check_progress")
        n.newline()

    n.build(
        inputs=str(project.arm9_o()),
        rule="check_modules",
        outputs="check_modules",
        variables={
            "config_path": project.arm9_config_yaml(),
        },
    )
    n.newline()

    n.build(
        inputs=str(project.arm9_o()),
        rule="check_symbols",
        outputs="check_symbols",
        variables={
            "config_path": project.arm9_config_yaml(),
            "elf_path": project.arm9_o(),
        },
    )
    n.newline()

    n.build(
        inputs=check_inputs,
        rule="phony",
        outputs="check",
    )
    n.newline()


def add_objdiff_builds(n: ninja_syntax.Writer, project: Project):
    n.build(
        inputs=project.dsd_configs() + [str(project.arm9_config_yaml())],
        implicit=DSD,
        rule="objdiff",
        outputs="objdiff.json",
        variables={
            "config_path": project.arm9_config_yaml(),
        }
    )
    n.newline()

    n.build(
        inputs="objdiff.json",
        rule="phony",
        outputs="objdiff",
    )
    n.newline()

    n.build(
        inputs=["objdiff.json"],
        # objdiff reads original objects written by delink. Without this edge,
        # parallel builds can compare stale objects or race their replacement.
        implicit=[OBJDIFF, str(project.arm9_delink_completion())] + OBJDIFF_PROFILE_DEPS + project.source_object_files(),
        rule="objdiff_report",
        outputs=str(project.objdiff_report()),
    )
    n.newline()

    n.build(
        inputs=str(project.objdiff_report()),
        rule="phony",
        outputs="report",
    )
    n.newline()


def get_config_files(game_config: Path, name: str) -> list[str]:
    return [
        f"{root}/{file}"
        for root, _, files in os.walk(game_config)
        for file in files
        if file == name
    ]


if __name__ == "__main__": main()
