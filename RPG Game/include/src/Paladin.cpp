#include "../include/Paladin.h"
#include <iostream>
using namespace std;

Paladin::Paladin() {
    name = "паладин";
    health = 25;
    damage = 12;
    strength = 27;
    // intellect берётся из Wizard
}

void Paladin::GetInfo() {
    // показываем как воинскую, так и магическую часть
    Warrior::GetInfo();
    cout << "Интеллект - " << intellect << '\n';
    cout << "Доступные заклинания:\n";
    for (int i = 0; i < lvl && i < 4; i++)
        cout << "  " << spell[i] << '\n';
}

void Paladin::Create() {
    cout << "Вы создали паладина\nВведите имя персонажа: ";
    cin >> name;
    GetInfo();
    CastSpell();
    GetWeapons();
}
