#pragma once
#include "node.hpp"

class Constant : Node {

public:
    Constant(float _value) {
        value = new float;
        *value = _value;
    }

    bool isConstant() override {
        return true;
    }
};