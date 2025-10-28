#ifndef NPC_H
#define NPC_H

#include <string>
using namespace std;

class Npc {
protected:
    string name = "персонаж";
    unsigned int health = 10;
    float damage = 5.0f;
    unsigned short lvl = 1;

public:
    virtual ~Npc() {} // виртуальный деструктор

    virtual void GetInfo();
    virtual void Create();

    void SetLevel(unsigned short l) { if (l >= 1 && l <= 4) lvl = l; }
    unsigned short GetLevel() const { return lvl; }
};

#endif // NPC_H
