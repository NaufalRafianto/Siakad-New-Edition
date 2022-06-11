#ifndef __MATKUL_HPP__
#define __MATKUL_HPP__

#include <iostream>
class matkul
{
private:
    std::string idMatkul, namaMatkul;

public:
    matkul();
    matkul(std::string matkulId, std::string matkulNama);
    void setId(std::string matkulId);
    void setNama(std::string matkulNama);
    std::string getId();
    std::string getNama();
};

#endif