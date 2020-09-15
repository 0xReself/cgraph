#pragma once
#include "node.hpp"

float calculate_local_derivative(float value, Node* node) {
    switch(node->getType()) {
        case NodeType::MUL:
            if(value == std::get<0>(node->getChildren())->compute()) {
                return std::get<1>(node->getChildren())->getValue();
            } else {
                return std::get<0>(node->getChildren())->getValue();
            }
        default:
            return 1.0;
            break;
    }
}