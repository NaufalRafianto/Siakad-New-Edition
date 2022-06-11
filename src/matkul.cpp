#include <iostream>
#include <vector>
#include "include/matkul.hpp"

matkul::matkul() {}
matkul::matkul(std::string matkulId, std::string matkulNama)
    : idMatkul(matkulId), namaMatkul(matkulNama) {}

void matkul::setIdMatkul(std::string matkulId)
{
    this->idMatkul = matkulId;
}
std::string matkul::getIdMatkul()
{
    return this->idMatkul;
}

void matkul::setNamaMatkul(std::string matkulNama)
{
    this->namaMatkul = matkulNama;
}
std::string matkul::getNamaMatkul()
{
    return this->namaMatkul;
}