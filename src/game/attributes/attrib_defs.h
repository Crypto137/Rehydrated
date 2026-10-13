#pragma once

#include <rex/system/xtypes.h>

#include "game/attributes/attrib.h"
#include "game/attributes/fast_attribute.h"

struct AttributeCompressor;

enum AttributeParameterType
{
    APT_NONE = -1,
    APT_ELEMENT,
    APT_ATTRIBUTE,
    APT_CLASS,
    APT_INDEX,
    APT_SKILL,
    APT_TIMER,
    APT_LEVEL,
    APT_ASPECT,
    APT_PROC,
    APT_BUFF,
    APT_RESOURCE,
    APT_RUNE_POWER,
    APT_PLAYER_IDX,
    APT_CRAFTERTYPE,
    APT_TREASURECLASS,
    APT_ACTOR,
    APT_CONVERSATION,
    APT_GBID,
    APT_MONSTER_TYPE,
    APT_INVENTORY_SLOT_TYPE,
    APT_POWER_ID,
    APT_COSMETIC_TYPE,  // this one probably didn't exist in vanilla
    APT_COUNT,
};

enum AttributeOperator
{
    ATTRIBUTEOP_NONE = -1,
    ATTRIBUTEOP_PLUS,
    ATTRIBUTEOP_MAX,
    ATTRIBUTEOP_APPEND,
    ATTRIBUTEOP_SET,
    ATTRIBUTEOP_NOAGG,
    ATTRIBUTEOP_MULTIPLY,
    ATTRIBUTEOP_MIN,
    ATTRIBUTEOP_MULTIPLY_INVERSE,
    ATTRIBUTEOP_ACDID,
};

enum AttributeDataType
{
    ATTRIBUTEDT_UNKNOWN = -1,
    ATTRIBUTEDT_FLOAT,
    ATTRIBUTEDT_INT,
};

enum AttributeSyncFlags
{
    ASTF_PLAYER_EXTRA,
    ASTF_MONSTER,
    ASTF_GIZMO,
    ASTF_ITEM,
    ASTF_SERVER_PROP,
    ASTF_RECORD_SPEED_VALUE,
    ASTF_PROJECTILE,
    ASTF_PLAYER_BASIC,
    ASTF_COUNT,
};

struct AttribDef
{
    rex::be<Attrib> eAttrib;
    rex::be<FastAttribValue> tDefaultValue;
    rex::be<AttributeParameterType> eParameterType;
    rex::be<AttributeOperator> eAttributeOperator;
    rex::be<AttributeDataType> eAttributeDataType;
    rex::TypedGuestPointer<char> pszFormulaItem;
    rex::TypedGuestPointer<char> pszFormulaCharacter;
    rex::TypedGuestPointer<char> pszName;
    rex::TypedGuestPointer<AttributeCompressor> ptCompressor;
    char uSyncFlags;
};
