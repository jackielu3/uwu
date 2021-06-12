#include "image.h"

#include <iostream>

#include <sstream>
#include <string>

using namespace std;

int main() {
  ifstream fppm ("sled_dog_ascii.ppm");

  ofstream outFile ("final_image.ppm");
  
  string line = "";
  string pixelLine = "";

  //Magic number
  getline(fppm, line); 
  //Image::Save(outFile, line);
  cout << line << endl;
  
  //Comments
  getline(fppm, line); 
  //Image::Save(outFile, line);
  cout << line << endl;

  //Size
  getline(fppm, line);
  //Image::Save(outFile, line);
  cout << line << endl;


  while (fppm >> line) {
    pixelLine = line + " ";
    for (int i = 0; i < 3; i++) {
      getline(fppm, line);
      pixelLine += line + " ";
    }
//    Image::Save(outFile, pixelLine);
  }

}











/*
int main() {
  ifstream fppm ("sled_dog_ascii.ppm");

  string line = "";
  char ch;
  getline(fppm, line);
  int fileLength = 0;
  int heading = 0;
  int stringToInt = 0;

  fppm.clear();
  fppm.seekg (0, ios::beg);

  while (fppm) {
    fileLength++;
    fppm.get(ch);
  }
  
  cout << "uwu" << endl;

  fppm.clear();
  fppm.seekg (0, ios::beg);

  while (line[0] == '#') {
    getline(fppm, line);
    heading++;
    cout << line << endl;
  }

  cout << "uwu" << endl;
  cout << heading << endl;

  int fullPixelLength = (fileLength - heading) / 3;\
  cout << fullPixelLength << endl;

  int pixelArray[fullPixelLength][3];
  cout << "uwu" << endl;


  for (int i = 0; i < ((fileLength - heading) / 3); i += 3) {
    for (int j = 0; j < 3; j++) {
      getline(fppm, line);
      stringToInt = stoi(line);
      pixelArray[i][j] = stringToInt;
      cout << stringToInt << endl;
    }
  }

  cout << pixelArray << endl;
  return(0);
}
*/