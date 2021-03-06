#include <iostream>
#include <vector>
#include "include/mahasiswa.hpp"


mahasiswa::mahasiswa(std::string id, std::string nama, int dd, int mm, int yy, 
				std::string NRP, std::string departemen, int tahunmasuk)
		: person(id, nama, dd, mm, yy), NRP(NRP), departemen(departemen), tahunmasuk(tahunmasuk)
{
	this->ipk = 0.0;
	this->ips = std::vector<float>(14,0);
}

void mahasiswa::setSemester(int semesterke)
{
	this->semesterke = semesterke;
}

int mahasiswa::getSemester()
{
	return this->semesterke;
}

void mahasiswa::setSKSLulus(int skslulus)
{
	this->skslulus = skslulus;
}

int mahasiswa::getSKSLulus()
{
	return this->skslulus;
}

void mahasiswa::hitungIPK()
{
}

// void mahasiswa::setTahunMasuk(int tahunmasuk)
// {
//     this->tahunmasuk = tahunmasuk;
// }

void mahasiswa::setIPS(int semester, float ips)
{
	// semester mulai dari 1
	if (semester < 15) {
		this->ips[semester-1] = ips;
	}
}

float mahasiswa::getIPS(int semester)
{
	if (semester < 15)
		return this->ips[semester-1];

	return -1.0;
}

std::vector<float> mahasiswa::getAllIPS()
{
	return this->ips;
}

std::string mahasiswa::getNRP(){
	return this->NRP;
}
std::string mahasiswa::getDepartment(){
	return this->departemen;
}


