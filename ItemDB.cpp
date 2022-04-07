#include "ItemDB.h"
#include <iostream>
#include "ReadUtils.h"

ItemDB::ItemDB(){
  numCats = 0;
  readCatData();
  }
int ItemDB::readCatData(){
  ifstream catFile("cats.txt");
 numCats = 0;
while(catFile.peek() != EOF && numCats < MAX_CATS){
  
  cats[numCats].readCat(catFile);
  numCats++;
}
  return numCats;
}

void ItemDB::printArrayToScreen() {
  cout << numCats << endl;
    for (int index = 0; index < numCats; index++) {
        cout << "Index " << index << ": ";
        cats[index].printCats(cout);
    }
}

void ItemDB::printArrayToFile(const char fileName[]) {
    ofstream outFile(fileName);
    for (int index = 0; index < numCats; index++) {
        cats[index].printCats(outFile);
    }
}
// removeCat removes a cat from the array
void ItemDB::removeCat(){
  int numRemove = -1;
  while((numRemove < 0) || (numRemove > 57)){
  numRemove = readInt("Enter a number between 0 and 57: ");
  }
 for(int index = numRemove; index < 56; index++){
   cats[index] = cats[index + 1];
 }
  numCats--;
}

void ItemDB::addCat(){
  cats[numCats].addCat();
  numCats++;
}

void ItemDB::searchData(){
  int option ;
    cout << "Enter a number to search by cat weight: "; 
  cin >> option;
  
for(int i = 0; i < MAX_CATS; i++){
 if(cats[i].getMinWeight() == option){
  cats[i].printCats(cout);
   
}
}
}

// displayMenu displays all the options the user can choose
void ItemDB::displayMenu(){
  char option;
  while(option != 'q'){
    cout << "Press 'l' to list, 'r' or 'a' to remove or add or remove a cat, 's' to search database, 'f' to save to file, 'd' to discard any changes,  or 'q' to quit: ";
    cin >> option;
{
if(option == 'r'){
  removeCat();
}
if(option == 'a'){
  addCat();
}
if(option == 'l'){
  printArrayToScreen();
}
if(option == 's'){
  searchData();
}
if(option == 'f'){
  printArrayToFile("example.txt");
}
if(option == 'd'){
  numCats = readCatData();
}
  }
}
  } 