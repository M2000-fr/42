#pragma once

#include <iostream>
#include "ASpell.hpp"
#include <map>
#include <utility>
using namespace std;

class SpellBook
{
    private:
    map<std::string, ASpell*> spells;
    SpellBook(const SpellBook&);
    SpellBook operator=(const SpellBook&);

    public:
    SpellBook();
    ~SpellBook();
    void learnSpell(ASpell* spell);
    void forgetSpell(const string& name);
    ASpell* createSpell(const string& name);
};
