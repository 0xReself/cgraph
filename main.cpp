#include <iostream>
#include "core.hpp"

float test1() {
    Variable* v = new Variable(4);
    Constant* c = new Constant(6);
    Add* a = new Add((Node*)v, (Node*)c);
    Constant* c2 = new Constant(2);
    Mul* m = new Mul((Node*)a, (Node*)c2);
    return m->compute();
}

float test2() {
    Constant* c = new Constant(10);
    Variable* v = new Variable(5);
    Sub* a = new Sub((Node*)v, (Node*)c);
    Constant* c2 = new Constant(2);
    Mul* m = new Mul((Node*)a, (Node*)c2);
    return m->compute();
}

float test3() {
    Constant* c = new Constant(4);
    Variable* v = new Variable(3);
    Mul* m = new Mul((Node*)c, (Node*)v);

    Constant* c2 = new Constant(5);
    Add* a = new Add((Node*)m, (Node*)c2);

    Constant* real = new Constant(21);
    Sub* s = new Sub((Node*)a, (Node*)real);

    for(int i = 0; i < 100; ++i) {
        a->optimize(1, nullptr, s->compute());
    }
    std::cout << v->getValue() << std::endl;
    return v->getValue();
}

bool test(float(*p)(), float expected, std::string msg) {
    if(p() != expected) {
        std::cout << msg << " : " << p() << " : " << expected << std::endl;
        return false;
    }
    return true;
}

int main() {
    std::cout << "Starting Testing..." << std::endl;
    test(test1, 20, "Test: 1 failed");
    test(test2, -10, "Test: 2 failed");
    test(test3, 4, "Test: 3 failed");
    std::cout << "Test Completed!" << std::endl;
    return 0;
}