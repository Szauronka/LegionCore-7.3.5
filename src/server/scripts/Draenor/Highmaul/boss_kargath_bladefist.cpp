////////////////////////////////////////////////////////////////////////////////
//
//  MILLENIUM-STUDIO
//  Copyright 2016 Millenium-studio SARL
//  All Rights Reserved.
//
////////////////////////////////////////////////////////////////////////////////

# include "highmaul.hpp"
#include "SpellAuraEffects.h"

Position const trashsSpawnPos = {3427.1f, 7530.21f, 55.3383f, 0.965533f};
Position const vulgorMovePos = {3449.81f, 7557.01f, 55.304f, 0.8995f};
Position const arenaStandsPos = {3507.99f, 7629.20f, 65.43f, 2.466646f};
Position const newInstancePortalPos = {3441.737f, 7547.819f, 55.30566f, 0.8291928f};

Position const sorcererPos[2] =
{
    {3452.08f, 7550.25f, 55.304f, 0.8995f},
    {3441.68f, 7558.45f, 55.304f, 0.8995f}
};

Position const sorcererSecondPos[2] =
{
    {3445.23f, 7575.57f, 55.30f, 0.235625f},
    {3468.69f, 7557.72f, 55.30f, 1.708251f}
};

Position const highmaulSweeperMoves[HighmaulSweeperCount][HighmaulSweeperMovesCount] =
{
    /// Right of Mar'gok
    {
        {3448.05f, 7517.22f, 65.45f, 6.157836f},
        {3465.95f, 7520.59f, 65.15f, 0.196663f},
        {3487.64f, 7532.83f, 65.44f, 0.554020f},
        {3503.33f, 7548.39f, 65.44f, 0.777640f},
        {3513.44f, 7564.58f, 65.44f, 1.017186f},
        {3521.71f, 7590.66f, 65.09f, 1.241025f},
        {3521.19f, 7607.86f, 65.44f, 1.598777f},
        {3514.75f, 7623.96f, 65.44f, 1.932571f},
        {3507.99f, 7629.20f, 65.43f, 2.466646f}
    },
    /// Left of Mar'gok
    {
        {3411.12f, 7546.78f, 65.44f, 1.558138f},
        {3410.64f, 7564.97f, 65.01f, 1.559507f},
        {3418.62f, 7590.24f, 65.45f, 1.241420f},
        {3429.80f, 7608.05f, 65.44f, 1.025436f},
        {3444.61f, 7621.95f, 65.42f, 0.774108f},
        {3464.96f, 7634.39f, 65.44f, 0.538489f},
        {3483.57f, 7637.60f, 65.44f, 0.157571f},
        {3500.82f, 7634.95f, 65.44f, 6.122672f},
        {3507.86f, 7629.08f, 65.41f, 5.608234f}
    }
};

Position const sweeperJumpPos[HighmaulSweeperCount][2] =
{
    /// Right of Mar'gok
    {
        {3476.025f, 7551.327f, 55.2557f, M_PI},
        {3498.104f, 7575.722f, 55.2557f, M_PI}
    },
    /// Left of Mar'gok
    {
        {3436.589f, 7581.993f, 55.2557f, M_PI},
        {3457.199f, 7607.632f, 55.2557f, M_PI}
    }
};

Position const drunkenBileslingerSpawns[2] =
{
    {3499.293f, 7642.336f, 67.58533f, 4.473204f},
    {3512.144f, 7574.136f, 63.50087f, 2.765742f}
};

uint32 const crowdEmotes[8] =
{
    EMOTE_ONESHOT_CHEER, EMOTE_ONESHOT_EXCLAMATION, EMOTE_ONESHOT_RUDE, EMOTE_ONESHOT_ROAR,
    EMOTE_ONESHOT_CHICKEN, EMOTE_ONESHOT_SHOUT, EMOTE_ONESHOT_POINT, EMOTE_ONESHOT_SALUTE
};

float const inArenaZ = 60.0f;
float const arenaFloor = 55.30f;

void ResetAllPlayersFavor(Creature* source)
{
    if (source == nullptr)
        return;

    source->GetMap()->ApplyOnEveryPlayer([&](Player* player)
    {
        if (!player)
            return;

        player->SetPower(POWER_ALTERNATE, 0);
    });
}

void GrantFavorToAllPlayers(Creature* source, int32 value, uint32 spellID)
{
    if (source == nullptr)
        return;

    source->GetMap()->ApplyOnEveryPlayer([&](Player* player)
    {
        if (!player)
            return;

        player->EnergizeBySpell(player, spellID, value, POWER_ALTERNATE);
    });
}




/// Smoldering Stoneguard - 80051
struct npc_highmaul_somldering_stoneguard : public ScriptedAI
{
    enum eSpell
    {
        SpellCleave = 161703
    };

    enum eEvent
    {
        EventCleave = 1
    };

    npc_highmaul_somldering_stoneguard(Creature* creature) : ScriptedAI(creature) { }

    EventMap m_Events;

    void Reset() override
    {
        m_Events.Reset();
    }

    void EnterCombat(Unit* /*attacker*/) override
    {
        m_Events.RescheduleEvent(EventCleave, 2000);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        m_Events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        switch (m_Events.ExecuteEvent())
        {
            case EventCleave:
                if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                    me->CastSpell(target, SpellCleave, false);
                m_Events.RescheduleEvent(EventCleave, 10000);
                break;
            default:
                break;
        }

        DoMeleeAttackIfReady();
    }
};


/// Fire Pillar - 78757
struct npc_highmaul_fire_pillar : public ScriptedAI
{
    enum eSpells
    {
        FirePillarSelector = 159712,
        FirePillarActivated = 159706,
        FirePillarKnockback = 158994,
        FirePillarSteamTimer = 163967,

        FlameJet = 159202,   ///< AreaTrigger
        KargathTrigger = 159070,
        KargathTrigger2 = 159073,

        /// Only for Mythic mode
        FlameGoutPeriodic = 162574,   ///< Trigger 162576 (searcher) every 5s
        FlameGoutSearcher = 162576,
        FlameGoutMissile = 162577
    };

    enum eData
    {
        AnimKit1 = 6295,
        AnimKit2 = 6296,
        AnimKit3 = 6297,
        AnimKit4 = 6308
    };

    enum eActions
    {
        DeactivatePillar,
        DeactivatePillarOther
    };

    npc_highmaul_fire_pillar(Creature* creature) : ScriptedAI(creature) { }

