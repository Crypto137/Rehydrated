import idc
import ida_funcs
import ida_name
import ida_typeinf

SLOTS = {
    2: "New",
    3: "Clear",
    4: "IsInitialized",
    7: "MergePartialFromCodedStream",
    8: "ByteSize",
    9: "SerializeWithCachedSizes",
    10: "SerializeWithCachedSizesToArray",
    11: "GetCachedSize",
    12: "CopyFrom",
    13: "MergeFrom",
    16: "SetCachedSize",
    18: "GetMetadata",
}

PTR_SIZE = 4
SUFFIX = "_vtable"
SLOT5_EXPECTED = "google::protobuf::Message::InitializationErrorString"
VTBL_TYPE = "google::protobuf::Message_vtbl"

def main():
    ea = idc.get_screen_ea()

    name = ida_name.get_name(ea)
    if not name.endswith(SUFFIX):
        print("Cursor is at '%s', which does not end with '%s'" % (name, SUFFIX))
        return

    slot5_ea = idc.get_wide_dword(ea + 5 * PTR_SIZE)
    slot5_name = ida_name.get_name(slot5_ea)
    if slot5_name != SLOT5_EXPECTED:
        print("Slot 5 is '%s', expected '%s'" % (slot5_name, SLOT5_EXPECTED))
        return

    prefix = name[:-len(SUFFIX)]

    tif = ida_typeinf.tinfo_t()
    if not tif.get_named_type(None, VTBL_TYPE):
        print("Type '%s' not found in the local types" % VTBL_TYPE)
        return
    if ida_typeinf.apply_tinfo(ea, tif, ida_typeinf.TINFO_DEFINITE):
        print("Applied type %s @ 0x%X" % (VTBL_TYPE, ea))
    else:
        print("FAILED to apply type %s @ 0x%X" % (VTBL_TYPE, ea))

    for slot, slot_name in SLOTS.items():
        func_ea = idc.get_wide_dword(ea + slot * PTR_SIZE)

        if ida_funcs.get_func(func_ea) is None:
            if ida_funcs.add_func(func_ea):
                print("Slot %2d @ 0x%X converted to function" % (slot, func_ea))
            else:
                print("Slot %2d @ 0x%X FAILED to convert to function" % (slot, func_ea))

        new_name = "%s::%s" % (prefix, slot_name)
        if ida_name.set_name(func_ea, new_name, ida_name.SN_NOWARN):
            print("Slot %2d @ 0x%X -> %s" % (slot, func_ea, new_name))
        else:
            print("Slot %2d @ 0x%X FAILED to rename to %s" % (slot, func_ea, new_name))
            

main()