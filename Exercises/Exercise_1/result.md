3: Sharing a variable
---------------------
When running a for loop in c
```
    for (int b = 0; b < 1000000; b++)
```
for both functions and then printing the magic number each time a functions has ''b%100000==0'' we can see that they both run simultaneously leading to the overwriting the i value leading to some incremends/decrements being "lost". 
$ ./a.out 
The magic number is: 1
The magic number is: 0
The magic number is: -94784
The magic number is: -96285
The magic number is: -189343
The magic number is: -193692
The magic number is: -172691
The magic number is: -290638
The magic number is: -189797
The magic number is: -387956
The magic number is: -308911
The magic number is: -309656
The magic number is: -260273
The magic number is: -407239
The magic number is: -306835
The magic number is: -505575
The magic number is: -405575
The magic number is: -602887
The magic number is: -626404
The magic number is: -698941
The final magic number is: -798083

the similar thing happened with go:
$ go run foo.go 
The magic number is: -1
The magic number is: -500
The magic number is: 16217
The magic number is: 61348
The magic number is: 61076
The magic number is: 115194
The magic number is: 51146
The magic number is: 61909
The magic number is: -37091
The magic number is: 79745
The magic number is: 64887
The magic number is: -33393
The magic number is: 134275
The magic number is: 129463
The magic number is: 135508
The magic number is: 133662
The magic number is: 217813
The magic number is: 317813
The magic number is: 417813
The magic number is: 517813
The final magic number is: 617812


4: Sharing a variable, but properly
-----------------------------------

I would choose mutexes in this scenario as this is quite the simple codewhere I don't need any interupts, also this code has no risk of sleeping while in the critical section or getting preemptied by a high-priority process, leading to no other thread can enter into the critical section(CS). Given the issues from the problem before we would like to keep the data consistent and maintain its integrity.

Semaphore has the advantage of allowing multiple threads to access the CS, but is prone to programming error and this can lead to deadlock.