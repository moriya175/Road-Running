#pragma once
class Observer
{
public:
	virtual ~Observer()=default;
	virtual void Update(int total_coins,int live) = 0;
};