import idautils
import idc
import ida_bytes
import ida_funcs
import ida_kernwin

SKIP_PREFIXES = ["__", "j_"]
SKIP_NAMES = ["Main", "qsort", "bsearch"]
SYSTEM_SECTION_START = 0x82F8BD4C # XamInputGetCapabilities

def format_str(s):
    s = s.replace('\\', '\\\\').replace('"', '\\"').replace("::~", "__dtor_").replace("::", "__")
    return '"' + s + '"'

def is_user_named(ea):
    return ida_bytes.has_user_name(ida_bytes.get_flags(ea))

def build():
    lines = ["[functions]"]
    count = 0
    for ea in idautils.Functions():
        if ea >= SYSTEM_SECTION_START:
            break

        f = ida_funcs.get_func(ea)
        if not f:
            continue

        if not is_user_named(ea):
            continue

        name = idc.get_func_name(ea)
        if (name.startswith(tuple(SKIP_PREFIXES))) or (name in SKIP_NAMES):
            continue

        fields = []
        fields.append("name = %s" % format_str(name))

        lines.append("0x%08X = { %s }" % (ea, ", ".join(fields)))
        count += 1
    return "\n".join(lines) + "\n", count

def main():
    path = ida_kernwin.ask_file(1, "functions.toml", "Save function TOML")
    if not path:
        return
    text, count = build()
    with open(path, "w", encoding="utf-8", newline="\n") as fh:
        fh.write(text)
    print("[Rehydrated] wrote %d functions to %s" % (count, path))

main()