How to compile all the algorithms into executables:
1. Open the bash console on the flip server.
2. In the console, navigate to the directory containing all the source files
3. Type in "make" into the console.
4. All executables should compile correctly.

Executeable Guide (To be followed after compiling):
1. Run "enum" in the console to run the enumerable implemention (algorithm 1)
2. Run "betterenum" in the console to run the better enumerable implemention (algorithm 2)
3. Run "dandc" in the console to run the divide and conquer implemention (algorithm 3)
2. Run "lineartime" in the console to run the linear time implemention (algorithm 4)

Behavior after running each executable:
- All algorithm executables are set to use the MSS_Problems.txt file and appead the results to MSS_Results.txt.

Extras:
- Run "make clean" to clean all the compiled executables and to clean the results file.
- Run "timing" (after compilation) to generate some timing trials. You will need to uncomment some code in timing.c in order to turn on the timing of all algorithms. We did this because it would take too long to run all algorithms at once.
