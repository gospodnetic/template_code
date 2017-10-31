#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

#include <boost/iostreams/filtering_stream.hpp>
#include <boost/iostreams/filter/zlib.hpp>

#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>
#include <boost/serialization/vector.hpp>

int main()
{
    // std::string filename = "/home/petra/Desktop/SampleBasedReconstruction/python_utils/zwrite_test.Z";
    std::string filename = "/home/petra/Desktop/SampleBasedReconstruction/python_utils/zwrite_test_numpy_arange.Z";

    std::cout << filename << std::endl;
    std::vector<float> data_in;
    {
        std::ifstream file_in(filename, std::ios_base::in | std::ios_base::binary);
        boost::iostreams::filtering_istream in;
        in.push(boost::iostreams::zlib_decompressor());
        in.push(file_in);

        boost::archive::binary_iarchive ia(in);
        ia & data_in;
    }

    for(std::vector<float>::const_iterator i = data_in.begin(); i != data_in.end(); i++)
        std::cout << *i << std::endl;

    std::cout << "Data in size: " << data_in.size() << std::endl;
    return 0;
}