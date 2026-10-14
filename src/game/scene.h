#pragma once

#include <rex/types.h>

#include "game/sigma/math/aabb.h"
#include "game/sigma/math/ivector2d.h"

struct SceneCachedValues
{
    rex::be<u32> dwCachedValuesValid;
    rex::be<i32> nNavmeshSizeX;
    rex::be<i32> nNavmeshSizeY;
    AABB aabbBounds;
    AABB aabbMarkerSetBounds;
    rex::be<i32> arNumNodesForDistByLevelArea[4];
    rex::be<u32> dwFlags;
};

enum DRLGTileType : int
{
    DRLG_TILE_UNDEFINED = -1,
    DRLG_TILE_NONE,
    DRLG_TILE_N,
    DRLG_TILE_S,
    DRLG_TILE_NS,
    DRLG_TILE_E,
    DRLG_TILE_NE,
    DRLG_TILE_SE,
    DRLG_TILE_NSE,
    DRLG_TILE_W,
    DRLG_TILE_NW,
    DRLG_TILE_SW,
    DRLG_TILE_NSW,
    DRLG_TILE_EW,
    DRLG_TILE_NEW,
    DRLG_TILE_SEW,
    DRLG_TILE_NSEW,
    DRLG_TILE_NUM_TYPES,
    DRLG_TILE_CUSTOM = 0xFFFFFF,
};

enum DRLGTileFamily : int
{
    TILE_FAMILY_NONE = -1,
    TILE_FAMILY_FULL_NSEW,
};

struct SceneDRLGCreationInfo
{
    rex::be<u32> field0;
    rex::be<u32> field4;
    rex::be<u32> field8;
    rex::be<u32> field12;
    rex::be<u32> field16;
    rex::be<u32> field20;
    rex::be<u32> field24;
};

struct SceneSpecification
{
    rex::be<i32> dHeight;
    IVector2D pointGridLocation;
    rex::be<SNO> arSnoLevelAreas[4];
    rex::be<SNO> snoPrevWorld;
    rex::be<u32> uPrevEntranceGUID;
    rex::be<SNO> snoPrevLevelArea;
    rex::be<SNO> snoNextWorld;
    rex::be<u32> uNextEntranceGUID;
    rex::be<SNO> snoNextLevelArea;
    rex::be<SNO> snoMusic;
    rex::be<SNO> snoAmbient;
    rex::be<SNO> snoReverb;
    rex::be<SNO> snoWeather;
    rex::be<SNO> snoPresetWorld;
    rex::be<i32> nDRLGIndex;
    rex::be<i32> nSceneChunk;
    rex::be<u32> dwOnPathBits;
    DRLGTileType nTileType;
    DRLGTileFamily nTileFamily;
    SceneDRLGCreationInfo tDRLGCreationInfo;
    rex::be<u32> uClusterID;
    SceneCachedValues tCachedValues;
};
