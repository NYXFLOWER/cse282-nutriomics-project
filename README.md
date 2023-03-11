# CSE 282 Final Project

LHS: A Combinatorial optimization algorithm for nutrient treatment Recommendations in patients with low microbe abundances.

## Requirements

1. Clang or GCC C++ compiler (Clang preferred)
2. CMake
3. Armadillo linear algebra library

### Installing requirements

For macOS with homebrew

```sh
brew install cmake armadillo
```

Note: `clang-format` is suggested to be installed with `brew` for coding style consistence.

## Compiling

1. Create the build folder

```sh
mkdir build
cd build
```

2. Configure the project

```sh
export CC=clang
export CXX=clang++
cmake -DCMAKE_BUILD_TYPE=Release ..
```

3. Build the project

```sh
cmake --build .
```

## Testing

We integrated Catch2 framework with `CTest`. To run the test, the following
command can be used.

```sh
# In the build folder
ctest
```

## Folder Architecture

`src`: cpp code folder

- `cli`: executable folder 
- `core`: functionality of the program
- `ds`: data structure for the program
- `util`: utility functions

`include`: header folder

`res`: data and resource folder

`test`: unit testing

## Usage and Experiments

The `nutriomics main` script can be used with the following arguments:

```shell
Usage: nutriomics_main [--help] [--version] --nim VAR --patient VAR -k VAR [--output VAR] [--algorithm VAR] [--depth VAR] [--top-level VAR] [--top-overall VAR]

Optional arguments:
  -h, --help            shows help message and exits 
  -v, --version         prints version information and exits 
  -n, --nim             specify the nutrient impact matrix file [required]
  -p, --patient         specify the patient input file [required]
  -k                    specify the maximum nutrient allowance [required]
  -o, --output          specify csv output path [default: "treatment_result.csv"]
  -a, --algorithm       specify the algorithm between bruteforce and proposed [default: "bruteforce"]
  -d, --depth           specify the subtree expanding depth for proposed algorithm [default: 2]
  -l, --top-level       specify the number of top states to keep at each level during subtree expanding for proposed algorithm [default: 10]
  -v, --top-overall     specify the number of top states to keep in the subtree during subtree expanding for proposed algorithm [default: 10]
```

Note for data preparation:

- The order of nutrients and microbes in the `nims.csv` and `patient_inputs.csv` need to be consistent.
- We use the `real` time from the `time` command for measuring the runtime of each experiments.
- An example experiment bash file if provided in the `experiment` folder for reference.

## Author

1. Pisit Wajanasara ([@nekoteoj](https://github.com/nekoteoj))
2. Hao Xu ([@NYXFLOWER](https://github.com/NYXFLOWER))
