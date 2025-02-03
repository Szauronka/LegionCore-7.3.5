/* Fluxurion */

#include "GameObject.h"
#include "GameObjectAI.h"
#include "ObjectMgr.h"
#include "Spell.h"
#include "SpellMgr.h"
#include "SpellScript.h"
#include "ScriptMgr.h"

class spell_warboard_alliance_261654 : public SpellScriptLoader
{
public:
    spell_warboard_alliance_261654() : SpellScriptLoader("spell_warboard_alliance_261654") {}

    class spell_warboard_alliance_261654_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_warboard_alliance_261654_SpellScript);

        void HandleDummy(SpellEffIndex /*effIndex*/)
        {
            WorldObject* caster = GetCaster();

            if (!caster->IsPlayer())
                return;

            caster->ToPlayer()->SendDisplayPlayerChoice(caster->GetGUID(), 352);
        }

        void Register() override
        {
            OnEffectHit += SpellEffectFn(spell_warboard_alliance_261654_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_warboard_alliance_261654_SpellScript();
    }
};

class spell_warboard_horde_261655 : public SpellScriptLoader
{
public:
    spell_warboard_horde_261655() : SpellScriptLoader("spell_warboard_horde_261655") {}

    class spell_warboard_horde_261655_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_warboard_horde_261655_SpellScript);

        void HandleDummy(SpellEffIndex /*effIndex*/)
        {
            WorldObject* caster = GetCaster();

            if (!caster->IsPlayer())
                return;

            caster->ToPlayer()->SendDisplayPlayerChoice(caster->GetGUID(), 342);
        }

        void Register() override
        {
            OnEffectHit += SpellEffectFn(spell_warboard_horde_261655_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_warboard_horde_261655_SpellScript();
    }
};

void AddSC_Warboard_Scripts()
{
    new spell_warboard_alliance_261654();
    new spell_warboard_horde_261655();
}
