#include <iostream>
using namespace std;

class ComponenteA {
public:
    ComponenteA() {
        cout << "Constructor de ComponenteA" << endl;
    }
    ~ComponenteA() {
        cout << "Destructor de ComponenteA" << endl;
    }
};

class ComponenteB {
public:
    ComponenteB() {
        cout << "Constructor de ComponenteB" << endl;
    }
    ~ComponenteB() {
        cout << "Destructor de ComponenteB" << endl;
    }
};

class Sistema {
private:
    ComponenteA a;
    ComponenteB b;
public:
    Sistema() {
        cout << "Constructor de Sistema" << endl;
    }
    ~Sistema() {
        cout << "Destructor de Sistema" << endl;
    }
};

/************************************************************
int main() {
    cout << "--- Creación de objeto Sistema ---" << endl;
    Sistema sistema;
    cout << "--- Fin del main() ---" << endl;
    return 0;
}
************************************************************/

class A {
public:
    A() {
        cout << "Constructor de A" << endl;
    }
    ~A() {
        cout << "Destructor de A" << endl;
    }
};

class B {
private:
    A a;
public:
    B() {
        cout << "Constructor de B" << endl;
    }
    ~B() {
        cout << "Destructor de B" << endl;
    }
};

int main() {
    cout << "--- Creación de objeto B ---" << endl;
    B objB;
    cout << "--- Fin del main() ---" << endl;
    return 0;
}