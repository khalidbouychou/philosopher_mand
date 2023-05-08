# Hak Sir Te9ra 
*************************************

# Problem description

The Dining Philosophers problem is a classical example in computer science to illustrate synchronisation issues in concurrent processes. It was originally formulated in 1965 by E. W. Dijkstra as a student exam exercise, and was later reworked in its current form by Tony Hoare:

Nsilent philosophers sit at a round table with bowls of spaghetti. Forks are placed between each pair of adjacent philosophers.
Each philosopher must alternately think and eat. However, a philosopher can only eat spaghetti when they have both left and right forks. Each fork can be held by only one philosopher and so a philosopher can use the fork only if it is not being used by another philosopher. After an individual philosopher finishes eating, they need to put down both forks so that the forks become available to others. A philosopher can take the fork on their right or the one on their left as they become available, but cannot start eating before getting both forks.
This projet dependly tremendous of architecture of you computer.

![download](https://user-images.githubusercontent.com/41027645/236893864-edfa4e3a-0d98-402b-8b2b-c7a4b560dded.png)


# Solution of Dining Philosophers Problem

A solution of the Dining Philosophers Problem is to use a semaphore to represent a chopstick. A chopstick can be picked up by executing a wait operation on the semaphore and released by executing a signal semaphore.

I did that in linux debian

thread :
https://www.pcerror-fix.com/about-processor-threads
https://www.youtube.com/watch?v=uA8X5zNOGw8&list=PL9IEJIKnBJjFZxuqyJ9JqVYmuFZHr7CFM
https://computing.llnl.gov/tutorials/pthreads/
http://www.csc.villanova.edu/~mdamian/threads/posixthreads.html#exercise_2
https://timmurphy.org/2010/05/04/pthreads-in-c-a-minimal-working-example/
https://www.ai.univ-paris8.fr/~alinehuf/m1/cours2-3/cours2-3_threads_acces_concurents.pdf

fork :

https://www.youtube.com/watch?v=PwxTbksJ2fo
https://www.youtube.com/watch?v=cex9XrZCU14
https://www.geeksforgeeks.org/fork-system-call/


Mutex and Semaphore:

https://docs.oracle.com/cd/E19253-01/816-5137/sync-11157/index.html
https://stackoverflow.com/questions/34524/what-is-a-mutex
https://stackoverflow.com/questions/9369873/sem-init-what-is-the-value-parameter-for
https://stackoverflow.com/questions/2065747/pthreads-mutex-vs-semaphore
https://www.youtube.com/watch?v=I-xQpuZ_UFM
https://www.ai.univ-paris8.fr/~alinehuf/m1/cours2-3/cours2-3_threads_acces_concurents.pdf
https://www.geeksforgeeks.org/mutex-lock-for-linux-thread-synchronization/
https://www.youtube.com/watch?v=F59sCis0hl4


Dining Philosophers Problem:

https://perso.ens-lyon.fr/michael.rao/ASR2/cours_slides_8.pdf
https://www.youtube.com/watch?v=dOVdsd31WNg
https://medium.com/swlh/the-dining-philosophers-problem-solution-in-c-90e2593f64e8
