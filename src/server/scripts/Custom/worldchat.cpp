/*
 *###############################################################################
 *#                                                                             #
 *# Copyright (C) 2022 Project Nighthold <https://github.com/ProjectNighthold>  #
 *#                                                                             #
 *# This file is free software; as a special exception the author gives         #
 *# unlimited permission to copy and/or distribute it, with or without          #
 *# modifications, as long as this notice is preserved.                         #
 *#                                                                             #
 *# This program is distributed in the hope that it will be useful, but         #
 *# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the      #
 *# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.    #
 *#                                                                             #
 *# Read the THANKS file on the source root directory for more info.            #
 *#                                                                             #
 *###############################################################################
 */

#include "ScriptMgr.h"
#include "Chat.h"
#include "Player.h"
#include "Config.h"
#include "WorldSession.h"

#include "World.h"

#define MSG_COLOR_BLUEVIOLET "|cFF8A2BE2"
const char* CLASS_ICON;
const char* SPEC_ICON;

#define FACTION_SPECIFIC 0

std::string GetNameLink(Player* player)
{
    std::string name = player->GetName();
    std::string color;
    switch (player->getClass())
    {
    case CLASS_DEATH_KNIGHT:
        if (player->GetUInt32Value(PLAYER_FIELD_CURRENT_SPEC_ID) == SPEC_DK_BLOOD)
        {
            color = "|cffC41F3B";
            SPEC_ICON = "|TInterface\\icons\\spell_deathknight_bloodpresence:15|t|r";
            CLASS_ICON = "|TInterface\\icons\\Spell_Deathknight_ClassIcon:15|t|r";
            break;

        }
        if (player->GetUInt32Value(PLAYER_FIELD_CURRENT_SPEC_ID) == SPEC_DK_FROST)
        {
            color = "|cffC41F3B";
            SPEC_ICON = "|TInterface\\icons\\spell_deathknight_frostpresence:15|t|r";
            CLASS_ICON = "|TInterface\\icons\\Spell_Deathknight_ClassIcon:15|t|r";
            break;
        }
        if (player->GetUInt32Value(PLAYER_FIELD_CURRENT_SPEC_ID) == SPEC_DK_UNHOLY)
        {
            color = "|cffC41F3B";
            SPEC_ICON = "|TInterface\\icons\\spell_deathknight_unholypresence:15|t|r";
            CLASS_ICON = "|TInterface\\icons\\Spell_Deathknight_ClassIcon:15|t|r";
            break;
        }
        break;
    case CLASS_DEMON_HUNTER:
        if (player->GetUInt32Value(PLAYER_FIELD_CURRENT_SPEC_ID) == SPEC_DEMON_HUNER_HAVOC)
        {
            color = "|cffC41F3B";
            SPEC_ICON = "|TInterface\\icons\\spell_deathknight_bloodpresence:15|t|r";
            CLASS_ICON = "|TInterface\\icons\\Spell_Deathknight_ClassIcon:15|t|r";
            break;

        }
        if (player->GetUInt32Value(PLAYER_FIELD_CURRENT_SPEC_ID) == SPEC_DEMON_HUNER_VENGEANCE)
        {
            color = "|cffC41F3B";
            SPEC_ICON = "|TInterface\\icons\\spell_deathknight_unholypresence:15|t|r";
            CLASS_ICON = "|TInterface\\icons\\Spell_Deathknight_ClassIcon:15|t|r";
            break;
        }
        break;
    case CLASS_DRUID:
        if (player->GetUInt32Value(PLAYER_FIELD_CURRENT_SPEC_ID) == SPEC_DRUID_BALANCE)
        {
            color = "|cffFF7D0A";
            SPEC_ICON = "|TInterface\\icons\\spell_nature_forceofnature:15|t|r";
            CLASS_ICON = "|TInterface\\icons\\Ability_Druid_Maul:15|t|r";
            break;

        }
        if (player->GetUInt32Value(PLAYER_FIELD_CURRENT_SPEC_ID) == SPEC_DRUID_CAT)
        {
            color = "|cffFF7D0A";
            SPEC_ICON = "|TInterface\\icons\\ability_druid_catform:15|t|r";
            CLASS_ICON = "|TInterface\\icons\\Ability_Druid_Maul:15|t|r";
            break;
        }
        if (player->GetUInt32Value(PLAYER_FIELD_CURRENT_SPEC_ID) == SPEC_DRUID_BEAR)
        {
            color = "|cffFF7D0A";
            SPEC_ICON = "|TInterface\\icons\\ability_racial_bearform:15|t|r";
            CLASS_ICON = "|TInterface\\icons\\Ability_Druid_Maul:15|t|r";
            break;
        }
        if (player->GetUInt32Value(PLAYER_FIELD_CURRENT_SPEC_ID) == SPEC_DRUID_RESTORATION)
        {
            color = "|cffFF7D0A";
            SPEC_ICON = "|TInterface\\icons\\spell_nature_healingtouch:15|t|r";
            CLASS_ICON = "|TInterface\\icons\\Ability_Druid_Maul:15|t|r";
            break;
        }
        break;
    case CLASS_HUNTER:
        if (player->GetUInt32Value(PLAYER_FIELD_CURRENT_SPEC_ID) == SPEC_HUNTER_BEASTMASTER)
        {
            color = "|cffABD473";
            SPEC_ICON = "|TInterface\\icons\\ability_hunter_bestialdiscipline:15|t|r";
            CLASS_ICON = "|TInterface\\icons\\INV_Weapon_Bow_07:15|t|r";
            break;
        }
        if (player->GetUInt32Value(PLAYER_FIELD_CURRENT_SPEC_ID) == SPEC_HUNTER_MARKSMAN)
        {
            color = "|cffABD473";
            SPEC_ICON = "|TInterface\\icons\\ability_hunter_focusedaim:15|t|r";
            CLASS_ICON = "|TInterface\\icons\\INV_Weapon_Bow_07:15|t|r";
            break;
        }
        if (player->GetUInt32Value(PLAYER_FIELD_CURRENT_SPEC_ID) == SPEC_HUNTER_SURVIVAL)
        {
            color = "|cffABD473";
            SPEC_ICON = "|TInterface\\icons\\ability_hunter_camouflage:15|t|r";
            CLASS_ICON = "|TInterface\\icons\\INV_Weapon_Bow_07:15|t|r";
            break;
        }
        break;
    case CLASS_MAGE:
        if (player->GetUInt32Value(PLAYER_FIELD_CURRENT_SPEC_ID) == SPEC_MAGE_ARCANE)
        {
            color = "|cff69CCF0";
            SPEC_ICON = "|TInterface\\icons\\spell_holy_magicalsentry:15|t|r";
            CLASS_ICON = "|TInterface\\icons\\INV_Staff_13:15|t|r";
            break;
        }
        if (player->GetUInt32Value(PLAYER_FIELD_CURRENT_SPEC_ID) == SPEC_MAGE_FIRE)
        {
            color = "|cff69CCF0";
            SPEC_ICON = "|TInterface\\icons\\spell_fire_firebolt:15|t|r";
            CLASS_ICON = "|TInterface\\icons\\INV_Staff_13:15|t|r";
            break;
        }
        if (player->GetUInt32Value(PLAYER_FIELD_CURRENT_SPEC_ID) == SPEC_MAGE_FROST)
        {
            color = "|cff69CCF0";
            SPEC_ICON = "|TInterface\\icons\\spell_frost_frostbolt02:15|t|r";
            CLASS_ICON = "|TInterface\\icons\\INV_Staff_13:15|t|r";
            break;
        }
        break;
    case CLASS_MONK:
        if (player->GetUInt32Value(PLAYER_FIELD_CURRENT_SPEC_ID) == SPEC_MONK_BREWMASTER)
        {
            color = "|cffABD473";
            SPEC_ICON = "|TInterface\\icons\\spell_monk_brewmaster_spec:15|t|r";
            CLASS_ICON = "|TInterface\\icons\\classicon_monk:15|t|r";
            break;
        }
        if (player->GetUInt32Value(PLAYER_FIELD_CURRENT_SPEC_ID) == SPEC_MONK_WINDWALKER)
        {
            color = "|cffABD473";
            SPEC_ICON = "|TInterface\\icons\\spell_monk_windwalker_spec:15|t|r";
            CLASS_ICON = "|TInterface\\icons\\classicon_monk:15|t|r";
            break;
        }
        if (player->GetUInt32Value(PLAYER_FIELD_CURRENT_SPEC_ID) == SPEC_MONK_MISTWEAVER)
        {
            color = "|cffABD473";
            SPEC_ICON = "|TInterface\\icons\\spell_monk_mistweaver_spec:15|t|r";
            CLASS_ICON = "|TInterface\\icons\\classicon_monk:15|t|r";
            break;
        }
        break;
    case CLASS_PALADIN:
        if (player->GetUInt32Value(PLAYER_FIELD_CURRENT_SPEC_ID) == SPEC_PALADIN_HOLY)
        {
            color = "|cffF58CBA";
            SPEC_ICON = "|TInterface\\icons\\spell_holy_holybolt:15|t|r";
            CLASS_ICON = "|TInterface\\icons\\INV_Hammer_01:15|t|r";
            break;
        }
        if (player->GetUInt32Value(PLAYER_FIELD_CURRENT_SPEC_ID) == SPEC_PALADIN_PROTECTION)
        {
            color = "|cffF58CBA";
            SPEC_ICON = "|TInterface\\icons\\ability_paladin_shieldofthetemplar:15|t|r";
            CLASS_ICON = "|TInterface\\icons\\INV_Hammer_01:15|t|r";
            break;
        }
        if (player->GetUInt32Value(PLAYER_FIELD_CURRENT_SPEC_ID) == SPEC_PALADIN_RETRIBUTION)
        {
            color = "|cffF58CBA";
            SPEC_ICON = "|TInterface\\icons\\spell_holy_auraoflight:15|t|r";
            CLASS_ICON = "|TInterface\\icons\\INV_Hammer_01:15|t|r";
            break;
        }
    case CLASS_PRIEST:
        if (player->GetUInt32Value(PLAYER_FIELD_CURRENT_SPEC_ID) == SPEC_PRIEST_DISCIPLINE)
        {
            color = "|cffFFFFFF";
            SPEC_ICON = "|TInterface\\icons\\spell_holy_powerwordshield:15|t|r";
            CLASS_ICON = "|TInterface\\icons\\INV_Staff_30:15|t|r";
            break;
        }
        if (player->GetUInt32Value(PLAYER_FIELD_CURRENT_SPEC_ID) == SPEC_PRIEST_HOLY)
        {
            color = "|cffFFFFFF";
            SPEC_ICON = "|TInterface\\icons\\spell_holy_guardianspirit:15|t|r";
            CLASS_ICON = "|TInterface\\icons\\INV_Staff_30:15|t|r";
            break;
        }
        if (player->GetUInt32Value(PLAYER_FIELD_CURRENT_SPEC_ID) == SPEC_PRIEST_SHADOW)
        {
            color = "|cffFFFFFF";
            SPEC_ICON = "|TInterface\\icons\\spell_shadow_shadowwordpain:15|t|r";
            CLASS_ICON = "|TInterface\\icons\\INV_Staff_30:15|t|r";
            break;
        }
        break;
    case CLASS_ROGUE:
        if (player->GetUInt32Value(PLAYER_FIELD_CURRENT_SPEC_ID) == SPEC_ROGUE_ASSASSINATION)
        {
            color = "|cffFFF569";
            SPEC_ICON = "|TInterface\\icons\\ability_rogue_eviscerate:15|t|r";
            CLASS_ICON = "|TInterface\\icons\\INV_ThrowingKnife_04:15|t|r";
            break;
        }
        if (player->GetUInt32Value(PLAYER_FIELD_CURRENT_SPEC_ID) == SPEC_ROGUE_COMBAT)
        {
            color = "|cffFFF569";
            SPEC_ICON = "|TInterface\\icons\\ability_backstab:15|t|r";
            CLASS_ICON = "|TInterface\\icons\\INV_ThrowingKnife_04:15|t|r";
            break;
        }
        if (player->GetUInt32Value(PLAYER_FIELD_CURRENT_SPEC_ID) == SPEC_ROGUE_SUBTLETY)
        {
            color = "|cffFFF569";
            SPEC_ICON = "|TInterface\\icons\\ability_stealth:15|t|r";
            CLASS_ICON = "|TInterface\\icons\\INV_ThrowingKnife_04:15|t|r";
            break;
        }
    case CLASS_SHAMAN:
        if (player->GetUInt32Value(PLAYER_FIELD_CURRENT_SPEC_ID) == SPEC_SHAMAN_ELEMENTAL)
        {
            color = "|cff0070DE";
            SPEC_ICON = "|TInterface\\icons\\spell_nature_lightning:15|t|r";
            CLASS_ICON = "|TInterface\\icons\\Spell_Nature_BloodLust:15|t|r";
            break;
        }
        if (player->GetUInt32Value(PLAYER_FIELD_CURRENT_SPEC_ID) == SPEC_SHAMAN_ENHANCEMENT)
        {
            color = "|cff0070DE";
            SPEC_ICON = "|TInterface\\icons\\spell_shaman_improvedstormstrike:15|t|r";
            CLASS_ICON = "|TInterface\\icons\\Spell_Nature_BloodLust:15|t|r";
            break;
        }
        if (player->GetUInt32Value(PLAYER_FIELD_CURRENT_SPEC_ID) == SPEC_SHAMAN_RESTORATION)
        {
            color = "|cff0070DE";
            SPEC_ICON = "|TInterface\\icons\\spell_nature_healingwavelesser:15|t|r";
            CLASS_ICON = "|TInterface\\icons\\Spell_Nature_BloodLust:15|t|r";
            break;
        }
        break;
    case CLASS_WARLOCK:
        if (player->GetUInt32Value(PLAYER_FIELD_CURRENT_SPEC_ID) == SPEC_WARLOCK_AFFLICTION)
        {
            color = "|cff9482C9";
            SPEC_ICON = "|TInterface\\icons\\spell_shadow_deathcoil:15|t|r";
            CLASS_ICON = "|TInterface\\icons\\Spell_Nature_FaerieFire:15|t|r";
            break;
        }
        if (player->GetUInt32Value(PLAYER_FIELD_CURRENT_SPEC_ID) == SPEC_WARLOCK_DEMONOLOGY)
        {
            color = "|cff9482C9";
            SPEC_ICON = "|TInterface\\icons\\spell_shadow_metamorphosis:15|t|r";
            CLASS_ICON = "|TInterface\\icons\\Spell_Nature_FaerieFire:15|t|r";
            break;
        }
        if (player->GetUInt32Value(PLAYER_FIELD_CURRENT_SPEC_ID) == SPEC_WARLOCK_DESTRUCTION)
        {
            color = "|cff9482C9";
            SPEC_ICON = "|TInterface\\icons\\spell_shadow_rainoffire:15|t|r";
            CLASS_ICON = "|TInterface\\icons\\Spell_Nature_FaerieFire:15|t|r";
            break;
        }
        break;
    case CLASS_WARRIOR:
        if (player->GetUInt32Value(PLAYER_FIELD_CURRENT_SPEC_ID) == SPEC_WARRIOR_ARMS)
        {
            color = "|cffC79C6E";
            SPEC_ICON = "|TInterface\\icons\\ability_warrior_savageblow:15|t|r";
            CLASS_ICON = "|TInterface\\icons\\INV_Sword_27.png:15|t|r";
            break;
        }
        if (player->GetUInt32Value(PLAYER_FIELD_CURRENT_SPEC_ID) == SPEC_WARRIOR_FURY)
        {
            color = "|cffC79C6E";
            SPEC_ICON = "|TInterface\\icons\\ability_warrior_innerrage:15|t|r";
            CLASS_ICON = "|TInterface\\icons\\INV_Sword_27.png:15|t|r";
            break;
        }
        if (player->GetUInt32Value(PLAYER_FIELD_CURRENT_SPEC_ID) == SPEC_WARRIOR_PROTECTION)
        {
            color = "|cffC79C6E";
            SPEC_ICON = "|TInterface\\icons\\ability_warrior_defensivestance:15|t|r";
            CLASS_ICON = "|TInterface\\icons\\INV_Sword_27.png:15|t|r";
            break;
        }
        break;
    }
    return "|Hplayer:" + name + "|h" + SPEC_ICON + "|h" + CLASS_ICON + "|h|cffFFFFFF[" + color + name + "|cffFFFFFF]|h|r";
}

