#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int new_value = 0;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            new_value = round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0);
            image[i][j].rgbtRed = new_value;
            image[i][j].rgbtGreen = new_value;
            image[i][j].rgbtBlue = new_value;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int s_red, s_green, s_blue;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            s_red = round(image[i][j].rgbtRed * 0.393 + image[i][j].rgbtGreen * 0.769 + image[i][j].rgbtBlue * 0.189);
            s_green = round(image[i][j].rgbtRed * 0.349 + image[i][j].rgbtGreen * 0.686 + image[i][j].rgbtBlue * 0.168);
            s_blue = round(image[i][j].rgbtRed * 0.272 + image[i][j].rgbtGreen * 0.534 + image[i][j].rgbtBlue * 0.131);
            if (s_red > 255)
                s_red = 255;
            if (s_green > 255)
                s_green = 255;
            if (s_blue > 255)
                s_blue = 255;
            image[i][j].rgbtRed = s_red;
            image[i][j].rgbtGreen = s_green;
            image[i][j].rgbtBlue = s_blue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int temp_red, temp_green, temp_blue;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            temp_red = image[i][j].rgbtRed;
            temp_green = image[i][j].rgbtGreen;
            temp_blue = image[i][j].rgbtBlue;
            image[i][j].rgbtRed = image[i][width - j - 1].rgbtRed;
            image[i][j].rgbtGreen = image[i][width - j - 1].rgbtGreen;
            image[i][j].rgbtBlue = image[i][width - j - 1].rgbtBlue;
            image[i][width - j - 1].rgbtRed = temp_red;
            image[i][width - j - 1].rgbtGreen = temp_green;
            image[i][width - j - 1].rgbtBlue = temp_blue;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    int avg_red = 0, avg_green = 0, avg_blue = 0;
    float pixnr = 0;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            for (int k = -1; k < 2; k++)
            {
                for (int l = -1; l < 2; l++)
                {
                    if ((i + k) >= 0 && (i + k) < height && (j + l) >= 0 && (j + l) < width)
                    {
                        avg_red += copy[i + k][j + l].rgbtRed;
                        avg_green += copy[i + k][j + l].rgbtGreen;
                        avg_blue += copy[i + k][j + l].rgbtBlue;
                        pixnr++;
                    }
                }
            }
            avg_red = round(avg_red / pixnr);
            avg_green = round(avg_green / pixnr);
            avg_blue = round(avg_blue / pixnr);
            image[i][j].rgbtRed = avg_red;
            image[i][j].rgbtGreen = avg_green;
            image[i][j].rgbtBlue = avg_blue;
            pixnr = 0;
            avg_red = 0;
            avg_green = 0;
            avg_blue = 0;
        }
    }
    return;
}
