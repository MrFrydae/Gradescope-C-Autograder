# Autograder for C Programs

This repository contains an autograder for C programs designed for use with Gradescope. The autograder script automates the process of compiling, running, and grading student submissions.

## Repository Structure

- `src/`: Contains the source code for the autograder.
- `submission/`: Contains student submissions.
- `autograder/`: Directory where the autograder processes and stores results.
- `test_autograder.sh`: Script to build and run the autograder.
- `.gitignore`: Specifies files and directories to be ignored by Git.

## Prerequisites

Ensure you have the following installed on your system:
- Bash
- Zip/Unzip utilities
- C compiler (e.g., `gcc`)

## Usage

1. **Prepare the Autograder:**
    - Place the autograder source code in the `src/` directory.  These files already exist:
        - main.c Runs the tests
        - test_tools.c/.h A place to put functions to support your tests
        - test_details.h Just the calls on check_one_thing that make up your tests
     - Build the whole autograder and a sample submission

2. **Prepare Student Submissions:**
    - Copy sample student submission  files into the `submission/` directory.

3. **Run the Autograder:**
    - Execute the `test_autograder.sh` script to build and run the autograder:
      ```sh
      ./test_autograder.sh
      ```
    - That will also build the zip file that you'll upload to GradeScope.  It will include the source files in the src/ file excluding files named the same as the the files in the submission/ directory.

## Script Details

The `test_autograder.sh` script performs the following steps:

1. **Create Autograder Archive:**
    - Removes any existing `autograder.zip` file.
    - Zips the contents of the `src/` directory into `autograder.zip`, excluding object files, the `runner` executable, and any "submission" files (files with matching names in both `src/` and `submission` directories).

2. **Setup Autograder Directory:**
    - Removes any existing `autograder` directory.
    - Creates necessary directories: `autograder/source`, `autograder/results`, and `autograder/submission`.
    - Unzips `autograder.zip` into `autograder/source`.
    - Copies the `run_autograder` script to the `autograder` directory.
    - Copies sample student submissions to `autograder/submission`.

3. **Run the Autograder:**
    - Changes to the `autograder` directory.
    - Executes the `run_autograder` script and saves the results to `autograder/results/results.json`.

## Results

The results of the autograder are stored in `autograder/results/results.json`. This file contains the scores and statuses of the tests run by the autograder.

## License

This project is provided without any specific license. It is freely available for use, modification, and distribution. No warranty or liability is provided for any use of this software.

## Contributing

Contributions are welcome! Please open an issue or submit a pull request for any improvements or bug fixes.

## Contact

For any questions or issues, please contact the repository maintainer at [MrFrydae@gmail.com](mailto:MrFrydae@gmail.com).

## Note

The `test_autograder.sh` script will build an `autograder.zip` file that the instructor will upload to Gradescope as the autograder file.
