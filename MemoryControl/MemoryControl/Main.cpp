#include <iostream>

#include "Headers/EventLoader.h"
#include "Headers/EventSaver.h"

#include <vector>
#include "Event.h"

void run();
void save();
void load();


int main() {
	
	try {
		run();
	}
	catch (std::exception e) {
		std::cout << e.what();
	}

	return 0;
}

void run() {
	save();
	load();
}

void save() {
	Chains::EventSaver saver;
	std::vector<Chains::Event> events;
	events.push_back(Chains::Event(65, 1, 650));
	events.push_back(Chains::Event(255, 2, 500));
	saver.saveEvents(events);
}

void load() {
	Chains::EventLoader l;

	std::vector<Chains::Event> eventss = l.getEvents();

	for (Chains::Event ev : eventss) {
		std::cout << "Event type = " << (int) ev.getEventType() << " || " << "Event value = " << ev.getEventValue() << " || " << "Event id = " << ev.getNextEvent() << std::endl;
	}
}