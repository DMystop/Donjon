#include <iostream>

using namespace std;

#pragma region Forwards

void SadEnding();
void ShameEnding();
void Introduction();
void PNJ();
//void Event();
void ElDragonDeLaMuerte(int _actualPlayerLife, int _healPotion, int _healPotionPower, int _maxPlayerLife, int _scytheAttack, int _monsterAttack, int _monsterPv, string _entityName);
void ActionsPlayer(int _scytheAttack, int& _actualPlayerLife, int _monsterAttack, int& _healPotion, int _healPotionPower, int _maxPlayerLife, int& _monsterPv, string _entityName);
void PlayerAttackMonster(int _weaponUsed, int& _monsterPv, string _entityName);
void MonsterAttackPlayer(int& _actualPlayerLife, int _monsterAttack, string _entityName);
void Healing(int& _actualPlayerLife, int& _healPotion, int _healPotionPower, int _maxPlayerLife, int _scytheAttack, int _monsterAttack, int _monsterPv, string _entityName);
void Display(string _storyText);
void AttackSentence(string _entityName);

#pragma endregion

int main()
{
#pragma region Variables	

	//Infos Potions
	int _healPotion = 3;
	int _healPotionPower = 60;

	//Infos Gobelin
	int _goblinAttack = 10;
	int _goblinPv = 40;

	//Infos Joueur
	int _maxPlayerLife = 100;
	int _actualPlayerLife = 100;
	int _scytheAttack = 30;
	bool _playerAnswer = 0;

	//Infos Dragon/Boss
	int _dragonPv = 110;
	int _dragonAttack = 35;

	//Textes
	string _storyText;
	string _player = "joueur";
	string _goblin = "gobelin ";
	string _dragon = "dragon ";

#pragma endregion

	//Début Histoire
	Introduction();

	//Event();

	//Action Gobelin
	AttackSentence(_goblin);
	MonsterAttackPlayer(_actualPlayerLife, _goblinAttack, _goblin);
	ActionsPlayer(_scytheAttack, _actualPlayerLife, _goblinAttack, _healPotion, _healPotionPower, _maxPlayerLife, _goblinPv, _goblin);

	//Rencontre avec le PNJ
	PNJ();

	//Action Boss
	AttackSentence(_dragon);
	ElDragonDeLaMuerte(_actualPlayerLife, _healPotion, _healPotionPower, _maxPlayerLife, _scytheAttack, _dragonAttack, _dragonPv, _dragon);
	MonsterAttackPlayer(_actualPlayerLife, _dragonAttack, _dragon);
	ActionsPlayer(_scytheAttack, _actualPlayerLife, _dragonAttack, _healPotion, _healPotionPower, _maxPlayerLife, _dragonPv, _dragon);


	return 0;
}

#pragma region Texts

void AttackSentence(string _entityName)
{
	cout << "Vous tombez face \x85\ un m\x82\chant vilain pas beau " << _entityName << " !" << endl;
	cout << "Le " << _entityName << "vous attaque f\x82rocement" << endl;
}

void Introduction()
{
	Display("Bienvenue dans le Donjon de la Muerte !");
	Display("Vous venez d'arriver dans ce donjon suite au choix de votre Guilde, la Guilde Hestia.");
	Display("On vous a donn\x82\ une arme : la Scythe (corps \x85\ corps).");
	Display("Ainsi que 3 potions de r\x82\g\x82n\x82ration qui soigne 60 points de vie.");
	Display("Vous \x88tes l\x27\ aventurier le plus faible de la guilde donc pour level up, on vous a donn\x82\ cette mission.");
	Display("Votre mission est de battre le Dragon de Foudre \x85\ la fin de ce donjon.");
	Display("Ce donjon est rempli de myst\x8Ares et de surprises. A vous de les d\x82\couvrir.");
	Display("Bonne chance \x85\ vous jeune aventurier.");
	Display("\n");
}

void PNJ()
{
	Display("Vous rencontrez sur votre chemin un vieux fou");
	Display("");
	Display("Bonjour \x85\ vous tr\x8As cher. Que faites-vous l\x85\ tout seul ?");
	Display("C\x27\est tr\x8As dangereux dans le coin. Es-tu l\x85\ pour le dragon ?");
	Display("Je te conseille de tourner \x85\ tout droit pour le rencontrer.");
	Display("Au revoir mon p\x27\ tit bonhomme. ^^");
	Display("\n");
}

void SadEnding()
{
	Display("Vous recroiser le vieux fou, il vous demande si vous avez bien nettoy\x82 les dents du v\x82n\x82r\x82 dragon.");
	Display("Vous sortez insouciant, heureux et victorieux du donjon, n'\x82\coutant pas les paroles du vieux fou.");
	Display("Vous rentrez avec empressement \x85\ la guilde, pour rapporter votre exploit. Vous parlez joyeusement \x85\ un membre de la guilde.");
	Display("Celui-ci vous explique que ce donjon servait \x85\ prot\x82\ger le dragon prot\x82\geant la vall\x82\e.");
	Display("Vous avez donc failli \x85\ votre mission. Vous \x88tes nul.");	
}

