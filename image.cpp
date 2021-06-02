#include "image.h"

#include <sstream>
#include <string>

using namespace std;

MagicNumber Image::ReadMagic(ifstream &fppm) {
  // TODO

  return MagicNumber::kFail;
}

Image::Image(ifstream &fppm) {
  // TODO
}

void Image::Save(ofstream &oppm) {
  // TODO
}

// Might be helpful
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
