#ifndef __MAHASISWA_HPP__
#define __MAHASISWA_HPP__


#include <iostream>
#include "include/person.hpp"

class mahasiswa : public person {
private:
	std::string NRP;
	std::string departemen;
	int tahunmasuk;
	int semesterke;
	int skslulus;
	float ipk;
	std::vector<float> ips;

public:
	mahasiswa(std::string id, std::string nama, int dd, int mm, int yy,
					std::string nrp, std::string departemen, int tahunmasuk);

	void setSemester(int semesterke);
	int getSemester();

	void setTahunMasuk(int tahunmasuk);
    int getTahunMasuk();


	void setSKSLulus(int skslulus);
	int getSKSLulus();

	std::string getNRP();
	std::string getDepartment();

	void hitungIPK();

	void setIPS(int semester, float ips);
	float getIPS(int semester);
	std::vector<float> getAllIPS();
};

void mahasiswa::setTahunMasuk(int tahunmasuk){
	this->tahunmasuk = tahunmasuk;
}
int mahasiswa::getTahunMasuk(){
	return this->tahunmasuk;
}

#endif