    void Reset() override
    {
        me->SetReactState(REACT_PASSIVE);

        me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_IMMUNE_TO_PC);
        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_LOOTING | UNIT_FLAG_TAXI_FLIGHT | UNIT_FLAG_IN_COMBAT | UNIT_FLAG_PLAYER_CONTROLLED);
        me->SetFlag(UNIT_FIELD_FLAGS_2, UNIT_FLAG2_DISABLE_TURN);
        me->RemoveAura(FlameGoutPeriodic);
    }

    void SpellHit(Unit* caster, SpellInfo const* spellInfo) override
    {
        if (caster == nullptr)
            return;

        switch (spellInfo->Id)
        {
            case FirePillarSelector:
            {
                me->CastSpell(me, FirePillarSteamTimer, true);
                me->CastSpell(me, FirePillarActivated, true);
                me->CastSpell(me, FirePillarKnockback, true, nullptr, nullptr, caster->GetGUID());

                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IN_COMBAT);
                me->PlayOneShotAnimKit(AnimKit1);
                AddDelayedEvent(3 * IN_MILLISECONDS, [this]() -> void { me->SetAnimKitId(AnimKit2); });
                AddDelayedEvent(3 * IN_MILLISECONDS, [this]() -> void { me->CastSpell(me, FlameJet, true); });

                if (me->GetMap()->IsMythicRaid())
                    me->CastSpell(me, FlameGoutPeriodic, true);

                break;
            }
            default:
                break;
        }
    }

    void SpellHitTarget(Unit* target, SpellInfo const* spellInfo) override
    {
        if (target == nullptr)
            return;

        switch (spellInfo->Id)
        {
            case FlameGoutSearcher:
                me->CastSpell(target, FlameGoutMissile, true);
                break;
            default:
                break;
        }
    }

    void DoAction(int32 const action) override
    {
        switch (action)
        {
            case DeactivatePillar:
                DeactivatePillars();
                break;
            case DeactivatePillarOther:
            {
                AddDelayedEvent(3 * IN_MILLISECONDS, [this]() -> void
                {
                    DeactivatePillars();

                    if (Creature* kargath = me->FindNearestCreature(KargathBladefist, 15.0f))
                    {
                        kargath->SetControlled(false, UNIT_STATE_ROOT);
                        kargath->SetReactState(REACT_AGGRESSIVE);
                        kargath->RemoveFlag(UNIT_FIELD_FLAGS_2, UNIT_FLAG2_DISABLE_TURN);
                        kargath->ClearUnitState(UNIT_STATE_CANNOT_TURN);
                    }
                });
                break;
            }
            default:
                break;
        }
    }

    void DeactivatePillars()
    {
        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IN_COMBAT);
        me->RemoveAllAuras();
        me->SetAnimKitId(0);
        me->PlayOneShotAnimKit(AnimKit3);
        me->RemoveAura(FlameGoutPeriodic);
    }

    void UpdateAI(uint32 diff) override
    {
    }
};

/// Ravenous Bloodmaw - 79296
struct npc_highmaul_ravenous_bloodmaw : public ScriptedAI
{
    enum eSpells
    {
        SpellMaul = 161218,
        OnTheHunt = 162497,
        SpellInflamed = 163130,
        InThePitAura = 161423
    };

    enum eActions
    {
        FreeRavenous,
        InterruptRavenous
    };

    enum eEvent
    {
        CheckPlayer = 1
    };

    npc_highmaul_ravenous_bloodmaw(Creature* creature) : ScriptedAI(creature) { }

    EventMap m_Events;

    void Reset() override
    {
        me->SetReactState(REACT_PASSIVE);
        me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE);

        m_Events.Reset();
        m_Events.RescheduleEvent(CheckPlayer, 500);

        me->RemoveAura(SpellInflamed);
    }

    void SpellHitTarget(Unit* target, SpellInfo const* spellInfo) override
    {
        if (target == nullptr)
            return;

        switch (spellInfo->Id)
        {
            case OnTheHunt:
            {
                me->ClearUnitState(UNIT_STATE_CASTING);

                me->SetInCombatWithZone();

                me->getThreatManager().clearReferences();
                me->getThreatManager().addThreat(target, std::numeric_limits<float>::max());

                me->SetReactState(REACT_AGGRESSIVE);
                me->TauntApply(target);
                me->SetReactState(REACT_PASSIVE);

                me->SetSpeed(MOVE_RUN, 0.5f);

                me->GetMotionMaster()->Clear(true);
                me->GetMotionMaster()->MoveChase(target);
                break;
            }
            default:
                break;
        }
    }

    void DoAction(int32 const action) override
    {
        switch (action)
        {
            case FreeRavenous:
            {
                if (!IsMythicRaid())
                    break;

                m_Events.CancelEvent(CheckPlayer);
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE);

                float x = me->GetPositionX() + (9.0f * cos(me->GetOrientation()));
                float y = me->GetPositionY() + (9.0f * sin(me->GetOrientation()));

                me->GetMotionMaster()->MoveJump(x, y, arenaFloor, 15.0f, 25.0f, me->GetOrientation());

                AddDelayedEvent(2 * IN_MILLISECONDS, [this]() -> void { me->CastSpell(me, OnTheHunt, false); });
                break;
            }
            case InterruptRavenous:
            {
                if (me->HasAura(SpellInflamed))
                    break;

                me->GetMotionMaster()->Clear();

                me->CastSpell(me, SpellInflamed, true);

                AddDelayedEvent(1 * IN_MILLISECONDS, [this]() -> void
                {
                    Position pos;
                    float x = me->GetPositionX() + (7.0f * cos(me->GetOrientation()));
                    float y = me->GetPositionY() + (7.0f * sin(me->GetOrientation()));

                    pos.m_positionX = x;
                    pos.m_positionY = y;

                    /// Creating the circle path from the center
                    me->GetMotionMaster()->Clear();
                    me->SetWalk(false);
                    me->SetSpeed(MOVE_RUN, 2.0f);

                    Movement::MoveSplineInit splineInit(*me);
                    FillCirclePath(pos, 7.0f, me->GetPositionZ(), splineInit.Path(), true);
                    splineInit.SetWalk(true);
                    splineInit.SetCyclic();
                    splineInit.Launch();
                });

                GrantFavorToAllPlayers(me, 10, SpellInflamed);
                break;
            }
            default:
                break;
        }
    }

    void MovementInform(uint32 type, uint32 /*id*/) override
    {
        if (type != CHASE_MOTION_TYPE)
            return;

        if (Unit* target = me->getVictim())
        {
            me->AddAura(InThePitAura, target);
            me->CastSpell(target, SpellMaul, true);
            target->RemoveAura(InThePitAura);
        }
    }

    void KilledUnit(Unit* /*killed*/) override
    {
        if (!IsMythicRaid())
            return;

        me->SetInCombatWithZone();

        /// Hunt another player only if the first one's dead, or at the end of the channel
        me->CastSpell(me, OnTheHunt, false);
    }

    void EnterEvadeMode() override
    {
        KillAllDelayedEvents();
        me->InterruptNonMeleeSpells(true);

        CreatureAI::EnterEvadeMode();
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        m_Events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING) || me->HasUnitState(UNIT_STATE_CHASE))
            return;

        if (m_Events.ExecuteEvent() == CheckPlayer)
        {
            std::list<Player*> playerList;
            me->GetPlayerListInGrid(playerList, 2.0f);

            for (Player* player : playerList)
            {
                if (!player->isAlive() || player->GetPositionZ() > 50.0f)
                    continue;

                me->AddAura(InThePitAura, player);
                me->CastSpell(player, SpellMaul, true);
                player->RemoveAura(InThePitAura);
                break;
            }

            m_Events.RescheduleEvent(CheckPlayer, 500);
        }
    }

    void FillCirclePath(Position const& p_Center, float radius, float p_Z, Movement::PointsArray& p_Path, bool p_Clockwise)
    {
        float step = p_Clockwise ? -M_PI / 8.0f : M_PI / 8.0f;
        float angle = p_Center.GetAngle(me->GetPositionX(), me->GetPositionY());

        for (uint8 itr = 0; itr < 16; angle += step, ++itr)
        {
            G3D::Vector3 point;
            point.x = p_Center.GetPositionX() + radius * cosf(angle);
            point.y = p_Center.GetPositionY() + radius * sinf(angle);
            point.z = p_Z;
            p_Path.push_back(point);
        }
    }
};

/// Kargath Bladefist (trigger) - 78846
struct npc_highmaul_kargath_bladefist_trigger : public MS::AI::CosmeticAI
{
    enum eSpells
    {
        BladeDanceDmg = 159217,
        BladeDanceCharge = 159265,
        SpellBladeDanceFadeOut = 159209
    };

