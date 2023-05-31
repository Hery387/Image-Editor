#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct
{
    int width;
    int height;
} Image;

Image createImage(int width, int height){
    Image image;
    image.width = width;
    image.height = height;

    return image;
}

void saveImageToFile(Image image, const char* filename){
    FILE* file = fopen(filename, "wb");
    if (file == NULL) {
        fprintf(stderr, "Error opening file.\n");
        return;
    }

Image readPPMFile(const char* filePath){
    FILE* file = fopen(filePath, "rb");
    if (file == NULL){
        fprintf(stdeer, "Error opening the file\r");
        Image emptyImage = {0, 0};
        return emptyImage;
    }
    
}

    fprintf(file, "P6 %d %d 255 ", image.width, image.height);

    // Write image data
    for (int i = 0; i < image.height; i++) {
        for (int j = 0; j < image.width; j++) {
            // Generate sample pixel data (all red)
            unsigned char pixel[3] = {255, 0, 0};
            fwrite(pixel, sizeof(unsigned char), 3, file);
        }
    }

    fclose(file);
}

Image loadImageFromFile(const char* filename){
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        fprintf(stderr, "Error opening file.\n");
        Image emptyImage = {0, 0};
        return emptyImage;
    }

    // Read metadata
    int width, height;
    fscanf(file, "P6 %d %d 255 ", &width, &height);

    // Allocate memory for image data
    unsigned char (*imageData)[3] = malloc(height * sizeof(unsigned char[3]) * width);

    // Read image data
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            fread(imageData[i * width + j], sizeof(unsigned char), 3, file);
        }
    }

    fclose(file);

    Image loadedImage = {width, height};
    return loadedImage;
}

int main(){
    int menu_choice;

    do {

        printf("Main menu\n");
        printf("1. Edit existing image\n");
        printf("2. Create new image\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");

        scanf("%d", &menu_choice);


        switch (menu_choice)
        {
        case 1:
            printf("You chose to edit an existing image.\n");
            {
                char filePath[100];
        printf("Enter the path to the target image file: ");
        scanf("%s", filePath);

                Image loadedImage = readPPMFile(filePath);

                if (loadedImage.width == 0 && loadedImage.height == 0)
                {
                    printf("Error loading the image\n");
                    break;
                }
                
                int rotateChoice;
                printf("Rotate options\n");
                printf("1. Rotate 90 degrees left\n");
                printf("2. Rotate 90 degrees right\n");
                printf("Enter your choice:");
                scanf("%d", &rotateChoice);

                switch (rotateChoice)
                {
                case 1:
                    rotateImage90Left(&loadedImage);
                    printf("Image rotated 90 degrees left. \n");
                    break;

                case 2:
                    rotateImage90Right(&loadedImage);
                    printf("Image rotated 90 degrees right. \n");
                    break;
                
                default:
                    printf("Invalid choice. Please try again. \n");
                    break;
                }

                // Save the modified image back to file
                saveImageToFile(existingImage, "modified_image.ppm");
            }
            break;

        case 2:
            printf("You chose to create a new image.\n");
            {
                int width, height;

                printf("Enter the width of the image:");
                scanf("%d", &width);
                printf("Enter the height of the image:");
                scanf("%d", &height);

                Image newImage = createImage(width, height);

                // Save the new image to file
                saveImageToFile(newImage, "new_image.ppm");
            }
            break;

        case 3:
            printf("Exiting the program. Goodbye!\n");
            break;

        default:
            printf("Invalid choice. Please try again.\n");
            break;
        }
    } while (menu_choice != 3);

    return 0;
}