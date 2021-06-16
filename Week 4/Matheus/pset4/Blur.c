#include <stdio.h>
#include <math.h>
#include <bmp.h>

int kernel[3][3] = {0};
RGBTRIPLE array[99][99] = {0};


int main(void)
{
    int rows = sizeof array / sizeof array[0];
    int cols = sizeof array[0] / sizeof array[0][0];
    
    // kernel[rows - 1][cols + 1]; // Top left
    // kernel[rows + 0][cols + 1]; // Top center
    // kernel[rows + 1][cols + 1]; // Top right
    // kernel[rows - 1][cols + 0]; // Mid left
    // kernel[rows + 0][cols + 0]; // Current pixel
    // kernel[rows + 1][cols + 0]; // Mid right
    // kernel[rows - 1][cols - 1]; // Low left
    // kernel[rows + 0][cols - 1]; // Low center
    // kernel[rows + 1][cols - 1]; // Low right

    int tl = kernel[rows - 1][cols + 1]; // Top left
    int tc = kernel[rows + 0][cols + 1]; // Top center
    int tr = kernel[rows + 1][cols + 1]; // Top right
    int ml = kernel[rows - 1][cols + 0]; // Mid left
    int mc = kernel[rows + 0][cols + 0]; // Current pixel
    int mr = kernel[rows + 1][cols + 0]; // Mid right
    int ll = kernel[rows - 1][cols - 1]; // Low left
    int lc = kernel[rows + 0][cols - 1]; // Low center
    int lr = kernel[rows + 1][cols - 1]; // Low right

    int sum_current_row[9] = {tl, tc, tr, ml, mc, mr, ll, lc, lr};

    for (int irow = 0; irow < rows; irow++)
    {
        for (int icol = 0; icol < cols; icol++)
        {

            array[irow][icol].rgbtBlue;
            array[irow][icol].rgbtRed;
            array[irow][icol].rgbtGreen;

            int cima = irow - (round(rows/2));
            int esq = icol - (round(cols/2));
            int dir = icol + (round(cols/2));
            int bax = irow + (round(rows/2));

            //If x < 0x000000 || x > 0xffffff, então x está dentro dos limites
            //else, está fora dos limites.

            if (cima < 1)
            {
                cima = 1;
            }
            else if (esq < 1)
            {
                esq = 1;
            }
            else if (dir > cols)
            {
                dir = cols;
            }
            else if (bax > rows)
            {
                bax = rows;
            }

            int sum = 0;
            for (int i = 0; i < 9; i++)
            {
                sum += sum_current_row[i];
                int mean_px = round(sum/9);
            }

            //If cima < 1 então coloca i = 1
            //If esquerda < 1 então coloca i = 1
            //If direita > width então coloca i = width
            //If baixo > heigth então coloca i = heigth
            //else, soma todos os valores dentro do kernel e divide por 9
        }
    }
}







//Função implementada no MATLAB

// function [output] = blur_3(img,x)
// Write a function called blur that blurs the input image. The funcion is to
// be called like this: output = blur(img,w);
// where img, the input image is a two-dimensional matrix of grayscale pixel
// values between 0 and 255. Blurring is to be carried out by averaging the
// pixel values in the vicinity of every pixel. Specifically, the output
// pixel value is thhe mean of the pixels in a square submatrix of size 2w+1
// where the given pixel sits in the center. For example, if w = 1, thenwe
// use a 3x3 matrix, that is, we average all the nighbouring pixels of the
// fivn pixel and itself. Only use valid pixels when portions of the blurring
// matrix fall outride the image. For example, the blurred value
// correspongind the w = 1 at index (1,1) would be the mean of elements (1,1)
// (1,2), (2,1) and (2,2). Both input img and output are of the type uint8.


// Transformação dos valores de uint8 para double
// k = double(img);

// Pega o input x e transforma no número que virará o array de WxW
// w=2.*x+1;

// [rw,cl] = size(k);
// output=[];
// for j = 1:cl
//     for i = 1:rw
//         cima = i-fix(w/2);
//         esq = j-fix(w/2);
//         dir = j+fix(w/2);
//         bax = i+fix(w/2);
                
//         if any([cima < 1])
//             cima = 1;
//         end 
//         if any([esq < 1])
//             esq = 1;
//         end
//         if any([bax > rw])
//             bax = rw;
//         end
//         if any([dir > cl])
//             dir = cl;
//         end
//             array = k([cima:bax],[esq:dir]);
//             temp_out(i,j) = mean(array(:));
//     end
// end
// output = uint8(temp_out);
// end