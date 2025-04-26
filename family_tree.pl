familyy tree

% Facts
male(john).
male(tom).
female(sara).
female(lily).

parent(john, tom).
parent(sara, tom).
parent(john, lily).
parent(sara, lily).

% Rules
father(X,Y) :- male(X), parent(X,Y).
mother(X,Y) :- female(X), parent(X,Y).
sibling(X,Y) :- parent(Z,X), parent(Z,Y), X \= Y.