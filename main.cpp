


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

    if(!img){
        std::cout << "ERROR: The image did not load in." << std::endl;
        exit(2);
    }

    std::cout << "Image loaded.\nThe parameters of the loaded image are:" << std::endl;
    std::cout << "\tHeight: " << height << "\n\tWidth: " << width << "\n\tChannels: " << channels << std::endl; 
    std::cout << "File Location Details: \n\tFile Path: " << fPath << "\n\tFile Name: " << fName << "\n\tFile Extension: " << fExt << std::endl; 

    size_t img_size = width * height * channels;
    fName = fPath + "changed_" + fName + fExt;
    const char* outFile = fName.c_str();

    if(fExt == ".jfif"){
    }
    else if(fExt == ".png"){

    }
    else if(fExt == ".jpg"){
        std::cout << "File Detected: .jpg | Output file named: " << fName << std::endl;
        stbi_write_jpg(outFile, width, height, channels, img, 100);
    }

    // delete(outFile);
    stbi_image_free(img);
    return 0;
}