void ShameEnding()
{
	Display("Vous \x88tes suppos\x82\ \x88tre mort mais le dragon a piti\x82\ de vous parce que vous \x88tes nul.");
	cout << "Celui-ci vous laisse agoniser par terre et vous fait signe de partir loin d\x27\ici après avoir d\x82\rang\x82\ son calme." << endl;
	Display("Vous rentrez d\x82\confit \x85\ la guilde, vous annoncez votre \x82\chec cuisant.");
	Display("Vous vous faites sermonner par votre guilde car b\x88ta comme vous \x88tes, vous vous \x88tes tromp\x82\ de donjon.");
	Display("Vous avez donc failli \x85\ votre mission. Vous \x88tes nul.");
}

/*void Event()
{
	Display("Vous tombez nez \x85\ nez face \x85\ un coffre.");
	Display("Vous l\x27\ouvrez et trouvez un Gun (arme \x85\ distance et plac\x82\ en arme secondaire).");
	Display("F\x82\licitations, vous avez obtenu un Gun !");
	Display("\n");
}*/

#pragma endregion

void ElDragonDeLaMuerte(int _actualPlayerLife, int _healPotion, int _healPotionPower, int _maxPlayerLife, int _scytheAttack, int _monsterAttack, int _monsterPv, string _entityName)
{
	//Demande au joueur if heal or not
	Display("Vous \x82\coutez le PNJ et continuez \x85\ marcher tout droit dans ce long couloir de donjon.");
	Display("Vous tombez face \x85\ face a un dragon");
	Display("Veux-tu te heal avant le combat? (y/n) ");
	char _ouiOuNon;
	cin >> _ouiOuNon;

	//if oui, heal else suite.
	switch (_ouiOuNon)
	{
	case 'y':
		Healing(_actualPlayerLife, _healPotion, _healPotionPower, _maxPlayerLife, _scytheAttack, _monsterAttack, _monsterPv, _entityName);
		break;
	case 'n':
		break;

	default:break;
	}
}

void ActionsPlayer(int _scytheAttack, int& _actualPlayerLife, int _monsterAttack, int& _healPotion, int _healPotionPower, int _maxPlayerLife, int& _monsterPv, string _entityName)
{
	//creation variable action
	int _action;

	//creation variable suite du jeu
	bool _wantToContinue = true;

	//Action joueur attaquer/heal
	do
	{
		Display("Que voulez-vous faire ? \n 1- Attaquer \n 2- se soigner");
		cin >> _action;
		switch (_action)
		{
		case 1:
			PlayerAttackMonster(_scytheAttack, _monsterPv, _entityName);
			_wantToContinue = false;
			break;
		case 2:
			Healing(_actualPlayerLife, _healPotion, _healPotionPower, _maxPlayerLife, _scytheAttack, _monsterAttack, _monsterPv, _entityName);
			_wantToContinue = false;
			break;

		default: _wantToContinue;
			break;

		}
		if (_monsterPv > 0)
		{
			MonsterAttackPlayer(_actualPlayerLife, _monsterAttack, _entityName);
		}
	} while (_wantToContinue || _monsterPv > 0 && _actualPlayerLife > 0); //sécurité

	//Condition mort du joueur/monstre
	if (_actualPlayerLife <= 0)
	{
		ShameEnding();
	}
}

void PlayerAttackMonster(int _weaponUsed, int& _monsterPv, string _entityName)
{
	_monsterPv -= _weaponUsed;
	cout << "Le " << _entityName << " perds " << _weaponUsed << " pv ! " << endl;
	if (_monsterPv > 0)
	{
		cout << "Il reste " << _monsterPv << " pv au " << _entityName << endl;
	}
	else
	{
		cout << "Bravo ! Le " << _entityName << " est mort !" << endl;
		if (_entityName == "dragon ")
		{
			SadEnding();
		}
	}
}

void MonsterAttackPlayer(int& _actualPlayerLife, int _monsterAttack, string _entityName)
{
	_actualPlayerLife -= _monsterAttack;
	//cout << endl << _actualPlayerLife << endl;
	if (_actualPlayerLife > 0)
	{
		cout << "Le joueur perd " << _monsterAttack << " pv ! " << endl << "Il reste " << _actualPlayerLife << " pv au joueur !" << endl;
	}

}

void Healing(int& _actualPlayerLife, int& _healPotion, int _healPotionPower, int _maxPlayerLife, int _scytheAttack, int _monsterAttack, int _monsterPv, string _entityName)
{
	cout << "Vous avez choisi de vous heal." << endl;
	if (_healPotion == 0)
	{
		Display("Vous ne posseder plus de potions. Bonne chance ;)");
		ActionsPlayer(_scytheAttack, _actualPlayerLife, _monsterAttack, _healPotion, _healPotionPower, _maxPlayerLife, _monsterPv, _entityName);
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
	cout << "Il vous reste " << _healPotion << " potions" << endl;
}

void Display(string _storyText)
{
	cout << _storyText << endl;
}
