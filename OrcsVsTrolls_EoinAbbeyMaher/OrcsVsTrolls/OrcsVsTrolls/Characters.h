#include <iostream>
#include <string>

using namespace std;

enum OrcSpell {
	ACIDARROW,
	BURNINGHANDS,
	FIRESTRIKE,
	FIREBOLT,
	FIREWAVE
};


enum OrcMelee
{
	AXE,
	PUNCH,
	HAMMER,
	DAGGER,
	CLUB,
	BITE,
	KNEE
};

enum OrcShield
{
	LIGHT,	MEDIUM,	STRONG,
};

enum TrollSpell
{
	EARTHSHAKE,
	MAGICDART,
	WATERSTRIKE,
	POWERWAVE,
	DESTRUCTIVEFORCE
};

enum TrollMelee
{
	PICKAXE,
	SPEAR,
	CUTLASS,
	KATANA,
	RAKE,
	KICK,
	ELBOW
};

enum TrollShield
{
	BRONZE,	SILVER,	GOLD
};

class Character {
public:
	void flip() { cout << "I know how to flip and I will flipping do it" << endl; }
	virtual void walk() { cout << "just in case they are too young to walk yet" << endl; }
	virtual void fly() = 0; //pure virtual function
	virtual void cast() = 0;
	virtual void attack() = 0;

	string m_currentSpellName;
	string m_currentMeleeName;
	string m_currentShieldName;

	int m_health{ 50 };
	int m_mana{ 100 };
	int m_damage{ 0 };
	int m_shield{ 20 };

	//spell Stats
	int m_manaCost{ 4 };
	int m_spellDamageMax{ 8 };
	int m_ShieldDefense{ 10 };
};

class Orc : public Character {
public:
	void barrelRoll() { cout << "rooooooolllllllllllinggggggg" << endl; }
	void walk() { cout << "Doopers have a really cool walk!" << endl; }
	void fly() { cout << "Dooper is flapping and flying" << endl; }

	void cast() { cout << "Orc Casts the " << m_currentSpellName << " Spell  For " << m_damage << " Damage" << endl; }
	void attack() { cout << "Orc attacks with " << m_currentMeleeName << " For " << m_damage << " Damage" << endl;}
	
	void setOrcSpellStats(string *t_currentSpellName, OrcSpell t_currentSpell, int *t_manaCost, int *t_damage);
	void setOrcMeleeStats(string *t_currentMeleeName, OrcMelee t_currentMelee, int *t_damage);
	void setOrcShieldName(string *t_currentShield, OrcShield t_orcShield, int *t_shield);


	OrcSpell m_currentSpell{ OrcSpell::ACIDARROW };
	OrcMelee m_currentMelee{ OrcMelee::AXE };
	OrcShield m_currentShield{ OrcShield::LIGHT };
};

class Troll : public Character {
public:
	void fly() { cout << "Average Dooper is flapping and flying" << endl; }

	void cast() { cout << "Troll casts the " << m_currentSpellName << " Spell For " << m_damage << " Damage" << endl; }
	void attack() { cout << "Troll Attacks with " << m_currentMeleeName<< " For " << m_damage << " Damage" << endl; }

	void setTrollSpellStats(string *t_currentSpellName, TrollSpell t_currentSpell, int *t_manaCost, int *t_damage);
	void setTrollMeleeName(string *t_currentMeleeName, TrollMelee t_currentMelee, int *t_damage);
	void setTrollShieldName(string *t_currentShield, TrollShield t_trollShield, int *t_shield);

	TrollSpell m_currentSpell{ TrollSpell::EARTHSHAKE };
	TrollMelee m_currentMelee{ TrollMelee::CUTLASS };
	TrollShield m_currentShield{ TrollShield::BRONZE };
};


