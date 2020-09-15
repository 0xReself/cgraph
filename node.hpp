#pragma once
#include "types.hpp"
#include <tuple>
#include <iostream>

class Node {

protected:
    float* value = nullptr;
    float deriv = 1;

public:

    virtual float getValue() {
        return *value;
    }

    virtual std::tuple<Node*, Node*> getChildren() { return std::make_tuple<Node*, Node*>(nullptr, nullptr); };

    virtual NodeType getType() { return NodeType::NONE; };

    virtual bool isConstant() { return false; };

    virtual float compute() {
        if(value != nullptr) {
            return *value;
        }
        return 0;
    }

    virtual void optimize(float deriv, Node* current, float loss) {};
};