    enum eDatas
    {
        MorphWithWeapon = 54674,
        MorphInvisible = 11686,
        AnimKit1 = 5865,
        AnimKit2 = 5864,
        AnimKit3 = 5863,
        AnimKit4 = 5861
    };

    npc_highmaul_kargath_bladefist_trigger(Creature* creature) : MS::AI::CosmeticAI(creature) { }

    void Reset() override
    {
        me->SetReactState(REACT_PASSIVE);
        me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_IMMUNE_TO_PC);
    }

    void SpellHit(Unit* caster, SpellInfo const* spellInfo) override
    {
        if (caster == nullptr)
            return;

        if (spellInfo->Id == BladeDanceCharge)
        {
            me->SetDisplayId(MorphWithWeapon);
            me->CastSpell(me, BladeDanceDmg, true, nullptr, nullptr, caster->GetGUID());
            me->CastSpell(caster, BladeDanceCharge, true);

            uint32 const anumKits[4] = {AnimKit1, AnimKit2, AnimKit3, AnimKit4};
            me->PlayOneShotAnimKit(anumKits[urand(0, 3)]);

            AddDelayedEvent(100, [this]() -> void { me->CastSpell(me, SpellBladeDanceFadeOut, true); });
            AddDelayedEvent(500, [this]() -> void { me->SetDisplayId(MorphInvisible); });
            AddDelayedEvent(600, [this]() -> void { me->DespawnOrUnsummon(); });
        }
    }
};

/// Drunken Bileslinger - 78954
struct npc_highmaul_drunken_bileslinger : public ScriptedAI
{
    enum eSpells
    {
        KegPackCosmetic = 160213,

        MaulingBrewSearch = 159410,
        MaulingBrew = 159414,
        VileBreath = 160521,

        /// Only in Mythic difficulty
        Heckle = 163408    ///< Reduces the favor within Roar of the Crowd.
    };

    enum eEvents
    {
        EventMaulingBrew = 1,
        EventVileBreath,
        EventHeckle
    };

    npc_highmaul_drunken_bileslinger(Creature* creature) : ScriptedAI(creature) { }

    EventMap m_ClassicEvent;
    EventMap m_FightEvent;

    void Reset() override
    {
        me->SetReactState(REACT_PASSIVE);

        me->CastSpell(me, KegPackCosmetic, true);

        m_ClassicEvent.Reset();
        m_ClassicEvent.RescheduleEvent(EventMaulingBrew, urand(3000, 5000));

        m_FightEvent.Reset();
    }

    void DamageTaken(Unit* /*attacker*/, uint32& /*damage*/, DamageEffectType dmgType) override
    {
        if (me->HasReactState(REACT_PASSIVE))
        {
            m_ClassicEvent.Reset();
            me->SetReactState(REACT_AGGRESSIVE);
            m_FightEvent.RescheduleEvent(EventVileBreath, 3000);
            m_ClassicEvent.RescheduleEvent(EventHeckle, 6000);
        }
    }

    void SpellHitTarget(Unit* target, SpellInfo const* spellInfo) override
    {
        if (target == nullptr)
            return;

        if (spellInfo->Id == MaulingBrewSearch)
            me->CastSpell(target, MaulingBrew, true);
    }

    void JustDied(Unit* /*killer*/) override
    {
        me->DespawnOrUnsummon(5000);
    }

    void UpdateAI(uint32 diff) override
    {
        m_ClassicEvent.Update(diff);

        switch (m_ClassicEvent.ExecuteEvent())
        {
            case EventMaulingBrew:
                me->CastSpell(me, MaulingBrewSearch, false);
                m_ClassicEvent.RescheduleEvent(EventMaulingBrew, urand(15000, 25000));
                break;
            case EventHeckle:
                me->CastSpell(me, Heckle, false);
                m_ClassicEvent.RescheduleEvent(EventHeckle, 10000);
                break;
            default:
                break;
        }

        if (!UpdateVictim())
            return;

        m_FightEvent.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        if (m_FightEvent.ExecuteEvent() == EventVileBreath)
        {
            me->CastSpell(me, VileBreath, false);
            m_FightEvent.RescheduleEvent(EventVileBreath, 10000);
        }

        DoMeleeAttackIfReady();

        /// Arena's trash mobs shouldn't enter into the arena
        if (me->GetPositionZ() <= inArenaZ)
            EnterEvadeMode();
    }
};

/// Iron Bomber - 78926
struct npc_highmaul_iron_bomber : public ScriptedAI
{
    enum eSpells
    {
        BombPackCosmetic = 160249,

        SpellIronBomb = 159386,
        FireBomb = 160953,

        /// Only for Mythic difficulty
        Heckle = 163408    ///< Reduces the favor within Roar of the Crowd.
    };

    enum eEvents
    {
        EventIronBomb = 1,
        EventHeckle
    };

    enum eDatas
    {
        MorphDead = 61562,
        IronBomb = 79712
    };

    enum eTalk
    {
        Bomb
    };

    npc_highmaul_iron_bomber(Creature* creature) : ScriptedAI(creature) { }

    bool m_HasBomb;

    EventMap m_Events;

    void Reset() override
    {
        me->SetReactState(REACT_PASSIVE);

        me->CastSpell(me, BombPackCosmetic, true);

        m_HasBomb = false;

        m_Events.Reset();
        m_Events.RescheduleEvent(EventIronBomb, urand(3000, 6000));
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage, DamageEffectType dmgType) override
    {
        if (me->HasReactState(REACT_PASSIVE))
        {
            m_Events.Reset();

            me->SetReactState(REACT_AGGRESSIVE);

            m_Events.RescheduleEvent(EventHeckle, 6000);
        }

        if (m_HasBomb)
            return;

        if (me->HealthBelowPctDamaged(50, damage))
        {
            m_HasBomb = true;

            if (Creature* ironBomb = me->SummonCreature(IronBomb, *me))
                ironBomb->EnterVehicle(me, 0, true);

            Talk(Bomb);
        }
    }

    void PassengerBoarded(Unit* passenger, int8 /*seat*/, bool apply) override
    {
        if (apply || passenger->ToCreature() == nullptr)
            return;

        passenger->CastSpell(passenger, FireBomb, true);
        passenger->ToCreature()->SetReactState(REACT_PASSIVE);
    }

    void JustDied(Unit* /*killer*/) override
    {
        me->SetDisplayId(MorphDead);
        me->DespawnOrUnsummon(5000);
    }

    void UpdateAI(uint32 diff) override
    {
        /// Iron Bombs are out of combat
        m_Events.Update(diff);

        switch (m_Events.ExecuteEvent())
        {
            case EventIronBomb:
                me->CastSpell(me, SpellIronBomb, false);
                m_Events.RescheduleEvent(EventIronBomb, urand(5000, 9000));
                break;
            case EventHeckle:
                me->CastSpell(me, Heckle, false);
                m_Events.RescheduleEvent(EventHeckle, 6000);
                break;
            default:
                break;
        }

        if (!UpdateVictim())
            return;

        DoMeleeAttackIfReady();

        /// Arena's trash mobs shouldn't enter into the arena
        if (me->GetPositionZ() <= inArenaZ)
            EnterEvadeMode();
    }
};

/// Iron Grunt (Cosmetic only) - 84946
struct npc_highmaul_iron_grunt : public ScriptedAI
{
    npc_highmaul_iron_grunt(Creature* creature) : ScriptedAI(creature) { }

