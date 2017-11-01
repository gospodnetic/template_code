/*
* @Author: Petra Gospodnetic
* @Date:   2017-10-20 14:40:31
* @Last Modified by:   Petra Gospodnetic
* @Last Modified time: 2017-11-02 09:44:37
*/

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

#include "yaml-cpp/yaml.h"

//
// Example assumes that the .Z  file contains only one array (single channel)
// of floats.
// Installation of Yaml-cpp library is required.
//
// If on linux, use $ apt-get install libyaml-cpp-dev
//
int main()
{
    // Example npz is an array of ordered values from 0 to 199.
    //
    const std::string filename = "../example.Z";
    const int height = 10;
    const int width = 20;
    // Call python. The call path assumes we are in the build folder at the time
    // of execution of the program.
    const std::string system_call = 
        "python ../z2yaml.py -i " + filename + 
        " -w " + std::to_string(width) +
        " -h " + std::to_string(height);

    std::system(system_call.c_str());

    YAML::Node primes = YAML::LoadFile(filename + ".yaml");
    std::cout << "Primes size: " << primes.size() << "x" << primes[0].size() << std::endl;        

    // Otput the data.
    for (YAML::const_iterator row=primes.begin(); row!=primes.end(); row++) {
        for (YAML::const_iterator col=row->begin(); col!=row->end(); col++)
            std::cout << col->as<float>() << " "; // Adjust type to your data
        std::cout << std::endl;
    }

    return 0;
}