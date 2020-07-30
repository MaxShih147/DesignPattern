#include <iostream>

class Component {
public:
	virtual void Show() = 0;
	virtual ~Component() {
		std::cout << "Component's destructor.\n";
	}
};

class ConcreteComponent : public Component {
public:
	void Show() {
		std::cout << "I am ConcreteComponent.\n";
	}
};

class Decorator : public Component {
private:
	Component *component;       // reference to Widget
public:
	Decorator(Component *c) {
		component = c;
	}
	void Show() {
		component->Show();
	}
	~Decorator() {
		std::cout << "Decorator's destructor.\n";
		delete component;
	}
};

class ConcreteDecorator_A : public Decorator {
public:
	ConcreteDecorator_A(Component *w) : Decorator(w) {}
	void Show() {
		Decorator::Show();
		std::cout << "I am ConcreteDecorator_A.\n";
	}
};

class ConcreteDecorator_B : public Decorator {
public:
	ConcreteDecorator_B(Component *w) : Decorator(w) {}
	void Show() {
		Decorator::Show();
		std::cout << "I am ConcreteDecorator_B.\n";
	}
};

int main(void) {

	Component *component = 
		new ConcreteDecorator_B(
			new ConcreteDecorator_A(
					new ConcreteComponent()));
	component->Show();
	delete component;
}