# include <stdio.h>
# include <unistd.h>
# include <pthread.h>

int i = 0;

void* func1()
{
    sleep(3);
    printf("2222\n");
    i++;
        
    return(0);
}
void* func()
{
    sleep(0);
    i++;
        
    return(0);
}

int main (void)
{
    pthread_t a, b;
    pthread_create(&a, NULL, &func1, NULL);
    pthread_create(&b, NULL, &func, NULL);
    pthread_join(a, NULL);
    pthread_join(b, NULL);
    printf("%d \n", i);

    return (0);
}