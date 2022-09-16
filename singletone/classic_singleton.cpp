// singletone.cpp : Defines the entry point for the application.
//

#include <iostream>
#include <string>
#include <mutex>

class Singleton {
public:
	static Singleton* getInstance(std::string_view name);

	~Singleton() {
		std::cout << name << " was deleted" << std::endl;
	}

private:
	Singleton(std::string_view name) : name(name) {
		std::cout << name << "was created" << std::endl;
	};

private:
	std::string name;
	static Singleton* instance;
	static std::mutex get_instance;
};

Singleton* Singleton::instance = nullptr;
std::mutex Singleton::get_instance = std::mutex();

Singleton* Singleton::getInstance(std::string_view name) {
	std::lock_guard guard(get_instance);
	if (instance == nullptr) {
		return new Singleton(name);
	}
	else {
		return instance;
	}
}


int main()
{
	auto singleton = Singleton::getInstance("Tom");
	delete singleton;
	return 0;
}
