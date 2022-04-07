//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
#include <iostream>
#include <fstream>
#include <cstring>
#include "ReadUtils.h"
#include "ItemClass.h"
using namespace std;


Cat::Cat(){
    for (int index = 0; index < MAX_CHAR_SIZE; index++) {
  minLifeSpan = 0;
  maxLifeSpan = 0;
  minWeight = 0;
  maxWeight = 0;
  temperment = "";
  origin = "";
  validEntry = false;
}
  }

  int Cat::getMinWeight(){
    return minWeight;
  }

  void Cat::readCat(ifstream & inFile){
    inFile.get(catName, Cat::MAX_CHAR_SIZE, ';');
    inFile.ignore(100,';');

    inFile >> minLifeSpan;
    inFile.ignore(100,';');

    inFile >> maxLifeSpan;
    inFile.ignore(100,';');

    inFile >> minWeight;
    inFile.ignore(100,';');

    inFile >> maxWeight;
    inFile.ignore(100,';');

    inFile >> temperment;
    inFile.ignore(100,';');

    inFile >> origin;

    validEntry = !inFile.eof();
  }

// printCats prints all the information for a cat
void Cat::printCats(ostream &out){
    out << catName << ",";
    out << "Minimun Lifespan: " << minLifeSpan << ",";
    out << "Maximum Lifespan: " << maxLifeSpan << ",";
    out << "Minimum weight: " << minWeight << ",";
    out << "Maximum weight: " << maxWeight << ",";
    out << "Temperment: " << temperment << " ";
    out << "Country of origin: " << origin << endl;
    out << endl;
}


//addCat adds a cat to the array
void Cat::addCat(){
    cout << "Enter a cat name: ";
    cin >> catName;

    minLifeSpan = readInt("Enter minimum life span: ");
    maxLifeSpan = readInt("Enter max life span: ");
    minWeight = readInt("Enter minimum weight: ");
    maxWeight = readInt("Enter max weight: ");
  cout << ("Enter temperment: ");
    cin >> temperment;
  cout << ("Enter country of origin: ");
    cin >> origin;
  
    validEntry = true;
    }
