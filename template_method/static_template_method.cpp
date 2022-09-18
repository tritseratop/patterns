#include <iostream>
#include <memory>

class FullTask {
public:
	template<class T>
	void runTask(const T& task) {
		preparation();
		task.task();
		cleaning();
	}

protected:
	virtual void preparation() {
		std::cout << "Preparing enviroment for task..." << std::endl;
	}

	virtual void cleaning() {
		std::cout << "Cleaning after task." << std::endl;
	}
};

class Task {
public:
	virtual void task() const {};
};

class SayHello : public Task {
public:
	void task() const override {
		std::cout << "Hello!" << std::endl;
	}
};

class SayBye : public Task {
public:
	void task() const override {
		std::cout << "Bye!" << std::endl;
	}
};

int main()
{
	FullTask runner;
	SayHello task;
	runner.runTask(task);

	SayBye bye;
	runner.runTask(bye);
	return 0;
}