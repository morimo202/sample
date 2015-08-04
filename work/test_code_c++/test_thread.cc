#include <iostream>
#include <unistd.h>
#include <pthread.h>
#include <queue>
#include <string>

using namespace std;

int counter = 0;
queue<std::string> q1;

void* thread( void* args )
{
    int i = 0;
    for( i=0; i < 10; i++, counter++ ){
        cout << "thread : ";
        cout << counter << endl;
        sleep(1);
    }
    while( !q1.empty() ){
        cout << "Queue : ";
        cout << q1.front() << endl;
        q1.pop();
    }

    return NULL;
}

int main()
{
    pthread_t th;

    q1.push("Data-1");
    q1.push("Data-2");
    q1.push("Data-3");

    pthread_create( &th, NULL, thread, (void*)NULL);


    //スレッド終了待ち
    pthread_join( th, NULL );

    return 0;
}

