#include "Bitmap/bitmap.h"
#include <iostream>
#include <vector>

using namespace std;

//argc - number of arguments in command
//argv - each argument word, stored in an array
int main(int argc, char* argv[])
{
  Pixel color;       
  string filename;
  filename=argv[1];
  Bitmap image;
  image.open(filename);
  if (argc == 2){
    if(!image.isImage()){
      cout<< "Image file must be a bitmap wth 24-bit color depth.\n";
    }
  else if (image.isImage()) { 
    vector <vector <Pixel> > imagePixels = image.toPixelMatrix();

    cout<< filename << " is "<<imagePixels.size()<<
           " pixels high and "<<imagePixels[0].size() << endl;
    for(int height=0;height<imagePixels.size();height++){
      for(int width=0;width<imagePixels[0].size();width++){
        color = imagePixels[height][width];
        color.green=0;
        color.blue=0;
        imagePixels[height][width]=color;
      }
    }
    image.fromPixelMatrix( imagePixels );
    image.save("redness.bmp");

  }

  }
  else {
    cout <<" Please specify one image file!\n";
  }
  return 0;
}
