#pragma once
#include "node.hpp"
#include "util.hpp"

class Variable : public Node {

public:
    Variable(float _value) {
        value = new float;
        *value = _value;
    }

    float get_deriv() {
        return deriv;
    }

    void optimize(float div, Node* current, float loss) override {
        deriv = 1.0;
        if(current != nullptr) {
            deriv = div * calculate_local_derivative(compute(), current);
        }

        *value -= 0.01 * deriv * loss;
    }
};