To compile the application
```
make app
```

This test creates a Gaussian with mean=0 and sigma=1. Provide the integration intervals in terms of sigma

For example to ingerate between [0,3sigma]:
```shell
$ ./app 
Program computes integral of the Gaussian function between  a x sigma -> b x sigma
a: 0.  
b: 3.
# points:         10	 Integral: 0.359179
# points:        100	 Integral: 0.55398
# points:       1000	 Integral: 0.505288
# points:      10000	 Integral: 0.498814
# points:     100000	 Integral: 0.497667
# points:    1000000	 Integral: 0.498952
# points:   10000000	 Integral: 0.498977
```

