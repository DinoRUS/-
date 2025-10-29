#pragma once
#include <iostream>
#include <fstream>
using namespace std;

class Npc
{
protected: //модификатор 0 защищенный (дает доступ внутри класса родителя и наследника)
    //но все еще не дает доступ в основном потоке программы

    string name{ "персонаж" };
    unsigned int health{ 10 };
    float damage{ 5 };
    unsigned short lvl{ 1 };

public:    //публичный модификатор доступ (использовать метод можно в любом месте)

    //
    string GetName()
    {
        return name;
    }
    unsigned int GeatHealth()
    {
        return health;
    }
    float GetDamage()
    {
        return damage;
    }
    unsigned short GetLvl()
    {
        
    }
    virtual void GetInfo() //метод класса
    {
        cout << "Имя - " << name << endl;
        cout << "Здоровье - " << health << endl;
        cout << "Урон - " << damage << endl;
    }

    virtual void Create() {};
    bool Save() {

        ofstream saveSystem("save.bin", ios::binary);
        if (saveSystem.is_open())
        {
            saveSystem.write(reinterpret_cast<const char*>(&name), sizeof(name));
            saveSystem.write(reinterpret_cast<const char*>(&health), sizeof(health));
            saveSystem.write(reinterpret_cast<const char*>(&damage), sizeof(damage));
            saveSystem.write(reinterpret_cast<const char*>(&lvl), sizeof(lvl));
        }
        else
        {
            cout << "сохранение не удалось\nПопроуйбте позже\n";
        }
        saveSystem.close();
    };
    Npc Load() 
    {
        ifstream loadSystem("save.bin", ios::binary);
        Npc npc; //временное хранилище для считываня из файла
        if (loadSystem.is_open())
        {
            loadSystem.read(reinterpret_cast<const char*>(&npc.name), sizeof(npc.name));
            loadSystem.read(reinterpret_cast<const char*>(&npc.health), sizeof(npc.health));
            loadSystem.read(reinterpret_cast<const char*>(&npc.damage), sizeof(npc.damage));
            loadSystem.read(reinterpret_cast<const char*>(&npc.lvl), sizeof(npc.lvl));
        }
        else
        {
            cout << "Связь с небесами нарушена\nПамять о ваших прошлых появляениях утеряна\n";
                return npc;
        }
        loadSystem.close();
        return npc;
    };
};
class Player
{
public:
    void Create(Npc* player)
    {
        player->Create();
    }
    void Save(Npc* player)
    {
        player->Save();
    }
};