    void Reset() override
    {
        me->SetReactState(REACT_PASSIVE);

        AddDelayedEvent(3 * IN_MILLISECONDS, [this]() -> void { me->HandleEmoteCommand(crowdEmotes[urand(0, 7)]); });
    }

    //void LastOperationCalled() override
    //{
    //    AddDelayedEvent(3 * IN_MILLISECONDS, [this]() -> void { me->HandleEmoteCommand(crowdEmotes[urand(0, 7)]); });
    //}

    void UpdateAI(uint32 diff) override
    {
    }
};

/// Iron Grunt - 79068
struct npc_highmaul_iron_grunt_second : public MS::AI::CosmeticAI
{
    enum eSpells
    {
        Grapple = 159188,
        CrowdMinionKilled = 163392
    };

    enum eEvent
    {
        EventGrapple = 1
    };

    npc_highmaul_iron_grunt_second(Creature* creature) : MS::AI::CosmeticAI(creature) { }

    EventMap m_Events;

    void Reset() override
    {
        me->SetReactState(REACT_PASSIVE);

        AddDelayedEvent(3 * IN_MILLISECONDS, [this]() -> void { me->HandleEmoteCommand(crowdEmotes[urand(0, 7)]); });
        m_Events.Reset();
    }

    void DamageTaken(Unit* /*attacker*/, uint32& /*damage*/, DamageEffectType dmgType) override
    {
        if (me->HasReactState(REACT_PASSIVE))
        {
            me->SetReactState(REACT_AGGRESSIVE);
            m_Events.Reset();
            m_Events.RescheduleEvent(EventGrapple, 3000);
        }
    }

    void JustDied(Unit* /*killer*/) override
    {
        /// In Mythic difficulty, killing Iron Grunts grants favor for Roar of the Crowd.
        if (Map* map = me->GetMap())
            if (map->IsMythicRaid())
                CastSpellToPlayers(map, nullptr, CrowdMinionKilled, true);
    }

    void LastOperationCalled() override
    {
        AddDelayedEvent(3 * IN_MILLISECONDS, [this]() -> void { me->HandleEmoteCommand(crowdEmotes[urand(0, 7)]); });
    }

    void UpdateAI(uint32 diff) override
    {
        MS::AI::CosmeticAI::UpdateAI(diff);

        if (!UpdateVictim())
            return;

        m_Events.Update(diff);

        if (m_Events.ExecuteEvent() == EventGrapple)
        {
            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                me->CastSpell(target, Grapple, true);
            m_Events.RescheduleEvent(EventGrapple, 6000);
        }

        DoMeleeAttackIfReady();

        /// Arena's trash mobs shouldn't enter into the arena
        if (me->GetPositionZ() <= inArenaZ)
            EnterEvadeMode();
    }
};

/// Ogre Grunt - 84958
struct npc_highmaul_ogre_grunt : public MS::AI::CosmeticAI
{
    npc_highmaul_ogre_grunt(Creature* creature) : MS::AI::CosmeticAI(creature) { }

    void Reset() override
    {
        me->SetReactState(REACT_PASSIVE);

        AddDelayedEvent(3 * IN_MILLISECONDS, [this]() -> void { me->HandleEmoteCommand(crowdEmotes[urand(0, 7)]); });
    }

    void DamageTaken(Unit* /*attacker*/, uint32& /*damage*/, DamageEffectType dmgType) override
    {
        if (me->HasReactState(REACT_PASSIVE))
            me->SetReactState(REACT_AGGRESSIVE);
    }

    void JustDied(Unit* /*killer*/) override
    {
        /// In Mythic difficulty, killing Iron Grunts grants favor for Roar of the Crowd.
    }

    void LastOperationCalled() override
    {
        AddDelayedEvent(3 * IN_MILLISECONDS, [this]() -> void { me->HandleEmoteCommand(crowdEmotes[urand(0, 7)]); });
    }

    void UpdateAI(uint32 diff) override
    {
        MS::AI::CosmeticAI::UpdateAI(diff);

        if (!UpdateVictim())
            return;

        DoMeleeAttackIfReady();

        /// Arena's trash mobs shouldn't enter into the arena
        if (me->GetPositionZ() <= inArenaZ)
            EnterEvadeMode();
    }
};

/// Ogre Grunt - 84948
struct npc_highmaul_ogre_grunt_second : public MS::AI::CosmeticAI
{
    npc_highmaul_ogre_grunt_second(Creature* creature) : MS::AI::CosmeticAI(creature) { }

    void Reset() override
    {
        me->SetReactState(REACT_PASSIVE);

        AddDelayedEvent(3 * IN_MILLISECONDS, [this]() -> void { me->HandleEmoteCommand(crowdEmotes[urand(0, 7)]); });
    }

    void DamageTaken(Unit* /*attacker*/, uint32& /*damage*/, DamageEffectType dmgType) override
    {
        if (me->HasReactState(REACT_PASSIVE))
            me->SetReactState(REACT_AGGRESSIVE);
    }

    void JustDied(Unit* /*killer*/) override
    {
        /// In Mythic difficulty, killing Iron Grunts grants favor for Roar of the Crowd.
    }

    void LastOperationCalled() override
    {
        AddDelayedEvent(3 * IN_MILLISECONDS, [this]() -> void { me->HandleEmoteCommand(crowdEmotes[urand(0, 7)]); });
    }

    void UpdateAI(uint32 diff) override
    {
        MS::AI::CosmeticAI::UpdateAI(diff);

        if (!UpdateVictim())
            return;

        DoMeleeAttackIfReady();

        /// Arena's trash mobs shouldn't enter into the arena
        if (me->GetPositionZ() <= inArenaZ)
            EnterEvadeMode();
    }
};

/// Highmaul Sweeper - 88874
struct npc_highmaul_highmaul_sweeper : public MS::AI::CosmeticAI
{
    enum eSpells
    {
        ArenaSweeper = 177776,
        MonstersBrawl = 177815,
        ArenaSweeperImpact = 177802
    };

    enum eActions
    {
        KickOutPlayers,

        SpawnIronBombers = 5,
        SpawnDrukenBileslinger
    };

    enum eSweeperType
    {
        TypeRight,
        TypeLeft
    };

    npc_highmaul_highmaul_sweeper(Creature* creature) : MS::AI::CosmeticAI(creature)
    {
        m_Instance = creature->GetInstanceScript();
    }

    InstanceScript* m_Instance;
    uint8 m_MoveID;
    uint8 m_SweeperType;
    bool m_ComeBack;

