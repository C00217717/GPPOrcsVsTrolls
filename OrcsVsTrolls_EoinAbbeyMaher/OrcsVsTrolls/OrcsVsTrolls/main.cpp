/// <summary>
/// @Author	Eoin Abbey-Maher
/// @Brief Create a game where orcs and trolls fight using inheritance and Polymorphism
/// 
/// Known Issues: NO proper usage of different Shields, No selecting what spell after first choice,
///				  At times if you input outside of the choices(input 3 when only 1&2 are options) the program just continues on.
/// </summary>

#include "Characters.h"
#include <ctime>

using namespace std;

//Global Functinos for use in the main
void clearScreen();
void pickCharacter(Orc *t_orc, Troll *t_troll);
void exitGame();
void travel();
void fight(Character *t_array[]);
void takeDamage(Character *t_array[]);
void giveDamage(Character *t_array[]);
void randomMelee(Character *t_array[]);
void drawUI(Character *t_array[]);

//Global Variables
int charChoice{ 0 };
int attackType{ 0 };
bool isGameActive{ true };
bool isGameWon{ false };
int main(void)
{
	srand((unsigned)time(0));
	Orc orc;
	Troll troll;
	cout << "\t Welcome To The Troll Versus Orcs Game \n \n \n " << endl;
	
	Character *charArray[2] = { &orc,&troll };

	pickCharacter(&orc, &troll);
	clearScreen();
	travel();
	while (isGameActive)
	{
		drawUI(charArray);
		fight(charArray);

	}
	clearScreen();

	if (isGameWon)
	{
		cout << "Congratulations You Won the Game!!" << endl;
	}
	else
	{
		cout << "Hard luck you lost!" << endl;
	}

	system("Pause");
	
	exitGame();
}

/// <summary>
/// Function to be called to inflict damage onto the character
/// </summary>
/// <param name="t_array">Pointer array for the character addresses</param>
void takeDamage(Character *t_array[])
{
	if (charChoice == 0)
	{
		t_array[0]->m_health -= t_array[1]->m_damage;
	}

	else if (charChoice == 1)
	{
		t_array[1]->m_health -= t_array[0]->m_damage;
	}
}

/// <summary>
/// function to give damage to the enemy character
/// </summary>
/// <param name="t_array">Pointer array for the character addresses</param>
void giveDamage(Character * t_array[])
{
	if (charChoice == 0)
	{
		t_array[1]->m_health -= t_array[0]->m_damage;
	}

	else if (charChoice == 1)
	{
		t_array[0]->m_health -= t_array[0]->m_damage;
	}
}

/// <summary>
/// Randomise the Enemies Melee weapon so they change what they attack you with
/// </summary>
/// <param name="t_array">Pointer array for the character addresses</param>
void randomMelee(Character *t_array[])
{
	int weaponChoice{ 0 };
	
	weaponChoice = rand() % 7;

	if (charChoice == 0)
	{
		switch (weaponChoice)
		{
		case 0:
			t_array[1]->m_currentMeleeName = "Pick Axe";
			t_array[1]->m_spellDamageMax = 4;
			break;
		
		case 1:
			t_array[1]->m_currentMeleeName = "Spear";
			t_array[1]->m_spellDamageMax = 6;
			break;

		case 2:
			t_array[1]->m_currentMeleeName = "Cutlass";
			t_array[1]->m_spellDamageMax = 4;
			break;

		case 3:
			t_array[1]->m_currentMeleeName = "Katana";
			t_array[1]->m_spellDamageMax = 8;
			break;

		case 4:
			t_array[1]->m_currentMeleeName = "Rake";
			t_array[1]->m_spellDamageMax = 2;
			break;

		case 5:
			t_array[1]->m_currentMeleeName = "Kick";
			t_array[1]->m_spellDamageMax = 2;
			break;

		case 6:
			t_array[1]->m_currentMeleeName = "Elbow";
			t_array[1]->m_spellDamageMax = 1;
			break;

		default:
			break;
		}
	}

	else if (charChoice == 1)
	{
		switch (weaponChoice)
		{
		case 0:
			t_array[0]->m_currentMeleeName = "Axe";
			t_array[0]->m_spellDamageMax = 7;
			break;

		case 1:
			t_array[0]->m_currentMeleeName = "Punch";
			t_array[0]->m_spellDamageMax = 2;
			break;

		case 2:
			t_array[0]->m_currentMeleeName = "Hammer";
			t_array[0]->m_spellDamageMax = 7;
			break;

		case 3:
			t_array[0]->m_currentMeleeName = "Dagger";
			t_array[0]->m_spellDamageMax = 2;
			break;

		case 4:
			t_array[0]->m_currentMeleeName = "Club";
			t_array[0]->m_spellDamageMax = 4;
			break;

		case 5:
			t_array[0]->m_currentMeleeName = "Bite";
			t_array[0]->m_spellDamageMax = 3;
			break;

		case 6:
			t_array[0]->m_currentMeleeName = "Knee";
			t_array[0]->m_spellDamageMax = 1;
			break;

		default:
			break;
		}
	}
}

