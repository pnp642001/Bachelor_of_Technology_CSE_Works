branch(a,b).
branch(a,c).
branch(c,d).
branch(c,e).

path(X,X).
path(X,Y):-
    branch(X,Z),path(Z,Y).
