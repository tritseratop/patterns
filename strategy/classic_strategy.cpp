#include <iostream>
#include <memory>

class SolverStrategy {
public:
	virtual ~SolverStrategy() {}
	virtual void solve() = 0;
};

class Euler : public SolverStrategy {
public:
	void solve() override {
		std::cout << "Woof!" << std::endl;
	}
	~Euler() {}
};

class RungeKutta : public SolverStrategy {
public:
	void solve() override {
		std::cout << "Meow!" << std::endl;
	}
	~RungeKutta() {}
};

class Solver {
public:
	Solver(std::unique_ptr<SolverStrategy>&& solver) : solver(std::move(solver)) {}
	void setStrategy(std::unique_ptr<SolverStrategy>&& solver) {
		this->solver = std::move(solver);
	}
	void solve() {
		solver->solve();
	}

private:
	std::unique_ptr<SolverStrategy> solver;
};

int main()
{
	// какой-то выбор
	Solver solver(std::make_unique<Euler>());
	solver.solve();
	solver.setStrategy(std::make_unique<RungeKutta>());
	solver.solve();
	return 0;
}