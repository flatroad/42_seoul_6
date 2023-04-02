#include <iostream>
#include <string>

class Zombie {
private:
    std::string name_;

public:
    Zombie() : name_("") {
        std::cout << "A new Zombie is born!" << std::endl;
    }

    Zombie(const std::string& name) : name_(name) {
        std::cout << name_ << " is born!" << std::endl;
    }

    ~Zombie() {
        std::cout << name_ << " is died!" << std::endl;
    }

    void announce() {
        std::cout << name_ << " BraiiiiiiinnnzzzZ..." << std::endl;
    }
};

Zombie* zombieHorde(int N, std::string name) {
    Zombie* zombies = new Zombie[N];

    for (int i = 0; i < N; i++) {
        zombies[i] = Zombie(name);
    }

    return zombies;
}

int main() {
    int n = 3;
    Zombie* zombies = zombieHorde(n, "Alice");

    for (int i = 0; i < n; i++) {
        zombies[i].announce();
    }

    delete[] zombies;

    return 0;
}