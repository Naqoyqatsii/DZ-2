#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>

std::vector<int> split(const std::string &str, char d) {
    std::vector<int> r;

    std::string::size_type start = 0;
    std::string::size_type stop = str.find_first_of(d);
    while (stop != std::string::npos) {
        r.push_back(std::stoi(str.substr(start, stop - start)));

        start = stop + 1;
        stop = str.find_first_of(d, start);
    }

    r.push_back(std::stoi(str.substr(start)));

    return r;
}

bool compare(std::vector<int> &a, std::vector<int> &b) {
    for (int i = 0; i < 4; i++) {
        if (a[i] != b[i]) {
            return a[i] > b[i];
        }
    }
    return false;
}

void separattor() {
    std::cout << std::endl;
    std::cout << "********************************************" << std::endl;
    std::cout << std::endl;
}

int main(int argc, char const *argv[]) {
    try {

        std::vector<std::vector<int> > ip_pool;
       

        for(std::string line; std::getline(std::cin, line);)
        {
            std::vector<int> v = split(line, '\t');
            ip_pool.push_back(split(std::to_string(v.at(0)), '.'));
        }


        // TODO reverse lexicographically sort
        sort(ip_pool.begin(), ip_pool.end(), compare);


        for (std::vector<std::vector<int> >::const_iterator ip = ip_pool.cbegin(); ip != ip_pool.cend(); ++ip) {
            for (std::vector<int>::const_iterator ip_part = ip->cbegin(); ip_part != ip->cend(); ++ip_part) {
                if (ip_part != ip->cbegin()) {
                    std::cout << ".";
                }
                std::cout << *ip_part;
            }
            std::cout << std::endl;
        }

        separattor();

        // TODO filter by first byte and output
        // ip = filter(1)
        for (const auto &addr: ip_pool) {
            if (addr[0] == 1) {
                std::cout << addr[0] << "." << addr[1] << "." << addr[2] << "." << addr[3] << std::endl;
            }
        }

        separattor();

        for (const auto &addr: ip_pool) {
            if (addr[0] == 46 && addr[1] == 70) {
                std::cout << addr[0] << "." << addr[1] << "." << addr[2] << "." << addr[3] << std::endl;
            }
        }

        separattor();

        for (const auto &addr: ip_pool) {
            if (find(addr.begin(), addr.end(), 46) != addr.end()) {
                std::cout << addr[0] << "." << addr[1] << "." << addr[2] << "." << addr[3] << std::endl;
            }
        }

    }
    catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}

