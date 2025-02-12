[![List](https://github.com/Fluxifys/exercies7/actions/workflows/build.yml/badge.svg?branch=main)](https://github.com/Fluxifys/exercies7/actions/workflows/build.yml)
EX 7:
====
To do exercise 4, practice CI by

    Following the Github Flow strategy
    Creating a workflow which is triggered on
        Push to any branch to build and run the test
        Pull request on the main branch to build and run the test
    Creating a status badge in README.md

EX 4:
Using TDD and googletest develop and test a linked list class to strore and restore data of type int according the following requirements.

    The data stored in a linked list shall be unique and sorted.
    The class shall be uncopayable and moveable.
    To build and run the test, use a cmake file.
    The class shall provide the following functions:
        An insert function to insert an integer in a list.
        A size function to return the number of data elements stored in a list.
        A search function to check if an integer exists in the list or not.
            If the value exists in the list the function shall return its position; otherwise 0 shall be returned
        A remove function to delete an integer from the list.
            If the integer does not exist the function shall return false.
        An edit function to change the data stored in a node of a list.
            Note that the data stored in the list shall always be unique and sorted.
        A clear function to clear a list.
    Don’t use std::exit or assert in the class.
