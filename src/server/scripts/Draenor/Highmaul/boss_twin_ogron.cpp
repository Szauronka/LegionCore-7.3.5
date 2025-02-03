////////////////////////////////////////////////////////////////////////////////
//
//  MILLENIUM-STUDIO
//  Copyright 2016 Millenium-studio SARL
//  All Rights Reserved.
//
////////////////////////////////////////////////////////////////////////////////

# include "highmaul.hpp"
#include "SpellAuraEffects.h"

float const gorthenonFloor = 330.0f;
float const circleToCenterDist = 30.0f;
float const blazeDistToCenter = 136.0f;

Position const polJumpPos = {4043.08f, 8500.94f, 322.226f, 5.63415f};
Position const phemosJumpPos = {4028.90f, 8485.51f, 322.226f, 5.63415f};
Position const centerPos = {4062.38f, 8470.91f, 322.226f, 0.0f};

Position const polMovePos[3] =
{
    {4031.884f, 8587.818f, 343.6748f, 4.55423f},
    {4028.196f, 8568.284f, 341.8094f, 4.51496f},
    {4012.667f, 8523.617f, 327.2006f, 5.63415f}
};

Position const phemosMovePos[3] =
{
    {3949.489f, 8484.431f, 343.7032f, 0.31307f},
    {3974.303f, 8497.139f, 335.4293f, 0.40340f},
    {4002.597f, 8510.825f, 327.1879f, 5.63415f}
};


void RespawnOgrons(Creature* source, InstanceScript* instance)
{
    if (source == nullptr || instance == nullptr)
        return;

    if (Creature* other = Creature::GetCreature(*source, (source->GetEntry() == Phemos) ? instance->GetGuidData(Pol) : instance->GetGuidData(Phemos)))
    {
        other->Respawn();
        other->GetMotionMaster()->MoveTargetedHome();
    }
}

void StartOgrons(Creature* source, Unit* target)
{
    if (source == nullptr || target == nullptr)
        return;

    if (Creature* other = source->FindNearestCreature((source->GetEntry() == Phemos) ? Pol : Phemos, 30.0f))
        other->AI()->AttackStart(target);
}




/// Warming Up - 173425
class spell_highmaul_warming_up : public AuraScript
{
    PrepareAuraScript(spell_highmaul_warming_up);

    enum eSpell
    {
        Disposition = 157953
    };

    void OnRemove(AuraEffect const* /*auraEffect*/, AuraEffectHandleModes /*mode*/)
    {
        if (Unit* target = GetTarget())
            target->CastSpell(target, Disposition, true);
    }

