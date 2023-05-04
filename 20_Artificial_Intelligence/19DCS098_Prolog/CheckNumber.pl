
checknumber(X,Y):-
    A is  ((X+Y)/2),

    B is sqrt(X*Y),

    C is max(X,Y),

   write("X+Y/2 : "),
   write(A),nl,
   write("sqrt(X,Y): "),
   write(B),nl,
   write("max(X,Y) : "),
   write(C),nl.
