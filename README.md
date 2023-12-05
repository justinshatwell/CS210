# CS210

# Summarize the project and what problem it was solving
The assignment was to create a program that read a list of grocery items from a text file, then recorded and displayed how many times each item appeared on the list. Users should have the ability to search for a particular item or see all items displayed both numerically and as a histogram. The program should also create a .dat backup file of the data it read.

# What did you do particularly well?
I made very concious decisions about what data structures to use and how to store data. Since the program needed both quick look-ups and quick ordered-list insertions, I created both a hash table and a linked list to accomplish this. All of the programs functions were either O(1) or O(N). I also dynamically allocated memory so that there was no redundant data storage. Each Word object in the program had a single memory location on the heap.

# Where could you enhance your code? How would these improvements make your code more efficient, secure, and so on?
The code could be improved by allowing it to read from other files. For the assignment, the test document we were to read from was simply hardcoded into the program, as was the back-up file. The program could be more useful if it allowed users to read outside files.

# Which pieces of the code did you find most challenging to write, and how did you overcome this? What tools or resources are you adding to your support network?
The most difficult aspect of the project was ensuring that the Word objects were only appearing once in memory. I used print statements in the ~Word() function to ensure that every Word created was deleted at the appropriate time.

# What skills from this project will be particularly transferable to other projects or course work?
I feel like I took a big step forward in my understanding of memory allocation. This is the first C++ program I've written where I was 100% sure of what my pointers were really doing. I'm interested in a career in C/C++, so this knowledge will be invaluable going forward.

# How did you make this program maintainable, readable, and adaptable?
I followed standard naming conventions and provided comments throughout the code. I also created documentation on how the program works.
