#ifndef PALADIN_H
#define PALADIN_H

#include "Warrior.h"
#include "Wizard.h"
using namespace std;

class Paladin : public Warrior, public Wizard {
public:
    Paladin();

    void GetInfo() override;
    void Create() override;
};

#endif // PALADIN_H
