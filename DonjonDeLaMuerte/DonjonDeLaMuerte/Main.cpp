#include <iostream>

using namespace std;

#pragma region Forwards

void Introduction();
void PNJ();
//void Event();
void ActionsPlayer(int _scytheAttack, int*& _actualPlayerLife, int _monsterAttack, int*& _healPotion, int _healPotionPower, int _maxPlayerLife, int*& _monsterPv);
void PlayerAttackMonster(int _weaponUsed, int _monsterPv);
void MonsterAttackPlayer(int _actualPlayerLife, int _monsterAttack);
void Healing(int _actualPlayerLife, int _healPotion, int _healPotionPower, int _maxPlayerLife);
void Display(string _storyText);

#pragma endregion

int main()
{
	int _healPotion = 3;
	int _healPotionPower = 20;
	int _maxPlayerLife = 100;
	int _actualPlayerLife = 100;
	int _monsterPv = 100;
	int _scytheAttack = 30;
	int _monsterAttack = 20;
	bool _playerAnswer=0;
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
	Display("C’est tr\x8As dangereux dans le coin. Es-tu l\x85\ pour le dragon ?");
	Display("Je te conseille de tourner \x85\ tout droit pour le rencontrer.");
	Display("Au revoir mon p\x27\ tit bonhomme.");
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

void ActionsPlayer(int _scytheAttack, int*& _actualPlayerLife, int _monsterAttack, int*& _healPotion, int _healPotionPower, int _maxPlayerLife, int*& _monsterPv)
{
	int _action;
	bool _WantToContinue = true;
	do
	{
		Display("Que voulez-vous faire ?");
		cin >> _action;
		switch (_action)
		{
		case 1:
			PlayerAttackMonster(_scytheAttack, *_monsterPv);
			_WantToContinue = false;
			break;
		case 2:
			Healing(*_actualPlayerLife, *_healPotion, _healPotionPower, _maxPlayerLife);
			_WantToContinue = false;
			break;

		default: _WantToContinue;
		break;

		}

	} while (_WantToContinue || *_monsterPv > 0);
	


}

void PlayerAttackMonster(int _weaponUsed, int _monsterPv)
{
	_monsterPv = _monsterPv - _weaponUsed;
	cout << "Le gobelin perds " << _weaponUsed << " pv ! " << endl;
	cout << "Il reste " << _monsterPv << " pv au gobelin" << endl;
}

void MonsterAttackPlayer(int _actualPlayerLife, int _monsterAttack)
{
	Display("Vous tombez face \x85\ un gobelin de niveau 1.");
	Display("Le gobelin vous attaque f\x82rocement");
	_actualPlayerLife -= _monsterAttack;
	cout << "Le joueur perd " << _monsterAttack << " pv ! " << endl << "Il lui reste " << _actualPlayerLife << " pv !" << endl;
}

void Healing(int _actualPlayerLife, int _healPotion, int _healPotionPower, int _maxPlayerLife)
{
	cout << "Tu as choisi de te heal." << endl;

	if (_healPotion == 0)
	{
		Display("Vous ne posseder plus de potions. Bonne chance ;)");
		return;
	}

	if (_actualPlayerLife + _healPotionPower >= 100)
	{
		_actualPlayerLife = 100;
	}

	else
	{
		_actualPlayerLife += _healPotionPower;

	}

	cout << "Votre vie est de " << _actualPlayerLife << endl;

}

void Display(string _storyText)
{
	cout << _storyText << endl;
}