// singletone.cpp : Defines the entry point for the application.
//

#include <iostream>
#include <string>
#include <mutex>
#include <memory>

class Singleton {
public:
	static std::shared_ptr<Singleton>& getInstance(std::string_view name);

	~Singleton() {
		std::cout << name << " was deleted" << std::endl;
	}

	Singleton(const Singleton& obj) = delete;

private:
	Singleton(std::string_view name) : name(name) {
		std::cout << name << " was created" << std::endl;
	};

private:
	std::string name;
	static std::shared_ptr<Singleton> instance;
	static std::mutex get_instance;
};

std::shared_ptr<Singleton> Singleton::instance = nullptr;
std::mutex Singleton::get_instance = std::mutex();

std::shared_ptr<Singleton>& Singleton::getInstance(std::string_view name) {
	std::cout << "getInstance()" << std::endl;
	std::lock_guard guard(get_instance);
	if (instance == nullptr) {
		instance.reset(new Singleton(name));
		return instance;
	}
	else {
		return instance;
	}
}


int main()
{
	std::thread first([]() {
		auto tom = Singleton::getInstance("Tom");
		});
	auto bob = Singleton::getInstance("Bob");
	std::this_thread::sleep_for(std::chrono::seconds(2));
	first.join();
	return 0;
}
