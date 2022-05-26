#ifndef HANDLEFILE_H
#define HANDLEFILE_H

#include "string"

class HandleFile
{
public:
    template <>
    void read_file(std::string);
    void write_file(std::string);
private:

};

#endif