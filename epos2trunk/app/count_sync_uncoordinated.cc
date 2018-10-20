// EPOS Synchronizer Component Test Program

#include <utility/ostream.h>
#include <semaphore.h>
#include <thread.h>
#include <machine.h>

using namespace EPOS;

int counter = 0;
Thread * phil[2];

OStream cout;

// mythread()
// Simply adds 1 to counter repeatedly, in a loop
// No, this is not how you would add 10,000,000 to
// a counter, but it shows the problem nicely.
int mythread() {
    for (int i = 0; i < 1e1; i++) {
        counter = counter + 1;
    }
    return 0;
}

// main()
// Just launches two threads (pthread_create)
// and then waits for them (pthread_join)
int main()
{
    cout << "main: begin (counter = " << counter << ")" << endl;

    phil[0] = new Thread(&mythread);
    phil[1] = new Thread(&mythread);

    // join waits for the threads to finish
    int ret1 = phil[0]->join();
    int ret2 = phil[1]->join();

    cout << "main: done with both (counter = " << counter << ")"<< endl;

    delete phil[0];
    delete phil[1];

    cout << "The end!" << endl;

    return 0;
}