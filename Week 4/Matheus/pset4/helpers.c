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
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
