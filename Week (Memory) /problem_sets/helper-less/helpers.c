#include "helpers.h"
#include <math.h>
#include <stdio.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // simply collecting RGB values from pixel, making average and
            // casting it back
            float average = (image[i][j].rgbtRed + image[i][j].rgbtGreen +
                             image[i][j].rgbtBlue) / 3.0;
            image[i][j].rgbtRed = round(average);
            image[i][j].rgbtGreen = round(average);
            image[i][j].rgbtBlue = round(average);
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // For each colour ajusting value by given coeficients, making sure
            // the value does not exceed 255
            int sepiaRed = round(.393 * image[i][j].rgbtRed + .769 *
                                 image[i][j].rgbtGreen + .189 *
                                 image[i][j].rgbtBlue);
            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            int sepiaGreen = round(.349 * image[i][j].rgbtRed + .686 *
                                   image[i][j].rgbtGreen + .168 *
                                   image[i][j].rgbtBlue);
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            int sepiaBlue = round(.272 * image[i][j].rgbtRed + .534 *
                                  image[i][j].rgbtGreen + .131 *
                                  image[i][j].rgbtBlue);
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }
            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            {
                // making instance for even number of columns
                if (width % 2 == 0)
                {
                    int tempRed = image[i][width / 2 - 1 - j].rgbtRed;
                    image[i][width / 2 - 1 - j].rgbtRed = image[i][width / 2 +
                                                          j].rgbtRed;
                    image[i][width / 2 + j].rgbtRed = tempRed;
                    int tempGreen = image[i][width / 2 - 1 - j].rgbtGreen;
                    image[i][width / 2 - 1 - j].rgbtGreen = image[i][width / 2 +
                                                            j].rgbtGreen;
                    image[i][width / 2 + j].rgbtGreen = tempGreen;
                    int tempBlue = image[i][width / 2 - 1 - j].rgbtBlue;
                    image[i][width / 2 - 1 - j].rgbtBlue = image[i][width / 2 +
                                                           j].rgbtBlue;
                    image[i][width / 2 + j].rgbtBlue = tempBlue;
                }
                // making instance for odd number of columns
                if (width % 2 != 0)
                {
                    int tempRed = image[i][width / 2 - 1 - j].rgbtRed;
                    image[i][width / 2 - 1 - j].rgbtRed = image[i][width / 2 + 1 + j].rgbtRed;
                    image[i][width / 2 + 1 + j].rgbtRed = tempRed;
                    int tempGreen = image[i][width / 2 - 1 - j].rgbtGreen;
                    image[i][width / 2 - 1 - j].rgbtGreen = image[i][width / 2 + 1 + j].rgbtGreen;
                    image[i][width / 2 + 1 + j].rgbtGreen = tempGreen;
                    int tempBlue = image[i][width / 2 - 1 - j].rgbtBlue;
                    image[i][width / 2 - 1 - j].rgbtBlue = image[i][width / 2 + 1 + j].rgbtBlue;
                    image[i][width / 2 + 1 + j].rgbtBlue = tempBlue;
                }

            }
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j].rgbtRed = image[i][j].rgbtRed;
            copy[i][j].rgbtGreen = image[i][j].rgbtGreen;
            copy[i][j].rgbtBlue = image[i][j].rgbtBlue;
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if ((i > 0 && i < height - 1) && (j > 0 && j < width - 1))
            {
                int avgRed = 0;
                int avgGreen = 0;
                int avgBlue = 0;

                for (int N = -1; N < 2; N++)
                {
                    for (int K = -1; K < 2; K++)
                    {
                        avgRed += copy[i + N][j + K].rgbtRed;
                        avgGreen += copy[i + N][j + K].rgbtGreen;
                        avgBlue += copy[i + N][j + K].rgbtBlue;
                    }
                }

                image[i][j].rgbtRed = round(avgRed / 9.0);
                image[i][j].rgbtGreen = round(avgGreen / 9.0);
                image[i][j].rgbtBlue = round(avgBlue / 9.0);
            }
            // 1st row
            if (i == 0 && (j > 0 && j < width - 1))
            {
                int avgRed = 0;
                int avgGreen = 0;
                int avgBlue = 0;

                for (int N = 0; N < 2; N++)
                {
                    for (int K = -1; K < 2; K++)
                    {
                        avgRed += copy[i + N][j + K].rgbtRed;
                        avgGreen += copy[i + N][j + K].rgbtGreen;
                        avgBlue += copy[i + N][j + K].rgbtBlue;
                    }
                }

                image[i][j].rgbtRed = round(avgRed / 6.0);
                image[i][j].rgbtGreen = round(avgGreen / 6.0);
                image[i][j].rgbtBlue = round(avgBlue / 6.0);
            }
            // last row
            if (i == height - 1 && (j > 0 && j < width - 1))
            {
                int avgRed = 0;
                int avgGreen = 0;
                int avgBlue = 0;

                for (int N = -1; N < 1; N++)
                {
                    for (int K = -1; K < 2; K++)
                    {
                        avgRed += copy[i + N][j + K].rgbtRed;
                        avgGreen += copy[i + N][j + K].rgbtGreen;
                        avgBlue += copy[i + N][j + K].rgbtBlue;
                    }
                }

                image[i][j].rgbtRed = round(avgRed / 6.0);
                image[i][j].rgbtGreen = round(avgGreen / 6.0);
                image[i][j].rgbtBlue = round(avgBlue / 6.0);
            }
            //1st column
            if (i > 0 && i < height - 1 && j == 0)
            {
                int avgRed = 0;
                int avgGreen = 0;
                int avgBlue = 0;

                for (int N = -1; N < 2; N++)
                {
                    for (int K = 0; K < 2; K++)
                    {
                        avgRed += copy[i + N][j + K].rgbtRed;
                        avgGreen += copy[i + N][j + K].rgbtGreen;
                        avgBlue += copy[i + N][j + K].rgbtBlue;
                    }
                }

                image[i][j].rgbtRed = round(avgRed / 6.0);
                image[i][j].rgbtGreen = round(avgGreen / 6.0);
                image[i][j].rgbtBlue = round(avgBlue / 6.0);
            }
            // last column
            if (i > 0 && i < height - 1 && j == width - 1)
            {
                int avgRed = 0;
                int avgGreen = 0;
                int avgBlue = 0;

                for (int N = -1; N < 2; N++)
                {
                    for (int K = -1; K < 1; K++)
                    {
                        avgRed += copy[i + N][j + K].rgbtRed;
                        avgGreen += copy[i + N][j + K].rgbtGreen;
                        avgBlue += copy[i + N][j + K].rgbtBlue;
                    }
                }

                image[i][j].rgbtRed = round(avgRed / 6.0);
                image[i][j].rgbtGreen = round(avgGreen / 6.0);
                image[i][j].rgbtBlue = round(avgBlue / 6.0);
            }
            // top left corner-case
            if (i == 0 && j == 0)
            {
                int avgRed = 0;
                int avgGreen = 0;
                int avgBlue = 0;

                for (int N = 0; N < 2; N++)
                {
                    for (int K = 0; K < 2; K++)
                    {
                        avgRed += copy[i + N][j + K].rgbtRed;
                        avgGreen += copy[i + N][j + K].rgbtGreen;
                        avgBlue += copy[i + N][j + K].rgbtBlue;
                    }
                }

                image[i][j].rgbtRed = round(avgRed / 4);
                image[i][j].rgbtGreen = round(avgGreen / 4);
                image[i][j].rgbtBlue = round(avgBlue / 4);
            }
            // top right corner-case
            if (i == 0 && j == width - 1)
            {
                int avgRed = 0;
                int avgGreen = 0;
                int avgBlue = 0;

                for (int N = 0; N < 2; N++)
                {
                    for (int K = -1; K < 1; K++)
                    {
                        avgRed += copy[i + N][j + K].rgbtRed;
                        avgGreen += copy[i + N][j + K].rgbtGreen;
                        avgBlue += copy[i + N][j + K].rgbtBlue;
                    }
                }

                image[i][j].rgbtRed = round(avgRed / 4.0);
                image[i][j].rgbtGreen = round(avgGreen / 4.0);
                image[i][j].rgbtBlue = round(avgBlue / 4.0);
            }
            // bot left corner-case
            if (i == height - 1 && j == 0)
            {
                int avgRed = 0;
                int avgGreen = 0;
                int avgBlue = 0;

                for (int N = -1; N < 1; N++)
                {
                    for (int K = 0; K < 2; K++)
                    {
                        avgRed += copy[i + N][j + K].rgbtRed;
                        avgGreen += copy[i + N][j + K].rgbtGreen;
                        avgBlue += copy[i + N][j + K].rgbtBlue;
                    }
                }

                image[i][j].rgbtRed = round(avgRed / 4.0);
                image[i][j].rgbtGreen = round(avgGreen / 4.0);
                image[i][j].rgbtBlue = round(avgBlue / 4.0);
            }
            // bot right corner-case
            if (i == height - 1 && j == width - 1)
            {
                int avgRed = 0;
                int avgGreen = 0;
                int avgBlue = 0;

                for (int N = -1; N < 1; N++)
                {
                    for (int K = -1; K < 1; K++)
                    {
                        avgRed += copy[i + N][j + K].rgbtRed;
                        avgGreen += copy[i + N][j + K].rgbtGreen;
                        avgBlue += copy[i + N][j + K].rgbtBlue;
                    }
                }
                image[i][j].rgbtRed = round(avgRed / 4.0);
                image[i][j].rgbtGreen = round(avgGreen / 4.0);
                image[i][j].rgbtBlue = round(avgBlue / 4.0);
            }


        }
    }
    return;
}
