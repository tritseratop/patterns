#include <iostream>
#include <string>
#include <memory>

class Logger {
public:
	virtual void log(std::string) const = 0;
protected:
	std::string formMessage(std::string message) const {
		return "log: " + message;
	}
};

class MainLogger : public Logger {
public:
	void log(std::string message) const override {
		std::cout << Logger::formMessage(message) << std::endl;
	}
protected:

};

class Decorator : public Logger {
private:
	std::unique_ptr<Logger> component;
public:
	Decorator(std::unique_ptr<Logger> component)
		: component(std::move(component))
	{}

	void log(std::string message) const override {
		component->log(message);
	}
};

class AdditionalLogger : public Decorator {
public:
	AdditionalLogger(std::unique_ptr<Logger> component)
		: Decorator(std::move(component))
	{}

	void log(std::string message) const override {
		std::cout << "This logger like interrupting" << std::endl;
		Decorator::log(message);
	}
};

int main() {
	std::unique_ptr<Logger> component = std::make_unique<MainLogger>();
	component->log("message");

	std::unique_ptr<Logger> component_a =
		std::make_unique<AdditionalLogger>(std::move(component));

	component_a->log("message");

	return 0;
}