/*
Made by Fluxurion for Heron - 2022
 */

#include "ScriptMgr.h"

class instance_tears_of_elune : public InstanceMapScript
{
public:
    instance_tears_of_elune() : InstanceMapScript("instance_tears_of_elune", 1478) { }

    InstanceScript* GetInstanceScript(InstanceMap* map) const override
    {
        return new instance_tears_of_elune_InstanceMapScript(map);
    }

    struct instance_tears_of_elune_InstanceMapScript : public InstanceScript
    {
        instance_tears_of_elune_InstanceMapScript(Map* map) : InstanceScript(map)
        { }

        void OnPlayerEnter(Player* player) override
        {
            if (Creature* ashalah = player->SummonCreature(102937, player->GetPosition(), player->GetGUID(), TempSummonType::TEMPSUMMON_MANUAL_DESPAWN, 3600000))
            {
                if (Creature* tyrande = player->SummonCreature(104799, player->GetPosition(), player->GetGUID(), TempSummonType::TEMPSUMMON_MANUAL_DESPAWN, 3600000))
                {                    
                    tyrande->EnterVehicle(ashalah, 0);
                    player->EnterVehicle(ashalah, 1);
                    ashalah->GetMotionMaster()->MovePoint(21, 3086.65f, 6518.47f, 205.529f);
                }
            }
        }

    };
};

void AddSC_instance_tears_of_elune()
{
    new instance_tears_of_elune();
}
