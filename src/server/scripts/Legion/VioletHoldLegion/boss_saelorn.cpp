/*
    Dungeon : Violet Hold Legion 100-110
    Encounter: Saelorn
    Normal: 100%, Heroic: 100%, Mythic: 100%
    Need cosmetic fix: stealth aura from Phase Spider.
*/

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "violet_hold_legion.h"

enum Says
{
    SAY_AGGRO           = 0,
    SAY_DEATH           = 7,
};

enum Spells
{
    SPELL_VENOM_SPRAY           = 202414,
    SPELL_WEB_GRAB              = 202462,
    SPELL_FEL_DETONATION        = 202473,
    SPELL_TOXIC_BLOOD           = 210504,

    //Spider
    SPELL_CREEPING_SLAUGHTER    = 202306,
};

enum eEvents
{
    EVENT_VENOM_SPRAY           = 1,
    EVENT_WEB_GRAB              = 2,
    EVENT_FEL_DETONATION        = 3,
    EVENT_PHASE_SPIDER          = 4,
    EVENT_TOXIC_BLOOD           = 5,
};

//102387
class boss_saelorn : public CreatureScript
{
public:
    boss_saelorn() : CreatureScript("boss_saelorn") {}

    struct boss_saelornAI : public BossAI
    {
        boss_saelornAI(Creature* creature) : BossAI(creature, DATA_SAELORN), timer(0), text(0)
        {
            me->SetReactState(REACT_PASSIVE);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_NON_ATTACKABLE);
            removeloot = false;
        }

        bool removeloot;
        uint32 timer;
        uint32 text;

        void Reset() override
        {
            _Reset();

            if (instance->GetData(DATA_MAIN_EVENT_PHASE) == IN_PROGRESS)
                me->SetReactState(REACT_DEFENSIVE);
            timer = 13000;
            text = 1;            
        }

        void EnterCombat(Unit* /*who*/) override
        {
            Talk(SAY_AGGRO);
            _EnterCombat();

            events.RescheduleEvent(EVENT_VENOM_SPRAY, 3000);
            events.RescheduleEvent(EVENT_WEB_GRAB, 14000);
            events.RescheduleEvent(EVENT_PHASE_SPIDER, 15000);

            if (GetDifficultyID() != DIFFICULTY_NORMAL)
                events.RescheduleEvent(EVENT_TOXIC_BLOOD, 10000);
        }

        void JustDied(Unit* /*killer*/) override
        {
            Talk(SAY_DEATH);
            _JustDied();

            if (removeloot)
                me->RemoveFlag(OBJECT_FIELD_DYNAMIC_FLAGS, UNIT_DYNFLAG_LOOTABLE);
        }

        void DoAction(int32 const action) override
        {
            if (action == ACTION_REMOVE_LOOT)
                removeloot = true;
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;
            
            if (timer <= diff)
            {
                if(text < 7)
                {
                    Talk(text);
                    text++;
                    timer = 13000;
                }
            } else timer -= diff;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_VENOM_SPRAY:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 35.0f, true))
                            DoCast(target, SPELL_VENOM_SPRAY);
                        events.RescheduleEvent(EVENT_VENOM_SPRAY, 27000);
                        break;
                    case EVENT_WEB_GRAB:
                        if (Unit* target = SelectTarget(SELECT_TARGET_FARTHEST, 0, 50.0f, true))
                            DoCast(target, SPELL_WEB_GRAB);
                        events.RescheduleEvent(EVENT_WEB_GRAB, 27000);
                        events.RescheduleEvent(EVENT_FEL_DETONATION, 500);
                        break;
                    case EVENT_FEL_DETONATION:
                        DoCast(SPELL_FEL_DETONATION);
                        break;
                    case EVENT_PHASE_SPIDER:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 60.0f, true))
                        {
                            Position pos = target->GetRandomNearPosition(5.0f);
                            me->SummonCreature(NPC_PHASE_SPIDER, pos);
                        }
                        break;
                    case EVENT_TOXIC_BLOOD:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 40.0f, true))
                            DoCast(target, SPELL_TOXIC_BLOOD);
                        events.RescheduleEvent(EVENT_TOXIC_BLOOD, 10000);
                        break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new boss_saelornAI (creature);
    }
};

//102434
class npc_saelorn_phase_spider : public CreatureScript
{
public:
    npc_saelorn_phase_spider() : CreatureScript("npc_saelorn_phase_spider") {}

    struct npc_saelorn_phase_spiderAI : public ScriptedAI
    {
        npc_saelorn_phase_spiderAI(Creature* creature) : ScriptedAI(creature)
        {
            me->SetReactState(REACT_PASSIVE);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_NOT_ATTACKABLE_1);
            me->SetSpeed(MOVE_RUN, 0.8f);
            me->SetSpeed(MOVE_WALK, 0.8f);
        }

        EventMap events;

        void Reset() override {}

        void IsSummonedBy(Unit* summoner) override
        {
            events.RescheduleEvent(EVENT_1, 2000);
            events.RescheduleEvent(EVENT_2, 2500);
        }

        bool checkPlayers()
        {
            std::list<HostileReference*> threatList = me->getThreatManager().getThreatList();
            if (threatList.size() > 1)
                return true;

            return false;
        }            

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim() && me->isInCombat())
                return;

            events.Update(diff);

            if (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_1:
                    {
                        if (me->GetAnyOwner())
                            if (Unit* summoner = me->GetAnyOwner())
                            {
                                me->StopAttack();
                                if (Unit* target = summoner->GetAI()->SelectTarget(SELECT_TARGET_RANDOM, checkPlayers(), 60.0f, true, -SPELL_CREEPING_SLAUGHTER))
                                {
                                    DoCast(target, SPELL_CREEPING_SLAUGHTER, true);
                                    AttackStart(target);
                                }
                                else if (Unit* target2 = summoner->GetAI()->SelectTarget(SELECT_TARGET_RANDOM, checkPlayers(), 60.0f, true))
                                    AttackStart(target2);
                            }
                        events.RescheduleEvent(EVENT_1, 16000);
                        break;
                    }
                    case EVENT_2:
                    {
                        if (me->HasUnitState(UNIT_STATE_CASTING))
                            me->ClearUnitState(UNIT_STATE_CASTING);
                        if (Unit* target = me->getVictim())
                        {
                            if (target->isInFront(me))
                            {
                                if (!me->HasUnitState(UNIT_STATE_ROOT | UNIT_STATE_STUNNED))
                                    me->AddUnitState(UNIT_STATE_ROOT | UNIT_STATE_STUNNED);
                            }
                            else
                            {
                                if (me->HasUnitState(UNIT_STATE_ROOT | UNIT_STATE_STUNNED))
                                    me->ClearUnitState(UNIT_STATE_ROOT | UNIT_STATE_STUNNED);
                            }
                        }
                        else if (!me->getVictim() || !me->getVictim()->IsAlive())
                            events.RescheduleEvent(EVENT_1, 1000);
                        events.RescheduleEvent(EVENT_2, 500);
                        break;
                    }
                }
            }
            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_saelorn_phase_spiderAI(creature);
    }
};

void AddSC_boss_saelorn()
{
    new boss_saelorn();
    new npc_saelorn_phase_spider();
}