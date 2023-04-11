// radio_propt.cpp : Defines the entry point for the application.
//
#include "radio_propt.h"


int main() {
		srand(time(NULL));

	std::vector<std::string> message = {
		"Stan na drodze Noxus, a posmakujesz własnej\a      ",
		"",
		"",
		"Tylko ja poprowadzę nas do zwycięstwa.\a           ",
		"Noxus powstanie\a                                  ",
		""
	};

	Loop wiadomosc;
	wiadomosc.addMessages(message);
	wiadomosc.display();
	std::cout << "message_2\n";
	wiadomosc.cipher(3);
	wiadomosc.display();
	
	//std::cout << "a";
	return 0;
}