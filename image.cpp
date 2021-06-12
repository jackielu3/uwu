#include "image.h"

#include <iostream>

#include <sstream>
#include <string>

using namespace std;

MagicNumber Image::ReadMagic(ifstream &fppm) {
  string MagicNumber;
  getline(fppm,MagicNumber);

  if (MagicNumber == "P6") {
    fprintf(stderr, "Not a valid File Type");

    return MagicNumber::kRawbits;
  }
  
  if (MagicNumber == "P3") {

    //return MagicNumber::kAscii;
    return MagicNumber::kFail;
  }
  fprintf(stderr, "Not a valid File Type");

  return MagicNumber::kFail;
}

Image::Image(ifstream &fppm) {
  ofstream outFile ("final_image.ppm");
  
  string line = "";
  string pixelLine = "";

  //Magic number
  getline(fppm, line); 
//  Image::Save(outFile, line);
  //cout << line << endl;
  
  //Comments
  getline(fppm, line); 
//  Image::Save(outFile, line);
  //cout << line << endl;

  //Size
  getline(fppm, line);
//  Image::Save(outFile, line);
  //cout << line << endl;


  while (fppm >> line) {
    pixelLine = line + " ";
    for (int i = 0; i < 3; i++) {
      getline(fppm, line);
      pixelLine += line + " ";
    }
//    Image::Save(outFile, pixelLine);
  }

}

//  string 

  void Save(std::ofstream &fppm) {
//    fppm;
  }


Pixel Scale(double scale, const Pixel &b) {
  Pixel r;
  r.red = scale * b.red;
  r.green = scale * b.green;
  r.blue = scale * b.blue;
  return r;
}

void Image::Convolve(double kernel[3][3]) {
  // TODO
}

Image::~Image() {
  // TODO
}
