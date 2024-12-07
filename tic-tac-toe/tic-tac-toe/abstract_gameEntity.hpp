#pragma once
#include <iostream>
/// <summary>
/// The abstract interface for all entities in the game.
/// </summary>
class abstract_gameEntity {
public: 
	/// <summary>
	/// Displays the entity representation.
	/// </summary>
	virtual void Display() const = 0; 

	/// <summary>
	/// Virtual destructor for proper memory management.
	/// </summary>
	virtual ~abstract_gameEntity() = default; 
};