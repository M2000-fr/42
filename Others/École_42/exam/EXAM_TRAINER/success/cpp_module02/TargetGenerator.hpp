#pragma once

#include <iostream>
#include "ATarget.hpp"
#include <map>
#include <utility>
using namespace std;

class TargetGenerator
{
    private:
    map<std::string, ATarget*> targets;
    TargetGenerator(const TargetGenerator&);
    TargetGenerator operator=(const TargetGenerator&);

    public:
    TargetGenerator();
    ~TargetGenerator();
    void learnTargetType(ATarget* target);
    void forgetTargetType(const string& type);
    ATarget* createTarget(const string& type);
};