#ifndef HANDLEFILE_H
#define HANDLEFILE_H

#include "string"

class HandleFile
{
public:
    template <class OBJECTFILE>
    OBJECTFILE read_file(std::string);
    
    template <class OBJECTFILE>
    void write_file(std::string, OBJECTFILE);
private:

};

#endif