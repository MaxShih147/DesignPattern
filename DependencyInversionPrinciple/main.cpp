// Dependency Inversion Principle, DIP
// 1. High level modules should not depend on low level modules.Both should depend on abstractions.
// 2. Abstractions should not depend on details.Details should depend on abstractions.
// References: 
// [1] SOLID Principles of Object - Oriented Design and Architecture, 
//     https://www.udemy.com/course/solid-principles-object-oriented-design-architecture/
// [2] https://www.jyt0532.com/2020/03/24/dip/
// [3] https://www.jyt0532.com/2020/03/19/ocp/

#include <iostream>

// Example 1: Dependency
// Programmer class (high level) depeneds on Computer class (low level), which might
// cause tight coupling.
class Computer {
public:
	void program() {
		std::cout << "Working hard.\n";
	}
};
class Programmer_D {
	Computer *computer;
	Programmer_D() {
		computer = new Computer();
	}
	~Programmer_D() {
		delete computer;
	}
	void code() {
		computer->program();
	}
};

// Example 2: Dependency Injection, DI
// Inject Computer by constructor, or using setter.
class Programmer_DI {
public:
	Computer *computer;
	Programmer_DI(Computer *c) {
		computer = c;
	}
	void code() {
		computer->program();
	}
	void setComputer(Computer *c) {
		computer = c;
	}
};

// Example 3: Inversion of Control, IOC
// Sample code in main function:
// 
//     Controller controller;
//     controller.AssignWork();
//
class Controller {
public:
	Computer *computer;
	Programmer_DI *programmer;
public:
	~Controller() {
		delete computer, programmer;
	}
	void AssignWork() {
		Computer *computer = new Computer();
		Programmer_DI *programmer = new Programmer_DI(computer);
	}
};

// Example 4: Dependency Inversion Principle, DIP
class Device {
public:
	virtual void program() = 0;
};
class Computer_DIP : public Device {
public:
	void program() {
		std::cout << "Working hard via computer.\n";
	}
};
class Laptop_DIP : public Device {
public:
	void program() {
		std::cout << "Working hard via laptop.\n";
	}
};
class Programmer_DIP {
public:
	Device *device;
	Programmer_DIP(Device *d) {
		device = d;
	}
	void code() {
		device->program();
	}
	void setComputer(Device *d) {
		device = d;
	}
};

int main() {
	Device *device = new Laptop_DIP;
	Programmer_DIP programmer(device);
	programmer.code();
	delete device;
	return 0;
}