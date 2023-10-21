#include <iostream>

using namespace std;

#pragma region Forwards

void Introduction();
void PNJ();
//void Event();
void ActionsPlayer(int _scytheAttack, int& _actualPlayerLife, int _monsterAttack, int& _healPotion, int _healPotionPower, int _maxPlayerLife, int& _monsterPv);
void PlayerAttackMonster(int _weaponUsed, int& _monsterPv);
void MonsterAttackPlayer(int& _actualPlayerLife, int _monsterAttack);
void Healing(int& _actualPlayerLife, int& _healPotion, int _healPotionPower, int _maxPlayerLife, int _scytheAttack, int _monsterAttack, int _monsterPv);
void Display(string _storyText);

#pragma endregion

int main()
{
	int _healPotion = 3;
	int _healPotionPower = 50;
	int _maxPlayerLife = 100;
	int _actualPlayerLife = 100;
	int _monsterPv = 40;
	int _scytheAttack = 30;
	int _monsterAttack = 10;
	int _dragonPv = 110;
	int _dragonAttack = 35;
	bool _playerAnswer = 0;
	string _storyText;

	Introduction();

	//Event();

	MonsterAttackPlayer(_actualPlayerLife, _monsterAttack);
	ActionsPlayer(_scytheAttack, _actualPlayerLife, _monsterAttack, _healPotion, _healPotionPower, _maxPlayerLife, _monsterPv);

	PNJ();

	//Boss

	return 0;
}

#pragma region Texts

void Introduction()
{
	Display("Bienvenue dans le Donjon de la Muerte !");
	Display("Vous venez de spawn dans ce donjon suite au choix de votre Guilde, la Guilde Hestia.");
	Display("On vous a donn\x82\ une arme : la Scythe (corps \x85\ corps et arme principale).");
	Display("Vous \x88tes l\x27\ aventurier le plus faible de la guilde donc pour level up, on vous a donn\x82\ cette mission.");
	Display("Votre mission est de battre le Dragon de Foudre \x85\ la fin de ce donjon.");
	Display("Ce donjon est rempli de myst\x8Ares et de surprises. A vous de les d\x82\couvrir.");
	Display("Bonne chance \x85\ vous jeune aventurier.");
	Display("\n");
}

void PNJ()
{
	Display("Vous rencontrez sur votre chemin un Pnj");
	Display("");
	Display("Bonjour \x85\ vous tr\x8As cher. Que faites-vous l\x85\ tout seul ?");
	Display("C\x27\est tr\x8As dangereux dans le coin. Es-tu l\x85\ pour le dragon ?");
	Display("Je te conseille de tourner \x85\ tout droit pour le rencontrer.");
	Display("Au revoir mon p\x27\ tit bonhomme. Va bien crever ! ^^ ");
	Display("\n");
}

/*void Event()
{
	Display("Vous tombez nez \x85\ nez face \x85\ un coffre.");
	Display("Vous l\x27\ouvrez et trouvez un Gun (arme \x85\ distance et plac\x82\ en arme secondaire).");
	Display("F\x82\licitations, vous avez obtenu un Gun !");
	Display("\n");
}*/

#pragma endregion

void SadEnding(int _actualPlayerLife, int _healPotion, int _healPotionPower, int _maxPlayerLife, int _scytheAttack, int _monsterAttack, int _monsterPv)
{
	Display("Vous \x82\coutez le PNJ et continuez \x85\ marcher tout droit dans ce long couloir de donjon.");
	Display("Vous tombez face \x85\ face au Dragon de Foudre");
	Display("Veux-tu te heal avant le combat?");
	char _ouiOuNon;
	cin >> _ouiOuNon;
	switch (_ouiOuNon)
	{
	case 'y':
		Healing(_actualPlayerLife, _healPotion, _healPotionPower, _maxPlayerLife, _scytheAttack, _monsterAttack, _monsterPv);
		break;
	case 'n':
		break;

	default:break;
	}

}

void ActionsPlayer(int _scytheAttack, int& _actualPlayerLife, int _monsterAttack, int& _healPotion, int _healPotionPower, int _maxPlayerLife, int& _monsterPv)
{
	int _action;
	bool _wantToContinue = true;
	do
	{
		Display("Que voulez-vous faire ? \n 1- Attaquer \n 2- se soigner");
		cin >> _action;
		switch (_action)
		{
		case 1:
			PlayerAttackMonster(_scytheAttack, _monsterPv);
			_wantToContinue = false;
			break;
		case 2:
			Healing(_actualPlayerLife, _healPotion, _healPotionPower, _maxPlayerLife, _scytheAttack, _monsterAttack, _monsterPv);
			_wantToContinue = false;
			break;

		default: _wantToContinue;
			break;

		}
		MonsterAttackPlayer(_actualPlayerLife, _monsterAttack);
	} while (_wantToContinue || _monsterPv > 0);

	if (_actualPlayerLife <= 0)
	{
		Display("Tu es mort, tu es nul ;) ");
	}
	else if (_monsterPv <= 0)
	{
		Display("Bravo il est mort ! ");
		PNJ();
	}
}

void PlayerAttackMonster(int _weaponUsed, int& _monsterPv)
{
	_monsterPv -= _weaponUsed;
	cout << "Le gobelin perds " << _weaponUsed << " pv ! " << endl;
	cout << "Il reste " << _monsterPv << " pv au gobelin" << endl;
}

void MonsterAttackPlayer(int& _actualPlayerLife, int _monsterAttack)
{
	Display("Vous tombez face \x85\ un gobelin de niveau 1.");
	Display("Le gobelin vous attaque f\x82rocement");
	_actualPlayerLife -= _monsterAttack;
	cout << "Le joueur perd " << _monsterAttack << " pv ! " << endl << "Il reste " << _actualPlayerLife << " pv au joueur !" << endl;
}

void Healing(int& _actualPlayerLife, int& _healPotion, int _healPotionPower, int _maxPlayerLife, int _scytheAttack, int _monsterAttack, int _monsterPv)
{
	cout << "Vous avez choisi de vous heal." << endl;

	if (_healPotion == 0)
	{
		Display("Vous ne posseder plus de potions. Bonne chance ;)");
		ActionsPlayer(_scytheAttack, _actualPlayerLife, _monsterAttack, _healPotion, _healPotionPower, _maxPlayerLife, _monsterPv);
		return;
	}

	if (_actualPlayerLife + _healPotionPower >= 100)
	{
		_actualPlayerLife = 100;
		_healPotion--;
	}

	else
	{
		_actualPlayerLife += _healPotionPower;
		_healPotion--;
	}

	cout << "Votre vie est de " << _actualPlayerLife << endl;
	cout << "Il vous reste " << _healPotion << endl;
}

void Display(string _storyText)
{
	cout << _storyText << endl;
}
