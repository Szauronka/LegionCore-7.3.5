/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
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

#include "MotionMaster.h"
#include "CombatAI.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ScriptedEscortAI.h"
#include "PassiveAI.h"
#include "QuestData.h"
#include "ScriptedGossip.h"
#include "SpellAuraEffects.h"
#include "SpellInfo.h"
#include "SpellScript.h"
#include "TaskScheduler.h"
#include "Vehicle.h"

struct npc_Wisp_110572 : public ScriptedAI
{
	npc_Wisp_110572(Creature* creature) : ScriptedAI(creature) { }

	void IsSummonedBy(Unit* summoner) override
	{
		me->SetDisableGravity(true);
		me->SetSpeed(MOVE_FLIGHT, 3.f);
		summoner->CastSpell(me, 46598, true); // Ride Vehicle

		if (summoner->IsPlayer())
			summoner->ToPlayer()->KilledMonsterCredit(me->GetEntry());

		me->GetMotionMaster()->MovePath(110572, false); // start waypoint
	}

	void MovementInform(uint32 type, uint32 id) override
	{
		if (type != WAYPOINT_MOTION_TYPE)
			return;

		switch (id)
		{
		case 8:
			if (Unit* passenger = me->GetVehicleKit()->GetPassenger(0))
				if (Player* player = passenger->ToPlayer())
					if (Creature* sec_wisp = player->SummonCreature(112252, me->GetPosition(), TEMPSUMMON_MANUAL_DESPAWN, 300000))
					{
						player->ExitVehicle();
						player->CastSpell(sec_wisp, 46598, true); // Ride Vehicle
						sec_wisp->SetDisableGravity(true);
						sec_wisp->SetSpeed(MOVE_FLIGHT, 2.f);
					}

			me->DespawnOrUnsummon();
			break;
		}
	}
};

struct npc_Wisp_112252 : public VehicleAI
{
	npc_Wisp_112252(Creature* creature) : VehicleAI(creature) {}

	uint32 timer;
	bool goingBack = false;

	void Reset() override
	{
		timer = 3000;
	}

	void UpdateAI(uint32 diff) override
	{
		if (timer <= diff)
		{
			timer = 3000;

			Vehicle* vehicle = me->GetVehicleKit();
			if (!vehicle) 
				return;

			Unit* passenger = vehicle->GetPassenger(0);
			if (!passenger)
			{
				me->DespawnOrUnsummon();

				return;
			}

			Player* player = passenger->ToPlayer();
			if (!player)
				return;

			if (player->GetQuestObjectiveData(39354, 111876) == 8 && !goingBack)
			{
				me->SetDisableGravity(true);
				me->SetSpeed(MOVE_FLIGHT, 3.f);
				me->GetMotionMaster()->MovePath(1105720, false); // start waypoint back
				goingBack = true;
			}
		}
		else
			timer -= diff;
	}

	void MovementInform(uint32 type, uint32 id) override
	{
		if (type != WAYPOINT_MOTION_TYPE)
			return;

		switch (id)
		{
		case 10:
			if (Unit* passenger = me->GetVehicleKit()->GetPassenger(0))
				if (Player* player = passenger->ToPlayer())
				{
					player->ExitVehicle();

					if (player->HasAura(219856))
						player->RemoveAura(219856);

					me->DespawnOrUnsummon();
				}
			break;
		}
	}
};

class spell_grow_tree_222728 : public SpellScript
{
	PrepareSpellScript(spell_grow_tree_222728);

	void HandleDummy(SpellEffIndex /*effIndex*/)
	{
		auto caster = GetCaster();
		if (!caster)
			return;

		if (auto target = GetHitCreature())
		{
			if (target->GetEntry() == 111876)
			{
				if (auto veh = caster->GetVehicleKit())
					if (auto pass = veh->GetPassenger(0))
						if (auto plr = pass->ToPlayer())
							if (target->GetDisplayId() != 62150) // check if not a grown tree already otherwise add credit
								plr->KilledMonsterCredit(111876, ObjectGuid::Empty);

				target->SetDisplayId(62150);
				target->SetObjectScale(4.f);

				target->DespawnOrUnsummon(30 * IN_MILLISECONDS, Seconds(45));
				target->AddDelayedEvent(30 * IN_MILLISECONDS, [target] 
					{ 
						target->RestoreDisplayId();
						target->SetObjectScale(1.f);
					});
			}
		}
	}

