#include "../include/Wizard.h"
#include <iostream>
using namespace std;

Wizard::Wizard() {
    name = "волшебник";
    health = 23;
    damage = 15;
}

Wizard::~Wizard() {
    cout << name << " испустил дух" << '\n';
}

void Wizard::GetInfo() {
    Npc::GetInfo();
    cout << "Интеллект - " << intellect << '\n';
    cout << "Доступные заклинания:\n";
    for (int i = 0; i < lvl && i < 4; i++)
        cout << "  " << spell[i] << '\n';
}

void Wizard::CastSpell() {
    unsigned short idx = (lvl >= 1 && lvl <= 4) ? (lvl - 1) : 0;
    cout << name << " применяет " << spell[idx] << '\n';
}

void Wizard::Create() {
    cout << "Вы создали волшебника\nВведите имя персонажа: ";
    cin >> name;
    GetInfo();
    CastSpell();
}

Wizard Wizard::operator+(const Wizard &other) const {
    Wizard res;
    res.name = this->name;
    res.health = this->health + other.health;
    res.damage = this->damage + other.damage;
    return res;
}
