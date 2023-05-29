//EDGES
            if (i == 0)
            {
                if (m == 0)
                {
                    sum5 = image[i][m + 1].rgbtRed * (2);
                    sum6 = image[i + 1][m + 1].rgbtRed * (1);
                    gxred = sum5 + sum6;

                    sum5 = image[i][m + 1].rgbtGreen * (2);
                    sum6 = image[i + 1][m + 1].rgbtGreen * (1);
                    gxgreen = sum5 + sum6;

                    sum5 = image[i][m + 1].rgbtBlue * (2);
                    sum6 = image[i + 1][m + 1].rgbtBlue * (1);
                    gxgreen = sum5 + sum6;
                }
                else if (m == (widht -1))
                {
                    sum2 = image[i][m - 1].rgbtRed * (-2);
                    sum3 = image[i + 1][m - 1].rgbtRed * (-1);
                    gxred = sum2 + sum3;

                    sum2 = image[i][m - 1].rgbtGreen * (-2);
                    sum3 = image[i + 1][m - 1].rgbtGreen * (-1);
                    gxred = sum2 + sum3;

                    sum2 = image[i][m - 1].rgbtBlue * (-2);
                    sum3 = image[i + 1][m - 1].rgbtBlue * (-1);
                    gxred = sum2 + sum3;
                }
                else
                {
                    sum2 = image[i][m - 1].rgbtRed * (-2);
                    sum3 = image[i + 1][m - 1].rgbtRed * (-1);
                    sum5 = image[i][m + 1].rgbtRed * (2);
                    sum6 = image[i + 1][m + 1].rgbtRed * (1);
                    gxred = sum2 + sum3 + sum5 + sum6;

                    sum2 = image[i][m - 1].rgbtGreen * (-2);
                    sum3 = image[i + 1][m - 1].rgbtGreen * (-1);
                    sum5 = image[i][m + 1].rgbtGreen * (2);
                    sum6 = image[i + 1][m + 1].rgbtGreen * (1);
                    gxred = sum2 + sum3 + sum5 + sum6;

                    sum2 = image[i][m - 1].rgbtBlue * (-2);
                    sum3 = image[i + 1][m - 1].rgbtBlue * (-1);
                    sum5 = image[i][m + 1].rgbtBlue * (2);
                    sum6 = image[i + 1][m + 1].rgbtBlue * (1);
                    gxred = sum2 + sum3 + sum5 + sum6;
                }
            else if (i == (height - 1))
            {
                if (m == 0)
                {
                    sum4 = image[i - 1][m + 1].rgbtRed * (1);
                    sum5 = image[i][m + 1].rgbtRed * (2);
                    gxred = sum4 + sum5;

                    sum4 = image[i - 1][m + 1].rgbtGreen * (1);
                    sum5 = image[i][m + 1].rgbtGreen * (2);
                    gxred = sum4 + sum5;

                    sum4 = image[i - 1][m + 1].rgbtBlue * (1);
                    sum5 = image[i][m + 1].rgbtBlue * (2);
                    gxred = sum4 + sum5;
                }
                else if (m == (widht -1))
                {
                    sum1 = image[i - 1][m - 1].rgbtRed * (-1);
                    sum2 = image[i][m - 1].rgbtRed * (-2);
                    gxred = sum1 + sum2;

                    sum1 = image[i - 1][m - 1].rgbtGreen * (-1);
                    sum2 = image[i][m - 1].rgbtGreen * (-2);
                    gxred = sum1 + sum2;

                    sum1 = image[i - 1][m - 1].rgbtBlue * (-1);
                    sum2 = image[i][m - 1].rgbtBlue * (-2);
                    gxred = sum1 + sum2;
                }
                else
                {
                    sum1 = image[i - 1][m - 1].rgbtRed * (-1);
                    sum2 = image[i][m - 1].rgbtRed * (-2);
                    sum4 = image[i - 1][m + 1].rgbtRed * (1);
                    sum5 = image[i][m + 1].rgbtRed * (2);
                    gxred = sum1 + sum2 + sum4 + sum5;

                    sum1 = image[i - 1][m - 1].rgbtGreen * (-1);
                    sum2 = image[i][m - 1].rgbtGreen * (-2);
                    sum4 = image[i - 1][m + 1].rgbtGreen * (1);
                    sum5 = image[i][m + 1].rgbtGreen * (2);
                    gxred = sum1 + sum2 + sum4 + sum5;

                    sum1 = image[i - 1][m - 1].rgbtBlue * (-1);
                    sum2 = image[i][m - 1].rgbtBlue * (-2);
                    sum4 = image[i - 1][m + 1].rgbtBlue * (1);
                    sum5 = image[i][m + 1].rgbtBlue * (2);
                    gxred = sum1 + sum2 + sum4 + sum5;
                }
            }
            else if ((m == 0) && (i != 0) && (i != (height - 1))
            {
                sum4 = image[i - 1][m + 1].rgbtRed * (1);
                sum5 = image[i][m + 1].rgbtRed * (2);
                sum6 = image[i + 1][m + 1].rgbtRed * (1);
                gxred = sum4 + sum5 + sum6;

                sum4 = image[i - 1][m + 1].rgbtGreen * (1);
                sum5 = image[i][m + 1].rgbtGreen * (2);
                sum6 = image[i + 1][m + 1].rgbtGreen * (1);
                gxred = sum4 + sum5 + sum6;

                sum4 = image[i - 1][m + 1].rgbtBlue * (1);
                sum5 = image[i][m + 1].rgbtBlue * (2);
                sum6 = image[i + 1][m + 1].rgbtBlue * (1);
                gxred = sum4 + sum5 + sum6;
            }
            else if ((m == (widht - 1)) && (i != 0) && (i != (height - 1))
            {
                sum1 = image[i - 1][m - 1].rgbtRed * (-1);
                sum2 = image[i][m - 1].rgbtRed * (-2);
                sum3 = image[i + 1][m - 1].rgbtRed * (-1);
                gxred = sum1 + sum2 + sum3;

                sum1 = image[i - 1][m - 1].rgbtGreen * (-1);
                sum2 = image[i][m - 1].rgbtGreen * (-2);
                sum3 = image[i + 1][m - 1].rgbtGreen * (-1);
                gxred = sum1 + sum2 + sum3;

                sum1 = image[i - 1][m - 1].rgbtBlue * (-1);
                sum2 = image[i][m - 1].rgbtBlue * (-2);
                sum3 = image[i + 1][m - 1].rgbtBlue * (-1);
                gxred = sum1 + sum2 + sum3;
            }
            }

printf("checking sums\n");
                printf("%i\n", sum1);
                printf("%i\n", sum2);
                printf("%i\n", sum3);
                printf("%i\n", sum4);
                printf("%i\n", sum5);
                printf("%i\n", sum6);

printf("checking 0\n");
    for (int i = 0; i < 5; i++)
    {

       printf("%i", fimage[0][i].rgbtRed);
       printf("%i", fimage[newheight - 1][i].rgbtRed);

    }
    printf("\n");
    printf("checking 0 again\n");
    for (int i = 0; i < 5; i++)
    {

       printf("%i", fimage[i][0].rgbtRed);
       printf("%i", fimage[i][newidht - 1].rgbtRed);
    }

    printf("\n");
    printf("checking trasppass of image into fimage\n");
    
    for (int i = 1; i <= 5; i++)
    {
        for (int m = 1; m <= 5; m++)
        {


            printf("%i", image[i - 1][m - 1].rgbtRed);

            printf("%i\n", fimage[i][m].rgbtRed);
        }
    }