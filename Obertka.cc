#include <iostream>
#include <FreeImage.h>
#include <string>

//using namespace std

/*
 Работа с изображением
*/

const int ImageFormatsCount = 4;

const std::string ImageFormats [ImageFormatsCount] =
{
	"bmp",
	"ico",
	"jpeg",
	"jng"
};

class ImageClass{
private:
	FIBITMAP* img;
	const char *fileName;
	FREE_IMAGE_FORMAT fiF;	
public:
	ImageClass(FREE_IMAGE_FORMAT fif, const char *filename){
		std::cout << "Constuctor is used.\n";
		FreeImage_Initialise();
		fileName = filename;
		fiF = fif;
		img = FreeImage_Load(fif, filename, JPEG_DEFAULT);
	}
	
	void Convert(FREE_IMAGE_FORMAT fifConv){
		//char tempConv = fileName + ".png";
		FreeImage_Save(fifConv, img, "two.png", 0);
	}
	
	void ShowFileName(){
		std::cout << "File name: " << fileName << "\n";
	}
	
	void ShowFileType(){
		std::cout << "File type: " << ImageFormats[fiF] << "\n";
	}
		
	~ImageClass(){
		std::cout << "Destructor is used.\n";
		FreeImage_Unload(img);
		FreeImage_DeInitialise();
	}
};

int main(int argc, char **argv) {
	ImageClass img = ImageClass(FIF_JPEG,"one.jpeg");
	img.ShowFileName();
	img.ShowFileType();
	img.Convert(FIF_PNG);
  return 0;
}






























  /*FreeImage_Initialise();
  //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  	FIBITMAP *one = FreeImage_Load(FIF_JPEG,"one.jpeg", JPEG_DEFAULT);
  
  	unsigned int img_w = FreeImage_GetWidth(one);
	unsigned int img_h = FreeImage_GetHeight(one);
	
	std::cout << "For one.jpeg w: " << img_w << " h:" << img_h << "\n";
	//std::cout << img_h;
  
  	FIBITMAP *two = FreeImage_ConvertTo8Bits(one);
  
  	FreeImage_Save(FIF_PNG, two, "two.png", 0);
  
  	FIBITMAP *clone = FreeImage_Clone(one);
  	FreeImage_Save(FIF_PNG, clone, "clone.png", 0);
  
  	FreeImage_Unload(one);
  //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  FreeImage_DeInitialise();*/
  
  /*void ConvertImg(FIBITMAP* imgT, FREE_IMAGE_FORMAT fif){
		//FreeImage_Save(FIF_PNG, two, "two.png", 0);
	}*/


