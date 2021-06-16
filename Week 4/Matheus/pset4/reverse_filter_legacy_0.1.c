#include "helpers.h"
#include <math.h>


// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int irow = 0; irow < height; irow++)
    {
        for (int icol = 0; icol < width; icol++)
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


    for (int irow = 0; irow < height; irow++)
    {
        for (int icol = 0; icol < width; icol++)
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

    int length = sizeof(image[0]) / sizeof(image[0][0]);
    RGBTRIPLE swap_temp;

    if (length % 2 != 0) //Check if the height in this image are even or odd. This can be done only once because an image is a ractangular grid of pixels.
    {
        for (int irow = 0; irow < height; irow++)
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
        for (int irow = 0; irow < height; irow++)
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
    RGBTRIPLE RGBTRIPLE_ZERO;
    
    RGBTRIPLE_ZERO.rgbtBlue = 0;
    RGBTRIPLE_ZERO.rgbtGreen = 0;
    RGBTRIPLE_ZERO.rgbtRed = 0;
    

    for (int irow = 0; irow < height; irow++)
    {
        for (int icol = 0; icol < width; icol++)
        {
            if (icol == 0 && irow == 0) // If is the top left corner
            {
                RGBTRIPLE tl = RGBTRIPLE_ZERO; // Top left
                RGBTRIPLE tc = RGBTRIPLE_ZERO; // Top center
                RGBTRIPLE tr = RGBTRIPLE_ZERO; // Top right
    
                RGBTRIPLE ml = RGBTRIPLE_ZERO; // Mid left
                int mcB = image[irow + 0][icol + 0].rgbtBlue; // Current pixel
                int mcG = image[irow + 0][icol + 0].rgbtGreen; // Current pixel
                int mcR = image[irow + 0][icol + 0].rgbtRed; // Current pixel
                
                int mrB = image[irow + 0][icol + 1].rgbtBlue; // Mid right
                int mrG = image[irow + 0][icol + 1].rgbtGreen; // Mid right
                int mrR = image[irow + 0][icol + 1].rgbtRed; // Mid right
    
                RGBTRIPLE ll = RGBTRIPLE_ZERO; // Low left
                int lcB = image[irow + 1][icol + 0].rgbtBlue; // Low center
                int lcG = image[irow + 1][icol + 0].rgbtGreen; // Low center
                int lcR = image[irow + 1][icol + 0].rgbtRed; // Low center
                
                int lrB = image[irow + 1][icol + 1].rgbtBlue; // Low right
                int lrG = image[irow + 1][icol + 1].rgbtGreen; // Low right
                int lrR = image[irow + 1][icol + 1].rgbtRed; // Low right
    
                int 
            }
            else if (icol == width - 1 && irow == 0) // If is the top right corner
            {
                RGBTRIPLE tl = RGBTRIPLE_ZERO; // Top left
                RGBTRIPLE tc = RGBTRIPLE_ZERO; // Top center
                RGBTRIPLE tr = RGBTRIPLE_ZERO; // Top right
    
                int mlB = image[irow + 0][icol - 1].rgbtBlue; // Mid left
                int mlG = image[irow + 0][icol - 1].rgbtGreen; // Mid left
                int mlR = image[irow + 0][icol - 1].rgbtRed; // Mid left
                
                int mcB = image[irow + 0][icol + 0].rgbtBlue; // Current pixel
                int mcG = image[irow + 0][icol + 0].rgbtGreen; // Current pixel
                int mcR = image[irow + 0][icol + 0].rgbtRed; // Current pixel
                
                int mrB = image[irow + 0][icol + 1].rgbtBlue; // Mid right
                int mrG = image[irow + 0][icol + 1].rgbtGreen; // Mid right
                int mrR = image[irow + 0][icol + 1].rgbtRed; // Mid right
    
                int llB = image[irow + 1][icol - 1].rgbtBlue; // Low left
                int llG = image[irow + 1][icol - 1].rgbtGreen; // Low left
                int llR = image[irow + 1][icol - 1].rgbtRed; // Low left
                
                int lcB = image[irow + 1][icol + 0].rgbtBlue; // Low center
                int lcG = image[irow + 1][icol + 0].rgbtGreen; // Low center
                int lcR = image[irow + 1][icol + 0].rgbtRed; // Low center
                
                RGBTRIPLE lr = RGBTRIPLE_ZERO; // Low right  
    
                // RGBTRIPLE kernel[9] = {tl, tc, tr, ml, mc, mr, ll, lc, lr};
            }
            else if (icol == width - 1 && irow == 0) // If is the lower left corner
            {
                RGBTRIPLE tl = RGBTRIPLE_ZERO; // Top left
                int tcB = image[irow - 1][icol + 0].rgbtBlue; // Top center
                int tcG = image[irow - 1][icol + 0].rgbtGreen; // Top center
                int tcR = image[irow - 1][icol + 0].rgbtRed; // Top center
                
                int trB = image[irow - 1][icol + 1].rgbtBlue; // Top right
                int trG = image[irow - 1][icol + 1].rgbtGreen; // Top right
                int trR = image[irow - 1][icol + 1].rgbtRed; // Top right

    
                RGBTRIPLE ml = RGBTRIPLE_ZERO; // Mid left
                int mcB = image[irow + 0][icol + 0].rgbtBlue; // Current pixel
                int mcG = image[irow + 0][icol + 0].rgbtGreen; // Current pixel
                int mcR = image[irow + 0][icol + 0].rgbtRed; // Current pixel
                
                int mrB = image[irow + 0][icol + 1].rgbtBlue; // Mid right
                int mrG = image[irow + 0][icol + 1].rgbtGreen; // Mid right
                int mrR = image[irow + 0][icol + 1].rgbtRed; // Mid rightt
    
                RGBTRIPLE ll = RGBTRIPLE_ZERO; // Low left
                RGBTRIPLE lc = RGBTRIPLE_ZERO; // Low center
                RGBTRIPLE lr = RGBTRIPLE_ZERO; // Low right   
    
                // int kernel[9] = {tl, tc, tr, ml, mc, mr, ll, lc, lr};
            }
            else if (icol == width - 1 && irow == 0) // If is the lower right corner
            {
                int tlB = image[irow - 1][icol - 1].rgbtBlue; // Top left
                int tlG = image[irow - 1][icol - 1].rgbtGreen; // Top left
                int tlR = image[irow - 1][icol - 1].rgbtRed; // Top left
                
                int tcB = image[irow - 1][icol + 0].rgbtBlue; // Top center
                int tcG = image[irow - 1][icol + 0].rgbtGreen; // Top center
                int tcR = image[irow - 1][icol + 0].rgbtRed; // Top center
                RGBTRIPLE tr = RGBTRIPLE_ZERO; // Top right
    
                int mlB = image[irow + 0][icol - 1].rgbtBlue; // Mid left
                int mlG = image[irow + 0][icol - 1].rgbtGreen; // Mid left
                int mlR = image[irow + 0][icol - 1].rgbtRed; // Mid left
                
                int mcB = image[irow + 0][icol + 0].rgbtBlue; // Current pixel
                int mcG = image[irow + 0][icol + 0].rgbtGreen; // Current pixel
                int mcR = image[irow + 0][icol + 0].rgbtRed; // Current pixel
                RGBTRIPLE mr = RGBTRIPLE_ZERO; // Mid right
    
                RGBTRIPLE ll = RGBTRIPLE_ZERO; // Low left
                RGBTRIPLE lc = RGBTRIPLE_ZERO; // Low center
                RGBTRIPLE lr = RGBTRIPLE_ZERO; // Low right   
    
                // int kernel[9] = {tl, tc, tr, ml, mc, mr, ll, lc, lr};
            }
            else if (irow >= 1 && irow <= height - 2 && icol >= 1 && icol <= width - 2) // If between second and second to last column, continue (inclusive) 
            // If between second a second to last row, continue (inclusive). These two ifs basically select the inner square of the grid 
            {
                int tlB = image[irow - 1][icol - 1].rgbtBlue; // Top left
                int tlG = image[irow - 1][icol - 1].rgbtGreen; // Top left
                int tlR = image[irow - 1][icol - 1].rgbtRed; // Top left
                
                int tcB = image[irow - 1][icol + 0].rgbtBlue; // Top center
                int tcG = image[irow - 1][icol + 0].rgbtGreen; // Top center
                int tcR = image[irow - 1][icol + 0].rgbtRed; // Top center
                
                int trB = image[irow - 1][icol + 1].rgbtBlue; // Top right
                int trG = image[irow - 1][icol + 1].rgbtGreen; // Top right
                int trR = image[irow - 1][icol + 1].rgbtRed; // Top right


    
    
                int mlB = image[irow + 0][icol - 1].rgbtBlue; // Mid left
                int mlG = image[irow + 0][icol - 1].rgbtGreen; // Mid left
                int mlR = image[irow + 0][icol - 1].rgbtRed; // Mid left
                
                int mcB = image[irow + 0][icol + 0].rgbtBlue; // Current pixel
                int mcG = image[irow + 0][icol + 0].rgbtGreen; // Current pixel
                int mcR = image[irow + 0][icol + 0].rgbtRed; // Current pixel
                
                int mrB = image[irow + 0][icol + 1].rgbtBlue; // Mid right
                int mrG = image[irow + 0][icol + 1].rgbtGreen; // Mid right
                int mrR = image[irow + 0][icol + 1].rgbtRed; // Mid right
    
    
    
    
                int llB = image[irow + 1][icol - 1].rgbtBlue; // Low left
                int llG = image[irow + 1][icol - 1].rgbtGreen; // Low left
                int llR = image[irow + 1][icol - 1].rgbtRed; // Low left
                
                int lcB = image[irow + 1][icol + 0].rgbtBlue; // Low center
                int lcG = image[irow + 1][icol + 0].rgbtGreen; // Low center
                int lcR = image[irow + 1][icol + 0].rgbtRed; // Low center
                
                int lrB = image[irow + 1][icol + 1].rgbtBlue; // Low right
                int lrG = image[irow + 1][icol + 1].rgbtGreen; // Low right
                int lrR = image[irow + 1][icol + 1].rgbtRed; // Low right
    
                // int kernel[9] = {tl, tc, tr, ml, mc, mr, ll, lc, lr};
            }
            else if (irow < height - 2 && irow > 0 && icol == 0) //If is the leftmost middle column (that has the left part equals to 0)
            {
                RGBTRIPLE tl = RGBTRIPLE_ZERO; // Top left
                int tcB = image[irow - 1][icol + 0].rgbtBlue; // Top center
                int tcG = image[irow - 1][icol + 0].rgbtGreen; // Top center
                int tcR = image[irow - 1][icol + 0].rgbtRed; // Top center
                
                int trB = image[irow - 1][icol + 1].rgbtBlue; // Top right
                int trG = image[irow - 1][icol + 1].rgbtGreen; // Top right
                int trR = image[irow - 1][icol + 1].rgbtRed; // Top right
    
                RGBTRIPLE ml = RGBTRIPLE_ZERO; // Mid left
                int mcB = image[irow + 0][icol + 0].rgbtBlue; // Current pixel
                int mcG = image[irow + 0][icol + 0].rgbtGreen; // Current pixel
                int mcR = image[irow + 0][icol + 0].rgbtRed; // Current pixel
                
                int mrB = image[irow + 0][icol + 1].rgbtBlue; // Mid right
                int mrG = image[irow + 0][icol + 1].rgbtGreen; // Mid right
                int mrR = image[irow + 0][icol + 1].rgbtRed; // Mid right
    
                RGBTRIPLE ll = RGBTRIPLE_ZERO; // Low left
                int lcB = image[irow + 1][icol + 0].rgbtBlue; // Low center
                int lcG = image[irow + 1][icol + 0].rgbtGreen; // Low center
                int lcR = image[irow + 1][icol + 0].rgbtRed; // Low center
                
                int lrB = image[irow + 1][icol + 1].rgbtBlue; // Low right
                int lrG = image[irow + 1][icol + 1].rgbtGreen; // Low right
                int lrR = image[irow + 1][icol + 1].rgbtRed; // Low right
    
                // int kernel[9] = {tl, tc, tr, ml, mc, mr, ll, lc, lr};
            }
            else if (irow < height - 2 && irow > 0 && icol == width - 1) //If is the rightmost middle column (that has the right part equals to 0)
            {
                int tlB = image[irow - 1][icol - 1].rgbtBlue; // Top left
                int tlG = image[irow - 1][icol - 1].rgbtGreen; // Top left
                int tlR = image[irow - 1][icol - 1].rgbtRed; // Top left
                
                int tcB = image[irow - 1][icol + 0].rgbtBlue; // Top center
                int tcG = image[irow - 1][icol + 0].rgbtGreen; // Top center
                int tcR = image[irow - 1][icol + 0].rgbtRed; // Top center
                RGBTRIPLE tr = RGBTRIPLE_ZERO; // Top right
    
                int mlB = image[irow + 0][icol - 1].rgbtBlue; // Mid left
                int mlG = image[irow + 0][icol - 1].rgbtGreen; // Mid left
                int mlR = image[irow + 0][icol - 1].rgbtRed; // Mid left
                
                int mcB = image[irow + 0][icol + 0].rgbtBlue; // Current pixel
                int mcG = image[irow + 0][icol + 0].rgbtGreen; // Current pixel
                int mcR = image[irow + 0][icol + 0].rgbtRed; // Current pixel
                RGBTRIPLE mr = RGBTRIPLE_ZERO; // Mid right
    
                int llB = image[irow + 1][icol - 1].rgbtBlue; // Low left
                int llG = image[irow + 1][icol - 1].rgbtGreen; // Low left
                int llR = image[irow + 1][icol - 1].rgbtRed; // Low left
                
                int lcB = image[irow + 1][icol + 0].rgbtBlue; // Low center
                int lcG = image[irow + 1][icol + 0].rgbtGreen; // Low center
                int lcR = image[irow + 1][icol + 0].rgbtRed; // Low center
                RGBTRIPLE lr = RGBTRIPLE_ZERO; // Low right
    
                // int kernel[9] = {tl, tc, tr, ml, mc, mr, ll, lc, lr};
            }
            else if (irow == 0 && icol > 0 && icol <= width - 2) //If topmost middle row (that has the upper part equals to 0)
            {
                RGBTRIPLE tl = RGBTRIPLE_ZERO; // Top left
                RGBTRIPLE tc = RGBTRIPLE_ZERO; // Top center
                RGBTRIPLE tr = RGBTRIPLE_ZERO; // Top right
    
                int mlB = image[irow + 0][icol - 1].rgbtBlue; // Mid left
                int mlG = image[irow + 0][icol - 1].rgbtGreen; // Mid left
                int mlR = image[irow + 0][icol - 1].rgbtRed; // Mid left
                
                int mcB = image[irow + 0][icol + 0].rgbtBlue; // Current pixel
                int mcG = image[irow + 0][icol + 0].rgbtGreen; // Current pixel
                int mcR = image[irow + 0][icol + 0].rgbtRed; // Current pixel
                
                int mrB = image[irow + 0][icol + 1].rgbtBlue; // Mid right
                int mrG = image[irow + 0][icol + 1].rgbtGreen; // Mid right
                int mrR = image[irow + 0][icol + 1].rgbtRed; // Mid right
    
                int llB = image[irow + 1][icol - 1].rgbtBlue; // Low left
                int llG = image[irow + 1][icol - 1].rgbtGreen; // Low left
                int llR = image[irow + 1][icol - 1].rgbtRed; // Low left
                
                int lcB = image[irow + 1][icol + 0].rgbtBlue; // Low center
                int lcG = image[irow + 1][icol + 0].rgbtGreen; // Low center
                int lcR = image[irow + 1][icol + 0].rgbtRed; // Low center
                
                int lrB = image[irow + 1][icol + 1].rgbtBlue; // Low right
                int lrG = image[irow + 1][icol + 1].rgbtGreen; // Low right
                int lrR = image[irow + 1][icol + 1].rgbtRed; // Low right
    
                // int kernel[9] = {tl, tc, tr, ml, mc, mr, ll, lc, lr};
            }
            else if (irow == height - 1 && icol > 0 && icol <= width - 2) //If downmost middle row (that has the lower part equals to 0)
            {
                int tlB = image[irow - 1][icol - 1].rgbtBlue; // Top left
                int tlG = image[irow - 1][icol - 1].rgbtGreen; // Top left
                int tlR = image[irow - 1][icol - 1].rgbtRed; // Top left

                int tcB = image[irow - 1][icol + 0].rgbtBlue; // Top center
                int tcG = image[irow - 1][icol + 0].rgbtGreen; // Top center
                int tcR = image[irow - 1][icol + 0].rgbtRed; // Top center
                
                int trB = image[irow - 1][icol + 1].rgbtBlue; // Top right
                int trG = image[irow - 1][icol + 1].rgbtGreen; // Top right
                int trR = image[irow - 1][icol + 1].rgbtRed; // Top right
    
                int mlB = image[irow + 0][icol - 1].rgbtBlue; // Mid left
                int mlG = image[irow + 0][icol - 1].rgbtGreen; // Mid left
                int mlR = image[irow + 0][icol - 1].rgbtRed; // Mid left
                
                int mcB = image[irow + 0][icol + 0].rgbtBlue; // Current pixel
                int mcG = image[irow + 0][icol + 0].rgbtGreen; // Current pixel
                int mcR = image[irow + 0][icol + 0].rgbtRed; // Current pixel
                
                int mrB = image[irow + 0][icol + 1].rgbtBlue; // Mid right
                int mrG = image[irow + 0][icol + 1].rgbtGreen; // Mid right
                int mrR = image[irow + 0][icol + 1].rgbtRed; // Mid right
    
                RGBTRIPLE ll = RGBTRIPLE_ZERO; // Low left
                RGBTRIPLE lc = RGBTRIPLE_ZERO; // Low center
                RGBTRIPLE lr = RGBTRIPLE_ZERO; // Low right
    
                // int kernel[9] = {tl, tc, tr, ml, mc, mr, ll, lc, lr};
            }
        }
    }
}