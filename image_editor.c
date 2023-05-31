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
            // Add Code here
            break;

        case 2:
            // Code to handle creating a new image
            printf("You chose to create a new image.\n");
            // Add Code here
            break;

        case 3:
            printf("Exiting the program. Goodbye!\n");
            break;

        default:
            printf("Invalid choice. Please try again.\n");
            break;
        }
    } while (menu_choice !=3);
    {
        return 1;
    }
    
}