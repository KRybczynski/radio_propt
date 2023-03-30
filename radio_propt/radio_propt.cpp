// radio_propt.cpp : Defines the entry point for the application.
//

#include "radio_propt.h"


enum Bound { Down = 0, Up = 1 };

/*
void corruptMessage(std::string msg, int n){
    vect = std::abs((msg.size() - n))
    for(int i = rand() %(msg.size() - n); i++){

    }
}
*/

int cipher(std::string* message, int n) {
  for (int i = 0; i < n; i++) {
    int bound[2];
    bound[0] = 0;
    bound[1] = 1;
    bool no_up = false, no_down = false;

    //int up = i + 1, down = i - 1;

    if (message[i] != "")
      continue;

    for (bound[Up] = i + 1; bound[Up] < n; bound[Up]++) {
      if (message[Up] != "")
        break;
    }

    for (bound[Down] = i - 1; bound[Down] > 0; bound[Down]--) {
      if (message[Down] != "")
        break;
    }


    if (bound[Down] < 0)
      no_down = true;
    if (bound[Up] > n)
      no_up = true;

    printf("%d %d\n", bound[Up], bound[Down]);
    if (bound[Up] < n) {
      message[i] = message[bound[Up]];
    }

  }
  return 1;

}
void printMess(std::string* message, int n) {
  std::srand(time(0));
  for (int i = 0; i < n; i++) {
    std::cout << message[i] << " " << std::endl;
  }
}


int main() {
  srand(time(NULL));
  int n = 6;
  std::string message[] = {
      "Stan na drodze Noxus, a posmakujesz własnej krwi.",
      "",
      "Mój cel jest jasny",
      "",
      "Wykorzystać ich słabość",
      "" };

  //cipher(message, n);
  //printMess(message, n);
  Loop wiadomosc;
  for (int i = 0; i < 5; i++) wiadomosc.add(message[i]);
  wiadomosc.display();
  std::cout << "message_2\n";
  wiadomosc.cipher(3);
  wiadomosc.display();

  return 1;
}