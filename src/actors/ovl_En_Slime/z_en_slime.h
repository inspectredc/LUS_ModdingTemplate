#ifndef Z_EN_SLIME_H
#define Z_EN_SLIME_H

#include "global.h"
#include "assets/object_slime.h"
#include "objects/gameplay_keep/gameplay_keep.h"

// Missing Definitions From MM
#define M_PIf 3.14159265358979323846f

typedef enum {
    /*  0 */ ACTOR_DRAW_DMGEFF_FIRE,
    /*  1 */ ACTOR_DRAW_DMGEFF_BLUE_FIRE,
    /* 10 */ ACTOR_DRAW_DMGEFF_FROZEN_NO_SFX = 10,
    /* 11 */ ACTOR_DRAW_DMGEFF_FROZEN_SFX,
    /* 20 */ ACTOR_DRAW_DMGEFF_LIGHT_ORBS = 20,
    /* 21 */ ACTOR_DRAW_DMGEFF_BLUE_LIGHT_ORBS,
    /* 30 */ ACTOR_DRAW_DMGEFF_ELECTRIC_SPARKS_SMALL = 30,
    /* 31 */ ACTOR_DRAW_DMGEFF_ELECTRIC_SPARKS_MEDIUM,
    /* 32 */ ACTOR_DRAW_DMGEFF_ELECTRIC_SPARKS_LARGE
} ActorDrawDamageEffectType;


#define COLORFILTER_COLORFLAG_NONE 0xC000
#define COLORFILTER_COLORFLAG_GRAY 0x8000
#define COLORFILTER_COLORFLAG_RED  0x4000
#define COLORFILTER_COLORFLAG_BLUE 0x0000

#define COLORFILTER_INTENSITY_FLAG 0x8000

#define COLORFILTER_BUFFLAG_XLU    0x2000
#define COLORFILTER_BUFFLAG_OPA    0x0000

// Flags for bgCheckFlags
#define BGCHECKFLAG_GROUND (1 << 0) // Standing on the ground
#define BGCHECKFLAG_GROUND_TOUCH (1 << 1) // Has touched the ground (only active for 1 frame)
#define BGCHECKFLAG_GROUND_LEAVE (1 << 2) // Has left the ground (only active for 1 frame)
#define BGCHECKFLAG_WALL (1 << 3) // Touching a wall
#define BGCHECKFLAG_CEILING (1 << 4) // Touching a ceiling
#define BGCHECKFLAG_WATER (1 << 5) // In water
#define BGCHECKFLAG_WATER_TOUCH (1 << 6) // Has touched water (reset when leaving water)
#define BGCHECKFLAG_GROUND_STRICT (1 << 7) // Similar to BGCHECKFLAG_GROUND but with no velocity check and is cleared every frame
#define BGCHECKFLAG_CRUSHED (1 << 8) // Crushed between a floor and ceiling (triggers a void for player)
#define BGCHECKFLAG_PLAYER_WALL_INTERACT (1 << 9) // Only set/used by player, related to interacting with walls
#define BGCHECKFLAG_PLAYER_400 (1 << 10) // 
#define BGCHECKFLAG_PLAYER_800 (1 << 11) // 
#define BGCHECKFLAG_PLAYER_1000 (1 << 12) // 

// Flags for Actor_UpdateBgCheckInfo
#define UPDBGCHECKINFO_FLAG_1 (1 << 0) // check wall
#define UPDBGCHECKINFO_FLAG_2 (1 << 1) // check ceiling
#define UPDBGCHECKINFO_FLAG_4 (1 << 2) // check floor and water
#define UPDBGCHECKINFO_FLAG_8 (1 << 3)
#define UPDBGCHECKINFO_FLAG_10 (1 << 4)
#define UPDBGCHECKINFO_FLAG_20 (1 << 5) // unused
#define UPDBGCHECKINFO_FLAG_40 (1 << 6) // disable water ripples
#define UPDBGCHECKINFO_FLAG_80 (1 << 7)
#define UPDBGCHECKINFO_FLAG_100 (1 << 8)
#define UPDBGCHECKINFO_FLAG_200 (1 << 9)
#define UPDBGCHECKINFO_FLAG_400 (1 << 10) // check water
#define UPDBGCHECKINFO_FLAG_800 (1 << 11)

#define MATRIX_FINALIZE_AND_LOAD(pkt, gfxCtx) \
    gSPMatrix(pkt, MATRIX_NEWMTX(gfxCtx), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW)


// z_en_slime.h
struct EnSlime;

typedef void (*EnSlimeActionFunc)(struct EnSlime*, PlayState*);


#define EN_SLIME_GET_TYPE(thisx) ((thisx)->params)
#define EN_SLIME_GET_REVIVE_TIME(thisx) ((((thisx)->params) >> 8) & 0xFF)

typedef enum EnSlimeType {
    /* 0 */ EN_SLIME_TYPE_BLUE,
    /* 1 */ EN_SLIME_TYPE_GREEN,
    /* 2 */ EN_SLIME_TYPE_YELLOW,
    /* 3 */ EN_SLIME_TYPE_RED,
    /* 4 */ EN_SLIME_TYPE_MAX
} EnSlimeType;

typedef enum EnSlimeBodyPart {
    /* 0 */ EN_SLIME_BODYPART_0,
    /* 1 */ EN_SLIME_BODYPART_1,
    /* 2 */ EN_SLIME_BODYPART_2,
    /* 3 */ EN_SLIME_BODYPART_3,
    /* 4 */ EN_SLIME_BODYPART_4,
    /* 5 */ EN_SLIME_BODYPART_MAX
} EnSlimeBodyPart;

typedef struct EnSlime {
    /* 0x000 */ Actor actor;
    /* 0x144 */ EnSlimeActionFunc actionFunc;
    /* 0x148 */ u8 iceBlockTimer;
    /* 0x149 */ u8 eyeTexIndex;
    /* 0x14A */ u8 drawDmgEffType;
    /* 0x14C */ s16 timer;
    /* 0x14E */ s16 idleRotY;
    /* 0x150 */ s16 reviveRotY;
    /* 0x152 */ s16 reviveTime;
    /* 0x154 */ union {
                    Vec3f iceBlockSnapPos;
                    Vec3f wobbleRot;
                };
    /* 0x160 */ TexturePtr itemDropTex;
    /* 0x164 */ f32 drawDmgEffAlpha;
    /* 0x168 */ f32 drawDmgEffScale;
    /* 0x16C */ f32 drawDmgEffFrozenSteamScale;
    /* 0x170 */ f32 distLimit;
    /* 0x174 */ Vec3f reviveScale;
    /* 0x180 */ Vec3f bodyPartsPos[EN_SLIME_BODYPART_MAX];
    /* 0x1BC */ ColliderCylinder collider;
} EnSlime; // size = 0x208

#endif // Z_EN_SLIME_H
