#pragma once
#include "SearchAlgorithm.h"
class WithIndex :
	public SearchAlgorithm
{
public:
	WithIndex() {}
	~WithIndex() {}

	virtual void buildIndex() = 0;
};

