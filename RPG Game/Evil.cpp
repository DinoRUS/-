#pragma once
#include "Evil.h"

Evil::Evil(string name) {
    this->name = name;
    health = 10;
    damage = 5;
}

Evil::Evil(string name, int health) : Evil::Evil(name) {
    this->health = health;
}

Evil::Evil(string name, int health, int damage) : Evil::Evil(name, health) {
    this->damage = damage;
}

void Evil::GetInfo() {
    cout << endl;
    cout << "на вас напал " << name << endl;
    if (health >= 0 && damage < 0) {
        cout << "Здоровье - " << health << endl;
    }
    if (health < 0 && damage >= 0) {
        cout << "урон - " << damage << endl;
    }
    if (health >= 0 && damage >= 0) {
        cout << "Здоровье - " << health << endl;
        cout << "урон - " << damage << endl;
    }
}