    void Reset() override
    {
        m_MoveID = 0;
        m_SweeperType = me->GetOrientation() >= 6.0f ? eSweeperType::TypeRight : eSweeperType::TypeLeft;
        m_ComeBack = false;

        me->SetReactState(REACT_PASSIVE);
        me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE);
        me->SetSpeed(MOVE_RUN, 2.0f);
    }

    void DoAction(int32 const action) override
    {
        if (action == KickOutPlayers)
        {
            me->CastSpell(me, ArenaSweeper, true);
            me->GetMotionMaster()->MovePoint(m_MoveID, highmaulSweeperMoves[m_SweeperType][m_MoveID]);
        }
    }

    void MovementInform(uint32 type, uint32 /*id*/) override
    {
        if (type != POINT_MOTION_TYPE)
            return;

        if (m_MoveID < (HighmaulSweeperMovesCount - 1) && !m_ComeBack)
        {
            ++m_MoveID;
            me->GetMotionMaster()->MovePoint(m_MoveID, highmaulSweeperMoves[m_SweeperType][m_MoveID]);
        }
        else if (m_MoveID == (HighmaulSweeperMovesCount - 1))
        {
            m_ComeBack = true;
            --m_MoveID;
            me->GetMotionMaster()->MovePoint(m_MoveID, highmaulSweeperMoves[m_SweeperType][m_MoveID]);
        }
        else if (m_MoveID == 0 && m_ComeBack)
        {
            /// End of move
            m_ComeBack = false;
            me->RemoveAura(ArenaSweeper);
            AddDelayedEvent(1 * IN_MILLISECONDS, [this]() -> void { me->SetFacingTo(me->GetHomePosition().m_orientation); });

            /// Just needed once
            if (m_SweeperType)
            {
                if (Creature* kargath = m_Instance->GetCreature((KargathBladefist)))
                {
                    kargath->AI()->DoAction(SpawnIronBombers);
                    kargath->AI()->DoAction(SpawnDrukenBileslinger);
                }
            }
        }
        else if (m_ComeBack && m_MoveID > 0)
        {
            --m_MoveID;
            me->GetMotionMaster()->MovePoint(m_MoveID, highmaulSweeperMoves[m_SweeperType][m_MoveID]);
        }
    }

    void SpellHitTarget(Unit* target, SpellInfo const* spellInfo) override
    {
        if (target == nullptr)
            return;

        if (spellInfo->Id == MonstersBrawl)
        {
            me->CastSpell(target, ArenaSweeperImpact, true);

            Position firstPos = sweeperJumpPos[m_SweeperType][0];
            Position secondPos = sweeperJumpPos[m_SweeperType][1];

            if (me->GetDistance(firstPos) > me->GetDistance(secondPos))
                target->GetMotionMaster()->MoveJump(secondPos, 15.0f, 25.0f);
            else
                target->GetMotionMaster()->MoveJump(firstPos, 15.0f, 25.0f);
        }
    }
};

/// Chain Hurl Vehicle - 79134
struct npc_highmaul_chain_hurl_vehicle : public MS::AI::CosmeticAI
{
    enum eSpells
    {
        ChainHurlJumpDest = 159995,
        Obscured = 160131,
        Chain = 159531,
        FlameJetDoT = 159311
    };

    enum eAction
    {
        EndOfChainHurl = 7
    };

    npc_highmaul_chain_hurl_vehicle(Creature* creature) : MS::AI::CosmeticAI(creature)
    {
        m_Instance = creature->GetInstanceScript();
    }

    InstanceScript* m_Instance;

    float m_Angle;
    bool m_Rotate;

    void Reset() override
    {
        m_Angle = 0.0f;
        m_Rotate = false;
    }

    void PassengerBoarded(Unit* passenger, int8 /*seatID*/, bool apply) override
    {
        if (apply || passenger == nullptr || passenger->GetTypeId() != TypeID::TYPEID_PLAYER)
        {
            if (!m_Rotate && apply)
                m_Rotate = true;

            if (apply && passenger != nullptr)
                passenger->RemoveAura(FlameJetDoT);

            return;
        }

        ObjectGuid guid = passenger->GetGUID();
        AddDelayedEvent(1 * IN_MILLISECONDS, [this, guid]() -> void
        {
            if (Unit* passenger = Unit::GetUnit(*me, guid))
                passenger->CastSpell(arenaStandsPos, ChainHurlJumpDest, true);
        });

        passenger->RemoveAura(Chain);
        passenger->AddAura(Obscured, passenger);

        m_Rotate = false;
        m_Angle = 0.0f;
        me->SetFacingTo(m_Angle);
        me->SetOrientation(m_Angle);
    }

    void UpdateAI(uint32 diff) override
    {
        MS::AI::CosmeticAI::UpdateAI(diff);

        if (!m_Rotate)
            return;

        m_Angle += (2.0f * M_PI) / 10.0f;

        if (m_Angle > (2.0f * M_PI))
            m_Angle = 0.0f;

        me->SetFacingTo(m_Angle);
        me->SetOrientation(m_Angle);
    }
};

/// Area Trigger for Crowd - 79260
struct npc_highmaul_areatrigger_for_crowd : public ScriptedAI
{
    enum eActions
    {
        StartIntro,
        VulgorDied = 2
    };

    enum eSpells
    {
        ElevatorSoundTrigger = 166694,
        Obscured = 160131
    };

    enum eEvent
    {
        InitObscured = 1
    };

    enum eCreatures
    {
        IronGrunt1 = 84946,
        IronGrunt2 = 79068,
        OgreGrunt1 = 84948,
        OgreGrunt2 = 84958
    };

    npc_highmaul_areatrigger_for_crowd(Creature* creature) : ScriptedAI(creature)
    {
        m_IntroStarted = false;
        m_Instance = creature->GetInstanceScript();
        m_CheckTimer = 1000;
    }

    bool m_IntroStarted;
    InstanceScript* m_Instance;
    uint32 m_CheckTimer;
    EventMap m_Events;

    void Reset() override
    {
        me->SetReactState(REACT_PASSIVE);
        me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE);
        me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_IMMUNE_TO_PC);

        m_Events.Reset();
        m_Events.RescheduleEvent(InitObscured, 2000);
    }

    void UpdateAI(uint32 diff) override
    {
        ScheduleIntro(diff);

        m_Events.Update(diff);

        if (m_Events.ExecuteEvent() == InitObscured)
        {
            std::list<Creature*> creatureList;
            me->GetCreatureListInGrid(creatureList, 300.0f);

            if (creatureList.empty())
                return;

            creatureList.remove_if([this](Creature* creature) -> bool
            {
                if (creature->GetEntry() != DrunkenBileslinger && creature->GetEntry() != IronBomber && creature->GetEntry() != IronGrunt1 && creature->GetEntry() != IronGrunt2 && creature->GetEntry() != OgreGrunt1 && creature->GetEntry() != OgreGrunt2)
                    return true;

                if (creature->HasAura(Obscured, me->GetGUID()))
                    return true;

                return false;
            });

            for (Creature* creature : creatureList)
                me->CastSpell(creature, Obscured, true);

            m_Events.RescheduleEvent(InitObscured, 3000);
        }
    }

    void ScheduleIntro(uint32 const diff)
    {
        if (!m_CheckTimer || m_IntroStarted)
            return;

        if (m_CheckTimer <= diff)
        {
            if (Player* player = me->FindNearestPlayer(10.0f))
            {
                m_IntroStarted = true;

                me->CastSpell(me, ElevatorSoundTrigger, true);

                if (Creature* vulgor = m_Instance->GetCreature((Vulgor)))
                {
                    if (vulgor->isAlive())
                    {
                        if (Creature* john = m_Instance->GetCreature((JhornTheMad)))
                            john->AI()->DoAction(StartIntro);

                        if (Creature* thoktar = m_Instance->GetCreature((ThoktarIronskull)))
                            thoktar->AI()->DoAction(StartIntro);
                    }
                    else /// Handle the case if Vul'gor already died
                    {
                        if (Creature* john = m_Instance->GetCreature((JhornTheMad)))
                            john->AI()->DoAction(VulgorDied);

                        if (Creature* thoktar = m_Instance->GetCreature((ThoktarIronskull)))
                            thoktar->AI()->DoAction(VulgorDied);

                        if (Creature* margokCosmetic = m_Instance->GetCreature((MargokCosmetic)))
                            margokCosmetic->AI()->DoAction(VulgorDied);

                        if (Creature* gharg = m_Instance->GetCreature((GhargArenaMaster)))
                            gharg->AI()->DoAction(StartIntro);
                    }
                }
            }
            else
                m_CheckTimer = 1000;
        }
        else
            m_CheckTimer -= diff;
    }
};

