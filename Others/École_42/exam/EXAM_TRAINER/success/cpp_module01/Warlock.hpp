#pragma once

#include <iostream>
#include "ASpell.hpp"
#include <map>
#include <utility>
using namespace std;

class Warlock
{
    private:
    std::string name;
    std::string title;
    map<std::string, ASpell*> spells;
    Warlock(const Warlock&);
    Warlock operator=(const Warlock&);

    public:
    Warlock(const std::string& _name, const std::string& _title);
    ~Warlock();
    const std::string& getName() const;
    const std::string& getTitle() const;
    void setTitle(const std::string& str);
    void introduce() const;
    void learnSpell(ASpell* spell);
    void forgetSpell(string name);
    void launchSpell(string name, const ATarget& target);
};
