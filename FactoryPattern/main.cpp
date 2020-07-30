#include <iostream>

class Operation {
public:
	virtual void AlgorithmInterface() = 0;
};

class ConcreteOperation_A : public Operation {
public:
	void AlgorithmInterface() {
		std::cout << "Do operation A.\n";
	}
};

class ConcreteOperation_B : public Operation {
public:
	void AlgorithmInterface() {
		std::cout << "Do operation B.\n";
	}
};

class Factory {
public:
	virtual Operation* CreateOperation() = 0;
};

class ConcreteFactory_A : public Factory {
public:
	Operation* CreateOperation() {
		return new ConcreteOperation_A;
	}
};

class ConcreteFactory_B : public Factory {
public:
	Operation* CreateOperation() {
		return new ConcreteOperation_B;
	}
};

int main() {
	Factory *f_1 = new ConcreteFactory_A;
	Operation *oper_1 = f_1->CreateOperation();
	oper_1->AlgorithmInterface();

	Factory *f_2 = new ConcreteFactory_B;
	Operation *oper_2 = f_2->CreateOperation();
	oper_2->AlgorithmInterface();

	delete oper_1, oper_2, f_1, f_2;
	return 0;
}