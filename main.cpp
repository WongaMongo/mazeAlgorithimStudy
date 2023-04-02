


// Christopher Wong
// Just trying to get it to take in a picture.


#include <iostream>

// Trying out the stb_image library. From: https://github.com/nothings/stb

/* Learning it from these 
        https://www.youtube.com/watch?v=1OyQoPCp46o
        https://www.youtube.com/watch?v=028GNYC32Rg&list=PLG5M8QIx5lkzdGkdYQeeCK__As6sI2tOY&index=1
*/
#define STB_IMAGE_IMPLEMENTATION
#include "./stb_image/stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "./stb_image/stb_image_write.h"

int main(int argc, char* argv[]){    
    if(argc < 2) {
        std::cout << "ERROR: The image argument wasn't found." << std::endl;
        exit(1);
    }
    if (argc > 2) {
        std::cout << "ERROR: Too many arguments (Max: 2) for image." << std::endl;
        exit(1);
    }  

    std::string argument = argv[1], fPath = "", fName = "", fExt = "";
    int linkAddress = 0;

    for(int i = argument.length() - 1; i > -1; i--) {
        if(!linkAddress) {
            if(argument[i] == '.') {
                linkAddress++;
                continue;
            }
            else if(argument[i] == '\\' || argument[i] == '/') {
                std::cout << "ERROR: Unrecognized Filetype" << std::endl;
                exit(1);
            }
            fExt = argument[i] + fExt;
        }
        else if(linkAddress == 1) {
            if(argument[i] == '\\' || argument[i] == '/'){
                linkAddress++;
                fPath += argument[i];
                continue;
            }
            fName = argument[i] + fName;
        }
        else
            fPath = argument[i] + fPath;
    }
    fExt = '.' + fExt;
    
    if(fExt != ".jfif" && fExt != ".png" && fExt != ".jpg") {
        std::cout << "ERROR: Improper filetype: " << fExt << ". Only verified .jfif .png .jpg" << std::endl;
        exit(1);
    }


    
    int width, height, channels;
    unsigned char *img = stbi_load(argv[1], &width, &height, &channels, 3);
    std::cout << "First Pixel Data: \n\tR: " << static_cast<unsigned>(img[0]) << "\n\tG: " << static_cast<unsigned>(img[1]) << "\n\tB: " << static_cast<unsigned>(img[2]) << std::endl;
    std::cout << "Second Pixel Data: \n\tR: " << static_cast<unsigned>(img[3]) << "\n\tG: " << static_cast<unsigned>(img[4]) << "\n\tB: " << static_cast<unsigned>(img[5]) << std::endl;
    std::cout << "Third Pixel Data: \n\tR: " << static_cast<unsigned>(img[6]) << "\n\tG: " << static_cast<unsigned>(img[7]) << "\n\tB: " << static_cast<unsigned>(img[8]) << std::endl;

    if(!img){
        std::cout << "ERROR: The image did not load in." << std::endl;
        exit(2);
    }

    std::cout << "Image loaded.\nThe parameters of the loaded image are:" << std::endl;
    std::cout << "\tHeight: " << height << "\n\tWidth: " << width << "\n\tChannels: " << channels << std::endl; 
    std::cout << "File Location Details: \n\tFile Path: " << fPath << "\n\tFile Name: " << fName << "\n\tFile Extension: " << fExt << std::endl; 

    size_t img_size = width * height * channels;
    fName = fPath + "changed_" + fName + fExt;

    if(fExt == ".jfif"){
    }
    else if(fExt == ".png"){

    }
    else if(fExt == ".jpg"){
        std::cout << "File Detected: .jpg | Output file named: " << fName << std::endl;
        unsigned char *someChange = img;
        // int etst = 0;
        // for(unsigned char *i = img, *sc = someChange; i != img + img_size; i += channels, sc += channels){
        //     etst++;
        //     if(etst > width)
        //         break;
        //     *sc = (uint8_t)0;
        //     *(sc + 1) = (uint8_t)0;
        //     *(sc + 2) = (uint8_t)0;
        // }
        int w = 1;
        for(unsigned char *i = img, *sc = someChange + ((height / 2) * width * channels); i != img + img_size, w <= width; i += channels, sc += channels, w++){
            *sc = *(sc - ((height / 4) * width * channels)) = *(sc - ((height / 8) * width * channels))
                = *(sc + ((height / 4) * width * channels)) = *(sc + ((height / 8) * width * channels)) = (uint8_t)0;
            *(sc + 1) = *(sc + 1 - ((height / 4) * width * channels)) = *(sc + 1 - ((height / 8) * width * channels)) 
                      = *(sc + 1 + ((height / 4) * width * channels)) = *(sc + 1 + ((height / 8) * width * channels)) = (uint8_t)0;
            *(sc + 2) = *(sc + 2 - ((height / 4) * width * channels)) = *(sc + 2 - ((height / 8) * width * channels))
                      = *(sc + 2 + ((height / 4) * width * channels)) = *(sc + 2 + ((height / 8) * width * channels)) = (uint8_t)0;    
        }
        stbi_image_free(someChange);
        stbi_write_jpg(fName.c_str(), width, height, channels, someChange, 100);
    }

    // delete(outFile);
    stbi_image_free(img);
    return 0;
}