/// Earth Breaker - 162271
class spell_highmaul_earth_breaker : public SpellScript
{
    PrepareSpellScript(spell_highmaul_earth_breaker);

    enum eDatas
    {
        TargetRestrict = 20675,
        EarthMissile = 162472,
        SmolderingStone = 80051
    };

    void CorrectTargets(std::list<WorldObject*>& targets)
    {
        if (targets.empty())
            return;

        SpellTargetRestrictionsEntry const* restriction = sSpellTargetRestrictionsStore.LookupEntry(TargetRestrict);
        if (restriction == nullptr)
            return;

        Unit* caster = GetCaster();
        if (caster == nullptr)
            return;

        float radius = GetSpellInfo()->Effects[1]->CalcRadius(caster);
        targets.remove_if([radius, caster, restriction](WorldObject* object) -> bool
        {
            if (object == nullptr)
                return true;

            if (!object->IsInAxe(caster, restriction->Width, radius))
                return true;

            return false;
        });
    }

    void HandleBeforeCast()
    {
        if (Unit* caster = GetCaster())
        {
            float radius = 30.0f;
            float o = caster->GetOrientation();
            float x = caster->GetPositionX() + (radius * cos(o));
            float y = caster->GetPositionY() + (radius * sin(o));
            float z = caster->GetPositionZ();
            caster->CastSpell(x, y, z, EarthMissile, true);
            caster->SummonCreature(SmolderingStone, x, y, z, o, TEMPSUMMON_TIMED_DESPAWN, 45000);
        }
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_highmaul_earth_breaker::CorrectTargets, EFFECT_1, TARGET_UNIT_ENEMY_BETWEEN_DEST);
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_highmaul_earth_breaker::CorrectTargets, EFFECT_2, TARGET_UNIT_ENEMY_BETWEEN_DEST);
        BeforeCast += SpellCastFn(spell_highmaul_earth_breaker::HandleBeforeCast);
    }
};

/// Impale - 159113
class spell_highmaul_impale : public AuraScript
{
    enum eSpell
    {
        OpenWounds = 159178
    };

    enum eCreature
    {
        AreaTriggerForCrowd = 79260
    };

    PrepareAuraScript(spell_highmaul_impale);