	void Register() override
	{
		OnEffectHitTarget += SpellEffectFn(spell_grow_tree_222728::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
	}
};

class npc_tyrande_whisperwind_104728 : public CreatureScript
{
public:
	npc_tyrande_whisperwind_104728() : CreatureScript("npc_tyrande_whisperwind_104728") { }

	CreatureAI* GetAI(Creature* creature) const
	{
		return new npc_tyrande_whisperwind_104728_escortAI(creature);
	}

	bool OnQuestAccept(Player* player, Creature* creature, Quest const* quest) override
	{
		if (quest->Id == 38687 || quest->Id == 41763)
			player->SummonCreature(104728, creature->GetPosition(), player->GetGUID(), TempSummonType::TEMPSUMMON_MANUAL_DESPAWN, 3600000);

		creature->DespawnOrUnsummon(0U, Seconds(60));

		return true;
	}

	struct npc_tyrande_whisperwind_104728_escortAI : public npc_escortAI
	{
		npc_tyrande_whisperwind_104728_escortAI(Creature* creature) : npc_escortAI(creature) { }

		void IsSummonedBy(Unit* summoner) override
		{
			if (!summoner->IsPlayer())
				return;

			Player* player = summoner->ToPlayer();

			me->Mount(67955);

			Talk(3, player->GetGUID()); // Shala'nir is just ahead. You should be ready for whatever foulness awaits us.
	
			Start(false, true, player->GetGUID()); // start waypoint
		}

		void SpellHit(Unit* /*caster*/, SpellInfo const* spell) override
		{
			if (spell->Id == 207191) // Ping Tyrande 2 - xavius cast it on tyrande when he finished the entrance monologue
			{
				Player* player = GetPlayerForEscort();
				if (!player)
					return;

				Talk(8, player->GetGUID()); // I have no time for games!
				SetEscortPaused(false);
			}
		}

		void WaypointReached(uint32 waypointId) override
		{
			Player* player = GetPlayerForEscort();
			if (!player)
				return;

			switch (waypointId)
			{
			case 1:
				SetEscortPaused(true);

				if (Creature* imageofxavius = me->FindNearestCreature(111228, 50.f))
					me->CastSpell(imageofxavius, 207189, true); // Ping Tyrande 1 - tyrande cast it on xavius to make him start the entrance monologue

				break;
			case 3:
				SetEscortPaused(true);
				Talk(9, player->GetGUID()); // Where are you Malfurion? Answer me!

				scheduler
					.Schedule(Seconds(3), [this, player](TaskContext context)
						{
							player->CreateConversation(3138);
						})
					.Schedule(Seconds(10), [this, player](TaskContext context)
						{
							player->KilledMonsterCredit(104799);
							Talk(10, player->GetGUID()); // I cannot tell where his voice is coming from! Quickly, search the buildings to the east. I will scour the west for signs of him! 
						})
					.Schedule(Seconds(13), [this](TaskContext context)
						{
							SetEscortPaused(false);
						});
				break;
			case 7:
				me->DespawnOrUnsummon();
				break;
			}
		}

		void Reset() override
		{
			scheduler.CancelAll();
		}

		void UpdateAI(uint32 diff) override
		{
			npc_escortAI::UpdateAI(diff);
			scheduler.Update(diff);
		}


	private:
		TaskScheduler scheduler;
	};
};

class npc_image_of_xavius_111228 : public CreatureScript
{
public:
	npc_image_of_xavius_111228() : CreatureScript("npc_image_of_xavius_111228") { }

	CreatureAI* GetAI(Creature* creature) const
	{
		return new npc_image_of_xavius_111228_AI(creature);
	}

	struct npc_image_of_xavius_111228_AI : public ScriptedAI
	{
		npc_image_of_xavius_111228_AI(Creature* creature) : ScriptedAI(creature) { }

