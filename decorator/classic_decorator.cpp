#include <iostream>
#include <string>

using namespace std;

class Component {
public:
	virtual ~Component() {}
	virtual string operation() const = 0;
};

class ConcreteComponent : public Component {
public:
	string operation() const override {
		return "ConcreteConponent";
	}
};

class Decorator : public Component {
protected:
	Component* component;
public:
	Decorator(Component* component)
		: component(component)
	{}

	string operation() const override {
		return component->operation();
	}
};

class ConcreteDecoratorA : public Decorator {
public:
	ConcreteDecoratorA(Component* component)
		: Decorator(component)
	{}
	string operation() const override {
		return "ConcreteDecoratorA(" + Decorator::operation() + ")";
	}
};

class ConcreteDecoratorB : public Decorator {
public:
	ConcreteDecoratorB(Component* component)
		: Decorator(component)
	{}
	string operation() const override {
		return "ConcreteDecoratorB(" + Decorator::operation() + ")";
	}
};

int main() {
	Component* component = new ConcreteComponent();
	cout << component->operation() << endl;

	Component* component_a = new ConcreteDecoratorA(component);
	cout << component_a->operation() << endl;
	Component* component_b = new ConcreteDecoratorB(component_a);
	cout << component_b->operation() << endl;
}