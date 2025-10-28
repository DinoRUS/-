#include "../include/Npc.h"
#include <iostream>
using namespace std;

void Npc::GetInfo() {
    cout << "Имя - " << name << '\n';
    cout << "Здоровье - " << health << '\n';
    cout << "Урон - " << damage << '\n';
}

void Npc::Create() {
    // базовая версия (потомки переопределяют)
}