    void OnRemove(AuraEffect const* /*auraEffect*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();
        Unit* caster = GetCaster();
        if (target == nullptr || caster == nullptr)
            return;

        AuraRemoveMode removeMode = GetTargetApplication()->GetRemoveMode();
        if (removeMode != AURA_REMOVE_BY_DEATH)
            caster->CastSpell(target, OpenWounds, true);

        if (Creature* trigger = target->FindNearestCreature(AreaTriggerForCrowd, 50.0f))
        {
            if (target->GetDistance(trigger) >= 10.0f)
            {
                float o = target->GetAngle(trigger);
                float x = target->GetPositionX() + 5.0f * cos(o);
                float y = target->GetPositionY() + 5.0f * sin(o);
                float z = caster->GetPositionZ();

                Position const pos = {x, y, z, o};
                target->ExitVehicle(&pos);
                return;
            }
        }

        target->ExitVehicle();
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_highmaul_impale::OnRemove, EFFECT_1, SPELL_AURA_PERIODIC_DAMAGE, AURA_EFFECT_HANDLE_REAL);
    }
};

/// Fire Pillar Steam Timer - 163967
class spell_highmaul_fire_pillar_steam_timer : public AuraScript
{
    enum eSpell
    {
        FirePillarSteamCosmetic = 163970
    };

    PrepareAuraScript(spell_highmaul_fire_pillar_steam_timer);

    void OnRemove(AuraEffect const* /*auraEffect*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();
        if (target == nullptr)
            return;

        target->CastSpell(target, FirePillarSteamCosmetic, true);
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_highmaul_fire_pillar_steam_timer::OnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

/// Fire Pillar Activated - 159706
class spell_highmaul_fire_pillar_activated : public AuraScript
{
    PrepareAuraScript(spell_highmaul_fire_pillar_activated);

    void OnRemove(AuraEffect const* /*auraEffect*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();
        if (target == nullptr)
            return;

        if (Creature* pillar = target->ToCreature())
            if (pillar->IsAIEnabled)
                pillar->AI()->DoAction(0);
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_highmaul_fire_pillar_activated::OnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

/// Berserker Rush - 159028
class spell_highmaul_berserker_rush : public AuraScript
{
    enum eAction
    {
        InterruptByPillar = 4
    };

    enum eSpell
    {
        BerserkerRushIncrease = 159029
    };

    PrepareAuraScript(spell_highmaul_berserker_rush);

    void OnRemove(AuraEffect const* /*auraEffect*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();
        if (target == nullptr)
            return;

        AuraRemoveMode removeMode = GetTargetApplication()->GetRemoveMode();

        if (Creature* kargath = target->ToCreature())
        {
            if (kargath->IsAIEnabled && removeMode != AURA_REMOVE_BY_EXPIRE)
                kargath->AI()->DoAction(InterruptByPillar);
            else if (kargath->IsAIEnabled)
            {
                //if (auto const& ai = CAST_AI(boss_kargath_bladefist, kargath->GetAI()))
                    //if (Unit* victim = Unit::GetUnit(*kargath, ai->m_BerserkerRushTarget))
                        //ai->EndBerserkerRush(victim);
            }

            kargath->RemoveAura(BerserkerRushIncrease);
        }
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_highmaul_berserker_rush::OnRemove, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
    }
};

/// Chain Hurl - 159947
class spell_highmaul_chain_hurl : public SpellScript
{
    enum eDatas
    {
        MaxAffectedTargets = 5,
        SpellObscured = 160131,
        OpenWounds = 159178,
        MaxLFRHealer = 1,
        MaxLFRDamagers = 3,
        MaxLFRTank = 1
    };

    PrepareSpellScript(spell_highmaul_chain_hurl);

    uint8 m_Count;
    ObjectGuid m_Targets[MaxAffectedTargets];

    bool Load() override
    {
        m_Count = 0;

        for (uint8 i = 0; i < MaxAffectedTargets; ++i)
            m_Targets[i].Clear();

        return true;
    }

    bool TargetsAlreadySelected() const
    {
        bool l_Return = false;
        for (uint8 i = 0; i < m_Count; ++i)
        {
            if (!m_Targets[i])
                return false;

            l_Return = true;
        }

        return l_Return;
    }

    void ProcessLFRTargetting(std::list<WorldObject*>& targets, std::list<Player*> playerList)
    {
        std::list<Player*> tanksList = playerList;
        std::list<Player*> healersList = playerList;
        std::list<Player*> damagersList = playerList;

        uint8 openWoundsStacks = 0;
        tanksList.remove_if([this, &openWoundsStacks](Player* player) -> bool
        {
            if (player->GetSpecializationRole() != ROLES_TANK)
                return true;

            if (player->HasAura(SpellObscured))
                return true;

            if (Aura* openWounds = player->GetAura(OpenWounds))
                if (openWounds->GetStackAmount() > openWoundsStacks)
                    openWoundsStacks = openWounds->GetStackAmount();

            return false;
        });

        if (!tanksList.empty())
        {
            tanksList.remove_if([this, openWoundsStacks](Player* player) -> bool
            {
                if (player->GetSpecializationRole() != ROLES_TANK)
                    return true;

                if (player->HasAura(SpellObscured))
                    return true;

                if (Aura* openWounds = player->GetAura(OpenWounds))
                    if (openWounds->GetStackAmount() != openWoundsStacks)
                        return true;

                return false;
            });
        }

        /// Just in case of all tanks have the same amount of Open Wounds
        if (!tanksList.empty() && tanksList.size() > MaxLFRTank)
            Trinity::Containers::RandomResizeList(tanksList, MaxLFRTank);

        healersList.remove_if([this](Player* player) -> bool
        {
            if (player->GetSpecializationRole() != ROLES_HEALER)
                return true;

            if (player->HasAura(SpellObscured))
                return true;

            return false;
        });

        if (!healersList.empty() && healersList.size() > MaxLFRHealer)
            Trinity::Containers::RandomResizeList(healersList, MaxLFRHealer);

        damagersList.remove_if([this](Player* player) -> bool
        {
            if (player->GetSpecializationRole() != ROLES_DPS)
                return true;

            if (player->HasAura(SpellObscured))
                return true;

            return false;
        });

        if (!damagersList.empty() && damagersList.size() > MaxLFRDamagers)
            Trinity::Containers::RandomResizeList(damagersList, MaxLFRDamagers);

        m_Count = 0;

        for (Player* player : tanksList)
        {
            targets.push_back(player);
            m_Targets[m_Count] = player->GetGUID();
            ++m_Count;
        }

        for (Player* player : healersList)
        {
            targets.push_back(player);
            m_Targets[m_Count] = player->GetGUID();
            ++m_Count;
        }

        for (Player* player : damagersList)
        {
            targets.push_back(player);
            m_Targets[m_Count] = player->GetGUID();
            ++m_Count;
        }
    }

    void CorrectTargets(std::list<WorldObject*>& targets)
    {
        targets.clear();

        Unit* caster = GetCaster();
        if (caster == nullptr)
            return;

        if (TargetsAlreadySelected())
        {
            for (uint8 i = 0; i < m_Count; ++i)
                if (WorldObject* l_Object = Player::GetPlayer(*caster, m_Targets[i]))
                    targets.push_back(l_Object);

            return;
        }

        std::list<Player*> playerList;
        caster->GetPlayerListInGrid(playerList, 300.0f);

        if (playerList.empty())
            return;

        playerList.remove_if(Trinity::UnitAuraCheck(true, SpellObscured));

        if (playerList.empty())
            return;

        /// In Looking for Raid difficulty, Kargath automatically tosses the tank with the highest amount of Open Wounds stacks,
        /// One random healer, and three random DPS into the crowd.
        if (caster->GetMap() && caster->GetMap()->IsLfr())
            ProcessLFRTargetting(targets, playerList);
        /// Kargath uses his chain to lash the 5 closest enemies and toss them into the arena's stands.
        else
        {
            playerList.sort(Trinity::ObjectDistanceOrderPred(caster));

            m_Count = 0;
            for (Player* player : playerList)
            {
                if (m_Count >= MaxAffectedTargets)
                    break;

                m_Targets[m_Count] = player->GetGUID();
                targets.push_back(player);
                ++m_Count;
            }
        }

        if (targets.size() > MaxAffectedTargets)
            Trinity::Containers::RandomResizeList(targets, MaxAffectedTargets);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_highmaul_chain_hurl::CorrectTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_highmaul_chain_hurl::CorrectTargets, EFFECT_1, TARGET_UNIT_SRC_AREA_ENEMY);
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_highmaul_chain_hurl::CorrectTargets, EFFECT_2, TARGET_UNIT_SRC_AREA_ENEMY);
    }
};

/// Vile Breath - 160521
class spell_highmaul_vile_breath : public SpellScript
{
    PrepareSpellScript(spell_highmaul_vile_breath);

    enum eSpell
    {
        TargetRestrict = 20321
    };

    void CorrectTargets(std::list<WorldObject*>& targets)
    {
        if (targets.empty())
            return;

        SpellTargetRestrictionsEntry const* restriction = sSpellTargetRestrictionsStore.LookupEntry(TargetRestrict);
        if (restriction == nullptr)
            return;

        Unit* caster = GetCaster();
        if (caster == nullptr)
            return;

        float angle = 2 * M_PI / 360 * restriction->ConeDegrees;
        targets.remove_if([caster, angle](WorldObject* object) -> bool
        {
            if (object == nullptr)
                return true;

            if (!object->isInFront(caster, angle))
                return true;

            return false;
        });
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_highmaul_vile_breath::CorrectTargets, EFFECT_0, TARGET_UNIT_CONE_ENEMY_110);
    }
};

/// Obscured - 160131
class spell_highmaul_obscured : public AuraScript
{
    PrepareAuraScript(spell_highmaul_obscured);

    uint32 m_UpdateTimer;

    bool Load() override
    {
        m_UpdateTimer = 8000;
        return true;
    }

    void OnUpdate(uint32 diff, AuraEffect* auraEffect)
    {
        if (m_UpdateTimer)
        {
            if (m_UpdateTimer > diff)
            {
                m_UpdateTimer -= diff;
                return;
            }
            else
                m_UpdateTimer = 0;
        }

        if (Unit* target = GetUnitOwner())
        {
            /// Target is not in Arena's stands anymore
            if (target->GetPositionZ() <= inArenaZ)
                auraEffect->GetBase()->Remove();
        }
    }

    void Register() override
    {
        OnEffectUpdate += AuraEffectUpdateFn(spell_highmaul_obscured::OnUpdate, EFFECT_0, SPELL_AURA_INTERFERE_TARGETTING);
    }
};

/// Crowd Minion Killed - 163392
class spell_highmaul_crowd_minion_killed : public SpellScript
{
    PrepareSpellScript(spell_highmaul_crowd_minion_killed);

    void HandleDummy(SpellEffIndex /*effectIndex*/)
    {
        if (Unit* caster = GetCaster())
            caster->EnergizeBySpell(caster, GetSpellInfo()->Id, 1, POWER_ALTERNATE);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_highmaul_crowd_minion_killed::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

/// Roar of the Crowd - 163302
class spell_highmaul_roar_of_the_crowd : public AuraScript
{
    enum eSpells
    {
        CrowdFavorite25 = 163366,   ///< Mod damage PCT done, and mod pet damage PCT done
        CrowdFavorite50 = 163368,   ///< Mod damage PCT done, and mod pet damage PCT done
        CrowdFavorite75 = 163369,   ///< Mod damage PCT done, and mod pet damage PCT done
        CrowdFavorite100 = 163370    ///< Mod damage PCT done, and mod pet damage PCT done
    };

    enum eDatas
    {
        Favor25 = 25,
        Favor50 = 50,
        Favor75 = 75,
        Favor100 = 100
    };

    PrepareAuraScript(spell_highmaul_roar_of_the_crowd);

    void OnTick(AuraEffect const* /*auraEffect*/)
    {
        if (Unit* caster = GetCaster())
        {
            int32 l_Favor = caster->GetPower(POWER_ALTERNATE);

            /// 0 ... 24
            if (l_Favor < Favor25)
            {
                caster->RemoveAura(CrowdFavorite25);
                caster->RemoveAura(CrowdFavorite50);
                caster->RemoveAura(CrowdFavorite75);
                caster->RemoveAura(CrowdFavorite100);
            }
            /// 25 ... 49
            else if (l_Favor < Favor50)
                caster->CastSpell(caster, CrowdFavorite25, true);
            /// 50 ... 74
            else if (l_Favor < Favor75)
                caster->CastSpell(caster, CrowdFavorite50, true);
            /// 75 ... 99
            else if (l_Favor < Favor100)
                caster->CastSpell(caster, CrowdFavorite75, true);
            /// 100
            else
                caster->CastSpell(caster, CrowdFavorite100, true);
        }
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_highmaul_roar_of_the_crowd::OnTick, EFFECT_1, SPELL_AURA_PERIODIC_DUMMY);
    }
};

/// Inflamed - 163130
class spell_highmaul_inflamed : public AuraScript
{
    enum eSpell
    {
        OnTheHunt = 162497
    };

