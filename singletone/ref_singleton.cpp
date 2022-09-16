// singletone.cpp : Defines the entry point for the application.
//

#include <iostream>
#include <string>
#include <mutex>
#include <thread>

class Singleton {
public:
	static Singleton& getInstance(std::string_view name);

	Singleton(const Singleton& obj) = delete;

private:
	~Singleton() {
		std::cout << name << " was deleted" << std::endl;
	}

	Singleton(std::string_view name) : name(name) {
		std::cout << name << " was created" << std::endl;
	};

private:
	std::string name;
	static Singleton* instance;
	static std::mutex get_instance;
};

Singleton* Singleton::instance = nullptr;
std::mutex Singleton::get_instance = std::mutex();

Singleton& Singleton::getInstance(std::string_view name) {
	std::cout << "getInstance()" << std::endl;
	std::lock_guard guard(get_instance);
	static Singleton inst(name);
	instance = &inst;
	return *instance;
}


int main()
{
	std::thread first([]() {
		auto tom = &Singleton::getInstance("Tom");
		});
	auto bob = &Singleton::getInstance("Bob");
	std::this_thread::sleep_for(std::chrono::seconds(2));
	first.join();
	return 0;
}
