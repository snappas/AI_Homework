connect(a,b,5).
connect(a,c,8).
connect(a,d,10).
connect(b,e,9).
connect(b,d,2).
connect(c,d,4).
connect(c,f,5).
connect(d,e,6).
connect(d,f,11).
connect(d,g,4).
connect(e,g,2).
connect(f,g,1).

% Base case
path(X,Y,L,Path) :- connect(X,Y,L), atom_concat(X,Y,Path). 
% when the knowledge base contains a direct path between X and Y the path is XY with length L

% Search case
path(X,Y,L,Path) :- connect(X,Z,L1), path(Z,Y,L2,P2), L is L1 + L2, atom_concat(X,P2,Path). 
% 1a. when the knowledge base does not contain a direct path between X and Y, search for an intermediary path where X -> Z -> Y
% 1b. recursively, continue searching for X,Z_1,...,Z_n,Y until the search space is exhausted
% 2a. using the base case, obtain L2 and P2
% 2b. P2 is the path between Z_1 and Y. L2 is the length between Z_1 and Y. L is the length between X and Z_1 + L2
% 3. Path is X + P2 = X,Z_1,...,Z_n,Y

% Base case 
pathLength([_],0). 
% when the list has 1 element, the path length is 0 

% Reduction case
pathLength([X,Y|T],L) :- connect(X,Y,L1), pathLength([Y|T],L2), L is L1 + L2.
% 1. when the list has 2 or more elements, use the first two to get the length between them, L1
% 2a. recursively repeat without the first element of the list to obtain L2 until the list is size 1, the base case
% 2b. when the base case returns, L will successively add the previous calls to obtain the original L2
% 3. add L1 and L2 to get the final L
