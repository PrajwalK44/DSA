% Facts
parent(john, mary).    % John is a parent of Mary
parent(john, jim).     % John is a parent of Jim
parent(mary, anne).    % Mary is a parent of Anne
parent(jim, ben).      % Jim is a parent of Ben

% Rules
% A person is a mother if they are a parent and their child is female.
mother(X, Y) :-
    parent(X, Y),
    female(Y).

% A person is a father if they are a parent and their child is male.
father(X, Y) :-
    parent(X, Y),
    male(Y).

% A person is a grandparent if they are a parent of a parent.
grandparent(X, Y) :-
    parent(X, Z),
    parent(Z, Y).

% A person is a sibling if they share the same parent.
sibling(X, Y) :-
    parent(Z, X),
    parent(Z, Y),
    X \= Y.

% A person is an ancestor if they are an ancestor of someone else.
ancestor(X, Y) :-
    parent(X, Y).
ancestor(X, Y) :-
    parent(X, Z),
    ancestor(Z, Y).

% Gender Facts (Can be used for mother/father rules)
female(mary).    % Mary is female
female(anne).    % Anne is female
male(john).      % John is male
male(jim).       % Jim is male
male(ben).       % Ben is male

% Queries
% Find the mother of Anne:
% ?- mother(Mother, anne).

% Find the siblings of Jim:
% ?- sibling(Sibling, jim).

% Find the ancestors of Ben:
% ?- ancestor(Ancestor, ben).
