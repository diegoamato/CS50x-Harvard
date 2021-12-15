#include "helpers.h"
#include <math.h>
#include <stdio.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE grayscale[height][width];
    float total = 0;
    int avrg_RGB = 0;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            total = image[i][j].rgbtRed +
                    image[i][j].rgbtGreen +
                    image[i][j].rgbtBlue;
                    
            avrg_RGB = round (total / 3);
            
            grayscale[i][j].rgbtRed = avrg_RGB;
            grayscale[i][j].rgbtGreen = avrg_RGB;
            grayscale[i][j].rgbtBlue = avrg_RGB;
            
            total =0;
            avrg_RGB = 0;
        }
    }

    for (int k = 0; k < height; k++)
    {
        for (int z = 0; z < width; z++)
        {
            image[k][z].rgbtRed = grayscale[k][z].rgbtRed;
            image[k][z].rgbtGreen = grayscale[k][z].rgbtGreen;
            image[k][z].rgbtBlue = grayscale[k][z].rgbtBlue;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE sepia[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int r = round(.393 * image[i][j].rgbtRed +
                          .769 * image[i][j].rgbtGreen +
                          .189 * image[i][j].rgbtBlue);

                if (r >= 255)
                {
                    sepia[i][j].rgbtRed = 255;
                }
                else
                {
                    sepia[i][j].rgbtRed = r;
                }

            int g = round(.349 * image[i][j].rgbtRed +
                          .686 * image[i][j].rgbtGreen +
                          .168 * image[i][j].rgbtBlue);

                if (g >= 255)
                {
                   sepia[i][j].rgbtGreen = 255;
                }
                else
                {
                  sepia[i][j].rgbtGreen = g;
                }

            int b = round(.272 * image[i][j].rgbtRed +
                          .534 * image[i][j].rgbtGreen +
                          .131 * image[i][j].rgbtBlue);

                if (b >= 255)
                {
                    sepia[i][j].rgbtBlue = 255;
                }
                else
                {
                    sepia[i][j].rgbtBlue = b;
                }
        }
    }

    for (int k = 0; k < height; k++)
    {
        for (int z = 0; z < width; z++)
        {
            image[k][z].rgbtRed = sepia[k][z].rgbtRed;
            image[k][z].rgbtGreen = sepia[k][z].rgbtGreen;
            image[k][z].rgbtBlue = sepia[k][z].rgbtBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE reflect[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            reflect[i][j].rgbtRed = image[i][j].rgbtRed;
            reflect[i][j].rgbtGreen = image[i][j].rgbtGreen;
            reflect[i][j].rgbtBlue = image[i][j].rgbtBlue;
        }
    }
    
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = reflect[i][width - j - 1].rgbtRed;
            image[i][j].rgbtGreen = reflect[i][width - j - 1].rgbtGreen;
            image[i][j].rgbtBlue = reflect[i][width - j - 1].rgbtBlue;   
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE blur[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int count_blur = 0;
            int avrg_r = 0, avrg_g = 0, avrg_b = 0;
            float tot_r = 0, tot_g = 0, tot_b = 0;
            
            for (int x = i - 1; x <= i + 1; x++)
            {
                if (x >= 0 && x < height)
                {
                    for (int y = j - 1; y <= j + 1; y++)
                    {
                        if (y >= 0 && y < width)
                        {
                            tot_r += image[x][y].rgbtRed;
                            tot_g += image[x][y].rgbtGreen;
                            tot_b += image[x][y].rgbtBlue;
                            count_blur++;
                        }
                    }
                }
            }
            
            avrg_r = round (tot_r / count_blur);
            avrg_g = round (tot_g / count_blur);
            avrg_b = round (tot_b / count_blur);
            
            blur[i][j].rgbtRed = avrg_r;
            blur[i][j].rgbtGreen = avrg_g;
            blur[i][j].rgbtBlue = avrg_b;
        }
    }

    for (int k = 0; k < height; k++)
    {
        for (int z = 0; z < width; z++)
        {
            image[k][z].rgbtRed = blur[k][z].rgbtRed;
            image[k][z].rgbtGreen = blur[k][z].rgbtGreen;
            image[k][z].rgbtBlue = blur[k][z].rgbtBlue;
        }
    }
    return;
}
