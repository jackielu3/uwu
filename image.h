#ifndef IMAGE_H_
#define IMAGE_H_

#include <fstream>
#include <string>
#include <vector>

enum class MagicNumber { kRawbits, kAscii, kFail };

// These are ints instead of chars to make it easier to scale
// the pixel values without hitting the bounds.
struct Pixel {
  int red;
  int green;
  int blue;
};

class Image {
 private:
  MagicNumber magic;                  // PPM format
  std::vector<std::string> comments;  // All comments
  int width;                          // image width
  int height;                         // image height
  int max_color;                      // maximum color value
  Pixel **pixels;                     // Acts as 2D array of pixels

  // Reads the magic number of PPM file.
  MagicNumber ReadMagic(std::ifstream &fppm);

 public:
  // Constructor
  Image(std::ifstream &fppm);

  // Destructor
  ~Image();

  // Transforms the image in place.
  void Convolve(double[3][3]);

  // Saves the image to a file.
  void Save(std::ofstream &fppm);
};

#endif  // IMAGE_H_
