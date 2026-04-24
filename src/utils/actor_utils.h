#ifndef ACTOR_UTILS_H
#define ACTOR_UTILS_H

#include "global.h"

void func_800BE504(Actor* actor, ColliderCylinder* cyl);
void Actor_SpawnIceEffects(PlayState* play, Actor* actor, Vec3f bodyPartsPos[], s32 bodyPartsCount, s32 effectsPerBodyPart, f32 scale, f32 scaleRange);

#endif // ACTOR_UTILS_H