class cs_world_chat : public CommandScript
{
public:
    cs_world_chat() : CommandScript("cs_world_chat") { }

    std::vector<ChatCommand> GetCommands() const
    {
        static std::vector<ChatCommand> WorldChatCommandTable =
        {
            { "chat",           SEC_PLAYER,         false, &HandleWorldChatCommand,             ""}
        };
        return WorldChatCommandTable;
    }

    static bool HandleWorldChatCommand(ChatHandler* handler, const char* args)
    {
        if (!handler->GetSession()->GetPlayer()->CanSpeak())
            return false;
        std::string temp = args;

        if (!args || temp.find_first_not_of(' ') == std::string::npos)
            return false;

        std::string msg = "";
        Player* player = handler->GetSession()->GetPlayer();

        switch (player->GetSession()->GetSecurity())
        {
            // Player
        case SEC_PLAYER:
            if (player->GetTeam() == ALLIANCE)
            {
                msg += "|cffABD473[World] ";
                msg += "|cff0000ff|TInterface\\pvpframe\\pvp-currency-alliance:17|t|r ";
                msg += GetNameLink(player);
                msg += " |cfffaeb00";
            }

            else
            {
                msg += "|cffABD473[World] ";
                msg += "|cffff0000|TInterface\\pvpframe\\pvp-currency-horde:17|t|r ";
                msg += GetNameLink(player);
                msg += " |cfffaeb00";
            }
            break;

		

            // Moderator
        case SEC_MODERATOR:
            if (player->GetTeam() == ALLIANCE)
            {
                msg += "|cffABD473[World] ";
                msg += "|TINTERFACE/CHATFRAME/UI-CHATICON-BLIZZ:15|t";
                msg += "|cff0000ff|TInterface\\pvpframe\\pvp-currency-alliance:17|t|r ";
                msg += GetNameLink(player);
                msg += " |cfffaeb00";
            }

            else
            {
                msg += "|cffABD473[World] ";
                msg += "|TINTERFACE/CHATFRAME/UI-CHATICON-BLIZZ:15|t";
                msg += "|cffff0000|TInterface\\pvpframe\\pvp-currency-horde:17|t|r ";
                msg += GetNameLink(player);
                msg += " |cfffaeb00";
            }
            break;

       

            // GM
        case SEC_GAMEMASTER:
            if (player->GetTeam() == ALLIANCE)
            {
                msg += "|cffABD473[World] ";
                msg += "|TINTERFACE/CHATFRAME/UI-CHATICON-BLIZZ:15|t";
                msg += "|cff0000ff|TInterface\\pvpframe\\pvp-currency-alliance:17|t|r ";
                msg += GetNameLink(player);
                msg += " |cfffaeb00";
            }

            else
            {
                msg += "|cffABD473[World] ";
                msg += "|TINTERFACE/CHATFRAME/UI-CHATICON-BLIZZ:15|t";
                msg += "|cffff0000|TInterface\\pvpframe\\pvp-currency-horde:17|t|r ";
                msg += GetNameLink(player);
                msg += " |cfffaeb00";
            }
            break;

            // Admin
        case SEC_ADMINISTRATOR:
            if (player->GetTeam() == ALLIANCE)
            {
                msg += "|cffABD473[World] ";
                msg += "|TINTERFACE/CHATFRAME/UI-CHATICON-BLIZZ:15|t";
                msg += "|cff0000ff|TInterface\\pvpframe\\pvp-currency-alliance:17|t|r ";
                msg += GetNameLink(player);
                msg += " |cfffaeb00";
            }

            else
            {
                msg += "|cffABD473[World] ";
                msg += "|TINTERFACE/CHATFRAME/UI-CHATICON-BLIZZ:15|t";
                msg += "|cffff0000|TInterface\\pvpframe\\pvp-currency-horde:17|t|r ";
                msg += GetNameLink(player);
                msg += " |cfffaeb00";
            }
            break;

			

            // Console
        case SEC_CONSOLE:
            if (player->GetTeam() == ALLIANCE)
            {
                msg += "|cffABD473[World] ";
                msg += "|TINTERFACE/CHATFRAME/UI-CHATICON-BLIZZ:15|t";
                msg += "|cff0000ff|TInterface\\pvpframe\\pvp-currency-alliance:17|t|r ";
                msg += GetNameLink(player);
                msg += " |cfffaeb00";
            }

            else
            {
                msg += "|cffABD473[World] ";
                msg += "|TINTERFACE/CHATFRAME/UI-CHATICON-BLIZZ:15|t";
                msg += "|cffff0000|TInterface\\pvpframe\\pvp-currency-horde:17|t|r ";
                msg += GetNameLink(player);
                msg += " |cfffaeb00";
            }
            break;
        }
        msg += args;
        if (FACTION_SPECIFIC)
        {
            SessionMap sessions = sWorld->GetAllSessions();
            for (SessionMap::iterator itr = sessions.begin(); itr != sessions.end(); ++itr)
                if (Player* plr = itr->second->GetPlayer())
                    if (plr->GetTeam() == player->GetTeam())
                        sWorld->SendServerMessage(SERVER_MSG_STRING, msg.c_str(), plr);
        }
        else
            sWorld->SendServerMessage(SERVER_MSG_STRING, msg.c_str(), 0);

        return true;
    }
};

void AddSC_cs_world_chat()
{
    new cs_world_chat();
}