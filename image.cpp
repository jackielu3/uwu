#include "image.h"

#include <iostream>

#include <sstream>
#include <string>

using namespace std;

string _line;

MagicNumber Image::ReadMagic(ifstream &fppm) {
  string MagicNumber;
  getline(fppm,MagicNumber);

  if (MagicNumber == "P6") {

    return MagicNumber::kRawbits;
  }
  
  if (MagicNumber == "P3") {
    fprintf(stderr, "Not a valid File Type");

    //return MagicNumber::kAscii;
    return MagicNumber::kFail;
  }
  fprintf(stderr, "Not a valid File Type");

  return MagicNumber::kFail;
}

Image::Image(ifstream &fppm) {
  ofstream outFile ("final_image.ppm");
  
  string pixelLine = "";
  _line = "";

  //Magic number
  getline(fppm, _line);
  Image::Save(outFile);
  //cout << line << endl;
  
  //Comments
  getline(fppm, _line);
  Image::Save(outFile);
  //cout << line << endl;

  //Size
  getline(fppm, _line);
  Image::Save(outFile);
  //cout << line << endl;

  string line = _line;
  
  while (fppm >> line) {
    pixelLine = line + " ";
    for (int i = 0; i < 3; i++) {
      getline(fppm, line);
      pixelLine += line + " ";
    }
    _line = pixelLine;
    Image::Save(outFile);    
  }
}

  void Image::Save(std::ofstream &fppm) {
    fppm << _line << endl;
  }
  


Pixel Scale(double scale, const Pixel &b) {
  Pixel r;
  r.red = scale * b.red;
  r.green = scale * b.green;
  r.blue = scale * b.blue;
  return r;
}

void Image::Convolve(double kernel[3][3]) {
  ifstream file ("sled_dog_ascii.ppm");
  file.clear();
  file.seekg (0, ios::beg);

  ofstream outFile ("convolution.ppm");
  
  _line = "";
  string line = "";
  string pixelLine = "";
  stringstream ss;
  int lineInt = 0;
  double lineDou = 0.0;
  
  //The same as constructor function but the for loop adds the kernal thingys
  
  getline(file, _line);
  Image::Save(outFile);
  
  //Comments
  getline(file, _line);
  Image::Save(outFile);

  //Size
  getline(file, _line);
  Image::Save(outFile);

  line = _line;
  
  while (file >> line) {
    for (int i = 0; i < 3; i++) {
      pixelLine = line + " ";
      for (int j = 0; j < 3; j++) {
        getline(file, line);
        
        cout << line << endl;
        /*
        //string to int
        ss << line;
        ss >> lineInt;
        lineDou = (lineInt * 1.0) * kernel[i][j];
        
        lineInt = int(lineDou);
        cout << line << endl;
        */

        pixelLine += lineInt + " ";
      }
      _line = pixelLine;
      Image::Save(outFile);
    }
    
    Image::Save(outFile);
    file.close();
  }
}

Image::~Image() {
  _line = "";
}
