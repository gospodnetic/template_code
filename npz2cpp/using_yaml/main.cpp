/*
* @Author: Petra Gospodnetic
* @Date:   2017-10-20 14:40:31
* @Last Modified by:   petra
* @Last Modified time: 2017-10-20 15:00:06
*/

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

#include "yaml-cpp/yaml.h"

//
// Example assumes that the .npz  file contains only one array (single channel)
// of floats.
// Installation of Yaml-cpp library is required.
//
// If on linux, use $ apt-get install libyaml-cpp-dev
//
int main()
{
    // Example npz is an array of ordered values from 0 to 200.
    //
    // NOTE that the array will be written upside down because of the
    // line 18 numpy_array = np.flipud(numpy_array) in npz2yaml.py.
    // That line was taken from kitware Cinema script for reading depth values
    // stored as npz files.
    //
    const std::string filename = "example.npz";
    // Call python. The call path assumes we are in the build folder at the time
    // of execution of the program.
    const std::string system_call = "python npz2yaml.py -i " + filename;
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