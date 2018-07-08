
#include<stdio.h>
#include<stdlib.h>

void fillmatrix(char** p, int rows, int cols)
{
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<cols; j++)
        {
            p[i][j] = '*';
        }
    }
}

void printmatrix(char** p, int rows, int cols)
{
    for(int i=rows-1; i>=0; i--)
    {
        printf("\n");
        printf("%d |",i);
        
        for(int j=0; j<cols; j++)
        {
            printf(" %c |",p[i][j]);
        }

        printf("\n");
    }
    printf("\n");
    printf(" ");
    for(int k=0; k<cols; k++)
    {
        printf("   %d ",k);
    }

    printf("\n");

}

int makemove(char **p, int rows, int cols, int col, char c)
{
    int j;
    j = col;
    for(int i=0; i<rows; i++)
    {
        if(p[i][j] == '*')
        {
            p[i][j] = c;
            return 1;
        }
    }
    return 0;
}

int horizon_win(char **v, int rows,  int cols, char c)
{
    if(c == '*')
    {
        return 0;
    }
    else
    {
        for(int i=0; i<rows; i++)
        {
            for(int j=0; j<cols-4+1; j++)
            {   
                if(c == v[i][j])
                {
                    c = v[i][j];
                    int count = 0;
                    int m = j;
                    for(int k=j; k<m+4; k++)
                    {
                        if(c == v[i][j])
                        {
                            j++;
                            count++;
                        }
                        else
                        {   break;  }
                    }
                    if(count == 4)
                    {   return 1;   }
                }
            }

        }
    
        return 0;
    }
}

int vertical_win(char **v, int rows,  int cols, char c)
{
    if(c == '*')
    {
        return 0;
    }
    else
    {
        for(int i=0; i<cols; i++)
        {
            for(int j=0; j<rows-4+1; j++)
            {   
                if(c == v[j][i])
                {
                    c = v[j][i];
                    int count = 0;
                    int m = j;
                    for(int k=j; k<m+4; k++)
                    {
                        if(c == a[j])
                        {
                            j++;
                            count++;
                        }
                        else
                        {   break;  }
                    }
                    if(count == 4)
                    {   return 1;   }
                }
            }

        }
    
        return 0;
    }
}

int horizontal(char *a,int cols, char c)
{
   
        if(c == '*')
        {   return 0;   }
        else
        {
            for(int j=0; j<cols-4+1; j++)
            {   
                if(c == a[j])
                {
                    c = a[j];
                    int count = 0;
                    int m = j;
                    for(int k=j; k<m+4; k++)
                    {
                        if(c == v[j][i])
                        {
                            j++;
                            count++;
                        }
                        else
                        {   break;  }
                    }
                    if(count == 4)
                    {   return 1;   }
                }
            }
            return 0;

        }
}
int validate(char **p, int rows, int cols, int col)
{
    if(col>cols || col<0 || p[rows-1][col] != '*')
    {
        return 0;
    }
    return 1;
}

int win(char **p, int rows, int cols, char c)
{
    if(horizon_win(p, rows, cols, c))
    {   return 1;   }
    else if(vertical_win(p, rows, cols, c))
    {   return 1; }
    else
    {   return 0;   }
}


int draw_game(char **p, int rows, int cols)
{
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<cols; j++)
        {
            if(p[i][j] == '*')
            {   return 0;   }
        }
    }
    return 1;
}
int main()
{
    int rows = 8, cols = 8;
    char **p;
    int x;
    int player = 1;
    char sym[2] = "$#";

    p = (char**)malloc(rows * sizeof(char*));

    for(int i=0; i<rows; i++)
    {
        p[i] = (char*)malloc(cols * sizeof(char));
    }
    
    fillmatrix(p, rows, cols);
    printmatrix(p, rows, cols);
    

    /*do
    {
        player = !player;

        do
        {
            printf("player %d turn \n",player+1);
            printf("enter your position in term of column\n");
            scanf("%d",&x);
        }while(!validate(p, rows, cols, x));

        makemove(p, rows, cols, x, sym[player]);
        printmatrix(p, rows, cols);
    }while(!win(p, rows, cols, sym[player]) && !draw_game(p, rows, cols));

    int ret = draw_game(p, rows, cols);
    if(ret == 1)
    {
        printf("game is draw\n");
    }
    else
    {
        printf("player %d win the game\n",player);
    }*/


    char a[100] = "#####!$##";
    int ret = horizontal(a, cols, '#');
    if(ret == 1)
    {   printf("game is win\n");   }
return 0;   
}
