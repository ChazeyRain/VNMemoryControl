#ifndef EVENT_LOADER_H
#define EVENT_LOADER_H

#include <vector>
#include <cstdint>
#include <memory>

#include "Event.h"

namespace Chains {

	class EventLoader {

	public:

		EventLoader();
		~EventLoader();

		std::vector<Chains::Event> getEvents();

	private:
		struct impl;
		std::unique_ptr<impl> pimpl;
	};
}

#endif