		void SpellHit(Unit* caster, SpellInfo const* spell) override
		{
			if (spell->Id == 207189) // Ping Tyrande 1 - tyrande cast it on xavius to make him start the entrance monologue
			{
				Talk(0); // Welcome to my "dream" home! Your beloved Malfurion awaits within. 

				scheduler
					.Schedule(Seconds(7), [this](TaskContext context)
						{
							Talk(1); // But what's this? Which Malfurion is real, and which is part of the Nightmare...? [Laugh] 
						})
					.Schedule(Seconds(14), [this](TaskContext context)
						{
							me->HandleEmoteCommand(11);
						})
					.Schedule(Seconds(17), [this, caster](TaskContext context)
						{
							me->CastSpell(caster, 207191, true); // Ping Tyrande 2 - xavius cast it on tyrande when he finished the entrance monologue
							me->CastSpell(me, 195110, true); // Dungeon Temp Nightmare Shader - can't find the exact spell of xavius shading/teleport
							me->DespawnOrUnsummon(0U, Seconds(60));
						});
			}
		}

		void Reset() override
		{
			scheduler.CancelAll();
		}

		void UpdateAI(uint32 diff) override
		{
			scheduler.Update(diff);
		}


	private:
		TaskScheduler scheduler;
	};
};

class npc_malfurion_stormrage_111258_111259_111260 : public CreatureScript
{
public:
	npc_malfurion_stormrage_111258_111259_111260() : CreatureScript("npc_malfurion_stormrage_111258_111259_111260") { }

	CreatureAI* GetAI(Creature* creature) const
	{
		return new npc_malfurion_stormrage_111258_111259_111260_PassiveAI(creature);
	}

	struct npc_malfurion_stormrage_111258_111259_111260_PassiveAI : public ScriptedAI
	{
		npc_malfurion_stormrage_111258_111259_111260_PassiveAI(Creature* creature) : ScriptedAI(creature) {}

		void Reset() override
		{
			conversation1Happened = false;
			conversation2Happened = false;

			switch (me->GetEntry())
			{
			case 111258:
				me->SetStandState(UNIT_STAND_STATE_KNEEL);
				break;
			case 111259:
				me->SetUInt32Value(UNIT_FIELD_EMOTE_STATE, EMOTE_STATE_DEAD);
				break;
			case 111260:
				me->SetUInt32Value(UNIT_FIELD_EMOTE_STATE, EMOTE_STATE_STUN);
				break;
			}
		}

		void MoveInLineOfSight(Unit* who) override
		{
			Player* player = who->ToPlayer();
			if (!player)
				return;

			switch (player->GetTeam())
			{
			case ALLIANCE:

				if (!conversation1Happened && me->GetEntry() == 111259 && !player->GetQuestObjectiveData(38687, me->GetEntry()))
				{
					player->CreateConversation(3142);
					conversation1Happened = true;
				}
				if (!conversation2Happened && me->GetEntry() == 111260 && !player->GetQuestObjectiveData(38687, me->GetEntry()))
				{
					player->CreateConversation(3140);
					conversation2Happened = true;
				}

				break;
			case HORDE:

				if (!conversation1Happened && me->GetEntry() == 111259 && !player->GetQuestObjectiveData(41763, me->GetEntry()))
				{
					player->CreateConversation(3142);
					conversation1Happened = true;
				}
				if (!conversation2Happened && me->GetEntry() == 111260 && !player->GetQuestObjectiveData(41763, me->GetEntry()))
				{
					player->CreateConversation(3140);
					conversation2Happened = true;
				}

				break;
			}
			
			ScriptedAI::MoveInLineOfSight(who);
		}

		void OnSpellClick(Unit* clicker) override
		{
			if (!clicker->IsPlayer())
				return;

			Player* player = clicker->ToPlayer();

			switch (me->GetEntry())
			{
			case 111258:
				me->SetStandState(UNIT_STAND_STATE_STAND);
				player->CreateConversation(3139);
				me->HandleEmoteCommand(EMOTE_ONESHOT_ROAR);
				break;
			case 111259:
				player->CreateConversation(3143);
				player->SummonCreature(97554, me->GetPosition(), player->GetGUID(), TEMPSUMMON_TIMED_DESPAWN, 60000);
				break;
			case 111260:
				player->CreateConversation(3141);
				me->Kill(me);
				break;
			}

			player->KilledMonsterCredit(me->GetEntry());
			me->DespawnOrUnsummon(1000, Seconds(60));
		}

	private:
		bool conversation1Happened, conversation2Happened;
	};
};

class npc_tyrande_whisperwind_104799 : public CreatureScript
{
public:
	npc_tyrande_whisperwind_104799() : CreatureScript("npc_tyrande_whisperwind_104799") { }

