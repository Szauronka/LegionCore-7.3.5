/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2006-2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

/* ScriptData
SDName: Stormwind_City
SD%Complete: 0
SDComment:
SDCategory: Stormwind City
EndScriptData */

/* ContentData
EndContentData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "ScriptedEscortAI.h"

class npc_102585_jace_for_dh_questline : public CreatureScript
{
public:
    npc_102585_jace_for_dh_questline() : CreatureScript("npc_102585_jace_for_dh_questline") { }

    struct npc_102585_jace_for_dh_questlineAI : ScriptedAI
    {
        npc_102585_jace_for_dh_questlineAI(Creature* creature) : ScriptedAI(creature) {}

        EventMap events;

        void MoveInLineOfSight(Unit* who) override
        {
            if (events.Empty())
                events.ScheduleEvent(EVENT_1, 2000);

            if (who->GetTypeId() != TYPEID_PLAYER)
                return;

            Player* player = who->ToPlayer();

            if (player->GetQuestStatus(39691) != QUEST_STATUS_INCOMPLETE)
                return;

            player->KilledMonsterCredit(102585);
        }

        void UpdateAI(uint32 diff) override
        {
            events.Update(diff);

            if (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_1:
                    events.ScheduleEvent(EVENT_1, 2000);

                    std::list<Player*> list;
                    me->GetPlayerListInGrid(list, 20.0f);
                    for (Player* player : list)
                        if (player->HasAura(188501) && player->GetQuestStatus(44471) == QUEST_STATUS_INCOMPLETE)
                            player->KilledMonsterCredit(102563);

                    break;
                }
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_102585_jace_for_dh_questlineAI(creature);
    }
};

// Rell Nightwind <SI:7> 55789
class npc_rell_nightwind : public CreatureScript
{
public:
    npc_rell_nightwind() : CreatureScript("npc_rell_nightwind") { }

    struct npc_rell_nightwindAI : public ScriptedAI
    {
        npc_rell_nightwindAI(Creature* creature) : ScriptedAI(creature) { }

        void MoveInLineOfSight(Unit* who) override
        {
            if (Player* player = who->ToPlayer())
                if (player->GetDistance(me) < 20.0f)
                    player->KilledMonsterCredit(55567);
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_rell_nightwindAI(creature);
    }
};

void AddSC_stormwind_city()
{
    new npc_102585_jace_for_dh_questline();
	new npc_rell_nightwind();
}