/// <summary>
/// Layout the Enemy and Player Health on screen
/// </summary>
/// <param name="t_array"></param>
void drawUI(Character * t_array[])
{
	clearScreen();
	if (charChoice == 0)
	{
		cout << "Health : " << t_array[0]->m_health << "\t Mana : " << t_array[0]->m_mana << endl;
		cout << "Enemy Health : " << t_array[1]->m_health << endl;
	}
	if (charChoice == 1)
	{
		cout << "Health : " << t_array[1]->m_health << "\t Mana : " << t_array[1]->m_mana << endl;
		cout << "Enemy Health : " << t_array[0]->m_health << endl;
	}
}

/// <summary>
/// Clear the console screen
/// </summary>
void clearScreen()
{
	system("cls");
}

/// <summary>
/// Function to pick the player character at the start of the game
/// </summary>
/// <param name="t_orc">Orc Object</param>
/// <param name="t_troll">Troll Object</param>
void pickCharacter(Orc *t_orc, Troll *t_troll)
{
	int spellChoice;
	int meleeChoice;
	int choice;	
	cout << "Please Pick Which character you'd like to be \n 1) Orc \n 2) Troll" << endl;
	cin >> choice;
	
	switch (choice)
	{
	case 1:
		charChoice = 0;
		cout << "You chose to be an Orc \n" << endl;
		cout << "Choose your Spell" << endl;
		cout << "\t SpellName \t|\t Mana \t|\t Max Damage \t|" << endl;
		cout << "\t 1.Acid Arrow \t|\t 5 \t|\t 6 \t\t|" << endl;
		cout << "\t 2.Burning Hand\t|\t 8 \t|\t 4 \t\t|" << endl;
		cout << "\t 3.Fire Strike \t|\t 10 \t|\t 8 \t\t|" << endl;
		cout << "\t 4.Fire Bolt \t|\t 5 \t|\t 5 \t\t|" << endl;
		cout << "\t 5.Fire Wave \t|\t 8 \t|\t 10 \t\t| \n" << endl;

		cin >> spellChoice;

		switch (spellChoice)
		{
		case 1:
			t_orc->m_currentSpell = OrcSpell::ACIDARROW;
			break;
		case 2:
			t_orc->m_currentSpell = OrcSpell::BURNINGHANDS;
			break;
		case 3:
			t_orc->m_currentSpell = OrcSpell::FIRESTRIKE;
			break;
		case 4:
			t_orc->m_currentSpell = OrcSpell::FIREBOLT;
			break;
		case 5:
			t_orc->m_currentSpell = OrcSpell::FIREWAVE;
			break;
		default:
			break;
		}
		t_orc->setOrcSpellStats(&t_orc->m_currentSpellName, t_orc->m_currentSpell, &t_orc->m_manaCost, &t_orc->m_spellDamageMax);

		cout << "Choose Your Melee Weapon " << endl;
		cout << "\t Melee Name \t|\t Max Damage \t|" << endl;
		cout << "\t 1.Axe \t\t|\t 7 \t\t|" << endl;
		cout << "\t 2.Punch \t|\t 2 \t\t|" << endl;
		cout << "\t 3.Hammer \t|\t 7 \t\t|" << endl;
		cout << "\t 4.Dagger \t|\t 2 \t\t|" << endl;
		cout << "\t 5.Club \t|\t 4 \t\t|" << endl;
		cout << "\t 6.Bite \t|\t 3 \t\t|" << endl;
		cout << "\t 7.Knee \t|\t 1 \t\t| \n" << endl;

		cin >> meleeChoice;

		t_orc->setOrcMeleeStats(&t_orc->m_currentMeleeName, t_orc->m_currentMelee, &t_orc->m_spellDamageMax);
		t_orc->setOrcShieldName(&t_orc->m_currentShieldName, t_orc->m_currentShield, &t_orc->m_shield);
		break;

	
	case 2:
		charChoice = 1;
		cout << "You chose to be a Troll" << endl;
		cout << "Choose your starting spell" << endl;
		cout << "\t SpellName \t|\t Mana \t|\t Max Damage \t|" << endl;
		cout << "\t 1.EarthShake \t|\t 5 \t|\t 6 \t\t|" << endl;
		cout << "\t 2.Magic Dart\t|\t 8 \t|\t 4 \t\t|" << endl;
		cout << "\t 3.Water Strike\t|\t 10 \t|\t 8 \t\t|" << endl;
		cout << "\t 4.Power Wave \t|\t 5 \t|\t 5 \t\t|" << endl;
		cout << "\t 5.Destructive \t|\t 8 \t|\t 10 \t\t| \n" << endl;

		cin >> spellChoice;

		switch (spellChoice)
		{
		case 1:
			t_troll->m_currentSpell = TrollSpell::EARTHSHAKE;
			break;
		case 2:
			t_troll->m_currentSpell = TrollSpell::MAGICDART;
			break;
		case 3:
			t_troll->m_currentSpell = TrollSpell::WATERSTRIKE;
			break;
		case 4:
			t_troll->m_currentSpell = TrollSpell::POWERWAVE;
			break;
		case 5:
			t_troll->m_currentSpell = TrollSpell::DESTRUCTIVEFORCE;
			break;
		default:
			break;
		}
		t_troll->setTrollSpellStats(&t_troll->m_currentSpellName, t_troll->m_currentSpell, &t_troll->m_manaCost, &t_troll->m_spellDamageMax);

		cout << "Choose Your Starting Melee" << endl;
		cout << "\t Melee Name \t|\t Max Damage \t|" << endl;
		cout << "\t 1.PickAxe \t|\t 4 \t\t|" << endl;
		cout << "\t 2.Spear \t|\t 6 \t\t|" << endl;
		cout << "\t 3.Cutlass \t|\t 4 \t\t|" << endl;
		cout << "\t 4.Katana \t|\t 8 \t\t|" << endl;
		cout << "\t 5.Rake \t|\t 2 \t\t| " << endl;
		cout << "\t 6.Kick \t|\t 2 \t\t| " << endl;
		cout << "\t 7.Elbow \t|\t 1 \t\t|" << endl;

		cin >> meleeChoice;

		t_troll->setTrollMeleeName(&t_troll->m_currentMeleeName, t_troll->m_currentMelee, &t_troll->m_spellDamageMax);
		t_troll->setTrollShieldName(&t_troll->m_currentShieldName, t_troll->m_currentShield, &t_troll->m_shield);
		break;

	default:
		system("cls");
		pickCharacter(t_orc, t_troll);
		break;
	}
}

