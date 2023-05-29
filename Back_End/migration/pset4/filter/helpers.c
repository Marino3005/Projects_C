#include "helpers.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{

    for (int i = 0; i < height; i++)
    {
        for (int m = 0; m < width; m++)
        {
            double Red = image[i][m].rgbtRed;
            double Green = image[i][m].rgbtGreen;
            double Blue = image[i][m].rgbtBlue;
            int average = round((Red + Green + Blue) / 3);
            image[i][m].rgbtRed = average;
            image[i][m].rgbtGreen = average;
            image[i][m].rgbtBlue = average;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int stop = width / 2;
    for (int i = 0; i < height; i++)
    {
        for (int m = 0; m < stop; m++)
        {
            int tempRed = image[i][m].rgbtRed;
            int tempGreen = image[i][m].rgbtGreen;
            int tempBlue = image[i][m].rgbtBlue;
            image[i][m] = image[i][width - (m + 1)];
            image[i][width - (m + 1)].rgbtRed = tempRed;
            image[i][width - (m + 1)].rgbtGreen = tempGreen;
            image[i][width - (m + 1)].rgbtBlue = tempBlue;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    double sumred;
    double sumgreen;
    double sumblue;
    int average;
    
    //create new array to store the new values of the pixels. Can't do it on original, woud interfier with the average.
    RGBTRIPLE tempimage[height][width];

    //Loop over all pixels
    for (int i = 0; i < height; i++)
    {
        for (int m = 0; m < width; m++)
        {
            sumred = image[i][m].rgbtRed;
            sumgreen = image[i][m].rgbtGreen;
            sumblue = image[i][m].rgbtBlue;
            average = 1;

            //Create different conditons according to the location of the pixel being modified
            //to determine what sorrounding pixels should be taken into account.
            if (i > 0) //Not on X edge
            {
                sumred = sumred + image[i - 1][m].rgbtRed;
                sumgreen = sumgreen + image[i - 1][m].rgbtGreen;
                sumblue = sumblue + image[i - 1][m].rgbtBlue;
                average++;
            }
            if (i < (height - 1))
            {
                sumred = sumred + image[i + 1][m].rgbtRed;
                sumgreen = sumgreen + image[i + 1][m].rgbtGreen;
                sumblue = sumblue + image[i + 1][m].rgbtBlue;
                average++;
            }
            if (m > 0)
            {
                sumred = sumred + image[i][m - 1].rgbtRed;
                sumgreen = sumgreen + image[i][m - 1].rgbtGreen;
                sumblue = sumblue + image[i][m - 1].rgbtBlue;
                average++;
            }
            if (m < (width - 1))
            {
                sumred = sumred + image[i][m + 1].rgbtRed;
                sumgreen = sumgreen + image[i][m + 1].rgbtGreen;
                sumblue = sumblue + image[i][m + 1].rgbtBlue;
                average++;
            }
            if ((i > 0) && (m > 0))
            {
                sumred = sumred + image[i - 1][m - 1].rgbtRed;
                sumgreen = sumgreen + image[i - 1][m - 1].rgbtGreen;
                sumblue = sumblue + image[i - 1][m - 1].rgbtBlue;
                average++;
            }
            if ((i > 0) && (m < (width - 1)))
            {
                sumred = sumred + image[i - 1][m + 1].rgbtRed;
                sumgreen = sumgreen + image[i - 1][m + 1].rgbtGreen;
                sumblue = sumblue + image[i - 1][m + 1].rgbtBlue;
                average++;
            }
            if ((i < (height - 1)) && (m > 0))
            {
                sumred = sumred + image[i + 1][m - 1].rgbtRed;
                sumgreen = sumgreen + image[i + 1][m - 1].rgbtGreen;
                sumblue = sumblue + image[i + 1][m - 1].rgbtBlue;
                average++;
            }
            if ((i < (height - 1)) && (m < (width - 1)))
            {
                sumred = sumred + image[i + 1][m + 1].rgbtRed;
                sumgreen = sumgreen + image[i + 1][m + 1].rgbtGreen;
                sumblue = sumblue + image[i + 1][m + 1].rgbtBlue;
                average++;
            }

            tempimage[i][m].rgbtRed = round(sumred / average);
            tempimage[i][m].rgbtGreen = round(sumgreen / average);
            tempimage[i][m].rgbtBlue = round(sumblue / average);
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int m = 0; m < width; m++)
        {
            image[i][m] = tempimage[i][m];
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    int sum1;
    int sum2;
    int sum3;
    int sum4;
    int sum5;
    int sum6;
    int gxred;
    int gxgreen;
    int gxblue;
    int gyred;
    int gygreen;
    int gyblue;
    double square;
    int Gred;
    int Ggreen;
    int Gblue;

    //Create new array that adds 1 block more at the edges. Remember, i needed to add 1 block of black pixels around the image for sober algorithm. 
    //If i use the original array, it would return segmentation failure.
    int newidht = width + 2;
    int newheight = height + 2;
    RGBTRIPLE fimage[(newheight)][(newidht)];

    //Make the edge blocks of the 2d array = 0(black).
    for (int i = 0; i < newidht; i++)
    {
        fimage[0][i].rgbtRed = 0;
        fimage[0][i].rgbtGreen = 0;
        fimage[0][i].rgbtBlue = 0;
        fimage[newheight - 1][i].rgbtRed = 0;
        fimage[newheight - 1][i].rgbtGreen = 0;
        fimage[newheight - 1][i].rgbtBlue = 0;
    }
    for (int i = 0; i < newheight; i++)
    {
        fimage[i][0].rgbtRed = 0;
        fimage[i][0].rgbtGreen = 0;
        fimage[i][0].rgbtBlue = 0;
        fimage[i][newidht - 1].rgbtRed = 0;
        fimage[i][newidht - 1].rgbtGreen = 0;
        fimage[i][newidht - 1].rgbtBlue = 0;
    }
    
    //Copy the original array inside the new one, starting from fimage[1][1], so the original array is now sorrounded by black blocks.
    for (int i = 1; i <= height; i++)
    {
        for (int m = 1; m <= width; m++)
        {
            fimage[i][m].rgbtRed = image[i - 1][m - 1].rgbtRed;
            fimage[i][m].rgbtGreen = image[i - 1][m - 1].rgbtGreen;
            fimage[i][m].rgbtBlue = image[i - 1][m - 1].rgbtBlue;
        }
    }

    //loop over all the pixels in the image
    for (int i = 1; i <= height; i++)
    {
        for (int m = 1; m <= width; m++)
        {
            //implement sobel operator

            // Calculate all three Gx values of a pixel
            //Gx red
            sum1 = fimage[i - 1][m - 1].rgbtRed * (-1);
            sum2 = fimage[i][m - 1].rgbtRed * (-2);
            sum3 = fimage[i + 1][m - 1].rgbtRed * (-1);
            sum4 = fimage[i - 1][m + 1].rgbtRed * (1);
            sum5 = fimage[i][m + 1].rgbtRed * (2);
            sum6 = fimage[i + 1][m + 1].rgbtRed * (1);

            gxred = sum1 + sum2 + sum3 + sum4 + sum5 + sum6;


            //Gx green
            sum1 = fimage[i - 1][m - 1].rgbtGreen * (-1);
            sum2 = fimage[i][m - 1].rgbtGreen * (-2);
            sum3 = fimage[i + 1][m - 1].rgbtGreen * (-1);
            sum4 = fimage[i - 1][m + 1].rgbtGreen * (1);
            sum5 = fimage[i][m + 1].rgbtGreen * (2);
            sum6 = fimage[i + 1][m + 1].rgbtGreen * (1);

            gxgreen = sum1 + sum2 + sum3 + sum4 + sum5 + sum6;


            //Gx blue
            sum1 = fimage[i - 1][m - 1].rgbtBlue * (-1);
            sum2 = fimage[i][m - 1].rgbtBlue * (-2);
            sum3 = fimage[i + 1][m - 1].rgbtBlue * (-1);
            sum4 = fimage[i - 1][m + 1].rgbtBlue * (1);
            sum5 = fimage[i][m + 1].rgbtBlue * (2);
            sum6 = fimage[i + 1][m + 1].rgbtBlue * (1);

            gxblue = sum1 + sum2 + sum3 + sum4 + sum5 + sum6;


            //calculate all Gy values for a pixel
            //Gy red
            sum1 = fimage[i - 1][m - 1].rgbtRed * (-1);
            sum2 = fimage[i - 1][m].rgbtRed * (-2);
            sum3 = fimage[i - 1][m + 1].rgbtRed * (-1);
            sum4 = fimage[i + 1][m - 1].rgbtRed * (1);
            sum5 = fimage[i + 1][m].rgbtRed * (2);
            sum6 = fimage[i + 1][m + 1].rgbtRed * (1);

            gyred = sum1 + sum2 + sum3 + sum4 + sum5 + sum6;


            //Gy green
            sum1 = fimage[i - 1][m - 1].rgbtGreen * (-1);
            sum2 = fimage[i - 1][m].rgbtGreen * (-2);
            sum3 = fimage[i - 1][m + 1].rgbtGreen * (-1);
            sum4 = fimage[i + 1][m - 1].rgbtGreen * (1);
            sum5 = fimage[i + 1][m].rgbtGreen * (2);
            sum6 = fimage[i + 1][m + 1].rgbtGreen * (1);

            gygreen = sum1 + sum2 + sum3 + sum4 + sum5 + sum6;


            //Gy blue
            sum1 = fimage[i - 1][m - 1].rgbtBlue * (-1);
            sum2 = fimage[i - 1][m].rgbtBlue * (-2);
            sum3 = fimage[i - 1][m + 1].rgbtBlue * (-1);
            sum4 = fimage[i + 1][m - 1].rgbtBlue * (1);
            sum5 = fimage[i + 1][m].rgbtBlue * (2);
            sum6 = fimage[i + 1][m + 1].rgbtBlue * (1);

            gyblue = sum1 + sum2 + sum3 + sum4 + sum5 + sum6;


            //combine Gx and Gy of each channel

            //red channel
            square = (gxred * gxred) + (gyred * gyred);
            Gred = round(sqrt(square));


            //green chanel
            square = (gxgreen * gxgreen) + (gygreen * gygreen);
            Ggreen = round(sqrt(square));


            //blue channel
            square = (gxblue * gxblue) + (gyblue * gyblue);
            Gblue = round(sqrt(square));

            //Set maximum value to 255
            if (Gred > 255)
            {
                Gred = 255;
            }
            if (Ggreen > 255)
            {
                Ggreen = 255;
            }
            if (Gblue > 255)
            {
                Gblue = 255;
            }


            //assign new values
            image[i - 1][m - 1].rgbtRed = Gred;
            image[i - 1][m - 1].rgbtGreen = Ggreen;
            image[i - 1][m - 1].rgbtBlue = Gblue;

        }

    }
    return;
}
