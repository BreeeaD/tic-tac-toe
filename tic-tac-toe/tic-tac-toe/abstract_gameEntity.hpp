#pragma once
#include <iostream>

class abstract_gameEntity {
public: 
	virtual void Display() const = 0; //metoda virtuala
	virtual ~abstract_gameEntity() = default; //destructor
};