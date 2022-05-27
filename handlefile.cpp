#include <iostream>
#include <fstream>

#include "handlefile.h"



template <class OBJECTFILE>
OBJECTFILE HandleFile::read_file(std::string filename)
{
    std::ifstream ifs;
    ifs.open(filename);

    OBJECTFILE obj;

    ifs >> obj;

    // ifs.read((char*)&obj, sizeof(obj));
    
    // while (!ifs.eof()) {
    //     ifs.read((char*)&obj, sizeof(obj));
    // }
    ifs.close();
    std::cout << "Read file succeeded!!!" << std::endl;
    return obj;
}

template <class OBJECTFILE>
std::vector<OBJECTFILE> HandleFile::read_file_multiple_obj(std::string filename)
{
    std::ifstream ifs;
    ifs.open(filename);

    std::vector<OBJECTFILE> objs;
    OBJECTFILE obj;
    while (ifs >> obj)
    {
        obj.print();
        objs.push_back(obj);
    }
    std::cout << objs.size() << std::endl;
    ifs.close();
    std::cout << "Read file succeeded!!!" << std::endl;
    return objs;
}
    
template <class OBJECTFILE>
void HandleFile::write_file(std::string filename, OBJECTFILE obj, bool app)
{
    std::ofstream ofs;
    if (app)
        ofs.open(filename, std::ios_base::app);
    else    
        ofs.open(filename);

    ofs << obj;
    ofs.close();
    std::cout << "Write file succeeded!!!" << std::endl;
    // ofs.write((char*)&obj, sizeof(obj));
}

