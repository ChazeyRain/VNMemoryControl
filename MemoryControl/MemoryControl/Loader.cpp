#include "Headers/Loader.h"

#include <iostream>
#include <fstream>
#include <string>


struct Loader::impl {
	
	std::string events_file_name = "data.bin";
};


Loader::Loader() : pimpl(new impl()) {}

Loader::~Loader() = default;


std::vector<CHAINS::Event>* Loader::getEvents() {

	std::ifstream file (pimpl->events_file_name, std::ios::in | std::ios::binary);

	std::vector<CHAINS::Event>* events = new std::vector<CHAINS::Event>;


	uint16_t event_id = 0;
	uint64_t event_value = 0;
	uint8_t event_type = 0;

	
	file.read((char*)event_id, sizeof(event_id));
	file.read((char*)event_value, sizeof(event_value));
	file.read((char*)event_type, sizeof(event_type));

	CHAINS::Event* ev = new CHAINS::Event(event_type, event_id, event_type);;

	return nullptr;
}
