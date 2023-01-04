#ifndef EVENT_SAVER_H
#define EVENT_SAVER_H

#include "Event.h"

#include <memory>
#include <vector>

namespace Chains {
	class EventSaver {
	public:
		EventSaver();
		EventSaver(const EventSaver& other);
		EventSaver& operator = (EventSaver rhs);
		~EventSaver();
		
		//void saveEvent(Chains::Event ev);
	
		void saveEvents(std::vector<Chains::Event> events);

	private:
		struct impl;
		std::unique_ptr<impl> pimpl;
	};
}

#endif