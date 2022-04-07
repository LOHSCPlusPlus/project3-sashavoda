#include <fstream>
using namespace std;

class Cat{
private:

  enum {MAX_CHAR_SIZE = 100};
  char catName[MAX_CHAR_SIZE];
  int minLifeSpan;
  int maxLifeSpan;
  int minWeight;
  int maxWeight;
  string temperment;
  string origin;
  bool validEntry;

public:
Cat();
int getMinWeight();
void readCat(ifstream & inFile);
void printCats(ostream &out);
void addCat();
};