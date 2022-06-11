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
    void setIdMatkul(std::string matkulId);
    void setNamaMatkul(std::string matkulNama);
    std::string getIdMatkul();
    std::string getNamaMatkul();
};

#endif