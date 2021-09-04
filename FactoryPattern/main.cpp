#include <iostream>
#include <vector>

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

//int main() {
//	Factory* f_1 = new ConcreteFactory_A;
//	Operation* oper_1 = f_1->CreateOperation();
//	oper_1->AlgorithmInterface();
//
//	Factory* f_2 = new ConcreteFactory_B;
//	Operation* oper_2 = f_2->CreateOperation();
//	oper_2->AlgorithmInterface();
//
//	delete oper_1, oper_2, f_1, f_2;
//	return 0;
//}

// Head First Design Patterns, E Freeman and E Freeman
// Chapter.4.1 Simple Factory
//class SimplePizzaFactory {
//public:
//	Pizza* CreatePizza(const std::string &type) {
//
//		Pizza* pizza = nullptr;
//
//		if (type == "cheese") {
//			pizza = new CheesePizza;
//		}
//		//else if (type == "greek") {
//		//	pizza = new GreekPizza;
//		//}
//		else if (type == "pepperoni") {
//			pizza = new PepperoniPizza;
//		}
//		else if (type == "clam") {
//			pizza = new ClamPizza;
//		}
//		else if (type == "veggie") {
//			pizza = new VeggiePizza;
//		}
//		else {
//
//		}
//
//		return pizza;
//	}
//};
//class PizzaStore {
//private:
//	SimplePizzaFactory factory;
//
//public:
//	Pizza* OrderPizza(const std::string& type) {
//		Pizza* pizza = factory.CreatePizza(type);
//		pizza->Prepare();
//		pizza->Bake();
//		pizza->Cut();
//		pizza->Box();
//		return pizza;
//	}
//};
//class Pizza {
//public:
//	void Prepare() {}
//	void Bake() {}
//	void Cut() {}
//	void Box() {}
//};
//class CheesePizza : public Pizza {
//};
//class GreekPizza : public Pizza {
//};
//class PepperoniPizza : public Pizza {
//};
//class ClamPizza : public Pizza {
//};
//class VeggiePizza : public Pizza {
//};

// Chapter.4.2 Factory Pattern
class Pizza {
public:
	std::string name;
	std::string dough;
	std::string sauce;
	std::vector<std::string> toppings;

public:
	void Prepare() {
		std::cout
			<< "Preparing " << name << "\n"
			<< "Tossing dough...\n"
			<< "Adding sauce...\n"
			<< "Adding toppings:\n";

		for (auto i = 0; i < toppings.size(); ++i) {
			std::cout << "    " << toppings[i] << "\n";
		}
	}
	void Bake() {
		std::cout << "Bake for 25 min. at 350.\n";
	}
	void Cut() {
		std::cout << "Cutting the pizza into diagonal slices.\n";
	}
	void Box() {
		std::cout << "Place pizza in official PizzaStore box.\n";
	}
public:
	std::string GetName() {
		return name;
	}
};

class NY_CheesePizza : public Pizza {
public:
	NY_CheesePizza() {
		name = "NY style sauce and cheese pizza";
		dough = "Thin crust dough";
		sauce = "Marinara sauce";
		toppings.push_back("Grated reggiano cheese");
	}
};
class NY_GreekPizza : public Pizza {
};
class NY_PepperoniPizza : public Pizza {
};
class NY_ClamPizza : public Pizza {
};
class NY_VeggiePizza : public Pizza {
};

class CHI_CheesePizza : public Pizza {
public:
	CHI_CheesePizza() {
		name = "Chicago style deep dish cheese pizza";
		dough = "Extra thick crust dough";
		sauce = "Plum tomato sauce";
		toppings.push_back("Shredded mozzarella cheese");
	}
	void Cut() {
		std::cout << "Cutting the pizza into square slices.\n";
	}
};
class CHI_GreekPizza : public Pizza {
};
class CHI_PepperoniPizza : public Pizza {
};
class CHI_ClamPizza : public Pizza {
};
class CHI_VeggiePizza : public Pizza {
};

class PizzaStore {
public:
	Pizza* OrderPizza(const std::string& type) {
		Pizza* pizza = /*factory.*/CreatePizza(type);
		pizza->Prepare();
		pizza->Bake();
		pizza->Cut();
		pizza->Box();
		return pizza;
	}
protected:
	// Abstract method, it's a factory!
	virtual Pizza* CreatePizza(const std::string& type) = 0;
};
class NY_PizzaStore : public PizzaStore {
public:
	Pizza* CreatePizza(const std::string& type) {

		Pizza* pizza = nullptr;

		if (type == "cheese") {
			pizza = new NY_CheesePizza;
		}
		else if (type == "greek") {
			pizza = new NY_GreekPizza;
		}
		else if (type == "pepperoni") {
			pizza = new NY_PepperoniPizza;
		}
		else if (type == "clam") {
			pizza = new NY_ClamPizza;
		}
		else if (type == "veggie") {
			pizza = new NY_VeggiePizza;
		}
		else {
		}
		return pizza;
	}
};

class CHI_PizzaStore : public PizzaStore {
public:
	Pizza* CreatePizza(const std::string& type) {

		Pizza* pizza = nullptr;

		if (type == "cheese") {
			pizza = new CHI_CheesePizza;
		}
		else if (type == "greek") {
			pizza = new CHI_GreekPizza;
		}
		else if (type == "pepperoni") {
			pizza = new CHI_PepperoniPizza;
		}
		else if (type == "clam") {
			pizza = new CHI_ClamPizza;
		}
		else if (type == "veggie") {
			pizza = new CHI_VeggiePizza;
		}
		else {
		}
		return pizza;
	}
};

class Test {
public:
	void OrderCheesePizzaFromTwoDifferentPizzaStore() {
		
		PizzaStore* nyPizzaStore = new NY_PizzaStore;
		PizzaStore* chiPizzaStore = new CHI_PizzaStore;
		
		Pizza* ethanPizza = nyPizzaStore->OrderPizza("cheese");
		std::cout << "Ethan ordered a " << ethanPizza->GetName() << "\n";
		std::cout << "\n";

		Pizza* joelPizza = chiPizzaStore->OrderPizza("cheese");
		std::cout << "Joel ordered a " << joelPizza->GetName() << "\n";

		delete nyPizzaStore;
		delete chiPizzaStore;
		delete ethanPizza;
		delete joelPizza;
	}
};

int main() {
	Test test;
	test.OrderCheesePizzaFromTwoDifferentPizzaStore();
	return 0;
}

