#include <fstream>
#include <iostream>
#include <string>

#include "image.h"

using namespace std;

int main(int argc, char *argv[]) {
  if (argc < 4) {
    fprintf(stderr, "Usage: input output filter1 [filter2 filter3 ...]\n");
    return EXIT_FAILURE;
  }

  double identity[3][3] = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
  double blur[3][3] = {
      {0.0625, 0.125, 0.0625}, {0.125, 0.25, 0.125}, {0.0625, 0.125, .0625}};
  // TODO: edges
  // TODO: emboss
  // TODO: sharpen

  // TODO: Use image class to read, transform, and save the image.
  int err = EXIT_SUCCESS;

  return err;
}
