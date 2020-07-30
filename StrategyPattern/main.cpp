#include <iostream>

class Strategy {
public:
	Strategy() {}
	virtual void AlgorithmInterface() = 0;
};

class ConcreteStrategy_A : public Strategy {
public:
	void AlgorithmInterface() {
		std::cout << "Use strategy A.\n";
	}
};

class ConcreteStrategy_B : public Strategy {
public:
	void AlgorithmInterface() {
		std::cout << "Use strategy B.\n";
	}
};

// Use Simple Factory Pattern inside the constructor.
class Context {
private:
	Strategy *s;
public:
	~Context() {
		if (s != nullptr) {
			delete s;
			s = nullptr;
		}
	}
public:
	Context(const int mode) {
		switch (mode) {
		default:
		case 0:
			s = new ConcreteStrategy_A;
			break;
		case 1:
			s = new ConcreteStrategy_B;
			break;
		}
	}
	void ContextInterface() {
		s->AlgorithmInterface();
	}
};

int main() {
	Context *cntx = nullptr;
	cntx = new Context(0);
	cntx->ContextInterface();
	delete cntx;
	return 0;
}