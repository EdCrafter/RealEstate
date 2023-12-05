#pragma once
#include "Array.h"
#include "String.h"
class Address
{
	struct city
	{
		ASD::String name;
		ASD::Array<ASD::String> streets;
	};
	ASD::Array<city> cities;
public:
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
				streetsR.Add(cities[i].streets);
				break;
			}
			i++;
		}
		return streetsR;
	}	
	Address& addAddress(ASD::String cityIn, ASD::Array<ASD::String> streetsIn) {
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
			city newCity;
			newCity.name = cityIn;
			newCity.streets = streetsIn;
			cities.Add(newCity);
		}
		return *this;
	}
};

