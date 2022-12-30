#include <vector>
#include <cstdint>
#include <memory>

#include "Event.h"

class Loader {

public:

	Loader();
	~Loader();

	std::vector<CHAINS::Event>* getEvents();

private:
	struct impl;
	std::unique_ptr<impl> pimpl;
};