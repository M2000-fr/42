#pragma once

#include <iostream>
class ATarget;
#include "ATarget.hpp"

class ASpell
{
    protected:
    std::string name;
    std::string effects;

    public:
    ASpell(const std::string& _name, const std::string& _effects);
    virtual ~ASpell(){};
    virtual ASpell* clone() const = 0;
    ASpell(const ASpell&);
    const std::string& getName() const;
    const std::string& getEffects() const;
    void launch(const ATarget& target) const;
};