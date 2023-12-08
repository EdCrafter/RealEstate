#pragma once
#include "Array.h"
#include "String.h"
class Addresses
{
	class City
	{
	public:
		ASD::String name;
		ASD::Array<ASD::String> streets;
		City& operator = (City& other) {
			name = other.name;
			streets = other.streets;
			return *this;
		}
		void toString() {
			std::cout << "name    = " << name << "\n";
			for (int i = 0; i < streets.GetCount(); i++) {
				std::cout << "street("<<i<<")=" << streets[i] << "\n";
			}
		}
	};
	ASD::Array<City> cities;
public:
	Addresses() : cities() {}
	Addresses(ASD::Array<City> cities) {
		this->cities = cities;
	}
	Addresses(Addresses& other) {
		cities = other.cities;
	}
	Addresses& operator = (Addresses& other) {
		cities = other.cities;
		return *this;
	}
	ASD::Array<ASD::String> getCitiesName() {
		ASD::Array<ASD::String> citiesName;
		int i = 0;
		while (i < cities.GetCount()) {
			citiesName.Add(cities[i].name);
			i++;
		}
		return citiesName;
	}
	ASD::Array<ASD::String> getCityStreets(ASD::String cityIn) {
		ASD::Array<ASD::String> streetsR;
		int i = 0;
		while (i < cities.GetCount()) {
			if (cityIn == cities[i].name) {
				streetsR=cities[i].streets;
				break;
			}
			i++;
		}
		return streetsR;
	}	
	Addresses& addAddress(ASD::String cityIn, ASD::Array<ASD::String> streetsIn) {
		int i = 0,j,k,repeat;
		int in = 0;
		while (i < cities.GetCount()) {
			if (cityIn == cities[i].name) {
				in = 1;
				j = 0;
				while (j < streetsIn.GetCount()) {
					repeat = 0;
					k = 0;
					while (k < cities[i].streets.GetCount()) {
						if (streetsIn[j] == cities[i].streets[k]) {
							repeat = 1;
							break;
						}
						k++;
					}
					if (!repeat) {
						cities[i].streets.Add(streetsIn[j]);
					}
					j++;
				}
			}
			i++;
		}
		if (!in) {
			
			City newCity;
			newCity.name = cityIn;
			newCity.streets = streetsIn;
			cities.Add(newCity);
		}
		return *this;
	}
	void toString() {
		for (int i = 0; i < cities.GetCount(); i++) {
			std::cout << "City id = " << i << "\n";
			cities[i].toString();
			std::cout << "\n";
		}
	}
};

class Address {
	ASD::String name;
	ASD::String street;
public:
	Address(const Address& other) {
		name = other.name;
		street = other.street;
	}
	Address (ASD::String name,ASD::String street) {
		this->name = name;
		this->street = street;
	}
	Address& set(ASD::String name,ASD::String street) {
		this->name = name;
		this->street = street;
	}
	void toString() {
		std::cout << "name   = " << name << "\n";
		std::cout << "street = " << street << "\n";
	}
};