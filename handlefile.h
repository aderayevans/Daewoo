#ifndef HANDLEFILE_H
#define HANDLEFILE_H

#include "string"

class HandleFile
{
public:
    template <class OBJECTFILE>
    static OBJECTFILE read_file(std::string);
    
    template <class OBJECTFILE>
    static void write_file(std::string, OBJECTFILE);
private:

};

#endif