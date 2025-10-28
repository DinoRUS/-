#ifndef WARRIOR_H
#define WARRIOR_H

#include "Npc.h"
#include <string>
using namespace std;

class Warrior : public virtual Npc {
protected:
    unsigned short strength = 31;
    string weapons[4] = {"кастет", "дубинка", "клинок", "меч"};

public:
    Warrior();
    ~Warrior() override;

    void GetWeapons();
    void GetInfo() override;
    void Create() override;

    bool operator==(const Warrior &other) const;
};

#endif // WARRIOR_H