/// <summary>
/// Shutdown the console Window
/// </summary>
void exitGame()
{
	exit(0);
}

/// <summary>
/// Intro Story for the game
/// </summary>
void travel()
{
	cout << "\n You wake from your slumber and make your way into the forest to find some food." ;
	cout << "\n You notice that as you get closer into the forest branches the area seems disturbed, ";
	cout << "\n it looks like somebody has been through here already this morning. You hear a screech";
	cout << "\n further into the forest, you run towards the sound. You see a red liquid on the ground";
	cout << "\n You look up to find the carcass of a freshly killed deer lying towards a tree. ";
	cout << "\n you hear branches crackling a little further into the forest and run towards it";

	switch (charChoice)
	{
	case 0:
		cout << "\n \n Infront of you stands a Troll, It was him who killed the deer \n You choose to attack him";
		break;
	case 1:
		cout << "\n \n Infront of you stands an Orc, It was him who killed the deer \n You choose to attack him";
	default:
		break;
	}
	system("Pause");
	clearScreen();
}


/// <summary>
/// Function to be looped, and have the ORc and Troll Fight eachother
/// </summary>
/// <param name="t_array"></param>
void fight(Character * t_array[])
{
	if (charChoice == 0)
	{
		if (t_array[0]->m_health > 0)
		{
			cout << "Do you choose to attack with 1) Melee or 2) Spell damage? " << endl;
			cin >> attackType;
			t_array[0]->m_damage = (rand() % t_array[0]->m_spellDamageMax) + 1;
			switch (attackType)
			{
			case 1:
				t_array[0]->attack();
				giveDamage(t_array);
				if (t_array[1]->m_health <= 0)
				{
					cout << "You Killed the Troll" << endl;
					isGameActive = false;
					isGameWon = true;
				}
			break;
			case 2:
				if ((t_array[0]->m_mana - t_array[0]->m_manaCost) >= 0)
				{
					t_array[0]->m_mana -= t_array[0]->m_manaCost;
					t_array[0]->cast();
					giveDamage(t_array);
					if (t_array[1]->m_health <= 0)
					{
						cout << "You Killed the Troll" << endl;
						isGameActive = false;
						isGameWon = true;
					}
				break;
				}
				else
				{
					cout << " You do not have enough mana To cast this spell, You must use melee";
					system("pause");
					clearScreen();
					fight(t_array);
				}
			default:
				break;
			}

			cout << "The Troll strikes back at you" << endl;
			randomMelee(t_array);
			t_array[1]->m_damage = (rand() % t_array[0]->m_spellDamageMax) + 1;
			t_array[1]->attack();
			takeDamage(t_array);
			if (t_array[0] <= 0)
			{
				cout << "You Died Hard Luck" << endl;
				isGameActive = false;
				isGameWon = false;
			}
		}
		else
		{
			isGameActive = false;
		}
	}
	
	else if (charChoice == 1)
	{
		if (t_array[1]->m_health > 0)
		{	
			cout << "Do you choose to attack with 1) Melee or 2) Spell damage? " << endl;
			cin >> attackType;
			t_array[1]->m_damage = (rand() % t_array[1]->m_spellDamageMax) + 1;
				switch (attackType)
				{
				case 1:
					t_array[1]->attack();
					giveDamage(t_array);
					if (t_array[0]->m_health <= 0)
					{
						cout << "You Killed the Orc" << endl;
						isGameActive = false;
						isGameWon = true;
					}
					break;
				case 2:
					if ((t_array[1]->m_mana - t_array[1]->m_manaCost) >= 0)
					{
						t_array[1]->m_mana -= t_array[1]->m_manaCost;
						t_array[1]->cast();
						giveDamage(t_array);
						if (t_array[0]->m_health <= 0)
						{
							cout << "You Killed the Orc" << endl;
							isGameActive = false;
							isGameWon = true;
						}
						break;
					}
					else
					{
						cout << " You do not have enough mana To cast this spell, You must use melee";
						system("pause");
						clearScreen();
						fight(t_array);
					}
				default:
					break;
				}

				cout << "The Troll strikes back at you" << endl;
				randomMelee(t_array);
				t_array[0]->m_damage = (rand() % t_array[0]->m_spellDamageMax) + 1;
				t_array[0]->attack();
				takeDamage(t_array);
				if (t_array[1] <= 0)
				{
					cout << "You Died Hard Luck" << endl;
					isGameActive = false;
					isGameWon = false;
				}
			}
		else
		{
			isGameActive = false;
		}
	}
	system("Pause");
}



