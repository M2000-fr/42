#pragma once

#include <iostream>
class ASpell;
#include "ASpell.hpp"

class ATarget
{
    protected:
    std::string type;

    public:
    ATarget(const std::string& _type);
    virtual ~ATarget(){};
    virtual ATarget* clone() const = 0;
    ATarget(const ATarget&);
    const std::string& getType() const;
    void getHitBySpell(const ASpell& spell) const;
};