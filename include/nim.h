#ifndef NIM_H_
#define NIM_H_

#include <filesystem>
#include <fstream>
#include <string>
#include <vector>

class NIM {
public:
    std::vector<std::string> nutrients;
    std::vector<std::string> microbes;
    std::vector<std::vector<double>> impactMatrix;
    
    size_t nutrient_size;
    size_t microbe_size;

    void load(std::filesystem::path path, std::string sep = ",");
};

#endif