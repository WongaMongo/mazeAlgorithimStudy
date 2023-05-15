


// Christopher Wong
// Just trying to get it to take in a picture.

#include "includes.hpp"
// #include <iostream>
// #include <vector>
// #include <sstream>
// #include "mazeAlgorithms\floodFill.cpp"
// #include "mazeAlgorithms\leftHand.cpp"


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
    std::cout << "ArgC: " << argc << std::endl;
    switch(argc){
        case 1:
            std::cout << "ERROR: The image argument wasn't found." << std::endl;
            exit(1);
            return 1;
        case 2:
        case 3:
        case 4:
        case 5:
            std::cout << "Error: The start and end points were not found." << std::endl;
            exit(1);
            return 1;
        case 6:
            break;
        default:
            std::cout << "Error: Unknown issue. Possibly too many (>5) arguments!" << std::endl;
            exit(1);
            return 1;
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


    
    int width, height, channels, req_comp = 3;
    if(fExt == ".png")
        req_comp = 4;
    unsigned char *img = stbi_load(argv[1], &width, &height, &channels, req_comp);
    if(!img){
        std::cout << "ERROR: The image did not load in." << std::endl;
        exit(2);
    }
    std::cout << "First Pixel Data: \n\tR: " << static_cast<unsigned>(img[0]) << "\n\tG: " << static_cast<unsigned>(img[1]) << "\n\tB: " << static_cast<unsigned>(img[2]) << std::endl;
    std::cout << "Second Pixel Data: \n\tR: " << static_cast<unsigned>(img[3]) << "\n\tG: " << static_cast<unsigned>(img[4]) << "\n\tB: " << static_cast<unsigned>(img[5]) << std::endl;
    std::cout << "Third Pixel Data: \n\tR: " << static_cast<unsigned>(img[6]) << "\n\tG: " << static_cast<unsigned>(img[7]) << "\n\tB: " << static_cast<unsigned>(img[8]) << std::endl;



    int sr = std::atoi(argv[2]), sc = std::atoi(argv[3]), er = std::atoi(argv[4]), ec = std::atoi(argv[5]);
    // int sr = 0, sc = 150, er = 321, ec = 169;
    std::cout << "Image loaded.\nThe parameters of the loaded image are:" << std::endl;
    std::cout << "\tHeight: " << height << "\n\tWidth: " << width << "\n\tChannels: " << channels << std::endl; 
    std::cout << "\tStarting Row: " << sr << "\t\tStarting Column: " << sc << "\n\tEnding Row: " << er << "\t\tEnding Column: " << ec << std::endl;
    std::cout << "File Location Details: \n\tFile Path: " << fPath << "\n\tFile Name: " << fName << "\n\tFile Extension: " << fExt << std::endl; 

    size_t img_size = width * height * channels;
    fName = fPath + "changed_" + fName + fExt;
    std::vector<std::vector<std::vector<int>>> rgbVector(height, std::vector<std::vector<int>>(width, std::vector<int>(4, 0)));
    
    if(fExt == ".jfif"){
    }
    else if(fExt == ".png"){
        std::cout << "File Detected: .png | Output file named: " << fName << std::endl;
        int w = 0, h = 0;
        for(unsigned char *i = img; i != img + img_size; i += channels, w++){
            if(w == width){
                h++;
                w = 0;
            }
            rgbVector[h][w] = {*i, *(i + 1), *(i + 2)};
        }

        // Algorithms //////////////////////////////////////////////////////////////////////////////////////////////
        floodFillAlgorithm(rgbVector, sr, sc, er, ec);
        // leftHand(rgbVector, sr, sc, er, ec);
        // actualFloodFill(rgbVector, sr, sc, er, ec);
        ///////////////////////////////////////////////////////////////////////////////////////////////////////////


        unsigned char *i = img;
        for(std::vector<std::vector<int>> r : rgbVector){
            for(std::vector<int> c : r){
                *i       = c[0];
                *(i + 1) = c[1];
                *(i + 2) = c[2];
                i += channels;
            }
        }
        stbi_write_png(fName.c_str(), width, height, channels, img, width * channels);
    }
    else if(fExt == ".jpg"){
        std::cout << "File Detected: .jpg | Output file named: " << fName << std::endl;
        unsigned char *imgChanges = img;
        // int etst = 0;
        // for(unsigned char *i = img, *sc = someChange; i != img + img_size; i += channels, sc += channels){
        //     etst++;
        //     if(etst > width)
        //         break;
        //     *sc = (uint8_t)0;
        //     *(sc + 1) = (uint8_t)0;
        //     *(sc + 2) = (uint8_t)0;
        // }
        int w = 0, h = 0;
        for(unsigned char *i = img; i != img + img_size; i += channels, w++){
            if(w == width){
                h++;
                w = 0;
            }
            if(h == height - 1 && w == width - 1)
                std::cout << "Last Pixel Data: \n\tR: " << static_cast<unsigned>(*i) << "\n\tG: " << static_cast<unsigned>(*(i + 1)) << "\n\tB: " << static_cast<unsigned>(*(i + 2)) << std::endl;
            rgbVector[h][w] = {*i, *(i + 1), *(i + 2)};
        }

        std::cout << "First Pixel Vector Data: \n\tR: " << rgbVector[0][0][0] << "\n\tG: " << rgbVector[0][0][1] << "\n\tB: " << rgbVector[0][0][2] << std::endl;
        std::cout << "Second Pixel Vector Data: \n\tR: " << rgbVector[0][1][0] << "\n\tG: " << rgbVector[0][1][1] << "\n\tB: " << rgbVector[0][1][2] << std::endl;
        std::cout << "Third Pixel Vector Data: \n\tR: " << rgbVector[0][2][0] << "\n\tG: " << rgbVector[0][2][1] << "\n\tB: " << rgbVector[0][2][2] << std::endl;
        std::cout << "Last Pixel Vector Data: \n\tR: " << rgbVector[height - 1][width - 1][0] << "\n\tG: " << rgbVector[height - 1][width - 1][1] << "\n\tB: " << rgbVector[height - 1][width - 1][2] << std::endl;

        std::cout << std::endl;
        stbi_write_jpg(fName.c_str(), width, height, channels, imgChanges, 100);
        stbi_image_free(imgChanges);
    }

    // delete(outFile);
    // stbi_image_free(img);
    return 0;
}