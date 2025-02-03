
#include "SpellTargetInfo.h"
#include "SpellPackets.h"
#include "TradeData.h"
#include "SharedDefines.h"

TargetInfo::TargetInfo(ObjectGuid tGUID, uint32 effMask) : TargetInfo()
{
    targetGUID = tGUID;
    effectMask = effMask;
}

TargetInfo::TargetInfo()
{
    targetGUID = ObjectGuid::Empty;
    missCondition = SPELL_MISS_NONE;
    reflectResult = SPELL_MISS_NONE;
    timeDelay = 0LL;
    effectMask = 0;
    targetInfoMask = 0;
    processed = false;
    damage = 0;
    damageBeforeHit = 0;
    scaleAura = false;
}

bool TargetInfo::HasMask(uint32 Mask) const
{
    return targetInfoMask & Mask;
}

uint32 TargetInfo::GetMask() const
{
    return targetInfoMask;
}

void TargetInfo::AddMask(uint32 Mask)
{
    targetInfoMask |= Mask;
}

