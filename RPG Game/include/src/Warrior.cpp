#include "../include/Warrior.h"
#include <iostream>
using namespace std;

Warrior::Warrior() {
    name = "воин";
    health = 35;
    damage = 10;
}

Warrior::~Warrior() {
    cout << name << " пал смертью храбрых" << '\n';
}

void Warrior::GetWeapons() {
    // защита от выхода за пределы массива
    unsigned short idx = (lvl >= 1 && lvl <= 4) ? (lvl - 1) : 0;
    cout << name << " взял в руки " << weapons[idx] << '\n';
}

void Warrior::GetInfo() {
    Npc::GetInfo();
    cout << "Сила - " << strength << '\n';
    cout << "Доступное оружие:\n";
    for (int i = 0; i < lvl && i < 4; i++)
        cout << "  " << weapons[i] << '\n';
}

void Warrior::Create() {
    cout << "Вы создали воина\nВведите имя персонажа: ";
    cin >> name;
    GetInfo();
    GetWeapons();
}

bool Warrior::operator==(const Warrior &other) const {
    return (other.damage == damage) && (other.health == health) && (other.strength == strength);
}
