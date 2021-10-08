#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int row = 0; row < height; row++)
    {
        for (int pixel = 0; pixel < width; pixel++)
        {
            int blue_amount = image[row][pixel].rgbtBlue;
            int green_amount = image[row][pixel].rgbtGreen;
            int red_amount = image[row][pixel].rgbtRed;

            float avg = (blue_amount + green_amount + red_amount) / 3.00;

            image[row][pixel].rgbtBlue = round(avg);
            image[row][pixel].rgbtGreen = round(avg);
            image[row][pixel].rgbtRed = round(avg);
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int row = 0; row < height; row++)
    {
        for (int pixel = 0; pixel < width; pixel++)
        {
            int originalBlue = image[row][pixel].rgbtBlue;
            int originalGreen = image[row][pixel].rgbtGreen;
            int originalRed = image[row][pixel].rgbtRed;

            // Formula to convert image to sepia
            float sepiaBlue = .272 * originalRed + .534 * originalGreen + .131 * originalBlue;
            float sepiaGreen = .349 * originalRed + .686 * originalGreen + .168 * originalBlue;
            float sepiaRed = .393 * originalRed + .769 * originalGreen + .189 * originalBlue;

            int max_value = 255;

            // Blue
            if (sepiaBlue > max_value)
            {
                image[row][pixel].rgbtBlue = max_value;
            }
            else
            {
                image[row][pixel].rgbtBlue = round(sepiaBlue);
            }

            // Green
            if (sepiaGreen > max_value)
            {
                image[row][pixel].rgbtGreen = max_value;
            }
            else
            {
                image[row][pixel].rgbtGreen = round(sepiaGreen);
            }

            // Red
            if (sepiaRed > max_value)
            {
                image[row][pixel].rgbtRed = max_value;
            }
            else
            {
                image[row][pixel].rgbtRed = round(sepiaRed);
            }
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int temp[3];
    for (int row = 0; row < height; row++)
    {                           // divides the image in two halfs
        for (int pixel = 0; pixel < round(width / 2); pixel++)
        {
            // temporary variables
            temp[0] = image[row][pixel].rgbtBlue;
            temp[1] = image[row][pixel].rgbtGreen;
            temp[2] = image[row][pixel].rgbtRed;
            // copies the rigth side to the left
            image[row][pixel].rgbtBlue = image[row][(width - 1) - pixel].rgbtBlue;
            image[row][pixel].rgbtGreen = image[row][(width - 1) - pixel].rgbtGreen;
            image[row][pixel].rgbtRed = image[row][(width - 1) - pixel].rgbtRed;
            // copies the left side to the right
            image[row][(width - 1) - pixel].rgbtBlue = temp[0];
            image[row][(width - 1) - pixel].rgbtGreen = temp[1];
            image[row][(width - 1) - pixel].rgbtRed = temp[2];
            /* -1 because for example if the width is 10, 0 to 10 is 11, so,
            10 - 1 is 9, 0 to 9 is 10*/
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // temporary variable
    RGBTRIPLE temp[height][width];

    for (int r = 0; r < height; r++)
    {
        for (int p = 0; p < width; p++)
        {
            int blue_value = 0;
            int green_value = 0;
            int red_value = 0;
            float counter = 0.0;

            for (int i = -1; i < 2; i++)
            {
                for (int j = -1; j < 2; j++)
                {
                    // if outside the edges
                    if (r + i < 0 || r + i > height - 1 || p + j < 0 || p + j > width - 1)
                    {
                        /* forces the next iteration of the loop to take place,
                        skipping any code in between.*/
                        continue;
                    }

                    blue_value += image[r + i][p + j].rgbtBlue;
                    green_value += image[r + i][p + j].rgbtGreen;
                    red_value += image[r + i][p + j].rgbtRed;
                    counter++;
                }
            }

            float avgB = blue_value / counter;
            float avgG = green_value / counter;
            float avgR = red_value / counter;

            // we use temp variable to not modify the original pixels
            temp[r][p].rgbtBlue = round(avgB);
            temp[r][p].rgbtGreen = round(avgG);
            temp[r][p].rgbtRed = round(avgR);

        }
    }
    for (int r = 0; r < height; r++)
    {
        for (int p = 0; p < width; p++)
        {
            image[r][p].rgbtBlue = temp[r][p].rgbtBlue;
            image[r][p].rgbtGreen = temp[r][p].rgbtGreen;
            image[r][p].rgbtRed = temp[r][p].rgbtRed;
        }
    }
    return;
}

