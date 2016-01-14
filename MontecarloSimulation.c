#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <errno.h>
 
  /* double random_generator(int min, int max)
{
        double r;
        r = (double) (rand() % RAND_MAX);
        return (((max - min)*r + min)/RAND_MAX);
}   */
 
 

int main(int argc, char *argv[])
{
        long n;
        int i, area = 0;
        char *endptr, *s;
        errno = 0;
        double x_cord, y_cord, areatot = 0;
        if (argc < 2)
        {
                fprintf(stderr, "Expected 2 arguments\n");
                return EXIT_FAILURE;
        }
        s = argv[1];
        n = strtol(s, &endptr, 0);
        if (*endptr != '\0' || errno != 0)
        {        /* Not necessarily an error... */
                fprintf(stderr,"Further characters after number: %s\n", endptr);
                return EXIT_FAILURE;
        }
 
        for(i = 0; i <= n; i++)
        {
                //x_cord = random_generator(0, 1);       
                //y_cord = random_generator(0, 1);
                //fprintf(stdout, "x_cord= %f , y_cord= %f\n", x_cord, y_cord);
                x_cord= (double) rand()/ (RAND_MAX+1.0);
                y_cord= (double) rand()/ (RAND_MAX+1.0);
                if(y_cord <= (x_cord * x_cord))
                {
                        area++;
                }
        }      
        areatot = (double) area / n;
        fprintf(stdout, "Area -> %f\n", areatot);
        return EXIT_SUCCESS;
}