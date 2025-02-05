
#ifndef _sCharService
#define _sCharService

class TC_GAME_API CharacterService
{
	CharacterService() = default;
	~CharacterService() = default;
	
public:
    void SetRename(Player* player);
    void ChangeFaction(Player* player);
    void ChangeRace(Player* player);
    void Customize(Player* player);
    void Boost(Player* player);
    void RestoreDeletedCharacter(WorldSession* session);
	void UnlockMOPChallengeModeTransmog(Player* target);
	void Gold20k(Player* player);
	void Gold50k(Player* player);
	void Gold100k(Player* player);
	void Gold250k(Player* player);
	void Gold500k(Player* player);
	void Gold1000k(Player* player);
	void ProfPriAlchemy(Player* player);
	void ProfPriSastre(Player* player);
	void ProfPriJoye(Player* player);
	void ProfPriHerre(Player* player);
	void ProfPriPele(Player* player);
	void ProfPriInge(Player* player);
	void ProfPriInsc(Player* player);
	void ProfPriEncha(Player* player);
	void ProfPriDesu(Player* player);
	void ProfPriMing(Player* player);
	void ProfPriHerb(Player* player, WorldSession* session);
	void ProfSecCoci(Player* player);
	void ProfSecPrau(Player* player);
	void ProfSecArque(Player* player);
	void ProfSecFish(Player* player);
	void Unbinall(Player* player);
	void RacesAlliedNightborne(Player* player);
	void RacesAlliedHighmountainTauren(Player* player);
	void RacesAlliedVoidElf(Player* player);
	void RacesAlliedLighForgedDraenei(Player* player);
	void RepClassic(Player* player);
	void RepBurnig(Player* player);
	void RepTLK(Player* player);
	void RepCata(Player* player);
	void RepPanda(Player* player);
	void RepDraenor(Player* player);
	void RepLegion(Player* player);
	void AppareanceArtifact(Player* player);

	static CharacterService* instance();
};

#define sCharacterService CharacterService::instance()

#endif