	struct npc_tyrande_whisperwind_104799_AI : public npc_escortAI
	{
		npc_tyrande_whisperwind_104799_AI(Creature* creature) : npc_escortAI(creature) { }

		void MoveInLineOfSight(Unit* who) override
		{
			Player* player = who->ToPlayer();
			if (!player)
				return;

			switch (player->GetTeam())
			{
			case ALLIANCE:

				if (player->GetQuestStatus(38687) != QUEST_STATUS_INCOMPLETE)
					return;

				if (!player->GetQuestObjectiveData(38687, 111258)
					|| !player->GetQuestObjectiveData(38687, 111259)
					|| !player->GetQuestObjectiveData(38687, 111260))
					return;

				FinalEvent_38687(player);

				Talk(0);

				break;
			case HORDE:

				if (player->GetQuestStatus(41763) != QUEST_STATUS_INCOMPLETE)
					return;

				if (!player->GetQuestObjectiveData(41763, 111258)
					|| !player->GetQuestObjectiveData(41763, 111259)
					|| !player->GetQuestObjectiveData(41763, 111260))
					return;

				FinalEvent_38687(player);

				Talk(0);

				break;
			}

			ScriptedAI::MoveInLineOfSight(who);
		}

		void FinalEvent_38687(Player* player)
		{
			player->CastSpell(player, 208444, true); // Tyrande's Choice Scene
			player->KilledMonsterCredit(104764);
			player->KilledMonsterCredit(111238);
			player->KilledMonsterCredit(111239);
		}

		void IsSummonedBy(Unit* summoner) override
		{
			Player* player = summoner->ToPlayer();
			if (!player)
				return;

			Creature* ashalah = me->FindNearestCreature(102937, 50.f);
			if (!ashalah)
				return;

			player->KilledMonsterCredit(104799);
			Talk(1, player->GetGUID()); // Come with me. Ysera won't stop until this whole realm is plunged into the Nightmare.

			me->AddDelayedEvent(4000, [this, ashalah]
				{
					me->EnterVehicle(ashalah, 0);
				});

			me->AddDelayedEvent(5000, [this, player, ashalah]
				{
					player->EnterVehicle(ashalah, 1);
				});

			me->AddDelayedEvent(6000, [this, player, ashalah]
				{
					ashalah->GetMotionMaster()->MovePath(102937, false); // start waypoint
				});
		}

		void WaypointReached(uint32 waypointId) override {}
	};

	bool OnGossipHello(Player* player, Creature* creature) override
	{
		if (creature->isQuestGiver())
			player->PrepareQuestMenu(creature->GetGUID());

		if (player->GetQuestStatus(38743) == QUEST_STATUS_INCOMPLETE)
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "I am ready.", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);

		player->PlayerTalkClass->SendGossipMenu(28755, creature->GetGUID());
		return true;
	}

	bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action) override
	{
		player->PlayerTalkClass->ClearMenus();

		if (action == GOSSIP_ACTION_INFO_DEF + 1)
		{
			if (Creature* ashalah = creature->FindNearestCreature(102937, 50.f))
			{
				player->SummonCreature(102937, ashalah->GetPosition(), player->GetGUID(), TempSummonType::TEMPSUMMON_MANUAL_DESPAWN, 3600000);
				ashalah->DespawnOrUnsummon(0U, Seconds(60));
			}

			player->SummonCreature(104799, creature->GetPosition(), player->GetGUID(), TempSummonType::TEMPSUMMON_MANUAL_DESPAWN, 3600000);
			creature->DespawnOrUnsummon(0U, Seconds(60));

			player->CLOSE_GOSSIP_MENU();
		}

		return true;
	}

	CreatureAI* GetAI(Creature* creature) const
	{
		return new npc_tyrande_whisperwind_104799_AI(creature);
	}
};

struct npc_ashalah_102937 : public VehicleAI
{
	npc_ashalah_102937(Creature* creature) : VehicleAI(creature) {}

