#include <iostream>

using namespace std;

#pragma region Forwards

void Introduction();
void PNJ();
void Event();
void Attack();
void Healing();
void ActualWeapon();
void SwapWeapon();
void FightMovement();
void Movement();
void Display(string _storyText);

#pragma endregion

void main()
{
	int _maxPlayerLife = 100;
	int _actualPlayerLife = 100;
	int _monsterPv = 100;
	int _scytheAttack = 30;
	int _gunAttack = 10;
	bool _playerAnswer;
	string _storyText;
}

#pragma region Texts

void Introduction()
{
	Display("Bienvenue dans le Donjon de la Muerte !");
	Display("Vous venez de spawn dans ce donjon suite au choix de votre Guilde, la Guilde Hestia.");
	Display("On vous a donné deux armes : la Scythe (corps à corps et arme principale).");
	Display("Vous êtes l’aventurier le plus faible de la guilde donc pour level up, on vous a donné cette mission.");
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
void Attack()
{
	
}

void Healing()
{
	
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
