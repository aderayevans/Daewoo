#include <iostream>
#include <fstream>

#include "handlefile.h"



template <class OBJECTFILE>
OBJECTFILE HandleFile::read_file(std::string filename)
{
    std::ifstream ifs;
    ifs.open(filename, std::ios::in);

    OBJECTFILE obj;

    ifs.read((char*)&obj, sizeof(obj));
    return obj;
}
    
template <class OBJECTFILE>
void HandleFile::write_file(std::string filename, OBJECTFILE obj)
{
    std::ofstream ofs;
    ofs.open(filename, std::ios::app);
    ofs.write((char*)&obj, sizeof(obj));

}

