#pragma once
#include "node.hpp"
#include "util.hpp"

class Add : Node {

private:
    Node* first;
    Node* second;

public:
    Add(Node* f, Node* s) {
        first = f;
        second = s;
        value = new float;
    }

    NodeType getType() override {
        return NodeType::ADD;
    }

    std::tuple<Node*, Node*> getChildren() override {
        return std::make_tuple(first, second);
    }

    float compute() override {
        *value = first->compute() + second->compute();
        return *value;
    }

    void optimize(float div, Node* current, float loss) override {
        deriv = 1.0;
        if(current != nullptr) {
            deriv = div * calculate_local_derivative(compute(), current);
        }

        if(!first->isConstant()) {
            first->optimize(deriv, this, loss);
        }

        if(!second->isConstant()) {
            second->optimize(deriv, this, loss);
        }
    }
};