#include<iostream>
#include<iomanip>
#include "Customer.h"

using namespace std;

Customer::Customer(int id, float x, float y, float startTime, float endTime, float quantity, float serviceTime){
	this->id = id;
	this->x = x;
	this->y = y;
	this->startTime = startTime;
	this->endTime = endTime;
	this->quantity = quantity;
	this->serviceTime = serviceTime;
}

void Customer::setId(int id){
	this->id = id;
}

void Customer::setX(float x){
	this->x = x;
}

void Customer::setY(float y){
	this->y = y;
}

void Customer::setStartTime(float startTime){
	this->startTime = startTime;
}

void Customer::setEndTime(float endTime){
	this->endTime = endTime;
}

void Customer::setQuantity(float quantity){
	this->quantity = quantity;
}

void Customer::setServiceTime(float serviceTime){
	this->serviceTime = serviceTime;
}

void Customer::show(){
	cout<<setiosflags(ios_base::left)<<setw(6)<<id<<setw(6)<<x<<setw(6)<<
		y<<setw(12)<<startTime<<setw(12)<<endTime<<setw(12)<<quantity<<setw(14)<<serviceTime<<endl;
}