#pragma once
#include"Observer.h"
class Subject
{
public:

	virtual void RegisterObserver(Observer* pObserver) = 0;

	virtual void RemoveObserver(Observer* pObserver) = 0;

	virtual void NotifyObservers() = 0;
	virtual ~Subject()=default;
};