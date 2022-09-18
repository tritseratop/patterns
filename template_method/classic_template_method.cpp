#include <iostream>
#include <memory>

class FullTask {
public:
	void runTask() {
		preparation();
		task();
		cleaning();
	}

protected:
	virtual void preparation() {
		std::cout << "Preparing enviroment for task..." << std::endl;
	}

	virtual void cleaning() {
		std::cout << "Cleaning after task." << std::endl;
	}

	virtual void task() = 0;
};

class SayHello : public FullTask {
private:
	void task() override {
		std::cout << "Hello!" << std::endl;
	}
};

class SayBye : public FullTask {
private:
	void task() override {
		std::cout << "Bye!" << std::endl;
	}
	void preparation() override {
		std::cout << "Preparing enviroment to say \"Bye\"..." << std::endl;
	}

	void cleaning() override {
		std::cout << "Cleaning after saying \"Bye\"." << std::endl;
	}
};

int main()
{
	std::unique_ptr<FullTask> task = std::make_unique<SayHello>();
	task->runTask();

	std::unique_ptr<FullTask> bye = std::make_unique<SayBye>();
	bye->runTask();
	return 0;
}