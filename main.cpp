


// Christopher Wong
// Just trying to get it to take in a picture.


#include <iostream>

// Trying out the stb_image library. From: https://github.com/nothings/stb

/* Learning it from these 
        https://www.youtube.com/watch?v=1OyQoPCp46o
        https://www.youtube.com/watch?v=028GNYC32Rg&list=PLG5M8QIx5lkzdGkdYQeeCK__As6sI2tOY&index=1
*/
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

int main(int argc, char* argv[]){
    if(argc < 2){
        std::cout << "ERROR: The image argument wasn't found." << std::endl;
        exit(1);
    }
    if (argc > 2){
        std::cout << "ERROR: Too many arguments (Max: 2) for image." << std::endl;
        exit(1);
    }  
    int width, height, channels;
    unsigned char *img = stbi_load(argv[1], &width, &height, &channels, 0);
    if(!img){
        std::cout << "ERROR: The image did not load in." << std::endl;
        exit(2);
    }
    std::cout << "Image loaded." << std::endl;
    std::cout << "The parameters of the loaded image are:" << std::endl;
    std::cout << "\tHeight: " << height << "\n\tWidth: " << width << "\n\tChannels: " << channels << std::endl; 
    stbi_image_free(img);
    return 0;
}