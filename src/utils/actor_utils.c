#include "actor_utils.h"

void func_800BE504(Actor* actor, ColliderCylinder* cyl) {
    // Checks if was hit by either DMG_NORMAL_ARROW, DMG_FIRE_ARROW, DMG_ICE_ARROW, DMG_LIGHT_ARROW
    if ((cyl->info.acHitInfo->bumper.dmgFlags & DMG_ARROW)) {
        actor->world.rot.y = cyl->base.ac->shape.rot.y;
    } else {
        actor->world.rot.y = Actor_WorldYawTowardActor(cyl->base.ac, actor);
    }
}

void Actor_SpawnIceEffects(PlayState* play, Actor* actor, Vec3f bodyPartsPos[], s32 bodyPartsCount,
                           s32 effectsPerBodyPart, f32 scale, f32 scaleRange) {
    static Color_RGBA8 sPrimColor = { 170, 255, 255, 255 };
    static Color_RGBA8 sEnvColor = { 200, 200, 255, 255 };
    static Vec3f sAccel = { 0.0f, -1.0f, 0.0f };
    s32 i;
    s32 pad;
    Vec3f velocity;
    s16 randomYaw;
    s16 yaw;
    s32 j;

    SoundSource_PlaySfxAtFixedWorldPos(play, &actor->world.pos, 30, NA_SE_EV_ICE_BROKEN);

    for (i = 0; i < bodyPartsCount; i++) {
        yaw = Actor_WorldYawTowardPoint(actor, bodyPartsPos);

        for (j = 0; j < effectsPerBodyPart; j++) {
            randomYaw = ((s32)Rand_Next() >> 0x13) + yaw;

            velocity.z = Rand_ZeroFloat(5.0f);

            velocity.x = Math_SinS(randomYaw) * velocity.z;
            velocity.y = Rand_ZeroFloat(4.0f) + 8.0f;
            velocity.z *= Math_CosS(randomYaw);

            EffectSsEnIce_Spawn(play, bodyPartsPos, Rand_ZeroFloat(scaleRange) + scale, &velocity, &sAccel, &sPrimColor,
                                &sEnvColor, 30);
        }

        bodyPartsPos++;
    }
}
