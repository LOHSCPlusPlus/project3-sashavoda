#include "ItemClass.h"

class ItemDB{
private:

  enum {MAX_CATS = 100};
  Cat cats[MAX_CATS];
  int numCats;

public:
ItemDB();
int readCatData();
void printArrayToScreen();
void printArrayToFile(const char fileName[]);
void removeCat();
void addCat();
void insertCat();
void searchData();
void displayMenu();
};