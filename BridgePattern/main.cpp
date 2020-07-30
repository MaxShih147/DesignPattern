#include <iostream>

class Implementor {
public:
	virtual void OperationImp() = 0;
};

class ConcreteImplementor_A : public Implementor {
public:
	void OperationImp() {
		std::cout << "do the operation A.\n";
	}
};

class ConcreteImplementor_B : public Implementor {
public:
	void OperationImp() {
		std::cout << "do the operation B.\n";
	}
};

class Abstraction {
protected:
	Implementor *implementor;
public:
	void SetImplementor(Implementor *_implementor) {
		implementor = _implementor;
	};
public:
	virtual void Operation() = 0;
};

class RefinedAbsrtraction_A : public Abstraction {
public:
	void Operation() {
		std::cout << "This is refined abstraction A, and I ";
		implementor->OperationImp();
	}
};

class RefinedAbsrtraction_B : public Abstraction {
public:
	void Operation() {
		std::cout << "This is refined abstraction B, and I ";
		implementor->OperationImp();
	}
};

int main() {
	Abstraction *a = new RefinedAbsrtraction_A;
	Implementor *imp_a = new ConcreteImplementor_A;
	a->SetImplementor(imp_a);
	a->Operation();
	delete a, imp_a;
	return 0;
}