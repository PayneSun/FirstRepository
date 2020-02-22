


#include <iostream>
#include <cstdlib>
#include <pthread.h>
#include <unistd.h>

using namespace std;

#define NUM_THREADS 5


void *say_hello(void *args)
{
	int tid = *((int*)args);
	cout << "Hello Thread! " << tid << endl;
	return 0;
}


void *wait(void *t)
{
	int i;
	long tid;

	tid = *t;
	sleep(1);
	cout << "Sleeping in thread" << endl;
	cout << "Thread with id: " << tid << "...exiting" << endl;
	pthread_exit(NULL);
	return 0;
}


int main()
{
	int i, rc;
	pthread_t threads[NUM_THREADS];
	pthread_attr_t attr;
	void *status;

	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

	for (i = 0; i < NUM_THREADS; ++i) {
		cout << "main(): creating thread " << i << endl;
		rc = pthread_create(&threads[i], NULL, wait, (void*)&i);
		if (rc) {
			cout << "pthread_create error: error_code=" << rc << endl;
			exit(-1);
		}
	}

	pthread_attr_destroy(&attr);
	for (i = 0; i < NUM_THREADS; i++) {
		rc = pthread_join(threads[i], &status);
		if (rc) {
			cout << "Error: unable to join, " << rc << endl;
			exit(-1);
		}
		cout << "Main: completed thread id: " << i << endl;
		cout << " exiting with status: " << status << endl;
	}

	pthread_exit(NULL);
}
