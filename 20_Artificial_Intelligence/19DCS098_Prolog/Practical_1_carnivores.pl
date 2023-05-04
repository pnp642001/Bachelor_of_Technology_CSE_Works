lion(simba).
tiger(rudra).
goat(ramesh).

animal(X):-
    lion(X);
    tiger(X);
    goat(X).

carnivores(X):-
    animal(X),lion(X);
    animal(X),tiger(X).


