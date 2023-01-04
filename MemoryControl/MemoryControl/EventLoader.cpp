#include "Headers/EventLoader.h"

#include <iostream>
#include <fstream>
#include <string>
#include <exception>

using namespace Chains;

struct EventLoader::impl {
	std::string events_file_name = "data.bin";

	std::ifstream file;

	impl() : file(events_file_name, std::ios::in | std::ios::binary) {
		if (!file.is_open()) {
			throw std::exception("Error: data.bin does not exist!");
		}
 	}

	Chains::Event readEvent() {
		uint16_t event_id = 0;
		uint64_t event_value = 0;
		uint8_t event_type = 0;

		file.read((char*) &event_type, sizeof(uint8_t));
		file.read((char*) &event_value, sizeof(uint64_t));
		file.read((char*) &event_id, sizeof(uint16_t));

		return Chains::Event(event_type, event_id, event_value);
	}
};


EventLoader::EventLoader() : pimpl(new impl()) {}

EventLoader::~EventLoader() = default;


std::vector<Chains::Event> EventLoader::getEvents() {

	std::vector<Chains::Event> events;

	while (!pimpl->file.eof()) {
		events.push_back(pimpl->readEvent());
	}

	return events;
}
