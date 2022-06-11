#include <iostream>
#include <vector>
#include "include/matkul.hpp"

matkul::matkul() {}
matkul::matkul(std::string matkulId, std::string matkulNama)
    : idMatkul(matkulId), namaMatkul(matkulNama) {}

void matkul::setId(std::string matkulId)
{
    this->idMatkul = matkulId;
}
std::string matkul::getId()
{
    return this->idMatkul;
}

void matkul::setNama(std::string matkulNama)
{
    this->namaMatkul = matkulNama;
}
std::string matkul::getNama()
{
    return this->namaMatkul;
}