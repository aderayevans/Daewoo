#ifndef HANDLEFILE_H
#define HANDLEFILE_H

#include "string"
#include <vector>

class HandleFile
{
public:
    template <class OBJECTFILE>
    static OBJECTFILE read_file(std::string);
    
    template <class OBJECTFILE>
    static void write_file(std::string, OBJECTFILE, bool app=false);
    
    template <class OBJECTFILE>
    static std::vector<OBJECTFILE> read_file_multiple_obj(std::string);

private:

};

#endif