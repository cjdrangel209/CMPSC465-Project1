# CMPSC465-Project1
For trains coming in on Track A in numerical order, the program determines if the order set in the input file can be accomplished so that the trains are in that order on track B. If that can be accomplished, it outputs "Yes" to an output file. If it cannot be accomplished, it outputs "No" to the file

There is a famous railway station in PopPush City. Country there is incredibly hilly. The station was built in
last century. Unfortunately, funds were extremely limited that time. It was possible to establish only a
surface track. Moreover, it turned out that the station could be only a dead-end one (see picture) and due to
lack of available space it could have only one track.
The local tradition is that every train arriving from the direction A continues in the direction B with coaches
reorganized in some way.
Assume that the train arriving from the direction A has N ≤ 1000 coaches numbered in increasing order
1, 2, …, N.
The chief for train reorganizations must know whether it is possible to marshal coaches continuing in
the direction B so that their order will be , , …, . Help him and write a program that decides
whether it is possible to get the required order of coaches.
You can assume that single coaches can be disconnected from the train before they enter the station
and that they can move themselves until they are on the track in the direction B.
You can also suppose that at any time there can be located as many coaches as necessary in the
station. But once a coach has entered the station it cannot return to the track in the direction A and
also once it has left the station in the direction B it cannot return back to the station.
Program Input
The input file consists of blocks of lines, each of which is a test case. Each block except the last
describes one train and possibly more requirements for its reorganization. In the first line of the block
there is the integer , which is the number of coaches in the train. In each of the next lines of the block
there is a permutation of 1, 2, …, N . For example, if N is 5, and the permutation could be 5, 3, 2, 1, 4.
Your program will take this permutation as input and determine whether you can marshal the coaches
from track A an incoming order 1, 2, 3, 4, 5 to track B with an outgoing order 5, 3, 2, 1, 4 using the
station, which can be treated as a stack.
The last line of the block contains just 0.
If a block starts with a zero, the program will terminate.
You should use the input file named lab1in.txt (download from Canvas) to test your program; an
output file named lab1out.txt (with correct output) is also provided for you to verify your program.
Program Output
The output file contains the lines corresponding to the lines with permutations in the input file. A line of the
output file contains "Yes" if it is possible to marshal the coaches in the order required on the corresponding
line of the input file. Otherwise it contains "No". In addition, there is one empty line after the lines
corresponding to one block of the input file. There is no line in the output file corresponding to the last
"null'' block of the input file.
