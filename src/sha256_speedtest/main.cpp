#include <iostream>
#include <string>

#include <chrono>
#include <vector>

#include "Sha256.h"

int main() {
    system("clear");

    std::string inp = "Some text or info here.";
    std::string enc;

    std::vector<double> data;

    for (unsigned long long int y = 0; y < 1000000; y++) {
        auto start = std::chrono::system_clock::now();
        enc = *Red::Sha256Hash(&inp);
        auto duration = std::chrono::system_clock::now() - start;

        if (y >= 500) {
            data.push_back(duration.count() / 1000000.0);
        }
    }

    double mean = 0;

    for (int p = 0; p < data.size(); p++) {
        mean += data[p] / data.size();
    }

    std::cout << "av: " << mean << " seconds, ~" << 1 / mean << " Hash/sec" << std::endl;
    std::cout << "Enc: " << enc << std::endl;

    return 0;
}
