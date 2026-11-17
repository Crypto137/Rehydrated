#pragma once

#include "core/memory.h"
#include "game/sigma/math/aabb.h"
#include "game/sigma/math/ivector2d.h"

struct SceneCachedValues
{
    be<u32> dwCachedValuesValid;
    be<i32> nNavmeshSizeX;
    be<i32> nNavmeshSizeY;
    AABB aabbBounds;
    AABB aabbMarkerSetBounds;
    be<i32> arNumNodesForDistByLevelArea[4];
    be<u32> dwFlags;
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
    be<u32> field0;
    be<u32> field4;
    be<u32> field8;
    be<u32> field12;
    be<u32> field16;
    be<u32> field20;
    be<u32> field24;
};

struct SceneSpecification
{
    be<i32> dHeight;
    IVector2D pointGridLocation;
    be<SNO> arSnoLevelAreas[4];
    be<SNO> snoPrevWorld;
    be<u32> uPrevEntranceGUID;
    be<SNO> snoPrevLevelArea;
    be<SNO> snoNextWorld;
    be<u32> uNextEntranceGUID;
    be<SNO> snoNextLevelArea;
    be<SNO> snoMusic;
    be<SNO> snoAmbient;
    be<SNO> snoReverb;
    be<SNO> snoWeather;
    be<SNO> snoPresetWorld;
    be<i32> nDRLGIndex;
    be<i32> nSceneChunk;
    be<u32> dwOnPathBits;
    DRLGTileType nTileType;
    DRLGTileFamily nTileFamily;
    SceneDRLGCreationInfo tDRLGCreationInfo;
    be<u32> uClusterID;
    SceneCachedValues tCachedValues;
};
