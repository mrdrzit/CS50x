#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int cols = width;
    int rows = height;

    for (int irow = 0; irow < rows; irow++)
    {
        for (int icol = 0; icol < cols; icol++)
        {
            int gray = round((image[irow][icol].rgbtBlue + image[irow][icol].rgbtGreen + image[irow][icol].rgbtRed) / 3.0);
            image[irow][icol].rgbtBlue = gray;
            image[irow][icol].rgbtRed = gray;
            image[irow][icol].rgbtGreen = gray;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    
    int cols = width;
    int rows = height;

    for (int irow = 0; irow < rows; irow++)
    {
        for (int icol = 0; icol < cols; icol++)
        {
            int sepiaRed = round(0.393 * image[irow][icol].rgbtRed + 0.769 * image[irow][icol].rgbtGreen + 0.189 * image[irow][icol].rgbtBlue);
            int sepiaGreen = round(0.349 * image[irow][icol].rgbtRed + 0.686 * image[irow][icol].rgbtGreen + 0.168 * image[irow][icol].rgbtBlue);
            int sepiaBlue = round(0.272 * image[irow][icol].rgbtRed + 0.534 * image[irow][icol].rgbtGreen + 0.131 * image[irow][icol].rgbtBlue);
            
            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }
            image[irow][icol].rgbtRed = sepiaRed;
            image[irow][icol].rgbtGreen = sepiaGreen;
            image[irow][icol].rgbtBlue = sepiaBlue;
        }
    }           
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    
    int cols = width;
    int rows = height;
    int length = sizeof(image[0]) / sizeof(image[0][0]);
    RGBTRIPLE swap_temp;

    if (length % 2 != 0) //Check if the rows in this image are even or odd. This can be done only once because an image is a ractangular grid of pixels.
    {
        for (int irow = 0; irow < rows; irow++)
        {
            int end_pointer = length - 1;
            int start_pointer = 0;
            for (int i = 0; i < floor(length/2.0); i++)
            {
                swap_temp = image[irow][i];
                image[irow][i] = image[irow][end_pointer];
                image[irow][end_pointer] = swap_temp;
                end_pointer--;
                start_pointer++;
            }
        }
    }
    else
    {
        for (int irow = 0; irow < rows; irow++)
        {
            int end_pointer = length - 1;
            int start_pointer = 0;
            for (int i = 0; i < round(length/2.0); i++)
            {
                swap_temp = image[irow][i];
                image[irow][i] = image[irow][end_pointer];
                image[irow][end_pointer] = swap_temp;
                end_pointer--;
                start_pointer++;
            } 
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
