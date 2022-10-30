#include <iostream>
#include <string>
#include <memory>

class Component {
public:
	virtual std::string operation() const = 0;
};

class MainComponent : public Component {
public:
	std::string operation() const override {
		return "MainComponent";
	}
};

class Decorator : public Component {
private:
	std::unique_ptr<Component> component;
public :
	Decorator(std::unique_ptr<Component> component)
		: component(std::move(component)) 
	{}

	std::string operation() const override {
		return component->operation();
	}
};

class ConcreteComponent : public Decorator {
public:
	ConcreteComponent(std::unique_ptr<Component> component)
		: Decorator(std::move(component))
	{}

	std::string operation() const override {
		return "ConcreteDecorator(" + Decorator::operation() + ")";
	}
};

int main() {
	std::unique_ptr<Component> component = std::make_unique<MainComponent>();
	std::cout << component->operation() << std::endl;

	std::unique_ptr<Component> component_a = 
		std::make_unique<ConcreteComponent>(std::move(component));

	std::cout << component_a->operation() << std::endl;

	return 0;
}