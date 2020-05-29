#pragma once
#include<fstream>
#include<conio.h>
#include<string.h>
#include<iomanip>
#include<iostream>

using namespace std;

class Human             // Class
{
private:
    char name[30];    // encapsulation
    char address[50];
    char phone[10];
    int room_number;
public:
    char* getName()   //encapsulation
    {
        return name;
    }   
    char* getAddress()
    {
        return address;
    }
    char* getPhone()
    {
        return phone;
    }
    int   getRoomNum() 
    { 
        return room_number; 
    }

    void setname()      //encapsulation
    {
        cout << "Enter your Name : ";
        cin.ignore(); cin.getline(name, 25);
    }
    void setaddress()
    {
        cout << "Enter your Adress : ";
        cin.getline(address, 25);
    }
    void setphone()
    {
        cout << "Enter your Phone : ";
        cin.getline(phone, 25);
    }
    void setRoomNum() 
    {
        cout << "Enter your Room Number : ";
        cin >> room_number;
    }

    virtual void ShowCutomerInfo() {};      //// polymorphism

};

class user : public Human   //inheritance
{

public:
    int ID;
    float balance;
    int num_of_day;

    void show(int &i);

    void Add();

    void Edit();


    void ShowCutomerInfo();     //// polymorphism
};

class admin : public Human
{
private:
    char user_name[20];
    int pass;

public:
    void showAllCust();

    void DeletCust();

    bool login();

    void ShowCutomerInfo();     // polymorphism

};