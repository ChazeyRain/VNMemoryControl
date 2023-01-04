#include "Headers/EventSaver.h"

#include <string>
#include <fstream>

struct Chains::EventSaver::impl {
	std::string event_file_name;

	std::fstream out;

	impl(std::string event_file_name) : out(std::fstream(event_file_name, std::ios::in | std::ios::out | std::ios::binary)) {
		this->event_file_name = event_file_name;
	};
	
	~impl() {
		out.flush();
		out.close();
	}

	void saveEvent(Chains::Event ev) {

		uint8_t event_type = ev.getEventType();
		uint64_t event_value = ev.getEventValue();
		uint16_t event_id = ev.getNextEvent();

		out.write((char*) &event_type, sizeof(uint8_t));
		out.write((char*) &event_value, sizeof(uint64_t));
		out.write((char*) &event_id, sizeof(uint16_t));

	}
};

Chains::EventSaver::EventSaver() : pimpl(new impl("data.bin")) {};

Chains::EventSaver::EventSaver(const EventSaver& other){
	
}

Chains::EventSaver& Chains::EventSaver::operator=(EventSaver rhs)
{
	// TODO: insert return statement here
	std::swap(rhs, *this);
	return *this;
}

Chains::EventSaver::~EventSaver() = default;

void Chains::EventSaver::saveEvents(std::vector<Chains::Event> events) {
	for (Chains::Event ev : events) {
		pimpl->saveEvent(ev);
	}
}

