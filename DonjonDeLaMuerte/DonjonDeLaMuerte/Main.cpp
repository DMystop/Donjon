#include <iostream>

using namespace std;

#pragma region Forwards

void Introduction();
void PNJ();
void Event();
void PlayerAttackMonster(int _weaponUsed, int _monsterPv);
void MonsterAttackPlayer(int _actualPlayerLife, int _monsterAttack);
void Healing(int _actualPlayerLife, int _healPotion, int _healPotionPower, int _maxPlayerLife);
void ActualWeapon();
void SwapWeapon();
void FightMovement();
void Movement();
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
	int _gunAttack = 10;
	int _monsterAttack = 20;
	bool _playerAnswer=0;
	string _storyText;

	Introduction();
	MonsterAttackPlayer(_actualPlayerLife, _monsterAttack);
	Healing(_actualPlayerLife, _healPotion, _healPotionPower, _maxPlayerLife); 

	return 0;
}

#pragma region Texts

void Introduction()
{
	Display("Bienvenue dans le Donjon de la Muerte !");
	Display("Vous venez de spawn dans ce donjon suite au choix de votre Guilde, la Guilde Hestia.");
	Display("On vous a donn\x82\ deux armes : la Scythe (corps \x85\ corps et arme principale).");
	Display("Vous \x88tes l’aventurier le plus faible de la guilde donc pour level up, on vous a donn\x8A\ cette mission.");
	Display("Votre mission est de battre le Dragon de Foudre à la fin de ce donjon.");
	Display("Ce donjon est rempli de mystères et de surprises. A vous de les découvrir.");
	Display("Bonne chance à vous jeune aventurier.");
}

void PNJ()
{
	Display("Bonjour à vous très cher. Que faites-vous là tout seul ?");
	Display("C’est très dangereux dans le coin. Es-tu là pour le dragon ?");
	Display("Je te conseille de tourner à droite pour le rencontrer.");
	Display("Au revoir mon p’tit bonhomme.");
}

void Event()
{
	Display("Vous tombez nez à nez face à un coffre.");
	Display("Vous l’ouvrez et trouvez un Gun (arme à distance et placé en arme secondaire).");
	Display("Félicitations, vous avez obtenu un Gun !");
}

#pragma endregion

void PlayerAttackMonster(int _weaponUsed, int _monsterPv)
{
	_monsterPv -= _weaponUsed;
	cout << "Le joueur attaque " << _weaponUsed << " pv ! " << endl;
}

void MonsterAttackPlayer(int _actualPlayerLife, int _monsterAttack)
{
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

void ActualWeapon()
{

}

void SwapWeapon()
{

}

void FightMovement()
{

}

void Movement()
{

}

void Display(string _storyText)
{
	cout << _storyText << endl;
}