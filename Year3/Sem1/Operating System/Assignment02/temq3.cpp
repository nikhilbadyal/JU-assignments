#include<bits/stdc++.h>
#include<pthread.h>
#include<unistd.h>
#define MAX 5
#define MaxItems 5 
using namespace std;
class BoundedBuffer
{
private:
  int buffer[MAX];
  int fill, use;
  int fullEntries;
  pthread_mutex_t monitor;  // monitor lock
  pthread_cond_t empty;
  pthread_cond_t full;
public:
  BoundedBuffer ()
  {
    use = fill = fullEntries = 0;
  }
  void produce (int element)
  {
    pthread_mutex_lock (&monitor);
    while (fullEntries == MAX)
      pthread_cond_wait (&empty, &monitor);
    buffer[fill] = element;
    printf("Producer %d : Insert Item %d at %d\n", buffer[fill],fill);
    fill = (fill + 1) % MAX;
    fullEntries++;
    sleep(rand()%2);
    pthread_cond_signal (&full);
    pthread_mutex_unlock (&monitor);
  }
  int consume ()
  {
    pthread_mutex_lock (&monitor);
    while (fullEntries == 0)
      pthread_cond_wait (&full, &monitor);
    int tmp = buffer[use];
    printf("Consumer %d: Remove Item %d from %d\n",tmp, use);
    use = (use + 1) % MAX;
    fullEntries--;
    sleep(rand()%2);
    pthread_cond_signal (&empty);
    pthread_mutex_unlock (&monitor);
    return tmp;
  }
}b;

void* producer(void *arg)
{
    for(int i = 0; i < MaxItems; i++) 
    {
        b.produce(i);
        fflush(stdout);
    }
}
void* consumer(void *arg)
{
    for(int i = 0; i < MaxItems; i++)
    {
        cout<<b.consume()<<" ";
        fflush(stdout);
    }
}
int main()
{
    pthread_t pro[20],con[20];//thread variable to identify thread in the system
    int n_prod, n_con;
    printf("Enter No. of Producers : ");
    scanf("%d",&n_prod);
    printf("Enter No. of Consumers : ");
    scanf("%d",&n_con);

    int a[5] = {1,2,3,4,5}; //Just used for numbering the producer and consumer
    int *prod_arr = (int*)malloc(n_prod*sizeof(int));
    int *con_arr = (int*)malloc(n_con*sizeof(int));
    for(int i = 0; i < n_prod; i++) {
        prod_arr[i]=i+1;
        pthread_create(&pro[i], NULL, producer, (void *)&prod_arr[i]);
        
    }
    for(int i = 0; i < n_con; i++) {
        con_arr[i]=i+1;
        pthread_create(&con[i], NULL, consumer, (void *)&con_arr[i]);
    }

    for(int i = 0; i < n_prod; i++) {
        pthread_join(pro[i], NULL);
    }
    for(int i = 0; i < n_con; i++) {
        pthread_join(con[i], NULL);
        
    }
    return 0;
}