    PrepareAuraScript(spell_highmaul_inflamed);

    void OnRemove(AuraEffect const* /*auraEffect*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();
        if (target == nullptr)
            return;

        if (Creature* ravenous = target->ToCreature())
        {
            ravenous->GetMotionMaster()->Clear();
            ravenous->CastSpell(ravenous, OnTheHunt, false);
        }
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_highmaul_inflamed::OnRemove, EFFECT_0, SPELL_AURA_MOD_DAMAGE_PERCENT_TAKEN, AURA_EFFECT_HANDLE_REAL);
    }
};

/// Heckle - 163408
class spell_highmaul_heckle : public SpellScript
{
    PrepareSpellScript(spell_highmaul_heckle);

    void HandleDummy(SpellEffIndex /*effectIndex*/)
    {
        if (Creature* caster = GetCaster()->ToCreature())
            GrantFavorToAllPlayers(caster, -2, GetSpellInfo()->Id);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_highmaul_heckle::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

/// Berserker Rush - 159001
class spell_highmaul_berserker_rush_periodic : public AuraScript
{
    PrepareAuraScript(spell_highmaul_berserker_rush_periodic);

    void OnTick(AuraEffect const* auraEffect)
    {
        if (Creature* caster = GetTarget()->ToCreature())
        {
            if (!caster->GetMap()->IsMythicRaid())
                return;

            /// Grants one point of Favor every second
            if (auraEffect->GetTickNumber() % 2)
                GrantFavorToAllPlayers(caster, 1, GetSpellInfo()->Id);
        }
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_highmaul_berserker_rush_periodic::OnTick, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
    }
};

/// Blade Dance (periodic triggered) - 159212
class spell_highmaul_blade_dance : public SpellScript
{
    enum eSpell
    {
        Obscured = 160131
    };

    PrepareSpellScript(spell_highmaul_blade_dance);

    void CorrectTargets(std::list<WorldObject*>& targets)
    {
        Unit* caster = GetCaster();
        if (caster == nullptr)
            return;

        targets.clear();

        std::list<Player*> playerList;
        caster->GetPlayerListInGrid(playerList, 300.0f);

        if (playerList.empty())
            return;

        playerList.remove_if([this](Player* player) -> bool
        {
            if (player->GetSpecializationRole() == ROLES_TANK)
                return true;

            if (player->HasAura(Obscured))
                return true;

            return false;
        });

        if (playerList.empty())
            return;

        std::list<Player*> snapShot;

        playerList.remove_if([this, caster, &snapShot](Player* player) -> bool
        {
            if (caster->GetDistance(player) <= 10.0f)
            {
                snapShot.push_back(player);
                return true;
            }

            return false;
        });

        if (playerList.empty() && !snapShot.empty())
            playerList = snapShot;

        Trinity::Containers::RandomResizeList(playerList, 1);
        targets.push_back(playerList.front());
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_highmaul_blade_dance::CorrectTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
    }
};

/// Berserker Rush - 163180
/// Mauling Brew - 159410
/// Iron Bomb - 159386
class spell_highmaul_correct_searchers : public SpellScript
{
    enum eSpells
    {
        Obscured = 160131,
        IronBomb = 159386,
        BerserkerRush = 163180
    };

    PrepareSpellScript(spell_highmaul_correct_searchers);

    void CorrectTargets(std::list<WorldObject*>& targets)
    {
        targets.remove_if(Trinity::UnitAuraCheck(true, Obscured));

        if (GetSpellInfo()->Id == BerserkerRush && !targets.empty())
        {
            Unit* caster = GetCaster();

            targets.remove_if([this, caster](WorldObject* object) -> bool
            {
                if (object == nullptr || object->GetTypeId() != TypeID::TYPEID_PLAYER)
                    return true;

                if (Player* player = object->ToPlayer())
                    if (!player->IsRangedDamageDealer())
                        return true;

                return false;
            });

            /// Kargath will target one of the three furthest targets and chase them till he either kills the player.
            if (caster->GetMap()->IsMythicRaid())
            {
                targets.sort(Trinity::DistanceCompareOrderPred2(caster, false));

                uint8 count = 0;
                std::list<WorldObject*> newTargets;

                for (WorldObject* itr : targets)
                {
                    if (count >= 3)
                        break;

                    newTargets.push_back(itr);
                    ++count;
                }

                targets.clear();

                if (!newTargets.empty())
                    Trinity::Containers::RandomResizeList(newTargets, count);

                if (!newTargets.empty())
                    targets.push_back(newTargets.front());
            }
        }
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_highmaul_correct_searchers::CorrectTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);

        if (m_scriptSpellId == IronBomb)
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_highmaul_correct_searchers::CorrectTargets, EFFECT_1, TARGET_UNIT_SRC_AREA_ENEMY);
    }
};

void AddSC_boss_kargath_bladefist()
{
   
    RegisterHighmaulCreatureAI(npc_highmaul_somldering_stoneguard);
    RegisterHighmaulCreatureAI(npc_highmaul_fire_pillar);
    RegisterHighmaulCreatureAI(npc_highmaul_ravenous_bloodmaw);
    RegisterHighmaulCreatureAI(npc_highmaul_kargath_bladefist_trigger);
    RegisterHighmaulCreatureAI(npc_highmaul_drunken_bileslinger);
    RegisterHighmaulCreatureAI(npc_highmaul_iron_bomber);
    RegisterHighmaulCreatureAI(npc_highmaul_iron_grunt);
    RegisterHighmaulCreatureAI(npc_highmaul_iron_grunt_second);
    RegisterHighmaulCreatureAI(npc_highmaul_ogre_grunt);
    RegisterHighmaulCreatureAI(npc_highmaul_ogre_grunt_second);
    RegisterHighmaulCreatureAI(npc_highmaul_highmaul_sweeper);
    RegisterHighmaulCreatureAI(npc_highmaul_chain_hurl_vehicle);
    RegisterHighmaulCreatureAI(npc_highmaul_areatrigger_for_crowd);

    RegisterSpellScript(spell_highmaul_earth_breaker);
    RegisterAuraScript(spell_highmaul_impale);
    RegisterAuraScript(spell_highmaul_fire_pillar_steam_timer);
    RegisterAuraScript(spell_highmaul_fire_pillar_activated);
    RegisterAuraScript(spell_highmaul_berserker_rush);
    RegisterSpellScript(spell_highmaul_chain_hurl);
    RegisterSpellScript(spell_highmaul_vile_breath);
    RegisterAuraScript(spell_highmaul_obscured);
    RegisterSpellScript(spell_highmaul_crowd_minion_killed);
    RegisterAuraScript(spell_highmaul_roar_of_the_crowd);
    RegisterAuraScript(spell_highmaul_inflamed);
    RegisterSpellScript(spell_highmaul_heckle);
    RegisterAuraScript(spell_highmaul_berserker_rush_periodic);
    RegisterSpellScript(spell_highmaul_blade_dance);
    RegisterSpellScript(spell_highmaul_correct_searchers);
}