	void MovementInform(uint32 type, uint32 id) override
	{
		if (type != WAYPOINT_MOTION_TYPE)
			return;

		Creature* tyrande = me->GetVehicleKit()->GetPassenger(0)->ToCreature();
		if (!tyrande || !tyrande->IsCreature())
			return;

		Player* player = me->GetVehicleKit()->GetPassenger(1)->ToPlayer();
		if (!player)
			return;

		switch (id)
		{
		case 1:
			tyrande->AI()->Talk(2, player->GetGUID()); // Xavius is using Malfurion to bait me, to distract me from what must be done. We are the only ones who can stop Ysera.
			break;
		case 5:
			tyrande->AI()->Talk(3, player->GetGUID()); // Ah, Malfurion, my beloved! For a hundred hundred years he slept beneath Moonglade.
			break;
		case 10:
			tyrande->AI()->Talk(4, player->GetGUID()); // Whenever I was plagued with doubt, I would descend into his barrow. I watched over him as he slept.
			break;
		case 15:
			tyrande->AI()->Talk(5, player->GetGUID()); // Even in slumber, his presence calmed me. I left my fears below the earth and emerged, ready to lead my people.
			break;
		case 20:
      me->GetVehicle()->RemoveAllPassengers();
			tyrande->DespawnOrUnsummon(3000);
			me->DespawnOrUnsummon(5000);
			player->TeleportTo(1478, player->GetPositionX(), player->GetPositionY(), player->GetPositionZ(), player->GetOrientation(), TELE_TO_SEAMLESS);
			break;
		case 21:
			tyrande->AI()->Talk(6, player->GetGUID()); // When Malfurion returned to my side, we worked as one. As if he had never been away. Have you ever loved as I have?
			me->GetMotionMaster()->MovePoint(22, 3064.61f, 6539.59f, 202.598f);
			break;
		case 22:
			me->GetMotionMaster()->MovePoint(23, 3060.26f, 6578.65f, 197.813f);
			break;
		case 23:
			me->GetMotionMaster()->MovePoint(24, 3042.72f, 6584.57f, 200.486f);
			break;
		case 24:
			me->GetMotionMaster()->MovePoint(25, 3001.14f, 6578.15f, 207.451f);
			break;
		case 25:
			me->GetMotionMaster()->MovePoint(26, 2949.99f, 6555.51f, 207.78f);
			break;
		case 26:
			me->GetMotionMaster()->MovePoint(27, 2931.99f, 6584.24f, 215.192f);
			break;
		case 27:
			tyrande->AI()->Talk(7, player->GetGUID()); // Now Xavius has me by the throat. I must abandon my beloved, and contend with the most beautiful creature I have ever known.
			me->GetMotionMaster()->MovePoint(28, 2929.16f, 6593.54f, 215.178f);
			break;
		case 28:
			tyrande->DespawnOrUnsummon();
			me->GetVehicle()->RemoveAllPassengers();
			me->DespawnOrUnsummon();
			break;
		}
	}
};

struct npc_bigtree_q38235_93602_93640_93644 : public ScriptedAI
{
	npc_bigtree_q38235_93602_93640_93644(Creature* creature) : ScriptedAI(creature) { }

	void SpellHit(Unit* caster, SpellInfo const* spell) override
	{
		Player* player = caster->ToPlayer();
		if (!caster || !player)
			return;

		if (spell->Id == 182117) // Rousing - added in npc_spellclick_spells for these creatures
		{
			switch (me->GetEntry())
			{
			case 93602:
				player->KilledMonsterCredit(93602);
				me->DespawnOrUnsummon(5000, Seconds(60));
				Talk(0);
				break;
			case 93640:
				player->KilledMonsterCredit(93640);
				me->DespawnOrUnsummon(5000, Seconds(60));
				Talk(0);
				break;
			case 93644:
				player->KilledMonsterCredit(93644);
				me->DespawnOrUnsummon(5000, Seconds(60));
				Talk(0);
				break;
			}

			if (player->GetQuestObjectiveData(38235, 277559) && 
				player->GetQuestObjectiveData(38235, 278645) &&
				player->GetQuestObjectiveData(38235, 278646))
				player->CastSpell(player, 197654, true);
		}
	}
};

void AddSC_zone_valsharah() 
{
	RegisterCreatureAI(npc_Wisp_110572);
	RegisterCreatureAI(npc_Wisp_112252);
	RegisterSpellScript(spell_grow_tree_222728);
	new npc_tyrande_whisperwind_104728();
	new npc_image_of_xavius_111228();
	new npc_malfurion_stormrage_111258_111259_111260();
	new npc_tyrande_whisperwind_104799();
	RegisterCreatureAI(npc_ashalah_102937);
}