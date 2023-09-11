# Grey Wolf Optimizer (GWO) implementation in C
Based on the tutorial: https://github.com/olehsinkevych/gwo_c

Here is the pure C implementation of the Grey Wolf optimizer mostlt based on the original paper https://doi.org/10.1016/j.advengsoft.2013.12.007.

## Build and run (Linux setup)
To build and run one can use CMakeLists.txt as follows:
1. Make sure you have a proper version of cmake. Check it
```bash
$ cmake --version
```
and if needed replace line cmake_minimum_required(VERSION 3.22) in CMakeLists.txt. 
2. From the folder project run:
```bash
$ cmake ./
```
3. Once done, run
```bash
$ cmake --build .
```
4. Ready to run file _gwo_ will be generated
## Experiment
You may test alredy provided functions or write your own and place it in functions.c.
Input parameters are hardcoded in main.c, but a better way is to use some config file.
