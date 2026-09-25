#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>

struct Program {
    std::string name;
    std::string path;
};

int main() {
    // List of learning binaries generated in the build directory
    std::vector<Program> programs = {
        {"numtheory", "./build/numtheory"}
        };

    std::cout << "RUNNING ALL LEARNING MODULES\n";

    for (const auto& prog : programs) {
        // std::system executes the process and returns the exit status
        int exit_code = std::system(prog.path.c_str());

        if (exit_code == 0) {
            std::cout << " -> " << prog.name << " is successful!\n\n";
        } else {
            std::cout << " -> " << prog.name << " FAILED (exit code: " << exit_code << ")\n\n";
        }
    }

    return 0;
}

