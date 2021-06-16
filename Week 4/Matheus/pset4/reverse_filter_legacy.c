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
                int mc = image[irow + 0][icol + 0]; // Current pixel
                int mr = image[irow + 0][icol + 1]; // Mid right
    
                RGBTRIPLE ll = RGBTRIPLE_ZERO; // Low left
                int lc = image[irow + 1][icol + 0]; // Low center
                int lr = image[irow + 1][icol + 1]; // Low right
    
                int kernel[9] = {tl, tc, tr, ml, mc, mr, ll, lc, lr};
            }
            else if (icol == cols - 1 && irow == 0) // If is the top right corner
            {
                RGBTRIPLE tl = RGBTRIPLE_ZERO; // Top left
                RGBTRIPLE tc = RGBTRIPLE_ZERO; // Top center
                RGBTRIPLE tr = RGBTRIPLE_ZERO; // Top right
    
                int ml = image[irow + 0][icol - 1]; // Mid left
                int mc = image[irow + 0][icol + 0]; // Current pixel
                RGBTRIPLE mr = RGBTRIPLE_ZERO; // Mid right
    
                int ll = image[irow + 1][icol - 1]; // Low left
                int lc = image[irow + 1][icol + 0]; // Low center
                RGBTRIPLE lr = RGBTRIPLE_ZERO; // Low right  
    
                RGBTRIPLE kernel[9] = {tl, tc, tr, ml, mc, mr, ll, lc, lr};
            }
            else if (icol == cols - 1 && irow == 0) // If is the lower left corner
            {
                RGBTRIPLE tl = RGBTRIPLE_ZERO; // Top left
                int tc = image[irow - 1][icol + 0]; // Top center
                int tr = image[irow - 1][icol + 1]; // Top right
    
                RGBTRIPLE ml = RGBTRIPLE_ZERO; // Mid left
                int mc = image[irow + 0][icol + 0]; // Current pixel
                int mr = image[irow - 0][icol + 1]; // Mid right
    
                RGBTRIPLE ll = RGBTRIPLE_ZERO; // Low left
                RGBTRIPLE lc = RGBTRIPLE_ZERO; // Low center
                RGBTRIPLE lr = RGBTRIPLE_ZERO; // Low right   
    
                int kernel[9] = {tl, tc, tr, ml, mc, mr, ll, lc, lr};
            }
            else if (icol == cols - 1 && irow == 0) // If is the lower right corner
            {
                int tl = image[irow - 1][icol - 1]; // Top left
                int tc = image[irow - 1][icol + 0]; // Top center
                RGBTRIPLE tr = RGBTRIPLE_ZERO; // Top right
    
                int ml = image[irow + 0][icol - 1]; // Mid left
                int mc = image[irow + 0][icol + 0]; // Current pixel
                RGBTRIPLE mr = RGBTRIPLE_ZERO; // Mid right
    
                RGBTRIPLE ll = RGBTRIPLE_ZERO; // Low left
                RGBTRIPLE lc = RGBTRIPLE_ZERO; // Low center
                RGBTRIPLE lr = RGBTRIPLE_ZERO; // Low right   
    
                int kernel[9] = {tl, tc, tr, ml, mc, mr, ll, lc, lr};
            }
            else if (irow >= 1 && irow <= rows - 2 && icol >= 1 && icol <= cols - 2) // If between second and second to last column, continue (inclusive) 
            // If between second a second to last row, continue (inclusive). These two ifs basically select the inner square of the grid 
            {
                int tl = image[irow - 1][icol - 1]; // Top left
                int tc = image[irow - 1][icol + 0]; // Top center
                int tr = image[irow - 1][icol + 1]; // Top right
    
                int ml = image[irow + 0][icol - 1]; // Mid left
                int mc = image[irow + 0][icol + 0]; // Current pixel
                int mr = image[irow - 0][icol + 1]; // Mid right
    
                int ll = image[irow + 1][icol - 1]; // Low left
                int lc = image[irow + 1][icol + 0]; // Low center
                int lr = image[irow + 1][icol + 1]; // Low right  
    
                int kernel[9] = {tl, tc, tr, ml, mc, mr, ll, lc, lr};
            }
            else if (irow < rows - 2 && irow > 0 && icol == 0) //If is the leftmost middle column (that has the left part equals to 0)
            {
                RGBTRIPLE tl = RGBTRIPLE_ZERO; // Top left
                int tc = image[irow - 1][icol + 0]; // Top center
                int tr = image[irow - 1][icol + 1]; // Top right
    
                RGBTRIPLE ml = RGBTRIPLE_ZERO; // Mid left
                int mc = image[irow + 0][icol + 0]; // Current pixel
                int mr = image[irow + 0][icol + 1]; // Mid right
    
                RGBTRIPLE ll = RGBTRIPLE_ZERO; // Low left
                int lc = image[irow + 1][icol + 0]; // Low center
                int lr = image[irow + 1][icol + 1]; // Low right
    
                int kernel[9] = {tl, tc, tr, ml, mc, mr, ll, lc, lr};
            }
            else if (irow < rows - 2 && irow > 0 && icol == cols - 1) //If is the rightmost middle column (that has the right part equals to 0)
            {
                int tl = image[irow - 1][icol - 1]; // Top left
                int tc = image[irow - 1][icol + 0]; // Top center
                RGBTRIPLE tr = RGBTRIPLE_ZERO; // Top right
    
                int ml = image[irow + 0][icol - 1]; // Mid left
                int mc = image[irow + 0][icol + 0]; // Current pixel
                RGBTRIPLE mr = RGBTRIPLE_ZERO; // Mid right
    
                int ll = image[irow + 1][icol - 1]; // Low left
                int lc = image[irow + 1][icol + 0]; // Low center
                RGBTRIPLE lr = RGBTRIPLE_ZERO; // Low right
    
                int kernel[9] = {tl, tc, tr, ml, mc, mr, ll, lc, lr};
            }
            else if (irow == 0 && icol > 0 && icol <= cols - 2) //If topmost middle row (that has the upper part equals to 0)
            {
                RGBTRIPLE tl = RGBTRIPLE_ZERO; // Top left
                RGBTRIPLE tc = RGBTRIPLE_ZERO; // Top center
                RGBTRIPLE tr = RGBTRIPLE_ZERO; // Top right
    
                int ml = image[irow + 0][icol - 1]; // Mid left
                int mc = image[irow + 0][icol + 0]; // Current pixel
                int mr = image[irow + 0][icol + 1]; // Mid right
    
                int ll = image[irow + 1][icol - 1]; // Low left
                int lc = image[irow + 1][icol + 0]; // Low center
                int lr = image[irow + 1][icol + 1]; // Low right
    
                int kernel[9] = {tl, tc, tr, ml, mc, mr, ll, lc, lr};
            }
            else if (irow == rows - 1 && icol > 0 && icol <= cols - 2) //If downmost middle row (that has the lower part equals to 0)
            {
                int tl = image[irow - 1][icol - 1]; // Top left
                int tc = image[irow - 1][icol + 0]; // Top center
                int tr = image[irow - 1][icol + 1]; // Top right
    
                int ml = image[irow + 0][icol - 1]; // Mid left
                int mc = image[irow + 0][icol + 0]; // Current pixel
                int mr = image[irow + 0][icol + 1]; // Mid right
    
                RGBTRIPLE ll = RGBTRIPLE_ZERO; // Low left
                RGBTRIPLE lc = RGBTRIPLE_ZERO; // Low center
                RGBTRIPLE lr = RGBTRIPLE_ZERO; // Low right
    
                int kernel[9] = {tl, tc, tr, ml, mc, mr, ll, lc, lr};
            }
        }
    }
}