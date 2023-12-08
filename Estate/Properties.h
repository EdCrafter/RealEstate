#pragma once
#include "Array.h"
#include "String.h"
#include "Address.h"
#include "Users.h"
class Properties
{
public:
    struct PropertyData
    {
        Address address;
        unsigned int countRooms;
        unsigned int price;
        unsigned int type;
        bool forRent;
        unsigned int houseNumber;
        int floorNumber;
        User* user;

        // Default constructor to initialize user to nullptr
        PropertyData() : user(nullptr),address("DefaultStreet", "DefaultCity"),countRooms(),price(),type(),forRent(),houseNumber(),floorNumber() {}
        PropertyData(const PropertyData& other)
            : address(other.address),
            countRooms(other.countRooms),
            price(other.price),
            type(other.type),
            forRent(other.forRent),
            houseNumber(other.houseNumber),
            floorNumber(other.floorNumber),
            user(other.user)  // Assuming User is copyable, adjust if needed
        {
        }
        PropertyData(Address addr,
            unsigned int countRms,
            unsigned int p,
            unsigned int t,
            bool rent,
            unsigned int houseNum,
            int floorNum,
            User* usr)
            : address(addr),
            countRooms(countRms),
            price(p),
            type(t),
            forRent(rent),
            houseNumber(houseNum),
            floorNumber(floorNum),
            user(usr)
        {
        }
        void toString() {
            address.toString();
            std::cout << "Count rooms  = " << countRooms << "\n";
            std::cout << "Price        = " << price << "\n";
            std::cout << "Type         = " << type << "\n";
            std::cout << "For Rent     = " << forRent << "\n";
            std::cout << "House Number = " << houseNumber << "\n";
            std::cout << "Floor Number = " << floorNumber << "\n";
            user->toString();
        }
    };
private:
    ASD::Array<PropertyData> properties;

public:
    Properties& add(Address address,
        unsigned int countRooms,
        unsigned int price,
        unsigned int type,
        bool forRent,
        unsigned int houseNumber,
        int floorNumber,
        User* user)
    {
        PropertyData newProperty(address, countRooms, price, type, forRent, houseNumber, floorNumber, user);
        properties.Add(newProperty);
        return *this;
    }
    ASD::Array<PropertyData> getProperties() {
        return properties;
    }
    PropertyData getProperty(int i) {
        return properties[i];
    }
    void remove(unsigned int i) {
        properties.RemoveAt(i);
    }
    void toString() {
        for (int i = 0; i < properties.GetCount(); i++) {
            std::cout << "Property id = " << i << "\n";
            properties[i].toString();
            std::cout << "\n";
        }
    }
};