    void Register() override
    {
        OnEffectRemove += AuraEffectRemoveFn(spell_highmaul_warming_up::OnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

/// Disposition - 157953
class spell_highmaul_disposition : public AuraScript
{
    PrepareAuraScript(spell_highmaul_disposition);

    uint8 tickCount;

    enum eActions
    {
        /// Phemos
        ScheduleQuake = 1,
        ScheduleEnfleeblingRoar = 2,
        ScheduleWhirlwind = 3,
        /// Pol
        SchedulePulverize = 0,
        ScheduleInterruptingShout = 1,
        ScheduleShieldCharge = 2
    };

    bool Load() override
    {
        tickCount = 0;
        return true;
    }

    void OnTick(AuraEffect const* /*auraEffect*/)
    {
        if (GetTarget() == nullptr)
            return;

        if (Creature* boss = GetTarget()->ToCreature())
        {
            float energyGain = 1.0f;
            energyGain *= 1.0f + (float)boss->GetPower(POWER_ALTERNATE) / 100.0f;

            /// Pol energizes 25% faster than Phemos
            if (boss->GetEntry() == Pol)
            {
                ++tickCount;
                energyGain *= 1.25f;

                if ((int32)energyGain == 1 && !(tickCount % 2))
                {
                    tickCount = 0;
                    energyGain += 1.0f;
                }
            }

            boss->EnergizeBySpell(boss, GetSpellInfo()->Id, (int32)energyGain, POWER_ENERGY);

            if (!boss->IsAIEnabled)
                return;

            switch (boss->GetEntry())
            {
                case Phemos:
                {
                    if (boss->GetPower(POWER_ENERGY) >= 100)
                        boss->AI()->DoAction(ScheduleQuake);
                    else if (boss->GetPower(POWER_ENERGY) >= 66 && boss->GetPower(POWER_ENERGY) <= 80)
                        boss->AI()->DoAction(ScheduleEnfleeblingRoar);
                    else if (boss->GetPower(POWER_ENERGY) >= 33 && boss->GetPower(POWER_ENERGY) <= 50)
                        boss->AI()->DoAction(ScheduleWhirlwind);

                    break;
                }
                case Pol:
                {
                    if (boss->GetPower(POWER_ENERGY) >= 100)
                        boss->AI()->DoAction(SchedulePulverize);
                    else if (boss->GetPower(POWER_ENERGY) >= 66 && boss->GetPower(POWER_ENERGY) <= 80)
                        boss->AI()->DoAction(ScheduleInterruptingShout);
                    else if (boss->GetPower(POWER_ENERGY) >= 33 && boss->GetPower(POWER_ENERGY) <= 50)
                        boss->AI()->DoAction(ScheduleShieldCharge);

                    break;
                }
                default:
                    break;
            }
        }
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_highmaul_disposition::OnTick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

/// Enfeebling Roar - 158026
class spell_highmaul_enfeebling_roar_AuraScript : public AuraScript
{
    enum eMisc
    {
        EnfeeblingCounter
    };

    PrepareAuraScript(spell_highmaul_enfeebling_roar_AuraScript);

    void AfterApply(AuraEffect const* auraEffect, AuraEffectHandleModes /*mode*/)
    {
        if (GetCaster() == nullptr)
            return;

        if (Creature* phemos = GetCaster()->ToCreature())
        {
            if (!phemos->IsAIEnabled)
                return;

            Aura* aura = auraEffect->GetBase();
            if (!aura)
                return;

            uint32 count = phemos->AI()->GetData(EnfeeblingCounter);
            if (!count)
                count = 1;

            uint32 maxDuration = aura->GetDuration() * 10;
            int32 amount = auraEffect->GetAmount() * 10;

            aura->SetDuration(maxDuration / count);
            aura->SetMaxDuration(maxDuration / count);
            aura->GetEffect(EFFECT_1)->ChangeAmount(amount / count);
            aura->SetNeedClientUpdateForTargets();
        }
    }

    void Register() override
    {
        AfterEffectApply += AuraEffectApplyFn(spell_highmaul_enfeebling_roar_AuraScript::AfterApply, EFFECT_1, SPELL_AURA_MOD_DAMAGE_PERCENT_TAKEN, AURA_EFFECT_HANDLE_REAL);
    }
};

class spell_highmaul_enfeebling_roar : public SpellScript
{
    enum eMiscs
    {
        EnfeeblingCounter,
    };

    PrepareSpellScript(spell_highmaul_enfeebling_roar);

    void HandleDamage(SpellEffIndex /*effectIndex*/)
    {
        if (GetCaster() == nullptr)
            return;

        if (Creature* phemos = GetCaster()->ToCreature())
        {
            if (!phemos->IsAIEnabled)
                return;

            uint32 count = phemos->AI()->GetData(EnfeeblingCounter);
            if (!count)
                count = 1;

            SetHitDamage(GetHitDamage() * 10 / count);
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_highmaul_enfeebling_roar::HandleDamage, EFFECT_2, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

/// Shield Charge - 158134
class spell_highmaul_pol_shield_charge : public SpellScript
{
    PrepareSpellScript(spell_highmaul_pol_shield_charge);

    WorldLocation m_Location;

    void HandleBeforeCast()
    {
        if (WorldLocation const* loc = GetExplTargetDest())
            m_Location = *loc;
    }

    void HandleAfterCast()
    {
        if (Unit* caster = GetCaster())
            caster->GetMotionMaster()->MoveCharge(m_Location.m_positionX, m_Location.m_positionY, m_Location.m_positionZ, SPEED_CHARGE, GetSpellInfo()->Id);
    }

    void Register() override
    {
        BeforeCast += SpellCastFn(spell_highmaul_pol_shield_charge::HandleBeforeCast);
        AfterCast += SpellCastFn(spell_highmaul_pol_shield_charge::HandleAfterCast);
    }
};

class spell_highmaul_pol_shield_charge_AuraScript : public AuraScript
{
    PrepareAuraScript(spell_highmaul_pol_shield_charge_AuraScript);

    enum eSpell
    {
        ShieldChargeDamage = 158159
    };

    uint32 m_DamageTimer;

    bool Load() override
    {
        m_DamageTimer = 500;
        return true;
    }

    void OnUpdate(uint32 diff)
    {
        if (m_DamageTimer)
        {
            if (m_DamageTimer <= diff)
            {
                if (Unit* caster = GetCaster())
                {
                    std::list<Unit*> targetList;
                    float radius = 1.0f;

                    Trinity::AnyUnfriendlyUnitInObjectRangeCheck check(caster, caster, radius);
                    Trinity::UnitListSearcher<Trinity::AnyUnfriendlyUnitInObjectRangeCheck> searcher(caster, targetList, check);
                    caster->VisitNearbyObject(radius, searcher);

                    for (Unit* itr : targetList)
                        caster->CastSpell(itr, ShieldChargeDamage, true);
                }

                m_DamageTimer = 500;
            }
            else
                m_DamageTimer -= diff;
        }
    }

    void Register() override
    {
        OnAuraUpdate += AuraUpdateFn(spell_highmaul_pol_shield_charge_AuraScript::OnUpdate);
    }
};

/// Aggressive Disposition - 157951
/// Fierce Disposition - 158016
/// Savage Disposition - 158017
class spell_highmaul_twin_ogron_dispositions : public AuraScript
{
    PrepareAuraScript(spell_highmaul_twin_ogron_dispositions);

    enum eSpells
    {
        AggressiveDisposition = 157951,
        FierceDisposition = 158016,
        SavageDisposition = 158017
    };

    uint32 m_CheckTimer;

    bool Load() override
    {
        m_CheckTimer = 200;
        return true;
    }

    void OnUpdate(uint32 diff)
    {
        if (m_CheckTimer)
        {
            if (m_CheckTimer <= diff)
            {
                if (Unit* caster = GetCaster())
                {
                    uint32 entry = caster->GetEntry() == Pol ? Phemos : Pol;
                    if (Creature* other = caster->FindNearestCreature(entry, 150.0f))
                    {
                        float distance = std::min(caster->GetDistance(other), 100.0f);
                        uint32 spellID = 0;

                        if (distance >= 50.0f)
                            spellID = SavageDisposition;
                        else if (distance >= 20.0f)
                            spellID = FierceDisposition;
                        else
                            spellID = AggressiveDisposition;

                        if ((int32)distance > DispositionPCT)
                            if (InstanceScript* instance = other->GetInstanceScript())
                                instance->SetData(TwinOgronAchievement, 1);

                        if (!caster->HasAura(spellID))
                            caster->CastSpell(caster, spellID, true);

                        if (!other->HasAura(spellID))
                            other->CastSpell(other, spellID, true);

                        if (Aura* casterAura = caster->GetAura(spellID))
                        {
                            if (AuraEffect* firstEffect = casterAura->GetEffect(EFFECT_0))
                                firstEffect->ChangeAmount((int32)distance);

                            if (AuraEffect* secondEffect = casterAura->GetEffect(EFFECT_1))
                                secondEffect->ChangeAmount((int32)distance);
                        }

                        if (Aura* otherAura = other->GetAura(spellID))
                        {
                            if (AuraEffect* firstEffect = otherAura->GetEffect(EFFECT_0))
                                firstEffect->ChangeAmount((int32)distance);

                            if (AuraEffect* secondEffect = otherAura->GetEffect(EFFECT_1))
                                secondEffect->ChangeAmount((int32)distance);
                        }

                        caster->SetPower(POWER_ALTERNATE, (int32)distance);
                        other->SetPower(POWER_ALTERNATE, (int32)distance);
                    }
                }

                m_CheckTimer = 200;
            }
            else
                m_CheckTimer -= diff;
        }
    }

    void Register() override
    {
        OnAuraUpdate += AuraUpdateFn(spell_highmaul_twin_ogron_dispositions::OnUpdate);
    }
};

/// Pulverize (Wave 3) - 158420
class spell_highmaul_pulverize_third_wave : public SpellScript
{
    PrepareSpellScript(spell_highmaul_pulverize_third_wave);

    void HandleDamage(SpellEffIndex /*effectIndex*/)
    {
        if (WorldLocation const* loc = GetExplTargetDest())
        {
            if (Unit* target = GetHitUnit())
            {
                int32 damage = GetHitDamage();
                SetHitDamage(damage - CalculatePct(damage, (int32)std::min(100.0f, target->GetDistance(*loc))));
            }
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_highmaul_pulverize_third_wave::HandleDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

/// Whirlwind - 157943
class spell_highmaul_phemos_whirlwind : public AuraScript
{
    PrepareAuraScript(spell_highmaul_phemos_whirlwind);

    enum eSpell
    {
        WeakenedDefenses = 159709
    };

    void OnTick(AuraEffect const* /*auraEffect*/)
    {
        if (Unit* caster = GetCaster())
            caster->CastSpell(caster, WeakenedDefenses, true);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_highmaul_phemos_whirlwind::OnTick, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
    }
};

void AddSC_boss_twin_ogron()
{
    

    RegisterAuraScript(spell_highmaul_warming_up);
    RegisterAuraScript(spell_highmaul_disposition);
    RegisterSpellAndAuraScriptPair(spell_highmaul_enfeebling_roar, spell_highmaul_enfeebling_roar_AuraScript);
    //RegisterSpellAndAuraScriptPair(spell_highmaul_pol_shield_charge, spell_highmaul_pol_shield_charge_AuraScript);
    RegisterAuraScript(spell_highmaul_twin_ogron_dispositions);
    RegisterSpellScript(spell_highmaul_pulverize_third_wave);
    RegisterAuraScript(spell_highmaul_phemos_whirlwind);
}
