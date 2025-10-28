#ifndef WIZARD_H
#define WIZARD_H

#include "Npc.h"
#include <string>
using namespace std;

class Wizard : public virtual Npc {
protected:
    unsigned short intellect = 27;
    string spell[4] = {"вспышка", "магическая стрела", "огненный шар", "метеоритный дождь"};

public:
    Wizard();
    ~Wizard() override;

    void GetInfo() override;
    void CastSpell();
    void Create() override;

    Wizard operator+(const Wizard &other) const;
};

#endif // WIZARD_H
