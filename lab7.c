#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef struct p
{
    char val;
    int row,col;
}Pixel;
#define row_number 6
#define col_number 9
#define total_pixel_number  row_number * col_number
void read_image(Pixel pix[]);
void fill_canvas(Pixel pixels[], Pixel canvas[][9]);
void draw_image(Pixel canvas[][9]);
int main(void) {
Pixel pixels[total_pixel_number];
Pixel canvas[row_number][col_number];
read_image(pixels);
fill_canvas(pixels, canvas);
draw_image(canvas);
return 0;
}
void read_image(Pixel pix[])
{
    FILE *fp=fopen("image.txt","r");
    int i=0;
    char t1,t2,t3;
    while (!feof(fp))
    {
        fscanf(fp," %c  %c %d %c %d %c",&pix[i].val,&t1,&pix[i].row,&t2,&pix[i].col,&t3);
        i++;
    }
    fclose(fp);
}
void fill_canvas(Pixel pixels[], Pixel canvas[][9])
{
    int i=0;
    while (i<total_pixel_number)
    {
        canvas[pixels[i].row][pixels[i].col].val=pixels[i].val;
        i++;
    }
}
void draw_image(Pixel canvas[][9])
{
    int p=0;
    int i=0,j=0;
    while (p<total_pixel_number)
    {
        if (j==col_number)
        {
            printf("\n");
            j=0;
            i++;
        }
        printf("%c ",canvas[i][j].val);
        j++;
        p++;
    }
}
