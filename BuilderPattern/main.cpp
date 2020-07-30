#include <iostream>

class Builder {
public:
	virtual void BuildPart() = 0;
};

class ConcreteBuilder_A : public Builder {
public:
	void BuildPart() {
		std::cout << "Do something A1.\n";
		std::cout << "Do something A2.\n";
	}
};

class ConcreteBuilder_B : public Builder {
public:
	void BuildPart() {
		std::cout << "Do something B1.\n";
		std::cout << "Do something B2.\n";
	}
};

class Director {
public:
	void Construct(Builder *builder) {
		builder->BuildPart();
	};
};

int main() {
	Director *d = new Director;
	Builder *b1 = new ConcreteBuilder_A;
	Builder *b2 = new ConcreteBuilder_B;

	d->Construct(b1);
	d->Construct(b2);

	delete d, b1, b2;
	return 0;
}