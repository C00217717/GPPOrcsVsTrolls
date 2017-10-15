#include "Characters.h"

//Setup all the Variables for the starting Spell
void Troll::setTrollSpellStats(string * t_currentSpellName, TrollSpell t_currentSpell, int *t_manaCost, int *t_damage)
{
	switch (t_currentSpell)
	{
	case EARTHSHAKE:
		*t_currentSpellName = "EARTHSHAKE";
		*t_manaCost = 1;
		*t_damage = 4;
		break;
	case MAGICDART:	
		*t_currentSpellName = "MAGICDART";
		*t_manaCost = 5;
		*t_damage = 7;
		break;
	case WATERSTRIKE:
		*t_currentSpellName = "WATERSTRIKE";
		*t_manaCost = 3;
		*t_damage = 12;
		break;
	case POWERWAVE:
		*t_currentSpellName = "POWERWAVE";
		*t_manaCost = 10;
		*t_damage = 5;
		break;
	case DESTRUCTIVEFORCE:
		*t_currentSpellName = "DESTRUCTIVEFORCE";
		*t_damage = 7;
		*t_manaCost = 6;
		break;
	default:
		break;
	}
}

//Setup all the Variables for the starting Melee
void Troll::setTrollMeleeName(string * t_currentMeleeName, TrollMelee t_currentMelee, int *t_damage)
{
	switch (t_currentMelee)
	{
	case PICKAXE:
		*t_currentMeleeName = "Pick Axe";
		*t_damage = 4;
		break;
	case SPEAR:
		*t_currentMeleeName = "Spear";
		*t_damage = 6;
		break;
	case CUTLASS:
		*t_currentMeleeName = "Cutlass";
		*t_damage = 4;
		break;
	case KATANA:
		*t_currentMeleeName = "Katana";
		*t_damage = 8;
		break;
	case RAKE:
		*t_currentMeleeName = "Rake";
		*t_damage = 2;
		break;
	case KICK:
		*t_currentMeleeName = "Kick";
		*t_damage = 2;
		break;
	case ELBOW:
		*t_currentMeleeName = "Elbow";
		*t_damage = 1;
		break;
	default:
		break;
	}
}

//Setup all the Variables for the starting Shield
void Troll::setTrollShieldName(string * t_currentShield, TrollShield t_trollShield, int *t_shield)
{

	switch (t_trollShield)
	{
	case BRONZE:
		*t_currentShield = "Bronze";
		*t_shield = 10;
		break;
	case SILVER:
		*t_currentShield = "Silver";
		*t_shield = 20;
		break;
	case GOLD:
		*t_currentShield = "Gold";
		*t_shield = 30;
		break;
	default:
		break;
	}
}

//Setup all the Variables for the starting Spell for the Orc
void Orc::setOrcSpellStats(string * t_currentSpellName, OrcSpell t_currentSpell, int *t_manaCost, int *t_damage)
{

	switch (t_currentSpell)
	{
	case ACIDARROW:
		*t_currentSpellName = "Acid Arrow";
		*t_manaCost = 5;
		*t_damage = 6;

		break;
	case BURNINGHANDS:
		*t_currentSpellName = "Burning Hands";
		*t_damage = 4;
		*t_manaCost = 8;
		break;
	case FIRESTRIKE:
		*t_currentSpellName = "Fire Strike";
		*t_manaCost = 10;
		*t_damage = 8;
		break;
	case FIREBOLT:
		*t_currentSpellName = "Fire Bolt";
		*t_manaCost = 5;
		*t_damage = 5;
		break;
	case FIREWAVE:
		*t_currentSpellName = "Fire Wave";
		*t_manaCost = 8;
		*t_damage = 10;
		break;
	default:
		break;
	}
}

//Setup all the Variables for the starting Melee for the Orc
void Orc::setOrcMeleeStats(string * t_currentMeleeName, OrcMelee t_currentMelee, int *t_damage)
{
	switch (t_currentMelee)
	{
	case AXE:
		*t_currentMeleeName = "Axe";
		*t_damage = 7;
		break;
	case PUNCH:
		*t_currentMeleeName = "Punch";
		*t_damage = 2;
		break;
	case HAMMER:
		*t_currentMeleeName = "Hammer";
		*t_damage = 7;
		break;
	case DAGGER:
		*t_currentMeleeName = "Dagger";
		*t_damage = 2;
		break;
	case CLUB:
		*t_currentMeleeName = "Club";
		*t_damage = 4;
		break;
	case BITE:
		*t_currentMeleeName = "Bite";
		*t_damage = 3;
		break;
	case KNEE:
		*t_currentMeleeName = "Knee";
		*t_damage = 1;
		break;
	default:
		break;
	}
}

//Setup all the Variables for the starting shield for the Orc
void Orc::setOrcShieldName(string * t_currentShield, OrcShield t_orcShield, int *t_shield)
{
	switch (t_orcShield)
	{
	case LIGHT:
		*t_currentShield = "Light";
		*t_shield = 15;
		break;
	case MEDIUM:
		*t_shield = 30;
		*t_currentShield = "Medium";
		break;
	case STRONG:
		*t_shield = 45;
		*t_currentShield = "Strong";
		break;
	default:
		break;
	}
}
